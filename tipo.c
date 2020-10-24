#include <stdio.h>
#include <stdlib.h>
#include "dataStore.h"
#include <string.h>
#include <ctype.h>
#include "mascotas.h"
#include "tipo.h"
#include "color.h"
#include "cliente.h"


#define TAM_T 5



int mostrarTipos(eTipo tipo[], int tamT)
{
    int error = 1;
    int flag = 0;

    if(tipo!= NULL && tamT > 0)
    {
        system("cls");
        printf(" ID     tipo     \n");
        printf("-------------------\n\n");
        for(int i=0; i<tamT; i++)
        {
            if(tipo[i].id_tipo != 0)
            {
                mostrarTipo(tipo[i],tamT);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("No hay ese tipo en la lista");
        }
        printf("\n\n");

        error = 0;
    }
    return error;
}



void mostrarTipo(eTipo unTipo, int t)
{
    printf(" %d   %s \n",unTipo.id_tipo,unTipo.descripcionT);
}



int validarIdTipo(eTipo tipo[],int tamT,int id_tipo)
{
    int esValido = 0;//no es valido

    if(tipo!= NULL && tamT >0 && id_tipo >= 1000)
    {
        for(int i=0; i<tamT; i++)
        {

            if(tipo[i].id_tipo==id_tipo)
            {
                esValido = 1;
                break;
            }


        }

    }

    return esValido;

}


int obtenerDescripcionTipo(eTipo tipo[], int tamT, int id_tipo, char descripcionT[])
{
    int error=1;
    if(tipo!= NULL && tamT >0 && id_tipo>=1000 &&descripcionT!= NULL)
    {
        for(int i=0; i<tamT; i++)
        {
            if(tipo[i].id_tipo == id_tipo)
            {
                strcpy(descripcionT,tipo[i].descripcionT);
                error=0;
                break;
            }
        }
    }
    return error;
}




