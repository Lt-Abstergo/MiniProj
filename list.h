//
// Created by ltabstergo on 2020-03-02.
//

#ifndef MINIPROJ_LIST_H
#define MINIPROJ_LIST_H

#include "task.h"

typedef struct node {
    Task *task;
    struct node *next;
} Node;
Node *header, *tail;


// insert and delete operations.
void insert(Node * head, Task *task);
void delete(struct node *head, Task *task);

void traverse(struct node *head);

#endif //MINIPROJ_LIST_H
