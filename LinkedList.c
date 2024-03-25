#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

ListNode* _create_node(int data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed for ListNode. \n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert_head(ListNode** head, int data) {
    ListNode* newNode = _create_node(data);
    newNode->next = *head;
    *head = newNode;
}

void insert_tail(ListNode* head, int data) {
    ListNode* current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    ListNode* newNode = _create_node(data);
    current->next = newNode;
}

int remove_head(ListNode** head) {
    if (*head == NULL)
        return -1;

    ListNode* newHead = (*head)->next;
    int val = (*head)->data;
    free(*head);
    *head = newHead;

    return val;
}

int remove_tail(ListNode** head) {
    if ((*head) == NULL)
        return -1;

    if ((*head)->next == NULL) {
        int val = (*head)->data;
        free(*head);
        (*head) = NULL;
        return val;
    }

    ListNode* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    int val = current->next->data;
    free(current->next);
    current->next = NULL;

    return val;
}

void display(ListNode* head) {
    if (head == NULL)
        return;

    for (ListNode* curr = head; curr != NULL; curr = curr->next) {
        printf("%d\n", curr->data);
    }
}

void clean(ListNode* head) {
    if (head == NULL)
        return;

    while (head != NULL) {
        ListNode* next = head->next;
        free(head);
        head = next;
    }
}

ListNode* init_from_array(int* data, int size) {
    if (size <= 0)
        return NULL;

    ListNode* head = _create_node(data[0]);
    for (int i = 1; i < size; i++) {
        insert_tail(&head, data[i]);
    }

    return head;
}

ListNode* init_with_value(int data) {
    return _create_node(data);
}