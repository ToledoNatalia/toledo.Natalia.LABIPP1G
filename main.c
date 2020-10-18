#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mascotas.h"
#include "validaciones.h"

#define TAM 10
#define TAM_C 5
#define TAM_T 5
#define TAM_S 3



char menuOpciones();
char menuModificacion();


int main()
{
    char seguir = 's';
    char confirma;
    int idParam;
    int flagOpcion=0;
    eMascota mascota[TAM];
    eTipo datosTipo [20]= {{1000,"Ave"},{1001,"Perro"},{1002,"Gato"},{1003,"Roedor"},{1004,"Pez"},};
    eColor datosColor [20]= { {5000,"Negro"}, {5001,"Blanco"}, {5002,"Gris"}, {5003,"Rojo"}, {5004,"Azul"} };
    eServicio  datosServicio[20]={ {20000,"Corte"}, {20001,"Castrado"}, {20002,"Desparacitado"} };
    int rta;

    int proximoIdMascota=0001;

    if(inicializarMascotas(mascota, TAM)==0)
    {
        printf("Mascota inicializadas con exito!");
    }
    else
    {
        printf("Ha ocurrido un problema al inicializar mascotas");
    }

    do
    {

        system("cls");
        switch(menuOpciones())
        {

        case 'a':
            if(altaMascota(mascota,TAM,datosTipo,TAM_T,datosColor,TAM_C,proximoIdMascota) == 0)
            {
                proximoIdMascota++;
                printf("ALTA EXITOSA!\n");
                flagOpcion=1;
            }
            else
            {
                printf("Problema para realizar el alta\n\n");
            }


            break;
        case 'b':

            if(flagOpcion==1)
            {
                printf("   ***MODIFICAR  MASCOTA***\n\n");
                mostrarMascotas(mascota, TAM,datosColor,TAM_C, datosTipo,TAM_T);
                idParam=getInt("Ingrese Id de la mascota que desea modificar :","ERROR\nEnter ID nuevamente:");
                switch(modificarMascota(mascota,TAM,datosColor,TAM_C,datosTipo,TAM_T))
                {
                case -1:
                    printf("\n no se pudo encontrar mascota\n\n");
                    break;
                case 0:
                    printf("\nOperacion Cancelada\n\n");//the user didn't confirm
                    break;
                default:
                    printf("\n modificacion exitosa!\n\n");
                    break;
                }
            }

            break;
        case 'c':

            rta= bajaMascota(mascota,TAM,datosColor,TAM_C,datosTipo,TAM_T);

            if( rta == 0)
            {
                printf("Baja exitosa\n");
            }
            else if(rta == 2)
            {
                printf("Baja cancelada por usuario\n");
            }
            else
            {
                printf("Se ha producido un error en la baja\n");
            }
            break;
        case 'd':
          mostrarMascotas(mascota,TAM,datosColor,TAM_C,datosTipo,TAM_T);
            break;
        case 'e':
            mostrarTipos(datosTipo, TAM_T);

            break;
        case 'f':

            mostrarColores(datosColor,TAM_C);
            break;
        case 'g':
            mostrarServicios(datosServicio, TAM_S);

            break;
        case 'h':
            break;
        case 'i':
            break;
        case 'j':
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
    printf("j_ Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());
    return opcion;
}


char menuModificacion()
{
    char opcion;

    system("cls");
    printf("   ***MENU MODIFICACION***\n\n");
    printf("a. Modificacion  tipo\n");
    printf("b. Modificacion edad\n");
    printf("c. Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());


    return opcion;
}

