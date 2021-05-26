#include "trabajo.h"

int inicializarTrabajos(eTrabajo lista[], int tam)
{
    int todoOk = 0;
    if (lista != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibreTrabajo(eTrabajo lista[], int tam)
{
    int indice = -1;
    if (lista != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (lista[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int altaTrabajo(eTrabajo lista[], int tam, int *pNextId, eServicio listaS[], int tamS, eAuto listaA[], int tamA, eMarca listaM[], int tamM, eColor listaC[], int tamC)
{
    int todoOk = 0;
    int indice;
    eTrabajo auxTrabajo;
    if (lista != NULL && tam >= 0 && pNextId != NULL)
    {
        indice = buscarLibreTrabajo(lista, tam);
        if (indice != -1)
        {
            mostrarAutos(listaA, tamA, listaM, tamM, listaC, tamC);
            printf("Ingrese Patente del auto: ");
            scanf("%s", auxTrabajo.patente);
            while (buscarAuto(listaA, tamA, auxTrabajo.patente) == -1)
            {
                printf("Error. ");
                printf("Ingrese Patente del auto: ");
                scanf("%s", auxTrabajo.patente);
                fflush(stdin);
            }
            mostrarServicios(listaS, tamS);
            if (getInt(&auxTrabajo.idServicio, 20000, 20003, INTENTOS, "Ingrese id de la Marca: ", "Error. "))
            {
                eFecha fechaHoy = {19, 05, 2021 };
                eFecha fechaMin = {01, 01, 2000};
                if (getFecha(&auxTrabajo.fecha, fechaHoy, fechaMin, 3, "Ingresar la fecha de hoy(DD/MM/AAAA): ", "Error. ") == 1)
                {
                    auxTrabajo.isEmpty = 0;
                    auxTrabajo.id = *pNextId;
                    (*pNextId)++;

                    lista[indice] = auxTrabajo;
                    todoOk = 1;
                }
            }
        }
    }
    else
    {
        printf("No hay lugar disponible\n");
    }
    return todoOk;
}

int mostrarTrabajo(eTrabajo Trabajo, eServicio listaS[], int tamS)
{
    char descripcionS[20];
    int todoOk = 0;
    if (listaS != NULL && tamS > 0)
    {

        if (cargarDescripcionServicio(Trabajo.idServicio, listaS, tamS, descripcionS))
        {
            printf(" %-8s %-10s %02d/%02d/%04d \n", Trabajo.patente, descripcionS, Trabajo.fecha.dia, Trabajo.fecha.mes, Trabajo.fecha.anio);
            todoOk = 1;
        }
    }
    return todoOk;
}

int mostrarTrabajos(eTrabajo lista[], int tam, eServicio listaS[], int tamS)
{
    int todoOk = 0;
    int flagIsEmpty = 1;
    if (listaS != NULL && tamS > 0 && lista != NULL && tam > 0)
    {
        printf("Patente   Servicio   Fecha \n");
        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty)
            {
                mostrarTrabajo(lista[i], listaS, tamS);
                flagIsEmpty = 0;
            }
        }
        if (flagIsEmpty)
        {
            printf("No hay Trabajos.\n");
        }
        printf("\n");
        todoOk = 1;
    }

    return todoOk;
}
