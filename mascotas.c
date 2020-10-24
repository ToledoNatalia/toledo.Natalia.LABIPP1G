
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "mascotas.h"
#include "mascotas.h"
#include "tipo.h"
#include "color.h"
#include "cliente.h"
#include "validaciones.h"





#define TAM 10
#define TAM_C 5
#define TAM_T 5
#define TAM_CL 5



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
        if(animal[i].id ==id&& animal[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



int bajaMascota(eMascota animal[], int tam, eColor color[],int tamC, eTipo tipo[], int tamT , eCliente cliente[],int tamCl)
{
    int error = 1;
    int id;
    int indice;
    int confirma;

    if(animal!= NULL && tam > 0)
    {
        system("cls");
        printf("    *** BAJA DE MASCOTAS ***\n\n");
        mostrarMascotas(animal, tam,color, tamC,tipo, tamT,cliente,tamCl);
        printf("Ingrese Id que desea dar de baja:  ");
        scanf("%d", &id);

        indice = buscarMascota(animal, tam, id);

        if( indice == -1)
        {
            printf("No existe una mascota con ese id.\n\n");
        }
        else
        {
            mostrarMascota(animal[indice],color,tamC,tipo, tamT,cliente,tamCl);
            printf("Confirma baja(num): 1 - si 2 - no\n\n");
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



int altaMascota( eMascota animal[], int tam,  eTipo tipo[], int tamT,eColor color[], int tamC, eCliente cliente[],int tamCl,int id)
{
    int error=1;
    int indice;
    eMascota nuevaMascota;

    int auxIdtipo;
    int auxIdColor;
    int auxIdCliente;


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

            mostrarTipos(tipo,tamT);

            printf("\nIngrese ID del  tipo de mascota: ");
            scanf("%d",&auxIdtipo);

            while(validarIdTipo(tipo,tamT,auxIdtipo)==0)//no valido
            {
                printf("id invalido. Reigrese id tipo : " );
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
            scanf("%d", &nuevaMascota.edad);


            mostrarClientes(cliente,tamCl);

            printf("\nIngrese ID cliente: ");
            scanf("%d", &auxIdCliente);

            while(validarIdCliente(cliente,tamCl,auxIdCliente)==0)//no valido
            {
                printf("id invalido. Reigrese id cliente: " );
                scanf("%d",&auxIdCliente);
            }

            nuevaMascota.idCliente=auxIdCliente;



            animal[indice] = nuevaMascota;

            error = 0;
        }
    }
    return error;
}



int mostrarMascotas(eMascota animal[], int tam, eColor color[],int tamC,eTipo tipo[], int tamT, eCliente cliente[],int tamCl)
{
    int error = 1;
    int flag = 0;
    if(animal!= NULL && tam > 0)
    {
        system("cls");
        printf(" ID      Color     Tipo     Nombre    Edad    Cliente\n\n");
        printf("------------------------------------------------------------\n\n");
        for(int i=0; i<tam; i++)
        {
            if(animal[i].isEmpty == 0)
            {

                mostrarMascota(animal[i],color,tamC,tipo,tamT,cliente, tamCl);
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



void mostrarMascota(eMascota unaMascota, eColor color[],int tamC, eTipo tipo[], int tamT,eCliente cliente[], int tamCl)
{
    char nombreColor[15];
    char nombretipo[15];
    char nombreCliente[15];
    if(obtenerDescripcionColor(color,tamC,unaMascota.idColor,nombreColor)==0 &&
            obtenerDescripcionTipo(tipo,tamT,unaMascota.idTipo,nombretipo)==0&&
            obtenerDescripcionCliente(cliente,tamCl,unaMascota.idCliente,nombreCliente)==0)

    {
        printf(" %d   %10s   %10s   %10s   %5d   %10s\n\n", unaMascota.id, nombreColor, nombretipo, unaMascota.nombre, unaMascota.edad,nombreCliente);
    }
}



int modificarMascota(eMascota animal[], int tam, eTipo tipo[], int tamT,eColor color[],int tamC,eCliente cliente[],int tamCl,int id)
{
    int index;
    int returnValue=-1;
    char confirm;

    index=buscarMascota(animal,tam,id);

    if(tam>0&&animal!=NULL)
    {
        if(index!=-1)
        {
            printf("\n");
            mostrarMascota(animal[index],color,tamC,tipo,tamT,cliente,tamCl);
            confirm=getCharTwoOptions("\n Desea modificar esta mascota:? s/n","ERROR\nEnter s or n:",'s','n');
            if(confirm=='s')
            {
                switch(menuModificacion())
                {
                case 'a':

                    mostrarTipos(tipo,tamT);
                    animal[index].idTipo=getInt("Ingrese  ID tipo:","ERROR\n Ingrese ID tipo nuevamente: ");
                    break;
                case 'b':

                    animal[index].edad=getInt("Ingrese edad :","ERROR\n Ingrese edad nuevamente: ");
                    break;

                default:
                    printf("Opcion invalida\n\n");
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

char menuModificacion()
{
    char opcion;

    system("cls");
    printf("   ***MODIFICACION MENU***\n\n");
    printf("a. Modificar ID tipo \nb. Modificar edad\n\n");
    printf("______________________________________________\n\n");
    opcion=getChar("Elija una opcion:","ERROR\nIngrese nuevamente una opcion:");

    return opcion;
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



int obtenerNombreMascota(eMascota mascota[],int tam,int id,char nombre[])//0si pudo cargar o 1 si no pudo
{
    int  error =1;// COMO SI HUBIERA UN ERROR

    if(mascota!= NULL && tam > 0  && nombre!=NULL)//VALIDACION A LOS PARAMETROS
    {

        for( int i =0; i<tam; i++)
        {
            if(mascota[i].id==id&& mascota[i].isEmpty ==0)
            {
                strcpy (nombre,mascota[i].nombre);
                error =0;

                break;
            }
        }


    }


    return error;
}
int validarIdMascota(eMascota mascota[],int tam,int id)
{
    int esValido = 0;//no es valido

    if(mascota!= NULL && tam>0 && id>= 0001)
    {
        for(int i=0; i<tam; i++)
        {

            if(mascota[i].id == id &&mascota [i].isEmpty ==0)
            {
                esValido = 1;
                break;
            }


        }

    }

    return esValido;

}



char menuOrdenamiento()
{
    char opcion;

    system("cls");
    printf("  *** MENU ORDENAMIENTO ***\n\n");
    printf("a. Ordenar mascotas por  nombre\n\n");
    printf("b. Ordenar mascotas por  tipo\n\n");
    printf("c. Listar mascotas \n\n");
    printf("d. salir \n\n");
    printf("_____________________________________\n\n");
    opcion= tolower (getChar("Elija una opcion:","ERROR\nIngrese nuevamente una opcion:"));
    return opcion;
}


void reportar(eMascota animal[],int tam,eColor color[],int tamC,eTipo tipo[],int tamT, eCliente cliente[],int tamCl)
{
    char opcion;
    int orden;

    opcion=menuOrdenamiento();

    switch(opcion)
    {
    case 'a':
        printf("\n Orden descendente ingrese 0, de lo contrario ingrese 1 \n");
        printf("\n Ingrese orden 0-1: ");
        scanf("%d",&orden);
        ordenarMascotasXNombre(animal,tam,orden);
        mostrarMascotas(animal, tam,color, tamC,tipo, tamT,cliente, tamCl);
        break;
    case 'b':
        printf("\n Orden  descendente ingrese 0, de lo contrario ingrese 1 \n\n");
        printf("\n Ingrese orden 0-1: ");
        scanf("%d",&orden);
        ordenarMascotasXTipo(animal,tam,orden);
        mostrarMascotas(animal, tam,color, tamC,tipo, tamT,cliente,tamCl);
        break;

    case 'c':

        mostrarMascotas(animal, tam,color, tamC,tipo, tamT,cliente,tamCl);

        break;
    default:
        printf("opcion invalida\n");
    }
    system("pause");
}



int ordenarMascotasXNombre(eMascota animal[], int tam,int orden)
{
    eMascota auxMascota;
    int error= 1;

    if(animal!=NULL && tam>0 && orden>=0 && orden<=1)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                switch(orden)
                {
                case 0:
                    if(strcmp(animal[i].nombre, animal[j].nombre) > 0)
                    {
                        auxMascota = animal[i];
                        animal[i] = animal[j];
                        animal[j] = auxMascota;
                    }

                    break;
                case 1:
                    if(strcmp(animal[i].nombre, animal[j].nombre) < 0)
                    {
                        auxMascota = animal[i];
                        animal[i] = animal[j];
                        animal[j] = auxMascota;
                    }

                    break;
                }

                error=0;
            }

        }
    }
  return error;
}





int ordenarMascotasXTipo(eMascota animal[], int tam,int orden)
{
    eMascota auxTipo;
    int error=1;

    if(animal!=NULL && tam>0 && orden>=0 && orden<=1)

    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {

                switch(orden)
                {
                case 0:

                    if(animal[i].idTipo > animal[j].idTipo)
                    {
                        auxTipo = animal[i];
                        animal[i] = animal[j];
                        animal[j] = auxTipo;
                    }

                    break;
                case 1:

                    if(animal[i].idTipo < animal[j].idTipo)
                    {
                        auxTipo = animal[i];
                        animal[i] = animal[j];
                        animal[j] = auxTipo;
                    }


                    break;
                }

                error=0;
            }
        }
    }

    return error;
}

int colorMascotaFavorito( eMascota animal[],int tam,eColor color[], int tamC)
{
    int error =1;
    int mayor;
    int contadores[tam];
    int flag=0;

        for (int i=0; i< tamC; i++){

            contadores[i]=0;

        }

    if(color!=NULL && animal!=NULL && tam > 0 && tamC>0)
    {
        system("cls");
        printf("color favorito\n");
        for(int c=0; c < tamC; c++)//recorro el vector de deportes
        {

            for (int i=0; i < tam; i++)//recooro el vectoer de personas
            {
                if(animal[i].isEmpty == 0 && animal[i].idColor==color[c].id_Color)//BUSCA LA PERSONA QUE ESTA ACTIVA
                {

                    contadores[c]++;
                }
            }
        }

        for(int i=0; i<tamC; i++)
        {
            if(contadores[i] >mayor || flag == 0)
            {
                mayor = contadores[i];
                flag = 1;
            }
        }

        printf("El color favoritos es:\n\n");

        for(int i=0; i< tamC; i++)
        {
            if(contadores[i]==mayor)// en cada iteracion pregunto si es mayor
            {
                printf("%s\n",color[i].nombreColor);

            }

        }

        printf("\n\n");
        error=0;

    }
    return error;

}

