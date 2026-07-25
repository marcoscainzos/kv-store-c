#include <stdio.h>
#include "hash_table.h"

int main(void) {
    HashTable table;
    init_table(&table);

    // Guardamos varios datos
    set(&table, "persona1", "Juan");
    set(&table, "persona2", "Marcos");
    set(&table, "persona3", "Lucía");

    // Buscamos una clave
    const char* persona = get(&table, "persona2");

    if (persona != NULL) {
        printf("Valor encontrado: %s\n", persona);
    } else {
        printf("La clave no existe\n");
    }

    // Probamos una clave inexistente
    const char* desconocido = get(&table, "persona99");

    if (desconocido != NULL) {
        printf("Valor encontrado: %s\n", desconocido);
    } else {
        printf("La clave persona99 no existe\n");
    }

    if (delete_key(&table, "persona2")) {
        printf("persona2 eliminada\n");
    } else {
        printf("persona2 no existe\n");
    }

    const char* resultado = get(&table, "persona2");

    if (resultado == NULL) {
        printf("Comprobado: persona2 ya no existe\n");
    }

    return 0;
}
