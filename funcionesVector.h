#ifndef FUNCIONESVECTOR_H_INCLUDED
#define FUNCIONESVECTOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void cargaVector(int tamanioVector, int *pVector){

    printf("\n ------------------------- \n");
    printf("\n  Ingrese los valores en la posicion: \n");
    for(int i = 0; i < tamanioVector; i++){
        printf("[%d] : ", i + 1);
        scanf("%d",(pVector + i));
    }
    printf("\n ------------------------- \n");
}

void cargaVectorFloat(int tamanioVector, float *pVector){

    printf("\n ------------------------- \n");
    printf("\n  Ingrese los valores en la posicion: \n");
    for(int i = 0; i < tamanioVector; i++){
        printf("[%d] : ", i + 1);
        scanf("%f",(pVector + i));
    }
    printf("\n ------------------------- \n");
}

void muestraVector(int tamanioVector,int *pVector){

    printf("\n ------------------------- \n");
    printf("\n  Los valores del vector actualmente son: \n");
    for(int i = 0; i < tamanioVector; i++){
        printf("  %d \t", *(pVector + i));
    }
    printf("\n ------------------------- \n");
}

void muestraVectorFloat(int tamanioVector,float *pVector){

    printf("\n ------------------------- \n");
    printf("\n  Los valores del vector actualmente son: \n");
    for(int i = 0; i < tamanioVector; i++){
        printf("  %f \t", *(pVector + i));
    }
    printf("\n ------------------------- \n");
}

void ordenarVectorAsc(int tamanioVector, int *pVector){

    for(int i = 0; i < tamanioVector; i++){
        for(int j = 0; j < tamanioVector - 1; j++){

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
int devuelveCantTotalEncontrados(int tamanioVector,int pKey, int *pVector){

    int keyEncontrados = 0;
    int i = 0;
    int aux = 0;

    while(aux < tamanioVector){

        if(pKey == *(pVector + i)){
            desplazarDatos(i, pVector, tamanioVector);
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
void desplazarDatos(int indice, int *pVector, int tamanioVector){

    while(indice < tamanioVector){

        *(pVector + indice) = *(pVector + indice + 1);
        indice++;
    }
}

void validaNroPositivo(int *pNro){

    bool nroPositivo = false;
    do{
        if(*(pNro) < 0){
            nroPositivo = false;
            printf("\n  El numero debe ser positivo, por favor vuelva a ingresarlo:  ");
            scanf("%d", pNro);
        }else{
            nroPositivo = true;
        }

    }while(!(nroPositivo == true));

}

///////////////////////////////////////////////////////////////////////////////////
                /*FUNCIONES PARA MATRICES*/
void cargaMatriz(int *pMatriz, int pFilas, int pColumnas){

    printf("\n ------------------------- \n");
    printf("\n  Ingrese los valores en la posicion: \n");
    int posicion = 0;
    for(int i = 0; i < pFilas; i++){
        for(int j = 0; j < pColumnas; j++){
            printf("[%d][%d] : ", i + 1, j + 1);
            scanf("%d",(pMatriz + posicion));
            posicion++;
        }
    }
    printf("\n ------------------------- \n");
}

void muestraMatriz(int *pMatriz, int pFilas, int pColumnas){

    printf("\n ------------------------- \n");
    printf("\n  Los valores de la matriz actualmente son: \n");
    int posicion = 0;
    for(int i = 0; i < pFilas; i++){
        for(int j = 0; j < pColumnas; j++){
            printf("%d \t",*(pMatriz + posicion));
            posicion++;
        }
        printf("\n");
    }
    printf("\n ------------------------- \n");
}

int sumaEncimaDiagonalPrincipal(int *pMatriz, int ordenN){

    int suma = 0;
    for(int i = 0; i < ordenN - 1; i++){

        for(int j = i + 1; j < ordenN; j++){

            suma += *(pMatriz + (i*ordenN) + j);
        }
    }
    return suma;
}

int sumaDiagonalPrincipal(int *pMatriz, int ordenN){

    int suma = 0;
    for(int i = 0; i < ordenN; i++){

        for(int j = 0; j < ordenN; j++){

            if(i == j){
                suma += *(pMatriz + (i*ordenN) + j);
            }
        }
    }
    return suma;
}

int sumaDebajoDiagonalPrincipal(int *pMatriz, int ordenN){

    int suma = 0;
    for(int i = 0; i < ordenN; i++){

        for(int j = 0; j < ordenN; j++){

            if(i > j){

                suma += *(pMatriz + (i*ordenN) + j);
            }
        }
    }
    return suma;
}

/*  1 = VERDADERO
    2 = FALSO
*/
bool esMatrizIdentidad(int *pMatriz, int ordenN){

    for(int i = 0; i < ordenN; i++){

        for(int j = 0; j < ordenN; j++){

            if(i == j){

                if(*(pMatriz + (i*ordenN) + j) != 1){
                    return false;
                }

            }else{
                if(*(pMatriz + (i*ordenN) + j) != 0){
                    return false;
                }
            }
        }
    }
    return true;
}

/*
    MATRIZ DIAGONAL SON AQUELLAS QUE TIENEN CEROS EN TODA SUS POSICIONES MENOS EN LA DIAGONAL PRINCIPAL
*/
bool esMatrizDiagonal(int *pMatriz, int ordenN){

    for(int i = 0; i < ordenN; i++){
        for(int j = 0; j < ordenN; j++){

            if( i != j){

                if(*(pMatriz + (i*ordenN) + j) != 0){
                    return false;
                }
            }
        }
    }
    return true;
}

int sumaDiagonalSecundaria(int *pMatriz, int ordenN){

    int suma = 0;
    for(int i = 0; i < ordenN; i++){
        for(int j = 0; j < ordenN; j++){

            if( i + j == ordenN - 1){
                suma += *(pMatriz + (i*ordenN) + j);
            }
        }
    }
    return suma;
}

bool esMatrizSimetrica(int *pMatriz, int ordenN){

    for(int i = 0; i < ordenN; i++){

        for(int j = 0; j < ordenN; j++){

            if( *(pMatriz + (i*ordenN) + j) != *(pMatriz + (j*ordenN) + i) ){
                return false;
            }
        }
    }
    return true;
}

#endif // FUNCIONESVECTOR_H_INCLUDED
