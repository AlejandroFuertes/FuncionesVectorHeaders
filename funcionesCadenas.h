#ifndef FUNCIONESCADENAS_H_INCLUDED
#define FUNCIONESCADENAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

void cargarCadena(char *cadena, int tamanio){
    printf("\n  Ingrese el texto o cadena:  ");
    fgets(cadena,tamanio, stdin);
    fflush(stdin);
}

void mostrarCadena(char *cadena){
    printf("%s",cadena);
}

#endif // FUNCIONESCADENAS_H_INCLUDED
