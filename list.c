//
// Created by ltabstergo on 2020-03-02.
//
#include "list.h"

#include <stdlib.h>
#include <string.h>

void insert(Node *head, Task *task) {
    Node* temp;
    Node *p;
    temp = malloc(sizeof(Node));
    temp->task= task;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
    }else{
        p = head;
        while(p->next!= NULL){
            p = p->next;
        }
        p->next =temp;
    }
}
void delete(Node *head, Task *task){
    Node *temp;
    Node *prev;

    temp = head;
    // special case - beginning of list
    if (strcmp(task->name,temp->task->name) == 0) {
        header->next = (head)->next;
    }
    else {
        // interior or last element in the list
        prev = head;
        temp = temp->next;
        while (strcmp(task->name,temp->task->name) != 0) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
    }
}

