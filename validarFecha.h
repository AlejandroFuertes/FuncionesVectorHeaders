#ifndef VALIDARFECHA_H_INCLUDED
#define VALIDARFECHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MES 30
#define ANIO 365

typedef struct{
    int dia;
    int mes;
    int anio;
}Fecha;

bool controlFecha(Fecha *pFecha, int pDias[]){

    bool fechaCorrecta = false;

    do{
        if((pFecha->anio < 1600) || (pFecha->anio) > 2020){
            fechaCorrecta = false;
        }else{
            fechaCorrecta = true;
            break;
        }
        printf("\n  A%co incorrecto, vuelva a introducir el a%co:   ", 164, 164);
        fflush(stdin);
        scanf("%i",&pFecha->anio);

    }while(!(fechaCorrecta == true));

    actualizaDiasBisiesto((pFecha->anio), pDias);

    fechaCorrecta = false;

    do{
        if((pFecha->mes) < 1 || (pFecha->mes) > 12){
            fechaCorrecta = false;
        }else{
            fechaCorrecta = true;
            break;
        }
        printf("\n  Mes incorrecto, vuelva a introducir el mes:    ");
        fflush(stdin);
        scanf("%d",&pFecha->mes);

    }while(!(fechaCorrecta == true));

    fechaCorrecta = false;

    do{
        if( (pFecha->dia) < 1 || (pFecha->dia) > pDias[pFecha->mes - 1]){
            fechaCorrecta = false;
        }else{
            fechaCorrecta = true;
            break;
        }
        printf("\n  Dia incorrecto vuelva a introducir el dia:  ");
        fflush(stdin);
        scanf("%d",&pFecha->dia);

    }while(!(fechaCorrecta == true));

    return true;
}

void diaSiguiente(Fecha *pFecha, int pDias[]){

    (pFecha->dia) += 1;

    if((pFecha->dia) > pDias[(pFecha->mes) - 1]){

        (pFecha->dia) = 1;
        (pFecha->mes) += 1;

        if((pFecha->mes) > 12){
            (pFecha->anio) += 1;
            (pFecha->mes) = 1;
        }
    }
}

void sumarDias(Fecha *pFecha,int pDias[], int suma){

    (pFecha->dia) += suma;
    while(((pFecha->dia ) > pDias[(pFecha->mes) - 1])){

        actualizaDiasBisiesto((pFecha->anio), pDias);

        (pFecha->dia) -= pDias[(pFecha->mes) - 1];

        if((pFecha->mes) > 11){
            (pFecha->mes) = 1;
            (pFecha->anio)++;
        }else{
            (pFecha->mes)++;
        }
    }
}

void restarDias(Fecha *pFecha, int pDias[], int resta){

   (pFecha->dia) -= resta;

   while(((pFecha->dia) < 1)){

        actualizaDiasBisiesto((pFecha->anio), pDias);

        if((pFecha->mes) == 1){

            (pFecha->dia) += pDias[11];
            (pFecha->mes)--;
        }
        else{
            (pFecha->dia) += pDias[(pFecha->mes) - 2];//-2 REFIERE A LA POSICION DEL VECTOR DONDE ESTA EL MES ANTERIOR INGRESADO
            (pFecha->mes)--;
        }
        if((pFecha->mes) < 1){
            (pFecha->mes) = 12;
            (pFecha->anio)--;
        }
    }
}

void actualizaDiasBisiesto(int anio, int pDias[]){

    if((((anio % 4) == 0) && (anio % 100) != 0)||(anio && 400 == 0)){
        pDias[1]=29;
    }else{
        pDias[1]=28;
    }
}

/*
    DETERMINA EL DIA EXACTO DE UNA FECHA
*/
void diaFecha(Fecha *pFecha){ //FORMULA D=[N+M+A+(A/4)+Ks]%7
    /*
    1600►6
    1700►4
    1800►2
    1900►0
    2000►6
    2100►4
    */
    enum diaSemana{
        domingo,
        lunes,
        martes,
        miercoles,
        jueves,
        viernes,
        sabado
    };

    int mes[12]={0,3,3,6,1,4,6,2,5,0,3,5},ks,resultado; //SI ES BISIESTO {6,2,...........}

    enum diaSemana dia;

    if((pFecha->anio)>1599&&(pFecha->anio)<1701)
        ks=6;
    if((pFecha->anio)>1699&&(pFecha->anio)<1801)
        ks=4;
    if((pFecha->anio)>1799&&(pFecha->anio)<1901)
        ks=2;
    if((pFecha->anio)>1899&&(pFecha->anio)<2001)
        ks=0;
    if((pFecha->anio)>1999&&(pFecha->anio)<2101)
        ks=6;
    if((pFecha->anio)>2099&&(pFecha->anio)<2201)
        ks=4;

    if((((pFecha->anio) % 4 == 0) && ((pFecha->anio) % 100 != 0)) || ((pFecha->anio) && 400 == 0)){
        mes[0]=6;
        mes[1]=2;
    }

    dia = ((pFecha->dia) + mes[(pFecha->mes) - 1] + ((pFecha->anio) % 100) + ((((pFecha->anio) % 100)) / 4) + ks) % 7; //FORMULA

    switch(dia){
        case domingo:printf("\n El dia es domingo \n");break;
        case lunes:printf("\n El dia es lunes \n");break;
        case martes:printf("\n El dia es martes \n");break;
        case miercoles:printf("\n El dia es miercoles \n");break;
        case jueves:printf("\n El dia es jueves \n");break;
        case viernes:printf("\n El dia es viernes \n");break;
        case sabado:printf("\n El dia es sabado \n");break;
        default:printf("\n error de resultado dia\n");
    }
}

void diferenciaDias(Fecha *pFecha1, Fecha *pFecha2, int pDias[]){

    Fecha fechaMenor,fechaMayor;
    int igual = 0, contadorDias=0;

//EMPEZAMOS COMPARANDO DIAS MUCHO MUY IMPORTANTE :v - FUNCION PARA COMPARAR FECHA MENOR;
    if(pFecha1->dia > pFecha2->dia){

        fechaMenor.dia = pFecha2->dia;
        fechaMenor.mes = pFecha2->mes;
        fechaMenor.anio = pFecha2->anio;

        fechaMayor.dia = pFecha1->dia;
        fechaMayor.mes = pFecha1->mes;
        fechaMayor.anio = pFecha1->anio;
    }else{
        if(pFecha1->dia < pFecha2->dia){

            fechaMenor.dia = pFecha1->dia;
            fechaMenor.mes = pFecha1->mes;
            fechaMenor.anio = pFecha1->anio;

            fechaMayor.dia = pFecha2->dia;
            fechaMayor.mes = pFecha2->mes;
            fechaMayor.anio = pFecha2->anio;
        }else{
            igual++;
        }
    }

    if(pFecha1->mes > pFecha2->mes){

        fechaMenor.dia = pFecha2->dia;
        fechaMenor.mes = pFecha2->mes;
        fechaMenor.anio = pFecha2->anio;

        fechaMayor.dia = pFecha1->dia;
        fechaMayor.mes = pFecha1->mes;
        fechaMayor.anio = pFecha1->anio;
    }else{
        if(pFecha1->mes < pFecha2->mes){

            fechaMenor.dia = pFecha1->dia;
            fechaMenor.mes = pFecha1->mes;
            fechaMenor.anio = pFecha1->anio;

            fechaMayor.dia = pFecha2->dia;
            fechaMayor.mes = pFecha2->mes;
            fechaMayor.anio = pFecha2->anio;
        }else{
            igual++;
        }
    }

    if(pFecha1->anio > pFecha2->anio){

        fechaMenor.dia = pFecha2->dia;
        fechaMenor.mes = pFecha2->mes;
        fechaMenor.anio = pFecha2->anio;

        fechaMayor.dia = pFecha1->dia;
        fechaMayor.mes = pFecha1->mes;
        fechaMayor.anio = pFecha1->anio;
    }else{
        if(pFecha1->anio < pFecha2->anio){

            fechaMenor.dia = pFecha1->dia;
            fechaMenor.mes = pFecha1->mes;
            fechaMenor.anio = pFecha1->anio;

            fechaMayor.dia = pFecha2->dia;
            fechaMayor.mes = pFecha2->mes;
            fechaMayor.anio = pFecha2->anio;
        }else{
            igual++;
        }
    }

    if(igual != 3){

        while((fechaMenor.dia != fechaMayor.dia)||(fechaMenor.mes != fechaMayor.mes)||(fechaMenor.anio != fechaMayor.anio)){

            actualizaDiasBisiesto(fechaMenor.anio, pDias);

            if(fechaMenor.dia == pDias[fechaMenor.mes - 1]){
                fechaMenor.dia = 1;
                fechaMenor.mes++;
                contadorDias++;

                if(fechaMenor.mes == 13){
                    fechaMenor.anio++;
                    fechaMenor.mes = 1;
                }
            }else{
                contadorDias++;
                fechaMenor.dia++;
            }
        }

        printf("\n  La diferencia de dias es:  %d ",contadorDias);
        printf("\n  La diferencia de meses es:  %d ",contadorDias/MES);
        printf("\n  La diferencia de a%cos es:  %d ",164, contadorDias/ANIO);
    }else{
        printf("\n las fechas son iguales");
    }
}

#endif // VALIDARFECHA_H_INCLUDED
