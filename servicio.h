#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED



typedef struct
{
    int id_Servicio;
    char descripcionS[25];
    float precio;

}eServicio;


#endif // SERVICIO_H_INCLUDED


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarServicio(eServicio unServicio);


/** \brief
 *
 * \param array de servicio
 * \param longitud del array
 * \return
 *
 */

int mostrarServicios(eServicio servicio[], int tamS);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int obtenerDescripcionServicio(eServicio servicio[], int tamS,int id_servicio, char descripcionS[]);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int validarIdServicio(eServicio servicio[],int tamS,int id_Servicio);







