
#include <stdio.h>
#include <stdlib.h>
#include "dataStore.h"
#include <string.h>
#include <ctype.h>
#include "mascotas.h"
#include "servicio.h"
#include "trabajo.h"


#define TAM_S 4



int mostrarServicios(eServicio servicio[], int tamS)
{
    int error = 1;
    int flag = 0;

    if(servicio!= NULL && tamS > 0)
    {
        system("cls");
        printf(" ID          SERVICIO          PRECIO   \n");
        printf("-----------------------------------------\n\n");
        for(int i=0; i<tamS; i++)
        {
            if(servicio[i].id_Servicio != 0)
            {
                mostrarServicio(servicio[i]);
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

void mostrarServicio(eServicio unServicio)
{
    printf(" %4d     %15s      %5.2f\n",unServicio.id_Servicio,unServicio.descripcionS,unServicio.precio);
}



int obtenerDescripcionServicio(eServicio servicio[], int tamS,int id_Servicio, char descripcionS[])
{
    int error=1;
    if(servicio!= NULL && tamS>0 && id_Servicio>=20000 &&descripcionS!=NULL)
    {
        for(int i=0; i<tamS; i++)
        {
            if(servicio[i].id_Servicio == id_Servicio)
            {
                strcpy(descripcionS,servicio[i].descripcionS);
                error=0;
                break;
            }
        }
    }
    return error;
}

int validarIdServicio(eServicio servicio[],int tamS,int id_Servicio)
{
    int esValido = 0;//no es valido

    if(servicio!= NULL && tamS>0 && id_Servicio>= 20000)
    {
        for(int i=0; i<tamS; i++)
        {

            if(servicio[i].id_Servicio == id_Servicio)
            {
                esValido = 1;
                break;
            }


        }

    }

    return esValido;

}


