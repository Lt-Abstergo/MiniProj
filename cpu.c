//
// Created by ltabstergo on 2020-03-02.
//

#include <stdio.h>
#include <zconf.h>

#include "task.h"

// run this task for the specified time slice
void run(Task *task, int slice) {
    if (slice == 0) {
        printf("Running task = [%s] [%d] [%d].\n", task->name, task->priority, task->burst);
    } else{
        printf("Running task = [%s] [%d] [%d] for %d units remaining [%d].\n",task->name, task->priority, task->burst, slice, task->remBurst);
    }
}