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
    nodo_t* primero_en_entrar;
    nodo_t* ultimo_en_entrar;
} cola_t;
// primitivas para practicar
cola_t* cola_crear(void) {
    cola_t *cola = malloc(sizeof(cola_t));
    if (!cola) return NULL;
    cola->primero_en_entrar = NULL;
    cola->ultimo_en_entrar = NULL;
    return cola;
}
bool cola_esta_vacia(const cola_t *cola) {
    return cola->ultimo_en_entrar == NULL && cola->primero_en_entrar == NULL;
}

// void cola_esta_vacia(cola_t *cola) {
//     if (vacia(cola)) printf("esta vacia\n");
//     else printf("No esta vacia\n");
// }

bool cola_encolar(cola_t *cola, void *valor) {
    nodo_t *nodo = malloc(sizeof(nodo_t));
    if (!nodo) return false;
    nodo->dato = valor;
    nodo->siguiente_nodo = NULL;
    // cola vacia
    if (cola->ultimo_en_entrar == NULL && cola->primero_en_entrar == NULL) {
        cola->ultimo_en_entrar = nodo;
        cola->primero_en_entrar = nodo;
        return true;
    }
    cola->ultimo_en_entrar->siguiente_nodo = nodo;
    cola->ultimo_en_entrar = cola->ultimo_en_entrar->siguiente_nodo;
    return true;
}

void *cola_ver_primero(const cola_t *cola) {
    return cola->primero_en_entrar->dato;
}

void *cola_desencolar(cola_t *cola) {
    // printf("(Entrando a cola_desencolar)\n" );

    if (cola_esta_vacia(cola)) return NULL;

    nodo_t * tmp = cola->primero_en_entrar;
    // 1 solo elemento
    if (cola->primero_en_entrar == cola->ultimo_en_entrar) {
        cola->ultimo_en_entrar = NULL;
        cola->primero_en_entrar = NULL;
        return &tmp->dato;
    }
    cola->primero_en_entrar = cola->primero_en_entrar->siguiente_nodo;
    // free(tmp);
    // printf("(cola_desencolar) despues del free\n" );
    // if (cola->primero_en_entrar == NULL) {
    //     printf("cola->primero_en_entrar=NULL\n");
    //     return NULL;
    // }
    return &tmp->dato;
}
void cola_destruir(cola_t *cola, void (*destruir_dato)(void *)) {
    // printf("(1 Entrando a cola_destruir)\n" );
    if (destruir_dato == NULL) {
        while (cola->primero_en_entrar) {
            void *tmp = cola_desencolar(cola);
            free(tmp);
            // cola_desencolar(cola);
            // printf("(dentro del while)\n" );
        }
    }
    else {
        while (cola->primero_en_entrar) {
            // printf("2 destruyendo: %d\n",*(int*)cola_ver_primero(cola) );
            destruir_dato(cola->primero_en_entrar->dato);
            // printf("( 3 dentro del while del else)\n" );
            // cola_desencolar(cola);
            void *tmp = cola_desencolar(cola);
            free(tmp);
        }
    }
    // free(cola->primero_en_entrar);
    // free(cola->ultimo_en_entrar);
    // printf("antes de free(cola)\n");
    // printf("cola_ver_primero: %d\n",*(int*)cola_ver_primero(cola) );

    free(cola);

}
/*
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
    //printf("Al principio: %d\n", cola->ultimo_en_entrar->dato);
    //printf("Al ultimo: %d\n", cola->primero_en_entrar->dato);
    // printf("desencolando :%d\n", desencolar(cola));
    // printf("desencolando :%d\n", desencolar(cola));
    // printf("desencolando :%d\n", desencolar(cola));

    // destruir(cola);
    cola_destruir(cola, free);
    free(datito);
    return 0;
}
*/


/*
void encolar(cola_t* cola, int dato) {
    nodo_t *nodo = malloc(sizeof(nodo_t));
    nodo->dato = dato;
    nodo->siguiente = NULL;
    if (cola->ultimo_en_entrar == NULL && cola->primero_en_entrar == NULL) {
    cola->ultimo_en_entrar = nodo;
    cola->primero_en_entrar = nodo;
    return;
    }
    cola->ultimo_en_entrar->siguiente = nodo;
    cola->ultimo_en_entrar = cola->ultimo_en_entrar->siguiente;
}
int desencolar(cola_t * cola) {
    nodo_t * tmp = cola->primero_en_entrar;
    int dato = tmp->dato;
    cola->primero_en_entrar = cola->primero_en_entrar->siguiente;
    free(tmp);
    return dato;
}
void destruir(cola_t* cola) {
    while (cola->primero_en_entrar) {
      desencolar(cola);
    }
    free(cola);
}
bool vacia(cola_t *cola) {
  return cola->ultimo_en_entrar == NULL && cola->primero_en_entrar == NULL;
}
void esta_vacia(cola_t *cola) {
    if (vacia(cola)) printf("esta vacia\n");
    else printf("No esta vacia\n");
}
void ver_primero(const cola_t * cola) {
    printf("el primero es: %d\n", cola->primero_en_entrar->dato);
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
