#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

void insert_head(ListNode** head, int data);
void insert_tail(ListNode* head, int data);
int remove_head(ListNode** head);
int remove_tail(ListNode** head);
void display(ListNode* head);
void clean(ListNode* head);
ListNode* init_from_array(int* data, int size);
ListNode* linkedlist_init_with_value(int data);

#endif