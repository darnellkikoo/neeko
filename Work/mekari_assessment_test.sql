with fact_timesheets as
( /* load all timesheets table */
  select *,
    /* handle all case checkin, assuming all workers check in before 12, making all above 12 to be converted into morning time */
    /* example: 20:00 into 08:00 , sample timesheet_id : 33861858 , 31374868*/
    CASE 
      WHEN EXTRACT(HOUR FROM checkin) > 12 THEN
        TIME_ADD(checkin, INTERVAL -12 HOUR)
      ELSE checkin
    END checkin_cleaned
  /* handle case where the time does not show in PM (06:00 should be 18:00) */
  /* sample timesheet_id 31156156 */
  , case
      WHEN EXTRACT(HOUR from checkout) < 12 
        THEN TIME_ADD(checkout, INTERVAL 12 HOUR)
      ELSE checkout
    end checkout_cleaned
    -- select *
    from `sandbox_bi.timesheets`
)
,  fact_working_hours as
( /* calculate the time of the employees working per date */
  select * except(hours_worked, hours_worked_cleaned)
  /* clean the data that has checkout null values */
  /* will coalesce it with the average worked hours of the employee if check out is null */
  /* sample timesheet_id, 33141552, 65879884 */
  , round(coalesce(hours_worked, avg(hours_worked) over(partition by employee_id))) hours_worked
  , round(coalesce(hours_worked_cleaned, avg(hours_worked_cleaned) over(partition by employee_id))) hours_worked_cleaned
  from
  (
    select
      timesheet_id
      , employee_id
      , date
      , checkin
      , checkout
      , checkin_cleaned
      , checkout_cleaned
      , abs(TIMESTAMP_DIFF
        (
            TIMESTAMP(DATETIME(date, checkout)),
            TIMESTAMP(DATETIME(date, checkin)),
            HOUR
        )) hours_worked      
      , abs(TIMESTAMP_DIFF
        (
            TIMESTAMP(DATETIME(date, checkout_cleaned)),
            TIMESTAMP(DATETIME(date, checkin_cleaned)),
            HOUR
        )) hours_worked_cleaned
      from fact_timesheets    
  )
)
, summary_working_hours as
( /* aggregate total working hours from each employee */
  select
    employee_id
    , date_trunc(date, month) working_month
    /* assuming employees worked 12 hours max, if it exceeds 14 hours, we will use the non cleaned data of working hours */
    /* example of employee_id, 37659 */
    /* using the cleaned checkin checkout, the result would be 19 */
    /* using the uncleaned checkin checkout, the result would be 7 */
    , sum(if(hours_worked_cleaned <= 12, hours_worked_cleaned, hours_worked)) total_hours_worked
  from fact_working_hours
  group by 1,2
)
, fact_employees as
( /* get all employees data */
  select * except(employe_id)
  , employe_id employee_id
  /* clean data for resign date is null, we assume they are still working until today */
  , date_diff(coalesce(resign_date, date(current_date('Asia/Jakarta'))),join_date, month) total_months_worked
  from `sandbox_bi.employees`
  /* there is 1 employee id in the table that has duplicate values. will take the one with the highest salary */
  /* sample id 218078 */
  qualify row_number() over(partition by employe_id order by salary desc) = 1
)
, summary_employees_working_salary as
(
  select w.*
    , e.* except(employee_id)
  from summary_working_hours w
  left join fact_employees e
    using(employee_id)
)
  select *
  from summary_employees_working_salary
/* duplicate check
  select employee_id, working_month, count(1) c
  from summary_employees_working_salary
  group by 1,2
  having c > 1
*/
