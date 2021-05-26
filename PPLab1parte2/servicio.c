#include "servicio.h"

void mostrarServicio(eServicio servicio)
{
    printf("#%03d  %-10s %.2f\n", servicio.id, servicio.descripcion, servicio.precio);
}

int mostrarServicios(eServicio servicios[], int tam)
{
    int todoOk = 0;
    if (servicios != NULL && tam > 0)
    {
        printf("\n--- Lista de servicios ---\n");
        printf(" ID   Descripcion   Precio\n");
        for (int i = 0; i < tam; i++)
        {
            mostrarServicio(servicios[i]);
        }
        printf("\n");
        todoOk =1;
    }
    return todoOk;
}

int cargarDescripcionServicio(int idServicio, eServicio listaS[], int tamS, char desc[])
{
    int todoOk = 0;

    if (listaS != NULL && tamS > 0 && desc != NULL && idServicio >= 20000 && idServicio <= 20003)
    {
        for (int i = 0; i < tamS; i++)
        {
            if (idServicio == listaS[i].id)
            {
                strcpy(desc, listaS[i].descripcion);
                todoOk = 1;
                break;
            }
        }
    }

    return todoOk;
}
