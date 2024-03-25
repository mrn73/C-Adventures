#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main() {
    ListNode* head = init_with_value(1);
    insert_tail(head, 2);
    insert_tail(head, 3);
    insert_tail(head, 4);
    insert_head(&head, 5);
    display(head);

    for (int i = 0; i < 6; i++) {
        int removed = remove_head(&head);
        printf("removed tail: %d\n", removed);
        display(head);
    }

}