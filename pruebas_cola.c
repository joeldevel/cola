#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "cola.h"
#include "pila.h"
#include "testing.h"

static void prueba_cola_vacia(void) {
    printf("INICIO DE PRUEBAS DE COLA VACÍA\n");

    cola_t *cola = cola_crear();
    print_test("la cola  esta vacía ", cola_esta_vacia(cola));
    print_test("ver primer es NULL ", cola_ver_primero(cola)==NULL);
    cola_destruir(cola, NULL);
}
static void prueba_cola_un_elemento_no_esta_vacia(void) {
    printf("INICIO DE PRUEBAS DE ENCOLAR, COLA QUEDA NO VACÍA\n");

    cola_t *cola = cola_crear();
    int dato = 78;
    cola_encolar(cola, &dato);
    print_test("cola con un elemento no esta vacía ", !cola_esta_vacia(cola));
    cola_destruir(cola, NULL);
}
static void prueba_cola_desencolar_elemento_queda_vacia(void) {
    printf("INICIO DE PRUEBAS DESENCOLAR EN COLA NO VACÍA, COLA QUEDA VACÍA\n");

    cola_t *cola = cola_crear();
    int dato = 458;
    cola_encolar(cola, &dato);
    cola_desencolar(cola);
    print_test("Acolar y desencolar 1 elemento, queda vacía: ", cola_esta_vacia(cola));
    cola_destruir(cola, NULL);
}
static void prueba_cola_ver_primero(void) {
    printf("INICIO DE PRUEBAS DE VER PRIMERO EN COLA NO VACÍA\n");

    cola_t *cola = cola_crear();
    int dato = 458;
    if(cola_encolar(cola, &dato)) {
        print_test("prueba cola ver primero ", 458==*(int*)cola_ver_primero(cola));
    }
    cola_destruir(cola, NULL);
}
static void prueba_cola_desencolar_y_ver_primero(void) {
    cola_t *cola = cola_crear();
    int dato = 458;
    int dato2 = 889;
    if (cola_encolar(cola, &dato)) {
        if (cola_encolar(cola, &dato2)) {
            cola_desencolar(cola);
            print_test("prueba cola desencolar y ver primero ", 889==*(int*)cola_ver_primero(cola));
        }
    }


    cola_destruir(cola, NULL);
}
static void prueba_cola_encolar_null(void) {
    printf("INICIO DE PRUEBAS DE ACOLAR NULL, LA COLA QUEDA NO VACÍA\n");

    cola_t *cola = cola_crear();
    cola_encolar(cola, NULL);
    print_test("cola con un NULL no esta vacia ", !cola_esta_vacia(cola));
    cola_destruir(cola, NULL);

}

static void prueba_cola_encolar_volumen() {
    printf("INICIO DE PRUEBAS DE VOLUMEN\n");

    cola_t *cola = cola_crear();
    size_t tam = 10000;
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
    // desencolar
    for (i = 0; i < tam; i++) {
        // Si algun elemento no se pudo guardar correctamente, ok sera false
        ok &= datos[i] == *(int*)cola_desencolar(cola);
    }
    print_test("se pudieron desencolar todos los elementos", ok);
    cola_destruir(cola, NULL);

}
void pila_destruir_wrapper(void * elem) {
    pila_destruir(elem);
}
static void prueba_cola_de_pilas() {
    printf("INICIO DE PRUEBAS COLAS DE PILAS, FUNCION DESTRUIR\n");
    cola_t *cola = cola_crear();
    // crear dos pilas y encolarlas;
    pila_t *pila1 = pila_crear();
    char elementos[] = {'A','b','c', 'F','X'};
    int tam1 = 5;
    bool ok = true;
    for(int i=0; i < tam1; i++) {
        pila_apilar(pila1, &elementos[i]);
        ok &= (elementos[i]==*(char*)pila_ver_tope(pila1));
    }
    print_test("se pudieron apilar todos los elementos pila1", ok);

    pila_t *pila2 = pila_crear();
    char elementos2[] = {'G','F','D','S','B','o'};
    int tam2 = 6;
    ok = true;
    for(int i=0; i < tam2; i++) {
        pila_apilar(pila2, &elementos2[i]);
        ok &= (elementos2[i]==*(char*)pila_ver_tope(pila2));
    }
    print_test("se pudieron apilar todos los elementos pila2", ok);

    cola_encolar(cola, pila1);
    print_test("la cola  No esta vacia ", !cola_esta_vacia(cola));
    cola_encolar(cola, pila2);

    //desencolar y contrastar los valores de la pila
    pila_t *aux = cola_desencolar(cola);
    ok = true;
    for(int i=0; i < tam1; i++) {
        ok &= (elementos[tam1-i-1]==*(char*)pila_ver_tope(aux));
        pila_desapilar(aux);
    }
    print_test("se pudieron desapilar todos los elementos pila1", ok);

    cola_destruir(cola, pila_destruir_wrapper);
    pila_destruir(aux);
}
void pruebas_cola_estudiante() {
    prueba_cola_vacia();
    prueba_cola_un_elemento_no_esta_vacia();
    prueba_cola_desencolar_elemento_queda_vacia();
    prueba_cola_ver_primero();
    prueba_cola_desencolar_y_ver_primero();
    prueba_cola_encolar_null();
    prueba_cola_encolar_volumen();
    prueba_cola_de_pilas();
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
