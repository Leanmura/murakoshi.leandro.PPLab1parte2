#include "servicio.h"
#include "auto.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    char patente[20];
    int idServicio;
    eFecha fecha;
    int isEmpty;
} eTrabajo;

#endif // TRABAJO_H_INCLUDED

int inicializarTrabajos(eTrabajo lista[], int tam);

/** \brief Da de alta un trabajo
 *
 * \param lista[] eTrabajo Vector de trabajos
 * \param tam int Tamanio del vectorde trabajos
 * \param pNextId int* ID a adjuntarle al trabajo
 * \param listaS[] eServicio Vector de servicios
 * \param tamS int Tamanio del vector de servicios
 * \param lista[] eAuto Vector de autos
 * \param tamA int Tamanio del vector de autos
 * \param listaM[] eMarca Vector de Marcas
 * \param tamM int Tamanio del vector de marcas
 * \param listaC[] eColor Vector de colores
 * \param tamC int Tamanio del vetor de colores
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int altaTrabajo(eTrabajo lista[], int tam, int *pNextId, eServicio listaS[], int tamS, eAuto listaA[], int tamA, eMarca listaM[], int tamM, eColor listaC[], int tamC);

/** \brief Busca el primer espacio libre (.isEmpty =0)
 *
 * \param lista[] eTrabajo Vector de trabajos
 * \param tam int Tamanio del vectorde trabajos
 * \return int Retorna el indice de la posicion donde esta el primer espacio libre, o -1 si no hay o hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int buscarLibreTrabajo(eTrabajo lista[], int tam);


/** \brief Muestra una lista de trabajos
 *
 * \param lista[] eTrabajo Vector de trabajos
 * \param tam int Tamanio del vectorde trabajos
 * \param listaS[] eServicio Vector de servicios
 * \param tamS int Tamanio del vector de servicios
 * \return int  Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int mostrarTrabajos(eTrabajo lista[], int tam, eServicio listaS[], int tamS);

/** \brief Muestra un trabajo
 *
 * \param Trabajo eTrabajo Trabajo a mostrar
 * \param listaS[] eServicio Vector de servicios
 * \param tamS int Tamanio del vector de servicios
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int mostrarTrabajo(eTrabajo Trabajo, eServicio listaS[], int tamS);
