#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define SUNDAY 0
#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define AN_MIN 1
#define AN_MAX 5000
#define IS_BISIESTO(X) (((X) % 4 == 0 && (X) % 100 != 0) || (X) % 400 == 0)

typedef struct{
    int day,
        month,
        year;
}tDate;

int insertDateDMA(tDate *date, const char *optionalMessage, int numero);
void getDateDMA(const tDate *date);
int isValidDate(const tDate *date);

/* PERMITE EL INGRESO DE UNA FECHA VALIDA */
int insertValidDateDMA(tDate *date, const char *optionalMessage);

/* COMPARA FECHA, RETURN 0 SI SON IGUALES, ALGUN VALOR NEGATIVO SI LA PRIMERA ES MENOR A LA SEGUNDA
Y ALGUN VALOR POSITIVO SI LA PRIMERA ES MAYOR QUE LA SEGUNDA */
int compareDates(const tDate *date1, const tDate2);

/* CALCULA Y DEVUELVE EL DIA DEL A�O DE ESA FECHA, PRECONDICION: QUE SEA UNA FECHA VALIDA*/
int toJuliano(const tDate *date);

/*DETERMINA EL NUMERO DE DIA DE LA SEMANA DE UNA FECHA SE DEBE TENER EN CUENTA LO SGTE:
    -EN UN LAPSO DE 400 A�OS LA CANTIDAD DE DIAS ES MULTIPLO DE 7
    -PARA C/U DE LOS A�OS CONSECUTIVOS DE ESOS INTERVALOS EL PRIMERO DE ENERO DE CADA A�O COMIENZA EL MISMO DIA
    -EL PRIMERO DE ENERO DE LOS A�OS MULTIPLO DE 400 ES SABADO (6) TOMAMOS COMO BASE EL A�O MULTIPLO DE 400
    INMEDIATO ANTERIOR AL A�O PERO SOLO ES NECESARIO CALCULAR LA DISTANCIA AL A�O BASE EN A�OS POR CADA A�O SE SUMA
    1 AL NRO DE DIA DEL A�O BASE, SALVO QUE CADA CUATRO A�OS ES BISIESTO Y SE SUMA UNO MAS, PERO CADA 100 A�OS NO ES
    BISIESTO Y SE RESTA 1.
    SI EL A�O NO FUERA EL A�O BASE CALCULADO, SE SUMA 1 POR QUE ES BISIESTO*/
int dayOfTheWeekNumber(const tDate *date);

/*CANTIDAD DE DIAS ENTRE 2 FECHAS*/
long numberOfDaysBetweenDates(const tDate *dateDesde, const tDate *dateHasta);

int calculateAge(const tDate *dateDesde, const tDate *dateHasta);

#endif // FECHA_H_INCLUDED
