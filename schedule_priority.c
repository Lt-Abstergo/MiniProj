//
// Created by ltabstergo on 2020-03-02.
//

#include "schedulers.h"

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
        tat += timePassed + pointer->task->burst;
        timePassed += pointer->task->burst;
        art += timePassed;
        tasks++;
        run(pointer->task, 0);
        delete(header->next, pointer->task);
        pointer = pointer->next;
    }
    ret->awt = total / tasks;
    ret->art = art / tasks;
    ret->tat = tat / tasks;
}

void mergeSort(Node **headRef) {
    Node *head = *headRef;
    Node *a;
    Node *b;
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
    split(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *headRef = sortedMerge(a, b);
}

Node *sortedMerge(Node *a, Node *b) {
    Node *result = NULL;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (a->task->priority > b->task->priority) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else if (a->task->priority == b->task->priority) {
        if (a->task->burst < b->task->burst) {
            result = a;
            result->next = sortedMerge(a->next,b);
        } else {
            result = b;
            result->next = sortedMerge(a, b->next);
        }
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return (result);
}

void split(Node *source, Node **frontRef, Node **backRef) {
    Node *fast;
    Node *slow;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;

}
