#include "mascotas.h"
#include "fecha.h"
#include "servicio.h"


#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED




typedef struct //trabajo
{
    int id_trabajo;
    int idMascota;
    int idServicio;
    eFecha fecha;
    int isEmpty;
} eTrabajo;



#endif // TRABAJO_H_INCLUDED


/** \brief
 *
 * \param mascota array de mascota
 * \param tam longitud del array de mascota
 * \param array de servicio
  * \param tamS longitud del array de servicio
 * \return
 *
 */

void mostrarTrabajo(eTrabajo unTrabajo, eMascota mascota[],int tam, eServicio servicio[], int tamS );


/** \brief
 *
 * \param array de mascota
 * \param longitud del array de mascota
  * \param
 * \return
 *
 */

int mostrarTrabajos(eTrabajo trabajos[],int tamTa, eMascota animal[], int tam,eServicio servicio[],int tamS);



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int inicializarTrabajos(eTrabajo trabajos[], int tamTa);


/** \brief busca un espacio libre en la matriz (isEmpty = 1)
 *
 * \param array de trabajo
 * \param tamaño del array
 * \return
 *
 */

int buscarTrabajoLibre(eTrabajo trabajos[], int tamTa);




/** \brief agregar en una lista existente de mascotas los valores recibidos como parámetros en la primera posición vacía
 *
 * \param array de mascota
 * \param array de servicio
 * \param longitud del array
 * \return
 *
 */
int altaTrabajo(eTrabajo trabajos[],int tamTa, eMascota animal[],int tam, eServicio servicio[],int tamS,eTipo tipo[], int tamT,eColor color[], int tamC, eCliente cliente[],int tamCl, int id_trabajo);

