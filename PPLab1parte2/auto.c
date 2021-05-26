#include "auto.h"

int inicializarAutos(eAuto lista[], int tam)
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

int buscarLibre(eAuto lista[], int tam)
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

int altaAuto(eAuto lista[], int tam, int *pNextId, eMarca listaM[], int tamM, eColor listaC[], int tamC)
{
    int todoOk = 0;
    int indice;
    eAuto auxAuto;
    if (lista != NULL && tam >= 0 && pNextId != NULL)
    {
        indice = buscarLibre(lista, tam);
        if (indice != -1)
        {
            if (getString(auxAuto.patente, 20, INTENTOS, "Ingrese patente: ", "Error. "))
            {
                mostrarMarcas(listaM, tamM);
                if (getInt(&auxAuto.idMarca, 1000, 1004, INTENTOS, "Ingrese id de la Marca: ", "Error. "))
                {
                    mostrarColores(listaC, tamC);
                    if (getInt(&auxAuto.idColor, 5000, 5004, INTENTOS, "Ingrese idColor: ", "Error. "))
                    {
                        if (getInt(&auxAuto.modelo, 1500, 2021, INTENTOS, "Ingrese modelo: ", "Error. "))
                        {
                            auxAuto.isEmpty = 0;
                            auxAuto.id = *pNextId;
                            (*pNextId)++;

                            lista[indice] = auxAuto;
                            todoOk = 1;
                        }
                    }
                }
            }
        }
        else
        {
            printf("No hay lugar disponible\n");
        }
    }
    return todoOk;
}

int ordenarAutosMarcaPatente(eAuto listaA[], int tamA, eMarca listaM[], int tamM)
{
    char marca1[20];
    char marca2[20];
    eAuto auxAuto;
    int todoOk = 0;

    if(listaA != NULL && tamA > 0 && listaM != NULL && tamM >0)
    {
        for(int i=0; i<tamA-1; i++)
        {
            for(int j=i; j<tamA; j++)
            {
                cargarDescripcionMarca(listaA[i].idMarca, listaM, tamM, marca1);
                cargarDescripcionMarca(listaA[j].idMarca, listaM, tamM, marca2);
                if(strcmp(marca1,marca2) > 0 || (strcmp(marca1,marca2) == 0 && strcmp(listaA[i].patente, listaA[j].patente) > 0))
                {
                    auxAuto = listaA[i];
                    listaA[i] = listaA[j];
                    listaA[j] = auxAuto;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarAuto(eAuto Auto, eMarca listaM[], int tamM, eColor listaC[], int tamC)
{
    char descripcionC[20];
    char marca[20];
    int todoOk = 0;
    if (listaM != NULL && listaC != NULL && tamC > 0 && tamM > 0)
    {
        if (cargarDescripcionMarca(Auto.idMarca, listaM, tamM, marca))
        {
            if (cargarDescripcionColor(Auto.idColor, listaC, tamC, descripcionC))
            {
                printf(" %-8s   %-10s  %-10s  %d  \n", Auto.patente, marca, descripcionC, Auto.modelo);
                todoOk = 1;
            }
        }
    }
    return todoOk;
}

int mostrarAutos(eAuto lista[], int tam, eMarca listaM[], int tamM, eColor listaC[], int tamC)
{
    int todoOk = 0;
    int flagIsEmpty = 1;
    if (listaC != NULL && tamC > 0 && listaM != NULL && tamM > 0 && lista != NULL && tam > 0)
    {
        printf("------------- LISTA DE AUTOS -------------\n");
        printf("PATENTE     MARCA       COLOR      MODELO \n");
        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty)
            {
                mostrarAuto(lista[i], listaM, tamM, listaC, tamC);
                flagIsEmpty = 0;
            }
        }
        if (flagIsEmpty)
        {
            printf("No hay autos.\n");
        }
        printf("\n");
        todoOk = 1;
    }

    return todoOk;
}

int buscarAuto(eAuto lista[], int tam, char patente[])
{
    int indice = -1;

    if (lista != NULL && tam > 0 && patente != NULL)
    {
        for (int i = 0; i < tam; i++)
        {
            if (strcmp(lista[i].patente, patente) == 0 && !lista[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int modificarAuto(eAuto lista[], int tam, eMarca listaM[], int tamM, eColor listaC[], int tamC)
{
    char patente[20];
    int indice;
    int todoOk = 0;
    char confirmacion;
    int opcion = 0;
    eAuto auxAuto;

    if (lista != NULL && tam >= 0)
    {
        mostrarAutos(lista, tam, listaM, tamM, listaC, tamC);
        if (getString(patente, 20, 3, "Ingrese la patente del Auto: ", "Error. "))
        {
            indice = buscarAuto(lista, tam, patente);
            if (indice != -1)
            {
                printf("  patente   Marca   Color Modelo \n");
                mostrarAuto(lista[indice], listaM, tamM, listaC, tamC);
                printf("\nEsta seguro que quiere modificar esta patente? [s/n] ");
                fflush(stdin);
                scanf("%c", &confirmacion);
                if (confirmacion == 's')
                {
                    menuModificar();
                    printf("Patente    Marca   Color Modelo\n");
                    mostrarAuto(lista[indice], listaM, tamM, listaC, tamC);

                    printf("\n");
                    getInt(&opcion, 1,3,INTENTOS,"Ingrese lo que desea modificar: ", "Error. ");


                    switch (opcion)
                    {
                    case 1:
                        printf("ID de la marca a modificar: %d\n", lista[indice].idMarca);
                        mostrarMarcas(listaM, tamM);
                        if (getInt(&auxAuto.idMarca, 1000, 1004, INTENTOS, "Ingrese id de la Marca: ", "Error. "))
                        {
                            printf("Esta seguro que quiere cambiar '%d' por '%d'? [s/n] ", lista[indice].idMarca, auxAuto.idMarca);
                            fflush(stdin);
                            scanf("%c", &confirmacion);
                            if (confirmacion == 's')
                            {
                                lista[indice].idMarca = auxAuto.idMarca;
                                printf("Marca modificado con exito!\n\n");
                                todoOk = 1;
                            }
                        }
                        break;

                    case 2:
                        printf("Modelo a modificar: %d\n", lista[indice].modelo);

                        if (getInt(&auxAuto.modelo, 1500, 2021, INTENTOS, "Ingrese modelo: ", "Error. "))
                        {
                            printf("Esta seguro que quiere cambiar '%d' por '%d'? ", lista[indice].modelo, auxAuto.modelo);
                            fflush(stdin);
                            scanf("%c", &confirmacion);
                            if (confirmacion == 's')
                            {
                                lista[indice].modelo = auxAuto.modelo;
                                printf("Modelo modificado con exito!\n\n");
                                todoOk = 1;
                            }
                        }
                        break;
                    }
                    if (confirmacion != 's')
                    {
                        printf("Modificacion abortada.\n");
                    }
                }
                else
                {
                    printf("Operacion abortada.\n");
                }
            }
        }
        else
        {
            printf("No se encontro el id.\n");
        }
    }

    return todoOk;
}


int bajaAuto(eAuto lista[], int tam, eMarca listaM[], int tamM, eColor listaC[], int tamC)
{
    char patente[20];
    int indice;
    int todoOk = 0;
    char confirmacion;

    if (lista != NULL && tam >= 0)
    {
        mostrarAutos(lista, tam, listaM, tamM, listaC, tamC);
        if (getString(patente, 20, 3, "Ingrese la patente del Auto: ", "Error. "))
        {
            indice = buscarAuto(lista, tam, patente);
            if (indice != -1)
            {
                printf("Patente    Marca   Color Modelo\n");
                mostrarAuto(lista[indice], listaM, tamM, listaC, tamC);
                printf("\nEsta seguro que quiere eliminar este auto? (s/n)");
                fflush(stdin);
                scanf("%c", &confirmacion);
                if (confirmacion == 's')
                {
                    lista[indice].isEmpty = 1;
                    todoOk = 1;
                }
                else
                {
                    printf("Operacion abortada.\n\n");
                }
            }
            else
            {
                printf("No se encontro la patente.\n\n");
            }
        }
    }

    return todoOk;
}
