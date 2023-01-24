//Saeed Pakniat 40139537


#include <stdio.h>
#include <stdlib.h>
#include "tdFuncs.h"


int main() {

    /*
    head = addNewTask();
    head = addNewTask();
    head = addNewTask();
    fixTasksNum(head);
    displayTaskTitles(head);
    fixTasksNum(head);
    editTask();
     */
    splashScreen();
while(1) {
    system("cls");

    printf("\nEnter The Number Of Option You Want To Use");
    printf("\n\n\n");
    printf("1. Display List Of Tasks With All Info");
    printf("\n2. Add New Task");
    printf("\n3. Remove A Task From List By Its Number");
    printf("\n4. Edit A Part Of Previous Added Task");
    printf("\n5. Prioritize Tasks");
    printf("\n6. Exit The App");
    printf("\n\n\nYour Choise : ");

    int userChoise = getNumericInput();
    switch(userChoise){
        case 1:
            displayFullTaskList(head);
            break;
        case 2:
            head = addNewTask();
            fixTasksNum(head);
            break;
        case 3:
            removeTask();
            break;
        case 4:
            editTask();
            break;
        case 5:
            prioritizeTasks();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Chosen Number Wasn't Recognized. Try Again");

    }
}

}
