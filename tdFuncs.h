// Saeed Pakniat 40139537
// Created by AghoyPandaaa on 1/19/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "tdLinkedList.h"
#ifndef TDY_TDFUNCS_H
#define TDY_TDFUNCS_H

#endif //TDY_TDFUNCS_H


task *addNewTask(){
    head = addTaskToEndOfList(head, newTask());
    return head;
}


void removeTask(){
    system("cls");
    displayTaskTitles(head);
    printf("\n\nWhich one should be deleted? : ");
    int selectedTaskToDelete = getNumericInput();
    deleteTask(&head, selectedTaskToDelete);
    fixTasksNum(head);

}


task *searchTasks(int taskNum){
    displayTaskTitles(head);
    return searchTaskByNumber(head, taskNum);
}


void editTask(){
    displayTaskTitles(head);
    printf("\n\nWhich one needs to be edited? : ");
    int selectedTaskNumber = getNumericInput();
    task *selectedTask = (searchTasks(selectedTaskNumber));
    editTaskData(selectedTask);
    displayFullTaskList(head);
}

void prioritizeTasks(){
    int numberOfTasks = fixTasksNum(head);
    displayTaskTitles(head);
    printf("\n\nWhich tasks position should be changed? : \n");
    int selectedTaskNumber = getNumericInput();
    task *selectedTask = searchTaskByNumber(head,selectedTaskNumber);
    printf("\n\nWhat position should it be replaced? : \n");
    int newPos = getNumericInput();

    if (newPos - 1 >= getLastNode(head)->taskNumber)
        printf("\n\nSelected number doesn't exist. Try again.");

    if(newPos == selectedTask->taskNumber)
        return;

    task *traversPointer = head;
    task *posPointer = head;
    int posHolder = newPos;

    if(newPos > selectedTask->taskNumber)
        newPos++;

    if(selectedTask->taskNumber == 1)
        head = traversPointer->next;
    else{
        while(traversPointer->next->taskNumber != selectedTask->taskNumber)
            traversPointer = traversPointer->next;

        traversPointer->next = traversPointer->next->next;
    }

    if(posHolder == 1){
        selectedTask->next = head;
        head = selectedTask;
    }
    else if(posHolder == getLastNode(head)->taskNumber){
        getLastNode(head)->next = selectedTask;
        selectedTask->next = NULL;
    }
    else{
        while(posPointer->next->taskNumber != newPos)
            posPointer = posPointer->next;

        selectedTask->next = posPointer->next;
        posPointer->next = selectedTask;
    }
    fixTasksNum(head);
}


void splashScreen(){
    printf("\n\n\n\n\n");
    printf("|-----------------------------------------------------------------------|\n");
    printf("|================= Todo List Simple App=================================|\n");
    printf("|-----------------------------------------------------------------------|\n");
    printf("\n\n\n\n\n\n");
    printf("|---------------------------   Welcome     -----------------------------|\n\n\n\n");
    system("pause");
}

