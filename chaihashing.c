#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the hash table
struct HashTable {
    int size;
    struct Node** table; // Array of pointers to linked lists
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to create a hash table
struct HashTable* createHashTable(int size) {
    struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    if (hashTable != NULL) {
        hashTable->size = size;
        hashTable->table = (struct Node**)malloc(size * sizeof(struct Node*));

        // Initialize each slot with NULL (empty linked list)
        for (int i = 0; i < size; i++) {
            hashTable->table[i] = NULL;
        }
    }
    return hashTable;
}

// Function to insert a key into the hash table
void insert(struct HashTable* hashTable, int key) {
    // Calculate the hash value
    int index = key % hashTable->size;

    // Create a new node with the key
    struct Node* newNode = createNode(key);

    // Insert the new node at the beginning of the linked list
    newNode->next = hashTable->table[index];
    hashTable->table[index] = newNode;
}

// Function to search for a key in the hash table
void search(struct HashTable* hashTable, int key) {
    // Calculate the hash value
    int index = key % hashTable->size;

    // Traverse the linked list at the calculated index
    struct Node* current = hashTable->table[index];
    while (current != NULL) {
        if (current->data == key) {
            printf("Key %d found in the hash table.\n", key);
            return;
        }
        current = current->next;
    }

    printf("Key %d not found in the hash table.\n", key);
}

// Function to display the contents of the hash table
void display(struct HashTable* hashTable) {
    printf("Hash Table Contents:\n");
    for (int i = 0; i < hashTable->size; i++) {
        printf("Slot %d:", i);

        // Traverse the linked list at the current slot
        struct Node* current = hashTable->table[i];
        while (current != NULL) {
            printf(" %d", current->data);
            current = current->next;
        }

        printf("\n");
    }
}

// Function to free the memory used by the hash table
void freeHashTable(struct HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        struct Node* current = hashTable->table[i];
        while (current != NULL) {
            struct Node* next = current->next;
            free(current);
            current = next;
        }
    }

    free(hashTable->table);
    free(hashTable);
}

int main() {
    // Choose the size of the hash table
    int size = 10;

    // Create a hash table
    struct HashTable* hashTable = createHashTable(size);

    // Insert keys into the hash table
    insert(hashTable, 5);
    insert(hashTable, 15);
    insert(hashTable, 25);
    insert(hashTable, 35);
    insert(hashTable, 6);

    // Display the contents of the hash table
    display(hashTable);

    // Search for a key in the hash table
    search(hashTable, 25);
    search(hashTable, 10);

    // Free the memory used by the hash table
    freeHashTable(hashTable);

    return 0;
}
