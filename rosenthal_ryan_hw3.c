#include <stdio.h>
#include <stdlib.h>

unsigned int count_nodes(struct node *head) {
    unsigned int count = 0;

    while (head != NULL) {
        count++;
        head = head->next;
    }

    return count;
}

struct Node** split_list(struct Node* head, unsigned int num) {
    if (head == NULL || num <= 0) {
        return NULL;
    }

    struct Node** split_heads = (struct Node**)malloc(num * sizeof(struct Node*));
    if (split_heads == NULL) {
        return NULL;
    }

    struct Node* current = head;
    struct Node* previous = NULL;

    for (int i = 0; i < num; i++) {
        split_heads[i] = current;
        struct Node* tail = NULL;

        int count = 0;
        while (current != NULL) {
            if (count % num == i) {
                if (previous != NULL) {
                    previous->next = current->next;
                } else {
                    head = current->next;
                }

                if (tail != NULL) {
                    tail->next = current;
                }
                tail = current;
                tail->next = NULL;
                current = previous;
            }

            previous = current;
            current = current->next;
            count++;
        }
    }

    return split_heads;
}

struct Node* insert_end(struct Node* list, struct Node* node) {
    if (list == NULL) {
        return node;
    }

    struct Node* current = list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
    return list;
}

struct node { 
int val; struct
node *next;
};


struct Node* interleave_list(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }

    struct Node* result = NULL;
    struct Node* current1 = head1;
    struct Node* current2 = head2;

    while (current1 != NULL || current2 != NULL) {
        if (current1 != NULL) {
            result = insert_end(result, current1);
            current1 = current1->next;
        }
        if (current2 != NULL) {
            result = insert_end(result, current2);
            current2 = current2->next;
        }
    }

    return result;
}

int get_float_exponent(float f) {
    int exponent = 0;
    unsigned char* ptr = (unsigned char*)&f;

    int new_exponent = (ptr[3] & 0x7F) << 1 | (ptr[2] >> 7 & 0x01);
    
    exponent = new_exponent - 127;

    return exponent;
}