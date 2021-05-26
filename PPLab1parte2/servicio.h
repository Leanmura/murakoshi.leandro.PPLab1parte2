#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
} eServicio;


#endif // SERVICIO_H_INCLUDED

/** \brief Muestra una lista de los servicios
 *
 * \param servicios[] eServicio vector de servicios
 * \param tam int tamanio del vector
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int mostrarServicios(eServicio servicios[], int tam);

/** \brief Muestra un servicio
 *
 * \param servicio eServicio Servicio a mostrar
 * \return void
 *
 */
void mostrarServicio(eServicio servicio);

/** \brief Nos da la descripcion de un servicio, pasandole id de algun servicio
 *
 * \param idServicio int ID del servicio
 * \param listaS[] eServicio Vector de servicios
 * \param tamS int Tamanio del servicio
 * \param desc[] char Variable donde nos va a devolverla descripcion del servicio
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int cargarDescripcionServicio(int idServicio, eServicio listaS[], int tamS, char desc[]);

/** \brief Nos da el precio de un servicio, pasandole id de algun servicio
 *
 * \param idServicio int ID del servicio
 * \param listaS[] eServicio Vector de servicios
 * \param tamS int Tamanio del servicio
 * \param precio float* Puntero donde se devuelve el precio
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int cargarPrecioServicio(int idServicio, eServicio listaS[], int tamS, float *precio);
