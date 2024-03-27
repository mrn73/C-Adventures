#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int *data;
    int size;
    int capacity;
} Queue;

void enqueue(Queue* queue, int value);
int dequeue(Queue* queue);
Queue* queue_init();
int get_head(Queue* q);
int get_tail(Queue* q);
void print_queue(Queue* q);
#endif