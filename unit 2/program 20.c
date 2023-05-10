20. Implement a divide-and-conquer algorithm for sorting a linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* merge(node* left, node* right) {
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }
    node* head;
    if (left->data < right->data) {
        head = left;
        head->next = merge(left->next, right);
    } else {
        head = right;
        head->next = merge(left, right->next);
    }
    return head;
}

void split(node* head, node** left, node** right) {
    if (head == NULL || head->next == NULL) {
        *left = head;
        *right = NULL;
        return;
    }
    node* slow = head;
    node* fast = head->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

void merge_sort(node** head_ref) {
    node* head = *head_ref;
    if (head == NULL || head->next == NULL) {
        return;
    }
    node* left;
    node* right;
    split(head, &left, &right);
    merge_sort(&left);
    merge_sort(&right);
    *head_ref = merge(left, right);
}

void push(node** head_ref, int data) {
    node* new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void print_list(node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;
    push(&head, 4);
    push(&head, 2);
    push(&head, 3);
    push(&head, 1);
    printf("Original list: ");
    print_list(head);
    merge_sort(&head);
    printf("Sorted list: ");
    print_list(head);
    return 0;
}