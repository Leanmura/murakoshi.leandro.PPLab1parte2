#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs_lean.h"
#include "auto.h"
#include "marca.h"
#include "color.h"

#define INTENTOS 3

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

/** \brief Lista los autos de X color
 *
 * \param listaA[] eAuto Vector de autos
 * \param tamA int Tamanio del vector de autos
 * \param listaC[] eColor Vector de colores
 * \param tamC int Tamanio del vedctor de colores
 * \param listaM[] eMarca Vector de marcas
 * \param tamM int Tamanio del vector de marcas
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int listarAutosUnColor(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM);

/** \brief Lista los autos de X marca
 *
 * \param listaA[] eAuto Vector de autos
 * \param tamA int Tamanio del vector de autos
 * \param listaC[] eColor Vector de colores
 * \param tamC int Tamanio del vedctor de colores
 * \param listaM[] eMarca Vector de marcas
 * \param tamM int Tamanio del vector de marcas
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int listarAutosUnaMarca(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM);

/** \brief Lista los autos que tienen el modelo mas viejo
 *
 * \param listaA[] eAuto Vector de autos
 * \param tamA int Tamanio del vector de autos
 * \param listaC[] eColor Vector de colores
 * \param tamC int Tamanio del vedctor de colores
 * \param listaM[] eMarca Vector de marcas
 * \param tamM int Tamanio del vector de marcas
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int listarAutosModeloMasViejo(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM);

/** \brief Lista los autos por color alfabeticamente
 *
 * \param listaA[] eAuto Vector de autos
 * \param tamA int Tamanio del vector de autos
 * \param listaC[] eColor Vector de colores
 * \param tamC int Tamanio del vedctor de colores
 * \param listaM[] eMarca Vector de marcas
 * \param tamM int Tamanio del vector de marcas
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int listarAutosPorColor(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM);

/** \brief Nos muesta la cantidad de autos de X color y X marca
 *
 * \param listaA[] eAuto Vector de autos
 * \param tamA int Tamanio del vector de autos
 * \param listaC[] eColor Vector de colores
 * \param tamC int Tamanio del vedctor de colores
 * \param listaM[] eMarca Vector de marcas
 * \param tamM int Tamanio del vector de marcas
 * \param idMarca int ID de la marca que se quiere contar
 * \param idColor int ID del color que se quiere contar
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int cantidadAutosMarcaColor(eAuto listaA[], int tamA, eColor listaC[],int tamC, eMarca listaM[], int tamM,  int idMarca, int idColor);

/** \brief Nos muestra cual es el color/es con la mayor cantidad de autos
 *
 * \param listaA[] eAuto Vector de autos
 * \param tamA int Tamanio del vector de autos
 * \param listaC[] eColor Vector de colores
 * \param tamC int Tamanio del vedctor de colores
 * \param listaM[] eMarca Vector de marcas
 * \param tamM int Tamanio del vector de marcas
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int colorMasElegidoPorClientes(eAuto listaA[], int tamA, eColor listaC[],int tamC, eMarca listaM[], int tamM);


/** \brief Nos muestra cual es la marca/s con la mayor cantidad de autos
 *
 * \param listaA[] eAuto Vector de autos
 * \param tamA int Tamanio del vector de autos
 * \param listaC[] eColor Vector de colores
 * \param tamC int Tamanio del vedctor de colores
 * \param listaM[] eMarca Vector de marcas
 * \param tamM int Tamanio del vector de marcas
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int marcaMasElegidaPorClientes(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM);
