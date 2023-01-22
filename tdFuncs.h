//
// Created by AghoyPandaaa on 1/19/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "tdBase.h"
#ifndef TDY_TDFUNCS_H
#define TDY_TDFUNCS_H

#endif //TDY_TDFUNCS_H


task *addNewTask(){
    head = addTaskToEndOfList(head, newTask());
    return head;
}


void removeTask(){
    displayTaskTitles(head);
    printf("Which one should be deleted? : ");
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
    printf("Which one needs to be edited? : ");
    int selectedTaskNumber = getNumericInput();
    task *selectedTask = (searchTasks(selectedTaskNumber));
    editTaskData(selectedTask);
    displayFullTaskList(head);
}

void prioritizeTasks(){
    int numberOfTasks = fixTasksNum(head);
    displayTaskTitles(head);
    printf("Enter the number of task you want to change its position : ");
    int selectedTaskNumber; scanf("%d", &selectedTaskNumber);
    task *selectedTask = searchTaskByNumber(head, selectedTaskNumber);
    printf("\n\nEnter new postition of the task : ");
    int newPos; scanf("%d", &newPos);
    if(newPos > numberOfTasks)
        printf("There are only %d tasks, try again...\n\n\n",numberOfTasks);
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
    }
    fixTasksNum(head);
}


