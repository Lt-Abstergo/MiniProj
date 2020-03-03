//
// Created by ltabstergo on 2020-03-02.
//

#ifndef TASK_H
#define TASK_H
typedef struct task {
    char *name;
    int tid;
    int priority;
    int burst;
    int remBurst;
    int waitTime;
    int tat;
} Task;

#endif //MINIPROJ_TASK_H