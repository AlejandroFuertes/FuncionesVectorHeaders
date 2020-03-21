#ifndef FUNCIONESVECTOR_H_INCLUDED
#define FUNCIONESVECTOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

void cargaVector(int tamanio, int *pVector){

    printf("\n  Ingrese los valores en la posicion: \n");
    for(int i = 0; i < tamanio; i++){
        printf("[%d] : ", i + 1);
        scanf("%d",(pVector + i));
    }
}

void muestraVector(int tamanio,int *pVector){

    printf("\n\n  Los valores del vector son: \n\n");
    for(int i = 0; i < tamanio; i++){
        printf("  %d \t", *(pVector + i));
    }
}

void ordenarVectorAsc(int tamanio, int *pVector){

    for(int i = 0; i < tamanio; i++){
        for(int j = 0; j < tamanio - 1; j++){

            if(*(pVector + j) > *(pVector + (j + 1))){
                intercambiar(pVector + j, pVector + (j + 1));
            }
        }
    }
}

void intercambiar(int *elemento1, int *elemento2){

    int temporal;

    temporal = *elemento1;
    *elemento1 = *elemento2;
    *elemento2 = temporal;
}
#endif // FUNCIONESVECTOR_H_INCLUDED
