//
// Created by ltabstergo on 2020-03-02.
//

#include "schedulers.h"
#include "mergeSortHelper.h"

void split(Node *source, Node **frontRef, Node **backRef);

Node *sortedMerge(Node *a, Node *b);

void mergeSort(Node **headRef);

void add(char *name, int priority, int burst) {
    Task *temp = malloc(sizeof(Task));
    static int index = 1;
    temp->tid = index++;
    temp->name = name;
    temp->burst = burst;
    temp->priority = priority;

    insert(tail, temp);
    tail = tail->next;
}

void schedule(Timings *ret) {
    double total = 0.0, timePassed = 0.0, tat = 0.0, art = 0.0;
    int tasks = 0;
    mergeSort(&header->next);
    struct node *pointer = header->next;
    while (pointer != NULL) {
        total += timePassed;
        pointer->task->waitTime = timePassed;
        tat += timePassed + pointer->task->burst;
        timePassed += pointer->task->burst;
        art += timePassed;
        pointer->task->waitTime = timePassed;
        pointer->task->tat = pointer->task->waitTime+ pointer->task->burst;
        tasks++;
        run(pointer->task, 0);
        pointer->task->remBurst=0;
        delete(header->next, pointer->task);
        pointer = pointer->next;
    }
    ret->awt = total / tasks;
    ret->art = art / tasks;
    ret->tat = tat / tasks;
}

Node *sortedMergeHelper(Node *result,Node *a, Node *b){
    if (a->task->priority > b->task->priority) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else if (a->task->priority == b->task->priority) {
        if (a->task->burst < b->task->burst) {
            result = a;
            result->next = sortedMerge(a->next, b);
        } else {
            result = b;
            result->next = sortedMerge(a, b->next);
        }
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
}