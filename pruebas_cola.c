#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "cola.h"
#include "testing.h"

static void prueba_cola_vacia(void) {
    cola_t *cola = cola_crear();
    print_test("la cola  esta vacia ", cola_esta_vacia(cola));
    // print_test( ... pila_esta_vacia(pila) ... );
    cola_destruir(cola, NULL);
}
static void prueba_cola_un_elemento_no_esta_vacia(void) {
    cola_t *cola = cola_crear();
    int dato = 78;
    cola_encolar(cola, &dato);
    print_test("cola con un elemento no esta vacia ", !cola_esta_vacia(cola));
    // print_test( ... pila_esta_vacia(pila) ... );
    cola_destruir(cola, NULL);
}
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
static void prueba_cola_ver_primero(void) {
    cola_t *cola = cola_crear();
    int dato = 458;
    cola_encolar(cola, &dato);
    print_test("prueba cola ver primero ", 458==*(int*)cola_ver_primero(cola));
    cola_destruir(cola, NULL);
}
static void prueba_cola_desencolar_y_ver_primero(void) {
    cola_t *cola = cola_crear();
    int dato = 458;
    int dato2 = 889;
    cola_encolar(cola, &dato);
    cola_encolar(cola, &dato2);
    int *tmp = cola_desencolar(cola);
    // cola_desencolar(cola);
    print_test("prueba cola desencolar y ver primero ", 889==*(int*)cola_ver_primero(cola));
    free(tmp);
    cola_destruir(cola, NULL);
}
static void prueba_cola_encolar_null(void) {
    cola_t *cola = cola_crear();
    cola_encolar(cola, NULL);
    print_test("cola con un NULL no esta vacia ", !cola_esta_vacia(cola));
    cola_destruir(cola, NULL);

}
void fx(void * dato) {
  printf("funcion custom!!!\n");
}
static void prueba_cola_destruir_con_funcion(void) {
    cola_t *cola = cola_crear();
    cola_encolar(cola, NULL);
    print_test("cola con funcion destruir custom ", !cola_esta_vacia(cola));
    cola_destruir(cola, fx);

}
/*
static void prueba_cola_encolar_volumen() {
    printf("INICIO DE PRUEBAS DE VOLUMEN\n");

    cola_t *cola = cola_crear();
    size_t tam = 1000;
    int datos[tam];
    for (int i = 0; i < tam; i++ ) {
        datos[i] = i;
    }
    //  Pruebo encolar
    size_t i;
    bool ok = true;
    for (i = 0; i < tam; i++) {
        // Si algun elemento no se pudo guardar correctamente, ok sera false
        ok &= cola_encolar(cola, &datos[i]);
    }
    print_test("se pudieron encolar todos los elementos", ok);
    // print_test("no se puede encolar un elemento en vec_vol[tam]", !vector_guardar(vec_vol, tam, 10));

    cola_destruir(cola, NULL);

}
*/
/*
static void prueba_cola_desencolar_volumen() {
    printf("INICIO DE PRUEBAS DESENCOLAR VOLUMEN\n");

    cola_t *cola = cola_crear();
    size_t tam = 100;
    int datos[tam];
    for (int i = 0; i < tam; i++ ) {
        datos[i] = i;
    }
    //  Pruebo encolar
    size_t i;
    bool ok = true;
    for (i = 0; i < tam; i++) {
        // Si algun elemento no se pudo guardar correctamente, ok sera false
        ok &= cola_encolar(cola, &datos[i]);
    }
    print_test("se pudieron encolar todos los elementos", ok);
    // pruebo desencolar
    // int *tmp = NULL;
    // for (i =  tam-1; i <-1; i--) {
    //     printf("i=%lu,\n",i);
        // Si algun elemento no se pudo guardar correctamente, ok sera false
        // tmp = cola_desencolar(cola);
        // printf("%lu==%d?\n", i,tmp);
        // ok &= datos[i] == *(int*)tmp;
        // free(tmp);
    // }
    // print_test("se pudieron desencolar todos los elementos", ok);

    // print_test("no se puede encolar un elemento en vec_vol[tam]", !vector_guardar(vec_vol, tam, 10));

    cola_destruir(cola, NULL);

}
*/
void pruebas_cola_estudiante() {
    prueba_cola_vacia();
    prueba_cola_un_elemento_no_esta_vacia();
    prueba_cola_desencolar_elemento_queda_vacia();
    prueba_cola_ver_primero();
    prueba_cola_desencolar_y_ver_primero();
    prueba_cola_encolar_null();
    prueba_cola_destruir_con_funcion();
    // prueba_cola_encolar_volumen();
    // prueba_cola_desencolar_volumen();
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
