int insertDateDMA(tDate *date, const char *optionalMessage, int numero) {

    if(optionalMessage){
        printf("\n  %s", mensajeOpcional);
    }else{
        printf("\n  Date: (dd/mm/aaaa) - 0 = No Insert");
    }

    date->day = 0;
    date->month = 0;
    date->year = 0;

    fflush(stdin);
    scanf("%d/%d/%d", &date->day, &date->month, &date->year);

    return date->day && date->month && date->year;
}

void getDateDMA(const tDate *date){

    printf("%02d/%02d/%04d", date->day, date->month, date->year);
}

int isValidDate(const tDate *date){

    static const char days[][12] = {
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

    return date->month > 0 && date->month <= 12 && date->year >= AN_MIN &&
           date->year <= AN_MAX && date->day >= 0 && date->day <= days[IS_BISIESTO(date->year)][date->month - 1];
}

int insertValidDateDMA(tDate *date, const char *optionalMessage){
    do{
        if(!insertDateDMA(date, optionalMessage)){
            return 0;
        }

    } while (!isValidDate(date));

    return 1;
}

int compareDates(const tDate *date1, const tDate *date2){

}
