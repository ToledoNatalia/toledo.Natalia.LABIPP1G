#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED


typedef struct //marca
{
    int id_tipo;
    char descripcionT[20];
} eTipo;



#endif // TIPO_H_INCLUDED



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int mostrarTipos(eTipo tipo[], int tamT);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarTipo(eTipo unTipo, int t);



/** \brief valida el id de tipo
 *
 * \param tipo, array de tipo
 * \param tamT, longitud del array de tipo
 * \param
 * \return
 */

int validarIdTipo(eTipo tipo[],int tamT,int id);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int obtenerDescripcionTipo(eTipo tipoM[], int tamT, int id_tipo, char descripcionT[]);






