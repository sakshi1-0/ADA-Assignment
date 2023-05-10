9. Implement a hash table data structure using linear probing collision resolution.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define DELETED_NODE (struct node*) -1

struct node {
    int key;
    char value[100];
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
    return new_node;
}

// Insert a new key-value pair into the hash table
void insert(struct hash_table* ht, int key, char* value) {
    int index = hash(key);
    int i = index;
    do {
        if (ht->table[i] == NULL || ht->table[i] == DELETED_NODE) {
            ht->table[i] = create_node(key, value);
            return;
        }
        i = (i + 1) % TABLE_SIZE;
    } while (i != index);
}

// Search for a key in the hash table and return its value
char* search(struct hash_table* ht, int key) {
    int index = hash(key);
    int i = index;
    do {
        struct node* node = ht->table[i];
        if (node == NULL) {
            return NULL;
        }
        if (node != DELETED_NODE && node->key == key) {
            return node->value;
        }
        i = (i + 1) % TABLE_SIZE;
    } while (i != index);
    return NULL;
}

// Delete a key-value pair from the hash table
void delete(struct hash_table* ht, int key) {
    int index = hash(key);
    int i = index;
    do {
        struct node* node = ht->table[i];
        if (node == NULL) {
            return;
        }
        if (node != DELETED_NODE && node->key == key) {
            ht->table[i] = DELETED_NODE;
            return;
        }
        i = (i + 1) % TABLE_SIZE;
    } while (i != index);
}

// Print the contents of the hash table
void print_hash_table(struct hash_table* ht) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        struct node* node = ht->table[i];
        if (node == NULL) {
            printf("[%d]: NULL\n", i);
        } else if (node == DELETED_NODE) {
            printf("[%d]: DELETED\n", i);
        } else {
            printf("[%d]: (%d, %s)\n", i, node->key, node->value);
        }
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

   }