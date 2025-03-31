#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <string.h>

struct Student {
    char name[20];
    char subject[30];
    float gpa;
    int age;
};

void printDetails(struct Student *s) {

    printf("Name is %s, Subject is: %s, GPA is: %f.1, Age is: %d", s->name, s->subject, s->gpa, s->age);
    return; 
}



int main() {
    

    int classSize = 0;
    int capacity = 2;

   struct Student *students = malloc(capacity * sizeof(struct Student));

    if(students == NULL) {
        perror("Malloc failed");
        return 1;
    }

    while(1) { 
    printf("\n1. Add Student\n2. View Student\n3. Exit\nChoose:");
    int choice;
    scanf("%d", &choice);
    getchar();

    if(choice == 1) {
      if(classSize == capacity) {
        capacity *= 2;
        students = realloc(students, capacity * sizeof(struct Student));
        if(students == NULL) {
            perror("Realloc failed");
            return 1;
        }
        }
     
        printf("Enter a name: ");
        fgets(students[classSize].name, 50, stdin);
        students[classSize].name[strcspn(students[classSize].name, "\n")] = 0;

        printf("Enter a subject: ");
        fgets(students[classSize].subject, 50, stdin);
        students[classSize].subject[strcspn(students[classSize].subject, "\n")] = 0;
       
        printf("Enter GPA: ");
        scanf("%f.1", students[classSize].gpa);
        
        printf("Enter age: ");
        scanf("%d", students[classSize].age);

        

        
    } 
        
    }

}










