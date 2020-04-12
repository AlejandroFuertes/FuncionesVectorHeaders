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

#endif // FUNCIONESCADENAS_H_INCLUDED
