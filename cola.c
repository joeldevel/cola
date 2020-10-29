#include<stdio.h>
#include<stdlib.h>
#include "cola.h"
// el nodo ?
typedef struct nodo {
    void *dato;
    struct nodo * siguiente_nodo;
} nodo_t;
// el struct
typedef struct cola {
    nodo_t* primer_elemento;
    nodo_t* ultimo_elemento;
} cola_t;
// primitivas para practicar
cola_t* crear_cola() {
    cola_t *cola = malloc(sizeof(cola_t));
    if (!cola) return NULL;
    cola->primer_elemento = NULL;
    cola->ultimo_elemento = NULL;
    return cola;
}
bool vacia(cola_t *cola) {
    return cola->primer_elemento == NULL && cola->ultimo_elemento == NULL;
}

void esta_vacia(cola_t *cola) {
    if (vacia(cola)) printf("esta vacia\n");
    else printf("No esta vacia\n");
}

bool cola_encolar(cola_t *cola, void *valor) {
    nodo_t *nodo = malloc(sizeof(nodo_t));
    if (!nodo) return false;
    nodo->dato = valor;
    nodo->siguiente_nodo = NULL;
    if (cola->primer_elemento == NULL && cola->ultimo_elemento == NULL) {
        cola->primer_elemento = nodo;
        cola->ultimo_elemento = nodo;
        return true;
    }
    cola->primer_elemento->siguiente_nodo = nodo;
    cola->primer_elemento = cola->primer_elemento->siguiente_nodo;
    return true;
}

void *cola_ver_primero(const cola_t *cola) {
    return cola->ultimo_elemento->dato;
}

void *cola_desencolar(cola_t *cola) {
    printf("(Entrando a cola_desencolar)\n" );

    if (vacia(cola)) return NULL;

    nodo_t * tmp = cola->ultimo_elemento;
    cola->ultimo_elemento = cola->ultimo_elemento->siguiente_nodo;
    free(tmp);
    printf("(cola_desencolar) despues del free\n" );
    if (cola->ultimo_elemento == NULL) {
        printf("cola->ultimo_elemento=NULL\n");
        return NULL;
    }
    return cola->ultimo_elemento->dato;
}
void cola_destruir(cola_t *cola, void (*destruir_dato)(void *)) {
    printf("(1 Entrando a cola_destruir)\n" );
    if (destruir_dato == NULL) {
        while (cola->ultimo_elemento) {
            cola_desencolar(cola);
            printf("(dentro del while)\n" );
        }
    }
    else {
        while (cola->ultimo_elemento) {
            printf("2 destruyendo: %d\n",*(int*)cola_ver_primero(cola) );
            destruir_dato(cola->ultimo_elemento->dato);
            printf("( 3 dentro del while del else)\n" );
            cola_desencolar(cola);
        }
    }
    // free(cola->ultimo_elemento);
    // free(cola->primer_elemento);
    printf("antes de free(cola)\n");
    // printf("cola_ver_primero: %d\n",*(int*)cola_ver_primero(cola) );

    free(cola);

}

int main(int argc, char *argv[]) {
    cola_t *cola = crear_cola();
    // esta_vacia(cola);
    // encolar( cola, 87);
    esta_vacia(cola);
    // int datito = 34;
    // int datito2 = 495;
    // cola_encolar( cola, &datito);
    // cola_encolar( cola, &datito2);
    // test con datos en memoria dinamica
    int *datito = malloc(sizeof(int));
    int *datito2 = malloc(sizeof(int));
    int *datito3 = malloc(sizeof(int));
    *datito = 34;
    *datito2 = 495;
    *datito3 = 121;
    cola_encolar( cola, datito);
    cola_encolar( cola, datito2);
    cola_encolar( cola, datito3);
    printf("ver_primero: %d\n",*(int*)cola_ver_primero(cola) );
    printf("desencolar: %d\n",*(int*)cola_desencolar(cola) );
    // printf("ver_primero despues de desencolar: %d\n",*(int*)cola_ver_primero(cola) );

    // encolar( cola, 45);
    // ver_primero(cola);
    //printf("Al principio: %d\n", cola->primer_elemento->dato);
    //printf("Al ultimo: %d\n", cola->ultimo_elemento->dato);
    // printf("desencolando :%d\n", desencolar(cola));
    // printf("desencolando :%d\n", desencolar(cola));
    // printf("desencolando :%d\n", desencolar(cola));

    // destruir(cola);
    cola_destruir(cola, free);
    free(datito);
    return 0;
}



/*
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
*/
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
