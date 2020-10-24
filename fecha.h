#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;


#endif // FECHA_H_INCLUDED



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarFecha(eFecha unaFecha);




/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int validarDia(int dia,int mes);



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int validarMes(int mes);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int validarAnio(int anio);

