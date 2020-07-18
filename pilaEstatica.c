#include "pilaEstatica.h"
//FUNCIONES PRIMITIVAS DE PILA

void crearPila(tPila *pila){
    pila->tope = 0;
}

int pilaLlena(const tPila *pila, unsigned cantBytes){
    return (pila->tope + sizeof(unsigned) + cantBytes > TAM_PILA)? VERDADERO : FALSO;
}

int ponerEnPila(tPila *pila, const void *d, unsigned cantBytes){
    if(pila->tope + cantBytes + sizeof(unsigned) > TAM_PILA){
        return FALSO;
    }

    memcpy(pila->vPila + pila->tope, d, cantBytes);
    pila->tope += cantBytes;

    *(unsigned*)(pila->vPila + pila->tope) = cantBytes; // memcpy(pila->vPila + pila->tope, &cantBytes, sizeof(unsigned));
    pila->tope += sizeof(unsigned);

    return VERDADERO;
}

int verTope(const tPila *pila, void *d, unsigned cantBytes){
    if(pila->tope == 0){
        return FALSO;
    }

    int topeTemporal = pila->tope;
    topeTemporal -= sizeof(unsigned);   //posiciona el tope en la linea -> dato | tipo de dato
    int tamElemReal = *(unsigned*)(pila->vPila + pila->tope);

    topeTemporal -= tamElemReal;
    memcpy(d, pila->vPila + topeTemporal, minimo(cantBytes, tamElemReal));

    return VERDADERO;
}

int sacarDePila(tPila *pila, void *d, unsigned cantBytes){
    if(pila->tope == 0){
        return FALSO;
    }

    pila->tope -= sizeof(unsigned);

    int tamElemReal = *(unsigned*)(pila->vPila + pila->tope);

    pila->tope -= tamElemReal;

    memcpy(d, pila->vPila + pila->tope, minimo(cantBytes, tamElemReal));

    return VERDADERO;
}

int pilaVacia(const tPila *pila){
    return (pila->tope == 0) ? VERDADERO : FALSO;
}

void vaciarPila(tPila *pila){
    pila->tope = 0;
}




