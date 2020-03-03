/**
 * Driver.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"

#define SIZE    100

int main(int argc, char *argv[])
{
    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int priority;
    int burst;
    header = malloc(sizeof(Node));
    tail = malloc(sizeof(Node));
    header= tail;
    Timings *schedTime = malloc(sizeof(Timings));


    in = fopen("schedule.txt","r");

    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));

        add(name,priority,burst);

        free(temp);
    }



    fclose(in);
    avgCalculation(header, schedTime);
    // invoke the scheduler
    schedule();
    printf("Average waiting time %.03f\n"
           "total turn around time  %.03f\n"
           "average response time %.03f\n", schedTime->awt,schedTime->tat, schedTime->art);
    return 0;
}