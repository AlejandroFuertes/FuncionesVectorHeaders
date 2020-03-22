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

    printf("\n\n  Los valores del vector actualmente son: \n\n");
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

/*
    FUNCION PARA BUSCAR LOS DATOS EN EL VECTOR, DEVUELVE
    LA CANTIDAD TOTAL DE DATOS QUE FUERON ENCONTRADOS.

    EJEMPLO: SI MI VECTOR ES : 1 1 5 1
    Y DESEO ELIMINAR LOS DATOS = 1

    LA FUNCION DEVUELVE 3
*/
int devuelveCantTotalEncontrados(int tamanio,int pKey, int *pVector){

    int keyEncontrados = 0;
    int i = 0;
    int aux = 0;

    while(aux < tamanio){

        if(pKey == *(pVector + i)){
            desplazarDatos(i, pVector, tamanio);
            i = 0;
            keyEncontrados++;
        }else{
            i++;
        }
        aux = i;
    }

    printf("\n  La cantidad de encontrados son %d\n", keyEncontrados);

    return keyEncontrados;
}

/*
  SI SE QUITA UN DATO DEL VECTOR, MOVEMOS LOS DATOS QUE QUEDAN
  HACIA LA IZQUIERDA
*/
void desplazarDatos(int indice, int *pVector, int tamanio){

    while(indice < tamanio){

        *(pVector + indice) = *(pVector + indice + 1);
        indice++;
    }
}
#endif // FUNCIONESVECTOR_H_INCLUDED
