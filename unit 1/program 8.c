8. Implement a hash table data structure using separate chaining collision resolution.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

struct node {
    int key;
    char value[100];
    struct node* next;
};

struct hash_table {
    struct node* table[TABLE_SIZE];
};

// Hash function to compute hash value for a key
int hash(int key) {
    return key % TABLE_SIZE;
}

// Create a new node with given key and value
struct node* create_node(int key, char* value) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->key = key;
    strcpy(new_node->value, value);
    new_node->next = NULL;
    return new_node;
}

// Insert a new key-value pair into the hash table
void insert(struct hash_table* ht, int key, char* value) {
    int index = hash(key);
    struct node* new_node = create_node(key, value);
    if (ht->table[index] == NULL) {
        ht->table[index] = new_node;
    } else {
        struct node* temp = ht->table[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Search for a key in the hash table and return its value
char* search(struct hash_table* ht, int key) {
    int index = hash(key);
    struct node* temp = ht->table[index];
    while (temp != NULL) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return NULL;
}

// Print the contents of the hash table
void print_hash_table(struct hash_table* ht) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        struct node* temp = ht->table[i];
        printf("[%d]: ", i);
        while (temp != NULL) {
            printf("(%d, %s) ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    // Create a hash table
    struct hash_table ht;
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        ht.table[i] = NULL;
    }

    // Insert some key-value pairs into the hash table
    insert(&ht, 10, "apple");
    insert(&ht, 25, "banana");
    insert(&ht, 7, "orange");
    insert(&ht, 31, "grape");
    insert(&ht, 15, "pear");

    // Print the contents of the hash table
    print_hash_table(&ht);

    // Search for a key in the hash table
    int key = 7;
    char* value = search(&ht, key);
    if (value == NULL) {
        printf("Key %d not found.\n", key);
    } else {
        printf("Value for key %d is %s.\n", key, value);
    }

    return 0;
}