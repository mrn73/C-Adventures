#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "LinkedList.h"

void runLinkedList()
{
    ListNode* head = linkedlist_init_with_value(1);
    insert_tail(head, 2);
    insert_tail(head, 3);
    insert_tail(head, 4);
    insert_head(&head, 5);
    display(head);

    for (int i = 0; i < 6; i++)
    {
        int removed = remove_head(&head);
        printf("removed tail: %d\n", removed);
        display(head);
    }
}

void runQueue() {
    Queue *queue = queue_init();
    printf("New queue...\n");
    print_queue(queue);

    int total = 15;
    printf("\nEnqueuing %d items...\n", total);
    for (int i = 0; i < total; i++) {
        enqueue(queue, i + 1);
    }

    printf("\nEnqueud.\n");
    print_queue(queue);

    printf("\nDequeuing...\n");
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    printf("\nDequeued three times.\n");
    print_queue(queue);
}

void main()
{
    runLinkedList();
    printf("\n\n");
    runQueue();
}
