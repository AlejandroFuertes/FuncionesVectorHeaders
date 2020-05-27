#ifndef FUNCIONESHEADERS_H_INCLUDED
#define FUNCIONESHEADERS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

/* FUNCIONES */

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
        printf("  %.2f \t", *(pVector + i));
    }
    printf("\n ------------------------- \n");
}

void muestraVectorFloatOrdenInverso(float *pVector, int pTamanio){

    printf("\n ------------------------- \n");
    printf("\n  Los valores del vector inverso son: \n");
    for(int i = pTamanio - 1; i >= 0; i--){
        printf("  %.2f \t", *(pVector + i));
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

void ordenarVectorDesc(int tamanioVector, int *pVector){

    for(int i = 0; i < tamanioVector; i++){
        for(int j = 0; j < tamanioVector - 1; j++){

            if(*(pVector + j) < *(pVector + (j + 1))){
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

/*FUNCION PARA CONTAR CUANTOS DATOS SE INTRODUCEN EN UN VECTOR*/
int cuentaDatosAlCargarVector(int tamanioVector, float *pVector){

    char continuar;
    int cuentaDatosIntroducidos = 0;
    int indice = 0;

    printf("\n  %cDesea introducir un dato (S/N)?    ",168);
    fflush(stdin);
    scanf("%c", &continuar);
    validarSoN(&continuar);

    (continuar != 'S')? printf("\n") : printf("\n  Ingrese los datos en las siguientes posiciones: ");

    while(continuar == 'S'){

        printf("\n  Posicion [%d]:  ", indice + 1);
        fflush(stdin);
        scanf("%f",(pVector + indice));

        cuentaDatosIntroducidos++;

        indice++;

        if(indice < tamanioVector){
            printf("\n  %cDesea introducir otro dato (S/N)?    ",168);
            fflush(stdin);
            scanf("%c", &continuar);
            validarSoN(&continuar);
        }else{
            continuar = "N";
        }
    }

    return cuentaDatosIntroducidos;
}

float devuelveElMinimo(float *pVector, int pTamanio){

    float valorMinimo = *(pVector);

    for(int i = 1; i < pTamanio; i++){

        if(*(pVector + i) < valorMinimo){
            valorMinimo = *(pVector + i);
        }
    }
    return valorMinimo;
}

float promedioPosicionesPares(float *pVector, int pTamanio){

    float suma = 0, promedio = 0;
    for(int i = 0; i < pTamanio; i += 2){

        suma += *(pVector + i);
    }
    promedio = (suma / pTamanio ) ;
    return promedio;
}

int* devuelvePosicionMemoriaDato(int *pVector, int pKey, int tamanioVector){

    int *posicionMemoriaDato = NULL;
    int cantidadEncontrado = 0;
    int indice = 0;

    while(indice < tamanioVector){

        if(pKey == *(pVector + indice)){
            posicionMemoriaDato = (pVector + indice);

        }
        indice++;
    }
    return posicionMemoriaDato;
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

void validarSoN(char *opcion){

    bool salir = false;
    do{
        /* MEDIANTE LA TABLA ASCII TRANSFORMA DE s a S */
        if(*opcion == 's' || *opcion == 'n'){
            *opcion = *opcion - 32;
            salir = true;
        }

        if(*opcion != 'S' && *opcion != 'N'){
            salir = false;
            printf("\n  Valor incorrecto vuelva a ingresarlo (S/N):    ");
            fflush(stdin);
            scanf("%c", opcion);
        }

    }while(!(salir == true));
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

////////////////////////////////////////////////////////////////////////////////////////////
/* FUNCIONES CADENAS */

void cargarCadena(char *cadena, int tamanio){
    printf("\n  Ingrese el texto o cadena:  ");
    fgets(cadena,tamanio, stdin);
    fflush(stdin);
}

void mostrarCadena(char *cadena){
    printf("%s",cadena);
}

/*FUNCION PARA IGNORAR LAS LETRAS Y QUEDARSE CON LOS NUMEROS QUE ESTEN EN FORMATO CARACTER*/
int caracterValido(const char caracter){
    return caracter >= '0' && caracter <= '9';
}

/*TRANSFORMA NUMEROS DE CARACTERES A ENTEROS*/
int mi_Atoi(const char *cadena, int tamanio){

    //VARIABLE PARA RECORRER EL VECTOR DE FIN A INICIO
    int i = tamanio - 1;
    //VARIABLE PARA UNIDAD, DECENA, CENTENA, ETC
    int pos = 1;
    //VARIABLE PARA IR ARMANDO EL NUMERO DE CHAR A INT
    int armandoNro = 0;
    while(i >= 0){

        while(caracterValido(*(cadena + i))){

            armandoNro = armandoNro + (*(cadena + i) - 48) * pos;
            pos *= 10;
            i--;
        }
        i--;
    }
    return armandoNro;
}

////////////////////////////////////////////////////////////////////////////////////////
/*FUNCIONES PARA ARCHIVOS*/

void cargarVectorFloatEnArchivo(float *pVector, char *pNombreArchivo, int tamanio){

    FILE *ptrArchivo = NULL;

    strcat(pNombreArchivo, ".txt");

    ptrArchivo = fopen(pNombreArchivo, "w");

    if(ptrArchivo == NULL){

        printf("\n  No se pudo crear el archivo");
    }

    for(int i = 0; i < tamanio; i++){

        fprintf(ptrArchivo, "%f \n", *(pVector + i));
    }

    printf("\n  Datos Guardados Correctamente!");

    fclose(ptrArchivo);

}

#endif // FUNCIONESHEADERS_H_INCLUDED
