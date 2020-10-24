
#include "tipo.h"
#include "color.h"
#include "cliente.h"

#ifndef MASCOTAS_H_
#define MASCOTAS_H_



typedef struct //auto/tiene isEmpty
{
    int id;
    char nombre[20];
    int idTipo;
    eTipo tipo;
    eColor color;
    int idColor;
    int edad;
    int idCliente;
    int isEmpty;// 1 esta vacia 0 esta llena
} eMascota;



#endif /* MASCOTAS_H_ */


/** \brief Para indicar que todas las posiciones de la matriz están vacías,
 *
 * \param int tam longitud del array
 * \return int Devuelve (1) si Error [longitud no válida] - (0) si está bien
 *
 */

int inicializarMascotas(eMascota animal[], int tam);


/** \brief agregar en una lista existente de mascotas los valores recibidos como parámetros en la primera posición vacía
 *
 * \param int tam longitud del array
 * \param
 * \return
 *
 */

int altaMascota( eMascota animal[], int tam,eTipo tipo[], int tamT,eColor color[], int tamC, eCliente cliente[],int tamCl,int id);



/** \brief Muestra las opciones de los campos a modificar y devuelve la opción elegida
 *
 * \param int tam longitud del array
 * \param color array de color
 * \param int tamC longitud del array de color
 * \param tipo array de tipo
 * \param int tamT longitud del array de tipo
 * \param cliente array de cliente
 * \param tamcl lingitud del array
 * \param in id del array
 * \return La opción elegida
 *
 */

int modificarMascota(eMascota animal[],int tam ,eTipo tipo[], int tamT,eColor color [],int tamC ,eCliente cliente[], int tamCl, int id );



/** \brief Muestra las opciones de los campos a modificar y devuelve la opción elegida
 *
 * \return La opcion elegida
 *
 */

char menuModificacion();



/** \brief
 * \param  animal , array de mascotas
 * \param int tam longitud del array
 * \param color , array de color
 * \param int tamC longitud del array de color
 * \param tipo ,array de tipo
 * \param int tamT longitud del array de tipo
 * \return
 *
 */

int mostrarMascotas(eMascota animal[], int tam, eColor color[],int tamC, eTipo tipo[], int tamT,eCliente cliente[],int tamCl);


/** \brief muestra una mascota
 *
 * \param color array de color
 * \param  tipo array de tipo
 * \return  mascota a mostrar
 */

void mostrarMascota(eMascota unaMascota, eColor color[],int tamC, eTipo tipo[], int tamT , eCliente cliente[], int tamcl);



/** \brief Eliminar una mascota por Id (poner la bandera isEmpty en 1)
 *
 * \param int tam longitud del array
 * \return int Devuelve (1) si Error [Longitud no válida o si no puede encontrar un empleado] - (0)
    si el usuario no confirmó y 2 si está bien
 *
 */

int bajaMascota(eMascota animal[], int tam, eColor color[],int tamC, eTipo tipo[], int tamT, eCliente cliente[], int tamcl);




/** \brief Busca un espacio libre en la matriz (isEmpty = 1)
 *
 * \param animal array de mascota
 * \param int tam longitud del array
 * \return El índice si hay posiciones libres o 0 si no las hay
 *
 */

int buscarLibre(eMascota animal[], int tam);



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int validarIdMascota(eMascota mascota[],int tam,int id);




/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int obtenerNombreMascota(eMascota mascota[],int tam,int id,char nombre[]);


/** \brief muestra el menu de opciones
 *
 * \return la opcion elegida
 *
 */
char menuOrdenamiento();


/** \brief Ordene los elementos en la matriz mascotas, el orden de los argumentos indicar orden ARRIBA o ABAJO
 *
 * \param int tam longitud del array
 * \param orden ascendente o descendente
 * \return int Devuelve (1) si hay error [longitud no válida ] - (0) si está bien
 *
 */

int ordenarMascotasXNombre(eMascota animal[], int tam,int orden);

/** \brief Ordene los elementos en la matriz mascotas, el orden de los argumentos indicar orden ARRIBA o ABAJO
 *
 *
 * \param int tam longitud del array
 * \param orden ascendente o descendente
 * \return int Devuelve (1) si hay error [longitud no válida ] - (0) si está bien
 *
 */

int ordenarMascotasXTipo(eMascota animal[], int tam,int orden);


/** \brief Muestra las opciones del menú  y devuelve la opción elegida
 *
 * \param animal , array de mascotas
 * \param color, array de color
 * \param int tamC, longitud del array de color
 * \param tipo, array de tipo
 * \param int tamT , longitud del array de tipo
 * \return
 *
 */

void reportar(eMascota animal[],int tam,eColor color[],int tamC,eTipo tipo[],int tamT,eCliente cliente[],int tamCl);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


int colorMascotaFavorito( eMascota animal[],int tam,eColor color[], int tamC);
