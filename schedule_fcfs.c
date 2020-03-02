//
// Created by ltabstergo on 2020-03-02.
//

#include <stdlib.h>
#include <string.h>
#include "schedulers.h"
#include "list.h"
#include "cpu.h"

void add(char *name, int priority, int burst) {
    static Node *cursor = &header;
    Task *temp = malloc(sizeof(Task));
    static int index = 1;
    temp->tid = index++;
    temp->name= name;
    temp->burst = burst;
    temp->priority = priority;
    insert(cursor, temp);
    cursor = cursor->next;

}

void schedule() {
    struct node *pointer = &header;
    struct node *temp = pointer->next;
    while(temp!= NULL){
        run(temp->task,0);
        temp=temp->next;
    }
    
}