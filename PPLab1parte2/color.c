#include "color.h"

void mostrarColor(eColor color)
{
    printf("#%03d  %-10s \n", color.id, color.nombreColor);
}

int mostrarColores(eColor colores[], int tam)
{
    int todoOk = 0;
    if (colores != NULL && tam > 0)
    {
        printf("\n Lista de colores\n");
        printf(" ID   Descripcion\n");
        for (int i = 0; i < tam; i++)
        {
            mostrarColor(colores[i]);
        }
        printf("\n");
        todoOk=1;
    }
    return todoOk;
}

int cargarDescripcionColor(int idColor, eColor listaC[], int tamC, char desc[])
{
    int todoOk = 0;

    if (listaC != NULL && tamC > 0 && desc != NULL && idColor >= 5000 && idColor <= 5004)
    {
        for (int i = 0; i < tamC; i++)
        {
            if (idColor == listaC[i].id)
            {
                strcpy(desc, listaC[i].nombreColor);
                todoOk = 1;
                break;
            }
        }
    }

    return todoOk;
}
