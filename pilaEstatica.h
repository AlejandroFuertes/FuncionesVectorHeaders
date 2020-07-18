#ifndef PILAESTATICA_H_INCLUDED
#define PILAESTATICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define TAM_PILA 6
#define VERDADERO 1
#define FALSO 0
#define minimo(x, y) ((x) < (y)? (x) : (y))

typedef struct sNodo{
    char vPila[TAM_PILA];
    unsigned tope;
} tPila;

//PRIMITIVAS
void crearPila(tPila *pila);
int pilaLlena(const tPila *pila, unsigned cantBytes);
int ponerEnPila(tPila *pila, const void *d, unsigned cantBytes); //APILAR
int verTope(const tPila *pila, void *d, unsigned cantBytes);
int pilaVacia(const tPila *pila);
int sacarDePila(tPila *pila, void *d, unsigned cantBytes); //SACAR


#endif // PILAESTATICA_H_INCLUDED
