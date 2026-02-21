#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define HASH_TABLE_SIZE 100

typedef struct HashNode {
    char* key;
    char* value;
    struct HashNode* next;
} Node;

typedef struct HashTable {
    Node* slots[HASH_TABLE_SIZE];
} HashTable;

unsigned int hash(const char* key);
void init_table(HashTable* table);
void set(HashTable* table, const char* key, const char* value);

#endif
