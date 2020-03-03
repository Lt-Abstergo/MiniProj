//
// Created by ltabstergo on 2020-03-02.
//

#include <stdlib.h>
#include <string.h>
#include "schedulers.h"
#include "list.h"
#include "cpu.h"

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

void schedule() {
    struct node *pointer = header->next;
    while (pointer != NULL) {
        run(pointer->task, 0);
        delete(header->next, pointer->task);
        pointer = pointer->next;
    }

}

void avgCalculation(Node *head, Timings *ret) {
    double total = 0.0 , timePassed = 0.0, tat = 0.0, art = 0.0;
    int tasks = 0;
    struct node *pointer = head->next;
    while (pointer != NULL) {
        total += timePassed;
        tat += timePassed + pointer->task->burst;
        timePassed += pointer->task->burst;
        art += timePassed;
        tasks++;
        pointer = pointer->next;
    }
    ret->awt = total/tasks;
    ret->art = art/tasks;
    ret->tat = tat/tasks;
}
