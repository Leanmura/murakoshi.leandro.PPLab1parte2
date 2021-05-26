#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs_lean.h"
#include "auto.h"
#include "marca.h"
#include "color.h"
#include "trabajo.h"
#include "servicio.h"

#define INTENTOS 3
#define FECHA_ACTUAL 26,05,2021
#define FECHA_MIN 01, 01, 2000

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

/** \brief Lista los autos por marca
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
int listarAutosPorMarca(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM);

/** \brief Nos muestra la cantidad de autos de X color y X marca
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

/** \brief Nos muestra los trabajos realizados a un auto seleccionado por el usuario
 *
 * \param listaT[] eTrabajo Vector de trabajos
 * \param tamT int Tamanio del vector de trabajos
 * \param listaS[] eServicio Vector de servicios
 * \param tamS int Tamanio del vector de servicios
 * \param listaA[] eAuto Vector de autos
 * \param tamA int Tamanio del vector de autos
 * \param listaC[] eColor Vector de colores
 * \param tamC int Tamanio del vedctor de colores
 * \param listaM[] eMarca Vector de marcas
 * \param tamM int Tamanio del vector de marcas
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int trabajosXAuto(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM);

/** \brief Muestra el importe total que debe un auto seleccionado por el usuario
 *
 * \param listaT[] eTrabajo Vector de trabajos
 * \param tamT int Tamanio del vector de trabajos
 * \param listaS[] eServicio Vector de servicios
 * \param tamS int Tamanio del vector de servicios
 * \param listaA[] eAuto Vector de autos
 * \param tamA int Tamanio del vector de autos
 * \param listaC[] eColor Vector de colores
 * \param tamC int Tamanio del vedctor de colores
 * \param listaM[] eMarca Vector de marcas
 * \param tamM int Tamanio del vector de marcas
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int totalImporteXAuto(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM);

/** \brief Muestra los autos a los que se le hizo el servicio seleccionado por el usuario
 *
 * \param listaT[] eTrabajo Vector de trabajos
 * \param tamT int Tamanio del vector de trabajos
 * \param listaS[] eServicio Vector de servicios
 * \param tamS int Tamanio del vector de servicios
 * \param listaA[] eAuto Vector de autos
 * \param tamA int Tamanio del vector de autos
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int autosXServicio(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eAuto listaA[], int tamA);

/** \brief Muestra los servicios realizados en una fecha ingresada por el usuario
 *
 * \param listaT[] eTrabajo Vector de trabajos
 * \param tamT int Tamanio del vector de trabajos
 * \param listaS[] eServicio Vector de servicios
 * \param tamS int Tamanio del vector de servicios
 * \param listaA[] eAuto Vector de autos
 * \param tamA int Tamanio del vector de autos
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int serviciosXFecha(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eAuto listaA[], int tamA);
