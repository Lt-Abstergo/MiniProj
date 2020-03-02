//
// Created by ltabstergo on 2020-03-02.
//
#include "list.h"

#include <stdlib.h>


void insert(Node *head, Task *task) {
    Node *newNode = malloc(sizeof(Node));
    newNode->task = malloc(sizeof(Task));
    newNode->task = task;
    if (head != NULL)
        head->next = newNode;
}
