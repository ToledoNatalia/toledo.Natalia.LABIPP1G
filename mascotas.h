
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
    char descripcion[25];
    int precio;
} eServicio;


typedef struct //marca
{
    int id_tipo;
    char descripcionT[20];
} eTipo;

typedef struct //color
{
    int id_Color;
    char nombreColor[20];
} eColor;

typedef struct //auto/tiene isEmpty
{
    int id;
    char nombre[20];
    int idTipo;
    eTipo tipo;
    eColor color;
    int idColor;
    int edad;
    int isEmpty;// 1 esta vacia 0 esta llena
} eMascota;

typedef struct //trabajo
{
    int id;
    int idmascota;
    int idServicio;
    int fecha;
} eTrabajo;



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


int altaMascota( eMascota animal[], int tam,  eTipo tipo[], int tamT,eColor color[], int tamC, int id);



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


/** \brief Muestra las opciones de los campos a modificar y devuelve la opción elegida
 *
 * \param int tam longitud del array
 * \param in id del array
 * \return La opción elegida
 *
 */


int modificarMascota(eMascota animal[], int tam, eColor color[],int tamC, eTipo tipo[], int tamT );

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


int mostrarMascotas(eMascota animal[], int tam, eColor color[],int tamC,eTipo tipo[], int tamT);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarMascota(eMascota unaMascota, eColor color[], eTipo tipo[], int tam_col, int tam_tipos);




/** \brief Eliminar un auto por Id (poner la bandera isEmpty en 1)
 *
 * \param int tam longitud del array
 * \return int Devuelve (1) si Error [Longitud no válida o si no puede encontrar un empleado] - (0)
si el usuario no confirmó y 2 si está bien
 *
 */

int bajaMascota(eMascota animal[], int tam, eColor color[],int tamC, eTipo tipo[], int tamT);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


int validarIdTipo(eTipo tipo[],int tamT,int id);


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





int obtenerDescripcionTipo(eTipo tipoM[], int tamT, int id_tipo, char descripcionT[]);



int obtenerDescripcionColor(eColor color[], int tamC,int id_color, char nombreColor[]);
