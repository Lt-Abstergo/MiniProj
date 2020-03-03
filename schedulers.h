//
// Created by ltabstergo on 2020-03-02.

#ifndef MINIPROJ_SCHEDULERS_H
#define MINIPROJ_SCHEDULERS_H

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

#include "task.h"
#include "list.h"
typedef struct calculation{
    double awt;
    double tat;
    double art;
} Timings;

void schedule();

void add(char *name, int priority, int burst);

void avgCalculation(Node* head, Timings *ret);
#endif //MINIPROJ_SCHEDULERS_H