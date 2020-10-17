
#ifndef MASCOTAS_H_
#define MASCOTAS_H_

typedef struct //fecha
{
    int dia;
    int mes;
    char anio;
} eFecha;

typedef struct //servicio
{
    int id;
    char descripcion[10][25];
    int precio;
} eServicio;

typedef struct //trabajo
{
    int id;
    int idmascota;
    int idServicio;
    int fecha;
} eTrabajo;

typedef struct //marca
{
    int id;
    char descripcion[20];
} etipo;

typedef struct //color
{
    int id;
    char nombreColor[20];
} eColor;

typedef struct //auto/tiene isEmpty
{
    int id;
    char nombre[20];
    int idTipo;
    etipo tipo;
    eColor color;
    int idColor;
    int edad;
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


/** \brief agregar en una lista existente de empleados los valores recibidos como parámetros en la primera posición vacía
 *
 * \param int tam longitud del array
 * \param
 * \return
 *
 */


int altaMascota( eMascota animal[], int tam,  etipo tipoM[], int tamT,eColor color[], int tamC, int id);



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int mostrarTipos(etipo tipo[], int tamT);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarTipo(etipo unTipo, int t);


/** \brief Muestra las opciones de los campos a modificar y devuelve la opción elegida
 *
 * \param int tam longitud del array
 * \param in id del array
 * \return La opción elegida
 *
 */


int modificarMascota(eMascota animal[], int tam, int id);

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



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int mostrarMascotas(eMascota animal[], int tam);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarMascota(eMascota unaMascota);


/** \brief Eliminar un auto por Id (poner la bandera isEmpty en 1)
 *
 * \param int tam longitud del array
 * \return int Devuelve (1) si Error [Longitud no válida o si no puede encontrar un empleado] - (0)
si el usuario no confirmó y 2 si está bien
 *
 */

int bajaMascota(eMascota animal[], int tam);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


int validarIdTipo(etipo tipo[],int tamT,int id);


/** \brief
 *
 * \param
 * \param
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



int buscarLibre(eMascota animal[], int tam);





int mostrarServicios(eServicio servicio[], int tamS);



int mostrarServicios(eServicio servicio[], int tamS);








