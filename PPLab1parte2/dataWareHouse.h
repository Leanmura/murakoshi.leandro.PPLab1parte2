#include "fecha.h"
#include "auto.h"
#include "trabajo.h"

#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED

//int hardcodearEmpleados(eEmpleado lista[], int tam, int cant, int *pLegajo);

//int hardcodearAlmuerzos(eAlmuerzo lista[], int tam, int cant, int *pId);

/** \brief Hardcodea x cantidad de autos, en el array lista[]
 *
 * \param lista[] eAuto Array donde se van a hardcodear los autos
 * \param tam int Tamanio del array
 * \param cant int Cantidad de autos a harcodear
 * \param pId int* Puntero al valor del Id a asignar
 * \return int Retorna la cantidad de autos hardcodeados, o 0 si hubo algun error(punteros a NULL o tamanios<=0)
 *
 */
int hardcodearAutos(eAuto lista[], int tam, int cant, int *pId);

int hardcodearTrabajos(eTrabajo lista[],int tam, int cant, int *pId);
#endif // DATAWAREHOUSE_H_INCLUDED
