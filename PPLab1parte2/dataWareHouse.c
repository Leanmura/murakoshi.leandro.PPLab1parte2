#include "dataWareHouse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char nombres[10][20]={
    "Candela",
    "Juan",
    "Valentina",
    "Abril",
    "Leo",
    "Sofia",
    "Micaela",
    "Milena",
    "Fabricio",
    "Leandro"
};

char sexos[10]={'f','m','f','f','m','f','f','f','m','m'};

eFecha fechas[10] = {
    {1, 3, 2004},
    {2, 3, 2005},
    {12, 4, 1990},
    {15, 6, 2000},
    {27, 2, 1999},
    {12, 4, 1990},
    {15, 6, 2000},
    {27, 2, 1999},
    {12, 4, 1990},
    {15, 6, 2000}

};

eFecha fechas2[] = {
    {1,1,2021},//6
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {2,1,2021},//5
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {3,1,2021}, // 6
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {4,1,2021}, //6
    {4,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021}
};

int idColor[]={5000,5001,5002,5003,5004,5004,5002,5003,5003,5001};

int idMarca[]={1000,1001,1002,1003,1004,1002,1001,1000,1003,1002};

int idServicio[]={20000,20001,20002,20002,20002,20001,20000,20000,20002,20001};

int anio[] = {1990, 1992, 1999, 2000, 2003,2001,2000,1950, 2019,1950};

char patente[][20] = {
    "IHG579",
    "ABC123",
    "ABC231",
    "DFK432",
    "LED456",
    "POR432",
    "LFO902",
    "TYF342",
    "DFK145",
    "ERT573"
};

char patente2[][20] = {
    "IHG579",
    "ABC123",
    "ABC231",
    "DFK432",
    "IHG579",
    "ABC123",
    "ABC231",
    "DFK432",
    "IHG579",
    "ABC123",
    "ABC231",
    "DFK432",
};

int hardcodearAutos(eAuto lista[], int tam, int cant, int *pId)
{
    int cantidad = 0;
    if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        for(int i=0; i<cant; i++)
        {
            lista[i].id = *pId;
            (*pId)++;
            lista[i].idColor = idColor[i];
            lista[i].idMarca = idMarca[i];
            lista[i].modelo = anio[i];
            strcpy(lista[i].patente, patente[i]);
            lista[i].isEmpty = 0;
            cantidad++;
        }

    }
    return cantidad;
}

int hardcodearTrabajos(eTrabajo lista[],int tam, int cant, int *pId)
{
    int cantidad = 0;
    if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        for(int i=0; i<cant; i++)
        {
            lista[i].fecha = fechas2[i];
            lista[i].id = *pId;
            (*pId)++;
            lista[i].idServicio = idServicio[i];
            strcpy(lista[i].patente, patente2[i]);
            lista[i].isEmpty = 0;
            cantidad++;
        }

    }
    return cantidad;
}
