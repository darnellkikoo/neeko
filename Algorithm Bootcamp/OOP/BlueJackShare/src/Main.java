import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//TITLE
		ArrayList<Participant> person = new ArrayList<>();
		Scanner scan = new Scanner(System.in);
		System.out.println();
		int choice = 1;
		
		do {
			System.out.println("+======================+");
			System.out.println("+Options               +");
			System.out.println("+======================+");
			System.out.println("+1. Start Sharing      +");
			System.out.println("+2. Update Participant +");
			System.out.println("+3. Delete Participant +");
			System.out.println("+4. Close App          +");
			System.out.println("+======================+");
			System.out.printf("Choice >> ");
			
			choice = scan.nextInt();
			scan.nextLine();
			
			if(choice == 1) {
				int choice1 = 0;
				
				//input number
				do {
					System.out.printf("Input a number [0 - 100]: ");
					try {
						choice1 = scan.nextInt();
						scan.nextLine();
					} catch (Exception e) {
						// TODO: handle exception
						scan.nextLine();
						System.out.println("Input must be numeric");
					}
				}while(choice1 < 0 || choice1 > 100);
				
				
				//input username
				String username;
				System.out.printf("Could you give me  you username [5 - 20 characters]? ");
				
			}


		}while(choice == 3);
		
		scan.close();
	}

}







