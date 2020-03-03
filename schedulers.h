//
// Created by ltabstergo on 2020-03-02.

#ifndef MINIPROJ_SCHEDULERS_H
#define MINIPROJ_SCHEDULERS_H

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10
#include <stdlib.h>
#include <string.h>
#include "schedulers.h"
#include "list.h"
#include "cpu.h"

typedef struct calculation{
    double awt;
    double tat;
    double art;
} Timings;

void schedule(Timings *ret);

void add(char *name, int priority, int burst);
#endif //MINIPROJ_SCHEDULERS_H