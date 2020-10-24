#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED


typedef struct{

    int id_cliente;
    char descripcionCl[20];


}eCliente;



#endif // CLIENTE_H_INCLUDED



/** \brief
 *
 * \param cliente array de cliente
 * \param longitud del array
 * \return
 *
 */

int mostrarClientes(eCliente cliente[], int tamCl);


/** \brief
 *
 * \param un cliente a mostrar
 * \param
 * \return
 *
 */

void mostrarCliente(eCliente unCliente, int t);



/** \brief valida el id de cliente
 *
 * \param cliente, array de cliente
 * \param tamCl, longitud del array de cliente
 * \param
 * \return
 */

int validarIdCliente(eCliente cliente[],int tamCl,int id);


/** \brief
 *
 * \param tamCL longitud del array
 * \param id cliente
  \param
 * \return
 *
 */

int obtenerDescripcionCliente(eCliente cliente[], int tamCl, int id_Cliente, char descripcionCl[]);






