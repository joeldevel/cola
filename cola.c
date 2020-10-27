#include<stdio.h>
#include<stdlib.h>
#include "cola.h"
// el nodo ?
typedef struct nodo {
    int dato;
    struct nodo * siguiente;
} nodo_t;
// el struct
typedef struct cola {
    nodo_t* primer_elemento;
    nodo_t* ultimo_elemento;
} cola_t;
// primitivas para practicar
cola_t* crear_cola() {
    cola_t *cola = malloc(sizeof(cola_t));
    cola->primer_elemento = NULL;
    cola->ultimo_elemento = NULL;
    return cola;
}
void encolar(cola_t* cola, int dato) {
    nodo_t *nodo = malloc(sizeof(nodo_t));
    nodo->dato = dato;
    nodo->siguiente = NULL;
    if (cola->primer_elemento == NULL && cola->ultimo_elemento == NULL) {
    cola->primer_elemento = nodo;
    cola->ultimo_elemento = nodo;
    return;
    }
    cola->primer_elemento->siguiente = nodo;
    cola->primer_elemento = cola->primer_elemento->siguiente;
}
int desencolar(cola_t * cola) {
    nodo_t * tmp = cola->ultimo_elemento;
    int dato = tmp->dato;
    cola->ultimo_elemento = cola->ultimo_elemento->siguiente;
    free(tmp);
    return dato;
}
void destruir(cola_t* cola) {
    while (cola->ultimo_elemento) {
      desencolar(cola);
    }
    free(cola);
}
bool vacia(cola_t *cola) {
  return cola->primer_elemento == NULL && cola->ultimo_elemento == NULL;
}
void esta_vacia(cola_t *cola) {
    if (vacia(cola)) printf("esta vacia\n");
    else printf("No esta vacia\n");
}
void ver_primero(const cola_t * cola) {
    printf("el primero es: %d\n", cola->ultimo_elemento->dato);
}
// las primitivas para el tp
/*
cola_t *cola_crear(void) {
}
void cola_destruir(cola_t *cola, void (*destruir_dato)(void *)) {
}
bool cola_esta_vacia(const cola_t *cola) {
}
bool cola_encolar(cola_t *cola, void *valor) {
}
void *cola_ver_primero(const cola_t *cola) {
}
void *cola_desencolar(cola_t *cola) {
}
*/
int main(int argc, char *argv[]) {
    //nodo_t nodo; nodo.dato = 5;
    //nodo_t nodo2; nodo2.dato = 87;
    //nodo.siguiente = &nodo2;
    // printf("el dato es %d\n", nodo.dato);
    // printf("el dato del siguiente es %d\n", nodo.siguiente->dato);
    // La cola
    cola_t *cola = crear_cola();
    esta_vacia(cola);
    encolar( cola, 87);
    esta_vacia(cola);
    encolar( cola, 21);
    encolar( cola, 45);
    ver_primero(cola);
    //printf("Al principio: %d\n", cola->primer_elemento->dato);
    //printf("Al ultimo: %d\n", cola->ultimo_elemento->dato);
    printf("desencolando :%d\n", desencolar(cola));
   // printf("desencolando :%d\n", desencolar(cola));
   // printf("desencolando :%d\n", desencolar(cola));
    
    destruir(cola);
    return 0;
}
