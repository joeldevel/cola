#include "pila.h"
#include <stdlib.h>

#define MIN_PILA 4 // el minimo que la pila al ser creada
#define FACTOR_INC_PILA 2 // duplicar la pila cuando llena
#define FACTOR_DEC_PILA 2 // dividir la pila cuando pocos elementos

/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void **datos;
    size_t cantidad;   // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
};
// función auxiliar
void * pila_redimensionar(pila_t *pila, bool hacia_arriba) {
  if (hacia_arriba)
      return realloc(pila->datos, pila->capacidad *FACTOR_INC_PILA * sizeof(void*));
  return realloc(pila->datos, (pila->capacidad / FACTOR_DEC_PILA) * sizeof(void*));
}
/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

// ..
pila_t *pila_crear(void) {
    pila_t *pila = malloc( sizeof(pila_t) );
    if (!pila) return NULL;
    void *datos = malloc( sizeof(void*) * MIN_PILA);
    if( !datos) {
      return NULL;
    }
    pila->datos = datos;
    pila->cantidad = 0;
    pila->capacidad = MIN_PILA;

    return pila;
}

void pila_destruir(pila_t *pila) {
    free(pila->datos);
    free(pila);
}

bool pila_esta_vacia(const pila_t *pila) {
    return pila->cantidad == 0;
}

bool pila_apilar(pila_t *pila, void *valor) {
    if (pila->cantidad == pila->capacidad-1) {
        void *datos_nuevo = pila_redimensionar(pila, true);
        if ( datos_nuevo == NULL) {
            return false;
        }
        pila->datos = datos_nuevo;
        pila->capacidad = pila->capacidad * FACTOR_INC_PILA;
    }
    pila->datos[pila->cantidad] = valor;
    pila->cantidad++;

    return true;
}

void *pila_ver_tope(const pila_t *pila) {
    if (pila_esta_vacia(pila)) return NULL;
    if (pila->datos[pila->cantidad-1] == NULL) return NULL;

    return pila->datos[pila->cantidad-1];
}

void *pila_desapilar(pila_t *pila) {
    if (pila->cantidad == 0) return NULL;
    if ((pila->capacidad > MIN_PILA*4) && (pila->cantidad <= pila->capacidad/4)) {
        void *datos_nuevo = pila_redimensionar(pila, false);
        pila->datos = datos_nuevo;
        pila->capacidad = pila->capacidad/FACTOR_DEC_PILA;
    }
    return pila->datos[--(pila->cantidad)];
}
