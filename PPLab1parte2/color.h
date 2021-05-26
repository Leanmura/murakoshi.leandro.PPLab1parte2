#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED


typedef struct
{
    int id;
    char nombreColor[20];
} eColor;

#endif // COLOR_H_INCLUDED

/** \brief Nos da la descripcion de un color, pasandole un id de un color
 *
 * \param idColor int ID del color
 * \param listaC[] eColor Vector de colores
 * \param tamC int Tamanio del vector de colores
 * \param desc[] char Varaibel donde nos va a devolverla la descripcion del color
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int cargarDescripcionColor(int idColor, eColor listaC[], int tamC, char desc[]);

/** \brief Muestra una lista de colores
 *
 * \param listaC[] eColor Vector de colores
 * \param tam int Tamanio del vector de colores
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int mostrarColores(eColor colores[], int tam);

/** \brief Muestra un color
 *
 * \param color eColor Color a mostrar
 * \return void
 *
 */
void mostrarColor(eColor color);
