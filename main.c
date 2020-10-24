#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mascotas.h"
#include "tipo.h"
#include "color.h"
#include "cliente.h"
#include "servicio.h"
#include "trabajo.h"
#include "fecha.h"
#include "validaciones.h"




#define TAM 10
#define TAM_C 5
#define TAM_T 5
#define TAM_S 4
#define TAM_TA 5
#define TAM_CL 5

char menuOpciones();



int main()
{
    char seguir = 's';
    char confirma;
    int idParam;
    int flagOpcion1=0;
    eMascota mascota[TAM];
    eTrabajo job[TAM_TA];

    eTipo datosTipo [20]= {{1000,"Ave"},{1001,"Perro"},{1002,"Gato"},{1003,"Roedor"},{1004,"Pez"}};
    eColor datosColor [20]= { {5000,"Negro"}, {5001,"Blanco"}, {5002,"Gris"}, {5003,"Rojo"}, {5004,"Azul"}};
    eServicio  datosServicio[20]= { {20000,"Corte",250}, {20001,"Desparacitado",300}, {20002,"Castrado",400}};
    eCliente datosCliente[20]= { {40000,"Romina"}, {40001,"Tamara"}, {40002,"Sofia"}, {40003,"Emilse"}, {40004,"Maria"}};

    int rta;

    int proximoIdMascota=0001;
    int proximoIdTrabajo=30000;

    if(inicializarMascotas(mascota, TAM)==0)
    {
        printf("Mascota inicializadas con exito!");
    }
    else
    {
        printf("Ha ocurrido un problema al inicializar mascotas");
    }
    if(inicializarTrabajos(job, TAM_TA)==0)
    {
        printf("trabajo inicializado con exito!");
    }
    else
    {
        printf("Ha ocurrido un problema al inicializar trabajo");
    }

      // proximoIdMascota += hardcodearMascotas(mascota, TAM, 8);//

    do
    {

        system("cls");
        switch(menuOpciones())
        {

        case 'a':
            if(altaMascota(mascota,TAM,datosTipo,TAM_T,datosColor,TAM_C,datosCliente, TAM_CL,proximoIdMascota) == 0)
            {
                proximoIdMascota++;
                printf("ALTA EXITOSA!\n");
                flagOpcion1=1;

            }
            else
            {
                printf("Problema para realizar el alta\n\n");
            }


            break;
        case 'b':
                if(flagOpcion1)
	            {
	                printf("   ***MODIFICAR MASCOTA***\n\n");
	                mostrarMascotas(mascota,TAM,datosColor,TAM_C,datosTipo,TAM_T,datosCliente,TAM_CL);
	                idParam=getInt("Ingrese ID de la mascota que desea modificar :","ERROR\n Intente nuevamente :");

	                switch(modificarMascota(mascota,TAM,datosTipo,TAM_T, datosColor,TAM_C,datosCliente,TAM_CL,idParam))
	                {
	                    case -1:
	                        printf("\n No se pudo encontrar esa mascota\n\n");
	                        break;
	                    case 0:
	                        printf("\nOperacion cancelada\n\n");
	                        break;
	                    default:
	                        printf("\n MODIFICACION EXITOSA!!!\n\n");
	                        break;
	                }
	            }
	            else
	            {
	                printf("\n Primero debe ingresar una mascota...\n\n");
	            }

	            break;

        case 'c':
            if (flagOpcion1)
            {
                rta= bajaMascota(mascota,TAM,datosColor,TAM_C,datosTipo,TAM_T,datosCliente,TAM_CL);

                if( rta == 0)
                {
                    printf("Baja exitosa\n");
                }
                else if(rta == 2)
                {
                    printf("Baja cancelada por usuario\n");
                }

            }
               else
	            {
	                printf("\n Primero debe ingresar una mascota...\n\n");
	            }


	            break;


        case 'd':

             if(flagOpcion1)
	            {
	                reportar(mascota,TAM,datosColor ,TAM_C,datosTipo,TAM_T,datosCliente,TAM_CL);
	            }else
	            {
	                printf("\n Primero debe agregar una mascota\n\n");
	            }

            break;
        case 'e':
            system("cls");
            mostrarTipos(datosTipo, TAM_T);

            break;
        case 'f':
            system("cls");
            mostrarColores(datosColor,TAM_C);
            break;
        case 'g':
            system("cls");
            mostrarServicios(datosServicio, TAM_S);

            break;
        case 'h':

            if(flagOpcion1)
            {
                mostrarMascotas(mascota,TAM,datosColor ,TAM_C,datosTipo,TAM_T,datosCliente,TAM_CL);
                altaTrabajo(job,TAM_TA, mascota,TAM,datosServicio,TAM_S,datosColor ,TAM_C,datosTipo,TAM_T,datosCliente,TAM_CL,proximoIdTrabajo);
                proximoIdTrabajo++;
                printf("ALTA EXITOSA!\n\n");

            }
            else
            {
                printf("Error,no hay mascotas cargadas en el sistema!.. \n\n");
            }

            break;

        case 'i':
            system("cls");
            mostrarTrabajos(job,TAM_TA,mascota,TAM,datosServicio,TAM_S);
            break;



        case 'j':
          if(flagOpcion1)
           {

            system("cls");
            colorMascotaFavorito(mascota, TAM ,datosColor,TAM_C);
           }else
	            {
	                printf("\n Primero debe agregar una mascota\n\n");
	            }
          break;
        case 'k':
            printf("Confirma salida? Ingrese s/n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }

            break;



        default:
            printf("Opcion invalida!!!\n");
        }
        system("pause");
    }
    while( seguir == 's');
    return 0;
}

 char menuOpciones()
{
    char opcion;
    printf("*** Bienvenido ***\n\n");
    printf("a_ Alta mascotas\n");
    printf("b_ Modificar mascota\n");
    printf("c_ Baja mascota\n");
    printf("d_ Listar mascotas\n");
    printf("e_ Listar tipos\n");
    printf("f_ Listar Colores\n");
    printf("g_ Listar Servicios\n");
    printf("h_ Alta Trabajo\n");
    printf("i_ Listar Trabajos\n");
    printf("j_ Informes mostrar color mas elegido\n");
    printf("k_ Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());
    return opcion;
}



