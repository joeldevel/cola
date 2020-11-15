#include<stdlib.h>
#include "cola.h"

typedef struct nodo {
    void *dato;
    struct nodo * siguiente_nodo;
} nodo_t;

typedef struct cola {
    nodo_t* primero;
    nodo_t* ultimo;
} cola_t;

nodo_t* nodo_crear(void * valor) {
    nodo_t *nodo = malloc(sizeof(nodo_t));
    if (!nodo) return NULL;
    nodo->dato = valor;
    nodo->siguiente_nodo = NULL;
    return nodo;
}

cola_t* cola_crear(void) {
    cola_t *cola = malloc(sizeof(cola_t));
    if (!cola) return NULL;
    cola->primero = NULL;
    cola->ultimo = NULL;
    return cola;
}

bool cola_esta_vacia(const cola_t *cola) {
    return cola->ultimo == NULL;
}

bool cola_encolar(cola_t *cola, void *valor) {
    nodo_t *nodo = nodo_crear(valor);
    if (!nodo) return false;
    if (cola_esta_vacia(cola)) {
        cola->primero = nodo;
    } else {
        cola->ultimo->siguiente_nodo = nodo;
    }
    cola->ultimo = nodo;
    return true;
}

void *cola_ver_primero(const cola_t *cola) {
    return (cola_esta_vacia(cola))? NULL: cola->primero->dato;
}

void *cola_desencolar(cola_t *cola) {
    if (cola_esta_vacia(cola)) return NULL;
    nodo_t *tmp = cola->primero;
    void *p = tmp->dato;
    if (cola->primero == cola->ultimo) {
        cola->ultimo = NULL;
    }
    else {
        cola->primero = cola->primero->siguiente_nodo;
    }
    free(tmp);
    return p;
}

void cola_destruir(cola_t *cola, void (*destruir_dato)(void *)) {
    while (!cola_esta_vacia(cola)) {
        if (!(destruir_dato == NULL)) {
            destruir_dato(cola->primero->dato);
        }
        cola_desencolar(cola);
    }
    free(cola);
}
