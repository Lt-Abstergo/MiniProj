//
// Created by ltabstergo on 2020-03-03.
//

#include <stdio.h>
#include "schedulers.h"

void add(char *name, int priority, int burst) {
    Task *temp = malloc(sizeof(Task));
    static int index = 1;
    temp->tid = index++;
    temp->name = name;
    temp->burst = burst;
    temp->priority = priority;
    temp->waitTime = 0;
    temp->remBurst = burst;
    temp->tat = 0;

    insert(tail, temp);
    tail = tail->next;
}

/*
void schedule(Timings *timings) {
    struct node *pointer = header->next;
    while (pointer != NULL) {
        Node *helper = pointer;
        Task *temp = pointer->task;
        run(pointer->task, QUANTUM);
        if (temp->remBurst < QUANTUM)
            temp->remBurst -= temp->remBurst;
        else
            temp->remBurst -= QUANTUM;
        helper= helper->next;
        while (helper != NULL) {
            if (helper->task != temp)
                if (helper->task->remBurst < QUANTUM)
                    helper->task->waitTime += helper->task->remBurst;
                else
                    helper->task->waitTime += QUANTUM;
            helper = helper->next;
        }
        delete(pointer, pointer->task);
        if (temp->remBurst > 0) {
            insert(tail, temp);
        }
        if (temp->remBurst == 0) {
            printf("task %d finished in %d\n", temp->tid, temp->waitTime);
        }

        pointer = pointer->next;
    }

}*/
void schedule(Timings *timings) {
    struct node *pointer = header->next;
    int tTime = 0;
    Task *temp;
    while (1) {
        int done = 1;
        while (pointer != NULL) {
            if (pointer->task->remBurst > 0) {
                done = 0;
                if (pointer->task->remBurst > QUANTUM) {
                    tTime += QUANTUM;
                    pointer->task->remBurst -= QUANTUM;
                    run(pointer->task, QUANTUM);
                    temp = pointer->task;
                    delete(header->next, pointer->task);
                    insert(header->next, temp);

                } else {
                    tTime += pointer->task->remBurst;
                    pointer->task->waitTime = tTime - pointer->task->remBurst;
                    run(pointer->task, QUANTUM);
                    pointer->task->remBurst = 0;
                    temp = pointer->task;
                    delete(header->next, pointer->task);
                    insert(header->next, temp);
                }
            }
            pointer = pointer->next;
        }
        if (done == 1) {
            break;
        }
    }
    pointer = header->next;
    printf("%d", tTime);
    double ttat = 0, tawt = 0, pN = 0;
    while (pointer != NULL) {
        tawt += pointer->task->waitTime;
        pointer->task->tat = pointer->task->burst + pointer->task->waitTime;
//        printf("task [%d] waited %d and tat %d\n", pointer->task->tid, pointer->task->waitTime, pointer->task->tat);
        ttat += pointer->task->tat;
        pointer = pointer->next;
        pN++;
    }
    timings->tat = ttat / pN;
    timings->awt = tawt / pN;
    timings->art = ttat / pN;

}