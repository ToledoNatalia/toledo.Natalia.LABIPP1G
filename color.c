#include <stdio.h>
#include <stdlib.h>
#include "dataStore.h"
#include <string.h>
#include <ctype.h>
#include "mascotas.h"
#include "tipo.h"
#include "color.h"
#include "cliente.h"


#define TAM_C 5



int mostrarColores(eColor color[], int tamC)
{
    int error = 1;
    int flag = 0;

    if(color!= NULL && tamC > 0)
    {
        system("cls");
        printf(" ID        Colores     \n");
        printf("--------------------------\n\n");
        for(int i=0; i<tamC; i++)
        {
            if(color[i].id_Color != 0)
            {
                mostrarColor(color[i],tamC);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("No hay mascotas en la lista");
        }
        printf("\n\n");

        error = 0;
    }
    return error;
}

void mostrarColor(eColor unColor,int t)
{
    printf(" %d   %s \n",unColor.id_Color,unColor.nombreColor);
}



int validarIdColor(eColor color[],int tamC,int id_Color)
{
    int esValido = 0;//no es valido

    if(color!= NULL && tamC >0 && id_Color>= 5000)
    {
        for(int i=0; i<tamC; i++)
        {

            if(color[i].id_Color == id_Color)
            {
                esValido = 1;
                break;
            }


        }

    }

    return esValido;

}


int obtenerDescripcionColor(eColor color[], int tamC,int id_Color, char nombreColor[])
{
    int error=1;
    if(color!=NULL&&tamC>0 &&id_Color>=1000&&nombreColor!=NULL)
    {
        for(int i=0; i<tamC; i++)
        {
            if(color[i].id_Color==id_Color)
            {
                strcpy(nombreColor,color[i].nombreColor);
                error=0;
                break;
            }
        }
    }
    return error;
}





