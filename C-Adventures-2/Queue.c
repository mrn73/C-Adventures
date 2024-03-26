#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

Queue* queue_init() {
    int capacity = 10;
    struct Queue* newQueue = malloc(sizeof(struct Queue) + (capacity * sizeof(int)));

    if (newQueue == NULL) {
        fprintf(stderr, "Memory allocation failed for Queue. \n");
        exit(1);
    }

    newQueue->data = malloc(capacity * sizeof(int));
    newQueue->size = 0;
    newQueue->capacity = capacity;
    return newQueue;
}


void enqueue(Queue *q, int value)
{
    if (q->capacity == q->size)
    {
        q->capacity *= 2;
    }

    q->size += 1;
    q->data[q->size - 1] = value;
}

int dequeue(Queue *q)
{
    int curr = q->data[0];
    int i = 0;

    while (i < q->size)
    {
        q->data[i] = q->data[i + 1];
        i++;
    }

    q->size -= 1;
    return curr;
}

int get_head(Queue* q) {
    if (q->size > 0) {
        return q->data[0];
    }

    return 0;
}

int get_tail(Queue* q) {
    if (q->size > 0) {
        return q->data[q->size-1];
    }

    return 0;
}


void print_queue(Queue* q) {
    printf("Size: %d\n", q->size);
    printf("Capacity: %d\n", q->capacity);
    printf("Head %d\n", get_head(q));
    printf("Tail %d\n", get_tail(q));
}