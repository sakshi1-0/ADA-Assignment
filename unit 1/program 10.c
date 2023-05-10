10. Implement a heap data structure and use it to sort an array of integers.

#include <stdio.h>
#include <stdlib.h>

struct heap {
    int* data;
    int size;
    int capacity;
};

// Initialize a new heap with given capacity
struct heap* create_heap(int capacity) {
    struct heap* new_heap = (struct heap*) malloc(sizeof(struct heap));
    new_heap->data = (int*) malloc(sizeof(int) * capacity);
    new_heap->size = 0;
    new_heap->capacity = capacity;
    return new_heap;
}

// Return the index of the parent of a given node in the heap
int parent(int i) {
    return (i - 1) / 2;
}

// Return the index of the left child of a given node in the heap
int left_child(int i) {
    return 2 * i + 1;
}

// Return the index of the right child of a given node in the heap
int right_child(int i) {
    return 2 * i + 2;
}

// Swap the values at the given indices in the heap
void swap(struct heap* h, int i, int j) {
    int temp = h->data[i];
    h->data[i] = h->data[j];
    h->data[j] = temp;
}

// Add a new value to the heap
void insert(struct heap* h, int value) {
    if (h->size == h->capacity) {
        printf("Heap is full!\n");
        return;
    }

    int i = h->size;
    h->data[i] = value;
    h->size++;

    while (i > 0 && h->data[i] > h->data[parent(i)]) {
        swap(h, i, parent(i));
        i = parent(i);
    }
}

// Return the maximum value in the heap
int extract_max(struct heap* h) {
    if (h->size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }

    int max_value = h->data[0];
    h->size--;
    h->data[0] = h->data[h->size];

    int i = 0;
    while (left_child(i) < h->size) {
        int j = left_child(i);
        if (right_child(i) < h->size && h->data[right_child(i)] > h->data[j]) {
            j = right_child(i);
        }
        if (h->data[i] >= h->data[j]) {
            break;
        }
        swap(h, i, j);
        i = j;
    }

    return max_value;
}

// Heap sort an array of integers in place
void heap_sort(int* arr, int n) {
    struct heap* h = create_heap(n);

    int i;
    for (i = 0; i < n; i++) {
        insert(h, arr[i]);
    }

    for (i = n - 1; i >= 0; i--) {
        arr[i] = extract_max(h);
    }
}

int main() {
    int arr[] = {4, 2, 7, 1, 9, 3, 6, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    heap_sort(arr, n);

    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}