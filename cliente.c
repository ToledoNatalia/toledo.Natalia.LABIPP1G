#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mascotas.h"
#include "cliente.h"


#define TAM_CL 5



int mostrarClientes(eCliente cliente[], int tamCl)
{
 int error = 1;
    int flag = 0;

    if(cliente!= NULL && tamCl > 0)
    {
        system("cls");
        printf(" ID     cliente     \n");
        printf("-------------------\n\n");
        for(int i=0; i<tamCl; i++)
        {
            if(cliente[i].id_cliente != 0)
            {
                mostrarCliente(cliente[i],tamCl);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("No hay ese cliente en la lista");
        }
        printf("\n\n");

        error = 0;
    }
    return error;


}



void mostrarCliente(eCliente unCliente, int t)
{

 printf(" %d   %s \n",unCliente.id_cliente,unCliente.descripcionCl);

}



int validarIdCliente(eCliente cliente[],int tamCl,int id_cliente)
{

    int esValido = 0;//no es valido

    if(cliente!= NULL && tamCl >0 && id_cliente >= 40000)
    {
        for(int i=0; i<tamCl; i++)
        {

            if(cliente[i].id_cliente==id_cliente)
            {
                esValido = 1;
                break;
            }


        }

    }

    return esValido;

}





int obtenerDescripcionCliente(eCliente cliente[], int tamCl, int id_cliente, char descripcionCl[])
{

   int error=1;
    if(cliente!= NULL && tamCl >0 && id_cliente>=1000 &&descripcionCl!= NULL)
    {
        for(int i=0; i<tamCl; i++)
        {
            if(cliente[i].id_cliente == id_cliente)
            {
                strcpy(descripcionCl,cliente[i].descripcionCl);
                error=0;
                break;
            }
        }
    }
    return error;


}


















