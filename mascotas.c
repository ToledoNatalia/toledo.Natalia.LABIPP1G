#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
# include "mascotas.h"
#include "validaciones.h"

#define TAM 10
#define TAM_C 5
#define TAM_T 5
#define TAM_S 3


int inicializarMascotas(eMascota animal[], int tam)
{
    int error = 1;
    if (animal!=NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            animal[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

int buscarMascota(eMascota animal[], int tam, int id)
{
    int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if(animal[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int bajaMascota(eMascota animal[], int tam)
{
    int error = 1;
    int id;
    int indice;
    int confirma;


    if(animal!= NULL && tam > 0)
    {
        system("cls");
        printf("    *** BAJA DE MASCOTA ***\n");
        mostrarMascotas(animal, tam);
        printf("Ingrese ID de la mascota: ");
        fflush(stdin);
        scanf("%d", &id);

        indice = buscarMascota(animal, tam,id);


        if( indice == -1)
        {
            printf("No existe una mascota con ese id .\n");
        }
        else
        {
            mostrarMascota(animal[indice]);
            printf("Confirma baja: 1 - SI 2 - NO\n\n");
            scanf("%d", &confirma);
            if(confirma == 1)
            {
                animal[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 2;
            }
        }

    }

    return error;

}


int altaMascota( eMascota animal[], int tam,  etipo tipoM[], int tamT,eColor color[], int tamC, int id)
{
    int error=1;
    int indice;
    eMascota nuevaMascota;

    int auxIdtipo;
    int auxIdColor;


    if(animal!=NULL && tam > 0 && id > 0)
    {
        system("cls");
        printf("***ALTA DE MASCOTAS***\n\n");
        indice = buscarLibre(animal, tam);
        printf("%d",indice);

        if(indice == -1)
        {
            printf("El sistema esta completo.\n\n");
        }
        else
        {

            nuevaMascota.id = id;
            nuevaMascota.isEmpty = 0;

            mostrarTipos(tipoM,tamT);

            printf("\nIngrese ID de tipo: ");
            scanf("%d",&auxIdtipo);

            while(validarIdTipo(tipoM,tamT,auxIdtipo)==0)//no valido
            {
                printf("id invalido. Reigrese id tipo: " );
                scanf("%d",&auxIdtipo);
            }
            nuevaMascota.idTipo=auxIdtipo;

            printf("\nIngrese nombre: ");
            fflush(stdin);
            gets(nuevaMascota.nombre);


            mostrarColores(color,tamC);

            printf("\nIngrese ID color: ");
            fflush(stdin);
            scanf("%d", &auxIdColor);

            while(validarIdColor(color,tamC,auxIdColor)==0)//no valido
            {
                printf("id invalido. Reigrese id color: " );
                scanf("%d",&auxIdColor);
            }
            nuevaMascota.idColor=auxIdColor;


            printf("\nIngrese edad: ");
            fflush(stdin);
            scanf("%d", &nuevaMascota.edad);
            fflush(stdin);

            nuevaMascota.idTipo=auxIdtipo;
            nuevaMascota.idColor=auxIdColor;
            animal[indice] = nuevaMascota;

            error = 0;
        }
    }
    return error;
}

int mostrarTipos(etipo tipo[], int tamT)
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
            if(tipo[i].id != 0)
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

void mostrarTipo(etipo unTipo, int t)
{
    printf(" %d   %s \n",unTipo.id,unTipo.descripcion);
}


int mostrarColores(eColor color[], int tamC)
{
    int error = 1;
    int flag = 0;

    if(color!= NULL && tamC > 0)
    {
        system("cls");
        printf(" ID      Colores     \n");
        printf("-------------------\n\n");
        for(int i=0; i<tamC; i++)
        {
            if(color[i].id != 0)
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

void mostrarColor(eColor unColor, int t)
{
    printf(" %d   %s \n",unColor.id,unColor.nombreColor);
}


int mostrarMascotas(eMascota animal[], int tam)
{
    int error = 1;
    int flag = 0;
    if(animal!= NULL && tam > 0)
    {
        system("cls");
        printf(" ID     IDTipo    IDColor    Nombre   Edad \n");
        printf("---------------------------------------------\n\n");
        for(int i=0; i<tam; i++)
        {
            if(animal[i].isEmpty == 0)
            {

                mostrarMascota(animal[i]);
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

void mostrarMascota(eMascota unaMascota)
{



    printf(" %4d     %4d    %4d     %10s   %4d     \n",unaMascota.id,unaMascota.idTipo,unaMascota.idColor,unaMascota.nombre,unaMascota.edad);
}

int validarIdTipo(etipo tipo[],int tamT,int id)
{
    int esValido = 0;//no es valido

    if(tipo!= NULL && tamT >0 && id >= 1000)
    {
        for(int i=0; i<tamT; i++)
        {

            if(tipo[i].id==id)
            {
                esValido = 1;
                break;
            }


        }

    }

    return esValido;

}

int validarIdColor(eColor color[],int tamC,int id)
{
    int esValido = 0;//no es valido

    if(color!= NULL && tamC >0 && id >= 5000)
    {
        for(int i=0; i<tamC; i++)
        {

            if(color[i].id==id)
            {
                esValido = 1;
                break;
            }


        }

    }

    return esValido;

}

int modificarMascota(eMascota animal[], int tam, int id)
{
    int indice;
    int returnValue=-1;
    char confirma;



    if(animal!= NULL && tam>0)
    {
        if(indice!=-1)
        {
            printf("\n");
            mostrarMascotas(animal, tam);
            printf("\n Seguro desea modificar: s/n\n\n");
            scanf("%c",&confirma);
            if(confirma=='s')
            {

                switch(menuModificacion())
                {
                case 'a':

                    mostrarMascotas(animal,tam);
                    animal[indice].idTipo=getInt("Ingrese id tipo (numero):","ERROR\n Ingrese id nuevamente:");
                    break;
                case 'b':
                    mostrarMascotas(animal,tam);
                    animal[indice].edad=getInt("Ingrese edad :","ERROR\n Ingrese modelo nuevamente:");
                    break;

                default:
                    printf("opcion invalida\n\n");
                    break;
                }
                returnValue=1;
            }
            else
            {
                returnValue=0;
            }
        }
    }

    return returnValue;
}
int buscarLibre(eMascota animal[], int tam) //para dar de alta
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(animal[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int mostrarServicios(eServicio servicio[], int tamS)
{
    int error = 1;
    int flag = 0;

    if(servicio!= NULL && tamS > 0)
    {
        system("cls");
        printf(" ID      SERVICIO     \n");
        printf("-------------------\n\n");
        for(int i=0; i<tamS; i++)
        {
            if(servicio[i].id != 0)
            {
                mostrarServicio(servicio[i],tamS);
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

void mostrarServicio(eServicio unServicio, int t)
{
    printf(" %d   %s \n",unServicio.id,unServicio.descripcion);
}









