#include <stdio.h>
#include "hash_table.h"

int main() {
    HashTable table;
    init_table(&table);

    set(&table, "nombre", "Juan");
    set(&table, "edad", "21");

    printf("Datos insertados correctamente.\n");

    return 0;
}
