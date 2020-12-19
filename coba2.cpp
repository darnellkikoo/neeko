#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// CRUD
// create, read, update, delete
struct Mentor{
    int ID;
    char name[255];
    int age;
    double gpa;
};

//function akan sebuah pointer yang menunjuk ke Mentor yang baru dibuat
Mentor *createMentor(const char *name, int age, double gpa)
{
    //malloc return void* dicast jadi mentor*
    //malloc sebesar ukuran struct mentor
    Mentor *newMentor = (Mentor*)malloc(sizeof(Mentor));
    strcpy(newMentor->name, name);
    newMentor->age = age;
    newMentor->gpa = gpa;
    return newMentor; //returun mentor baru
}

void printData(Mentor *m) {
    printf("Name: %s\n", m->name);
    printf("Age: %d\n", m->age);
    printf("GPA: %.2lf\n", m->gpa);
}

void deleteMentor(Mentor *m)
{
    free(m); //free allocated memory
}

int main()
{
    //static memory allocation
    Mentor *m = createMentor("Kevice", 20, 3.85);
    printData(m);
    deleteMentor(m);
    return 0;
}
    