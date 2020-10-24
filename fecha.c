
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fecha.h"







void mostrarFecha(eFecha unaFecha)
{

    printf("%02d/%02d/%d\n\n", unaFecha.dia, unaFecha.mes, unaFecha.anio);

}
/*
int validarDia(int dia,int mes)
{
    int valido=0;

    if(dia>0)
    {
        switch(dia)
        {
        case 2:
            if(dia<29)
            {
                valido =1;

            }
            break;

        case 4:
        case 5:
        case 6:
        case 9:


        case 11:

            if(dia<31)
            {
                valido=1;
            }

            break;

        default:
            if(dia<32)
            {
                valido=1;
            }

            break;
        }

    }

       return valido;

}


int validarMes(int mes){
int valido=0;

   if(mes>0 && mes< 13){
     valido= 1;

   }

return valido;


}

int validarAnio(int anio){
int valido=0;

   if(anio>=2010 && anio<=2020){
     valido= 1;

   }

return valido;


}

*/


