
#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED




typedef struct //color
{
    int id_Color;
    char nombreColor[20];
} eColor;



#endif // COLOR_H_INCLUDED



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int mostrarColores(eColor color[], int tamC);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarColor(eColor unColor, int t);




/** \brief valida el id de color
 *
 * \param color, array de color
 * \param int tamC, longitud del arrat
 * \return
 *
 */

int validarIdColor(eColor color[],int tamC,int id);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int obtenerDescripcionColor(eColor color[], int tamC,int id_color, char nombreColor[]);










