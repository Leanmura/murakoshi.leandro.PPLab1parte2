#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
} eMarca;

#endif // MARCA_H_INCLUDED

/** \brief Nos da la descripcion de una marca, pasandole un id de una marca
 *
 * \param idMarca int ID de la marca
 * \param listaM[] eMarca Vector de marcas
 * \param tamM int Tamanio del vector de marcas
 * \param marca[] char Variable donde nos va a devolver la descripcion de la marca
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int cargarDescripcionMarca(int idMarca, eMarca listaM[], int tamM, char marca[]);

/** \brief Muestra una marca
 *
 * \param marca eMarca Marca a mostrar
 * \return void
 *
 */
void mostrarMarca(eMarca marca);

/** \brief Muestra una lista de marcas
 *
 * \param listaM[] eMarca Vector de marcas
 * \param tam int Tamanio del vector de marcas
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int mostrarMarcas(eMarca marcas[], int tam);
