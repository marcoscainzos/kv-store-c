#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

unsigned int hash(const char* key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key;
        key++;
    }
    return hash % HASH_TABLE_SIZE;
}

void init_table(HashTable* table) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        table->slots[i] = NULL;
    }
}

void set(HashTable* table, const char* key, const char* value) {
    unsigned int index = hash(key);
    Node* head = table->slots[index];

    // Revisar si la clave ya existe → actualizar
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            free(current->value);           // liberar valor viejo
            current->value = strdup(value); // asignar nuevo valor
            return;
        }
        current = current->next;
    }

    // Clave nueva → crear nodo
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Error malloc\n");
        exit(1);
    }

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = head;

    table->slots[index] = new_node; // insertar al inicio de la lista
}