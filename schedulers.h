//
// Created by ltabstergo on 2020-03-02.

#ifndef MINIPROJ_SCHEDULERS_H
#define MINIPROJ_SCHEDULERS_H

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

#include "task.h"
#include "list.h"


void schedule();

void add(char *name, int priority, int burst);

#endif //MINIPROJ_SCHEDULERS_H