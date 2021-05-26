#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"
#include "color.h"
#include "inputs_lean.h"
#include "menus.h"

#define INTENTOS 3

#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct
{
    int id;
    char patente[20];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
} eAuto;

#endif // AUTO_H_INCLUDED

/** \brief Inicializa todo los lugares del array como vacios (.isEmpty = 1)
 *
 * \param lista[] eAuto Vector de autos
 * \param tam int Tamanio del vector
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int inicializarAutos(eAuto lista[], int tam);

/** \brief Busca el primer espacio libre (.isEmpty =0)
 *
 * \param lista[] eAuto Vector de autos
 * \param tam int Tamanio del vector
 * \return int Retorna el indice de la posicion donde esta el primer espacio libre, o -1 si no hay o hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int buscarLibre(eAuto lista[], int tam);

/** \brief Da de alta un auto
 *
 * \param lista[] eAuto Vector de autos
 * \param tam int Tamanio del vector
 * \param pNextId int* ID a adjuntarle al auto
 * \param listaM[] eMarca Vector de Marcas
 * \param tamM int Tamanio del vector de marcas
 * \param listaC[] eColor Vector de colores
 * \param tamC int Tamanio del vetor de colores
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int altaAuto(eAuto lista[], int tam, int *pNextId, eMarca listaM[], int tamM, eColor listaC[], int tamC);

/** \brief Ordena el vector de autos por marca alfabeticamente y por patente ascendente
 *
 * \param lista[] eAuto Vector de autos
 * \param tam int Tamanio del vector
 * \param listaM[] eMarca Vector de Marcas
 * \param tamM int Tamanio del vector de marcas
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int ordenarAutosMarcaPatente(eAuto listaA[], int tamA, eMarca listaM[], int tamM);

/** \brief Muestra un auto
 *
 * \param Auto eAuto Auto a mostrar
 * \param listaM[] eMarca Vector de Marcas
 * \param tamM int Tamanio del vector de marcas
 * \param listaC[] eColor Vector de colores
 * \param tamC int Tamanio del vetor de colores
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int mostrarAuto(eAuto Auto, eMarca listaM[], int tamM, eColor listaC[], int tamC);

/** \brief Muestrar una lista de autos
 *
 * \param lista[] eAuto Vector de autos
 * \param tam int Tamanio del vector
 * \param pNextId int* ID a adjuntarle al auto
 * \param listaM[] eMarca Vector de Marcas
 * \param tamM int Tamanio del vector de marcas
 * \param listaC[] eColor Vector de colores
 * \param tamC int Tamanio del vetor de colores
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int mostrarAutos(eAuto lista[], int tam, eMarca listaM[], int tamM, eColor listaC[], int tamC);

/** \brief Busca un auto por su patente
 *
 * \param lista[] eAuto Vector de autos
 * \param tam int Tamanio del vector
 * \param patente[] char Patente a buscar
 * \return int
 *
 */
int buscarAuto(eAuto lista[], int tam, char patente[]);

/** \brief Modifica un campo del auto (marca o color)
 *
 * \param lista[] eAuto Vector de autos
 * \param tam int Tamanio del vector
 * \param listaM[] eMarca Vector de Marcas
 * \param tamM int Tamanio del vector de marcas
 * \param listaC[] eColor Vector de colores
 * \param tamC int Tamanio del vetor de colores
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0 o ingreso mal de datos)
 *
 */
int modificarAuto(eAuto lista[], int tam, eMarca listaM[], int tamM, eColor listaC[], int tamC);

/** \brief Realiza la baja logica de un auto (.isEmpty = 1)
 *
 * \param lista[] eAuto Vector de autos
 * \param tam int Tamanio del vector
 * \param listaM[] eMarca Vector de Marcas
 * \param tamM int Tamanio del vector de marcas
 * \param listaC[] eColor Vector de colores
 * \param tamC int Tamanio del vetor de colores
 * \return int Retorna 1 si esta todoOk, o 0 si hubo algun error(punteros a NULL o tamanios<=0 o ingreso mal de datos)
 *
 */
int bajaAuto(eAuto lista[], int tam, eMarca listaM[], int tamM, eColor listaC[], int tamC);

