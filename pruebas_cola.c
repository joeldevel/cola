#include<stddef.h>
#include<stdlib.h>
#include "cola.h"
#include "testing.h"

static void prueba_cola_vacia(void) {
    cola_t *cola = cola_crear();
    print_test("la cola  esta vacia ", cola_esta_vacia(cola));
    // print_test( ... pila_esta_vacia(pila) ... );
    cola_destruir(cola, NULL);
}
// static void prueba_cola_un_elemento_no_esta_vacia(void) {
//     cola_t *cola = cola_crear();
//     int dato = 78;
//     cola_encolar(cola, &dato);
//     print_test("cola con un elemento no esta vacia ", !cola_esta_vacia(cola));
//     // print_test( ... pila_esta_vacia(pila) ... );
//     cola_destruir(cola, NULL);
// }
static void prueba_cola_desencolar_elemento_queda_vacia(void) {
    cola_t *cola = cola_crear();
    int dato = 458;
    cola_encolar(cola, &dato);
    int *tmp = cola_desencolar(cola);
    // cola_desencolar(cola);
    print_test("Acolar y desencolar 1 elemento, queda vacia: ", cola_esta_vacia(cola));
    // print_test( ... pila_esta_vacia(pila) ... );
    cola_destruir(cola, NULL);
    // free(cola);
    free(tmp);
}

void pruebas_cola_estudiante() {
    prueba_cola_vacia();
    // prueba_cola_un_elemento_no_esta_vacia();
    prueba_cola_desencolar_elemento_queda_vacia();
    // ...
}


/*
 * Función main() que llama a la función de pruebas.
 */

#ifndef CORRECTOR  // Para que no dé conflicto con el main() del corrector.

int main(void) {
    pruebas_cola_estudiante();
    return failure_count() > 0;  // Indica si falló alguna prueba.
}

#endif
