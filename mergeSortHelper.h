//
// Created by ltabstergo on 2020-03-03.
//

#ifndef MINIPROJ_MERGESORTHELPER_H
#define MINIPROJ_MERGESORTHELPER_H

#include "schedulers.h"

Node *sortedMerge(Node *a, Node *b);

void split(Node *source, Node **frontRef, Node **backRef);

void mergeSort(Node **headRef);

Node *sortedMergeHelper(Node *result, Node *a, Node *b);


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
    sortedMergeHelper(result, a, b);
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


#endif //MINIPROJ_MERGESORTHELPER_H
