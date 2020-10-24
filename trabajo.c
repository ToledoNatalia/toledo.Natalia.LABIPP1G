
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trabajo.h"
#include "mascotas.h"
#include "tipo.h"
#include "color.h"
#include "cliente.h"


#define TAM 10
#define TAM_C 5
#define TAM_T 5
#define TAM_S 4
#define TAM_CL 5
#define TAM_TA 5





int inicializarTrabajos(eTrabajo trabajos[], int tamTa)
{
    int error = 1;
    if (trabajos!=NULL && tamTa > 0)
    {
        for(int i=0; i<tamTa; i++)
        {
            trabajos[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

int mostrarTrabajos(eTrabajo trabajos[],int tamTa, eMascota mascota[], int tam,eServicio servicio[],int tamS)
{

    int error = 1;
    int flag = 0;

    if( trabajos!= NULL && tamTa > 0)//hacer con todos los parametros
    {
        //system("cls");
        printf(" Id        Mascota        Servicio         Fecha\n");
        printf("---------------------------------------------------\n\n");

        for(int i=0; i<tamTa; i++)
        {
            if(trabajos[i].isEmpty == 0)
            {
                mostrarTrabajo(trabajos[i],mascota,tam,servicio,tamS);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("   No hay trabajos en la lista");
        }
        printf("\n\n");

        error = 0;

    }
    return error;

}
void mostrarTrabajo(eTrabajo unTrabajo, eMascota animal[],int tam, eServicio servicio[], int tamS )
{
    char descServicio[20];// CARGO ESTA CADENA DE CARACTERES CON LA DESCRIPCION
    char nombreMascota[20];



    if(obtenerDescripcionServicio(servicio,tamS,unTrabajo.idServicio,descServicio)==0
            &&obtenerNombreMascota(animal,tam,unTrabajo.idMascota,nombreMascota)==0)
    {


        printf(" %4d     %10s     %10s     %02d/%02d/%d   \n",
               unTrabajo.id_trabajo,
               nombreMascota,
               descServicio,
               unTrabajo.fecha.dia,
               unTrabajo.fecha.mes,
               unTrabajo.fecha.anio
              );

    }
    else
    {

        printf("problema al obtener descripciones");
    }
}


int buscarTrabajoLibre(eTrabajo trabajos[], int tamTa)
{
    int indice = -1;

    for(int i = 0; i < tamTa; i++)
    {
        if(trabajos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


int altaTrabajo(eTrabajo trabajos[],int tamTa, eMascota animal[],int tam, eServicio servicio[],int tamS ,eTipo tipo[], int tamT,eColor color[], int tamC, eCliente cliente[],int tamCl, int id_trabajo)
{
    int error = 1;
    int auxIdMascota;
    int auxIdServicio;
    int indice;
    eTrabajo nuevoTrabajo;

    if(trabajos!=NULL && tamTa > 0 && id_trabajo> 0)
    {

        system("cls");
        printf("ALTA TRABAJO\n\n");

        indice = buscarTrabajoLibre(trabajos, tamTa);

        if(indice == -1)
        {
            printf("El sistema esta completo.\n");
        }
        else
        {

            nuevoTrabajo.id_trabajo = id_trabajo;
            nuevoTrabajo.isEmpty = 0;


            mostrarMascotas(animal, tam,color, tamC,tipo, tamT,cliente,tamCl);


            printf("\n\n Ingrese Id mascota que desea dar de alta  : ");
            scanf ("%d",&auxIdMascota);

            while(validarIdMascota(animal,tam,auxIdMascota)==0)
            {
                printf("id invalido. Reigrese ID mascota: " );
                scanf("%d",&auxIdMascota);
            }
            nuevoTrabajo.idMascota=auxIdMascota;


            mostrarServicios(servicio, tamS);
            printf("\n\nIngrese ID servicio: ");
            fflush(stdin);
            scanf ("%d",&auxIdServicio);
            while(validarIdServicio(servicio,tamS,auxIdServicio)==0)//no valido
            {
                printf("id invalido. Reigrese ID servicio: " );
                scanf("%d",&auxIdServicio);
            }

            nuevoTrabajo.idServicio=auxIdServicio;


            printf("Ingrese fecha dd/mm/aaaa:  ");
            scanf("%d/%d/%d", &nuevoTrabajo.fecha.dia, &nuevoTrabajo.fecha.mes, &nuevoTrabajo.fecha.anio);




            nuevoTrabajo.idServicio=auxIdServicio;


            trabajos[indice] = nuevoTrabajo;
            error = 0;
        }
    }

    return error;
}
