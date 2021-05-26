#include "marca.h"

int cargarDescripcionMarca(int idMarca, eMarca listaM[], int tamM, char marca[])
{
    int todoOk = 0;
    if (listaM != NULL && tamM > 0 && marca != NULL && idMarca >= 1000 && idMarca <= 1004)
    {
        for (int i = 0; i < tamM; i++)
        {
            if (idMarca == listaM[i].id)
            {
                strcpy(marca, listaM[i].descripcion);
                todoOk = 1;
            }
        }
        return todoOk;
    }
    return todoOk;
}


void mostrarMarca(eMarca marca)
{
    printf("#%03d  %-10s \n", marca.id, marca.descripcion);
}

int mostrarMarcas(eMarca marcas[], int tam)
{
    int todoOk = 0;
    if (marcas != NULL && tam > 0)
    {
        printf("\n Lista de marcas \n");
        printf(" ID   Descripcion\n");
        for (int i = 0; i < tam; i++)
        {
            mostrarMarca(marcas[i]);
        }
        printf("\n");
        todoOk =1;
    }
    return todoOk;
}
