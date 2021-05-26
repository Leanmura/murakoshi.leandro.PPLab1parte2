#include "informes.h"

int listarAutosUnColor(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM)
{
    int opcionIdColor;
    char color[20];
    int flagAutoColor = 0;
    int todoOk = 0;

    if (listaA != NULL && tamA > 0 && listaC != NULL && tamC > 0 && listaM != NULL && tamM > 0)
    {
        mostrarColores(listaC, tamC);
        if (!getInt(&opcionIdColor, 5000, 5004, INTENTOS, "Ingrese id del color: ", "Color no valido. "))
        {
            printf("Ha excedido el limite de intentos.\n");
        }
        else
        {
            for (int i = 0; i < tamA; i++)
            {
                if (!listaA[i].isEmpty && opcionIdColor == listaA[i].idColor)
                {
                    flagAutoColor = 1;
                    break;
                }
            }
            if (flagAutoColor)
            {
                printf("PATENTE     MARCA       COLOR      MODELO \n");
                for (int i = 0; i < tamA; i++)
                {
                    if (!listaA[i].isEmpty && opcionIdColor == listaA[i].idColor)
                    {
                        mostrarAuto(listaA[i], listaM, tamM, listaC, tamC);
                    }
                }
                todoOk = 1;
            }
            else
            {
                cargarDescripcionColor(opcionIdColor, listaC, tamC, color);
                printf("No hay autos de color %s.\n", color);
            }
        }
    }
    printf("\n");
    return todoOk;
}

int listarAutosUnaMarca(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM)
{
    int opcionIdMarca;
    char marca[20];
    int flagAutoMarca = 0;
    int todoOk = 0;

    if (listaA != NULL && tamA > 0 && listaC != NULL && tamC > 0 && listaM != NULL && tamM > 0)
    {
        mostrarMarcas(listaM, tamM);
        if (!getInt(&opcionIdMarca, 1000, 1004, INTENTOS, "Ingrese id de la marca: ", "Marca no valida. "))
        {
            printf("Ha excedido el limite de intentos.\n");
        }
        else
        {
            for (int i = 0; i < tamA; i++)
            {
                if (!listaA[i].isEmpty && opcionIdMarca == listaA[i].idMarca)
                {
                    flagAutoMarca = 1;
                    break;
                }
            }
            if (flagAutoMarca)
            {
                printf("PATENTE     MARCA       COLOR      MODELO \n");
                for (int i = 0; i < tamA; i++)
                {
                    if (!listaA[i].isEmpty && opcionIdMarca == listaA[i].idMarca)
                    {
                        mostrarAuto(listaA[i], listaM, tamM, listaC, tamC);
                    }
                }
                todoOk = 1;
            }
            else
            {
                cargarDescripcionMarca(opcionIdMarca, listaM, tamM, marca);
                printf("No hay autos de la marca %s.\n", marca);
            }
        }
    }
    printf("\n");
    return todoOk;
}

int listarAutosModeloMasViejo(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM)
{
    int todoOk = 0;
    int modeloMasViejo;

    if (listaA != NULL && tamA > 0 && listaC != NULL && tamC > 0 && listaM != NULL && tamM > 0)
    {
        for (int i = 0; i < tamA; i++)
        {
            if (!listaA[i].isEmpty && (i == 0 || listaA[i].modelo < modeloMasViejo))
            {
                modeloMasViejo = listaA[i].modelo;
            }
        }
        printf("PATENTE     MARCA       COLOR      MODELO \n");
        for (int i = 0; i < tamA; i++)
        {
            if (!listaA[i].isEmpty && listaA[i].modelo == modeloMasViejo)
            {
                mostrarAuto(listaA[i], listaM, tamM, listaC, tamC);
            }
        }
        todoOk = 1;
    }
    printf("\n");
    return todoOk;
}

int listarAutosPorColor(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM)
{
    char color1[20];
    char color2[20];
    eAuto auxAuto;
    int todoOk = 0;

    if (listaA != NULL && tamA > 0 && listaM != NULL && tamM > 0)
    {
        for (int i = 0; i < tamA - 1; i++)
        {
            for (int j = i; j < tamA; j++)
            {
                cargarDescripcionColor(listaA[i].idColor, listaC, tamC, color1);
                cargarDescripcionColor(listaA[j].idColor, listaC, tamC, color2);
                if (strcmp(color1, color2) > 0)
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

int cantidadAutosMarcaColor(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM, int idMarca, int idColor)
{
    int contador = -1;
    char descC[20];
    char descM[20];

    if (listaA != NULL && tamA > 0 && listaC != NULL && tamC > 0 && listaM != NULL && tamM > 0 && idMarca >= 1000 && idMarca <= 1004 && idColor >= 5000 && idColor <= 5004)
    {
        contador = 0;
        for (int i = 0; i < tamA; i++)
        {
            if (!listaA[i].isEmpty && listaA[i].idColor == idColor && listaA[i].idMarca == idMarca)
            {
                contador++;
                //mostrarAuto(listaA[i],listaM,tamM,listaC,tamC);
            }
        }

        cargarDescripcionColor(idColor, listaC, tamC, descC);
        cargarDescripcionMarca(idMarca, listaM, tamM, descM);
        strupr(descC);
        strupr(descM);

        printf("CANTIDAD DE AUTOS %s %s: ", descM, descC);
        printf("%d\n\n", contador);
    }
    return contador;
}

int colorMasElegidoPorClientes(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM)
{
    int contador[tamC];
    int mayorCantidad;
    int todoOk = 0;

    for (int x = 0; x < tamC; x++)
    {
        contador[x] = 0;
    }

    if (listaA != NULL && tamA > 0 && listaC != NULL && tamC > 0 && listaM != NULL && tamM > 0)
    {
        for (int i = 0; i < tamA; i++)
        {
            for (int c = 0; c < tamC; c++)
            {
                if (!listaA[i].isEmpty && listaA[i].idColor == listaC[c].id)
                {
                    contador[c]++; // vector paralelo a listaC[]
                    break;
                }
            }
        }
        for (int y = 0; y < tamC; y++)
        {
            //printf("Cantidad autos %s: %d\n", listaC[y].nombreColor, contador[y]);
            if (y == 0 || mayorCantidad < contador[y])
            {
                mayorCantidad = contador[y]; // determino la cantidad de autos que tiene el color con mas autos
            }
        }

        printf("COLOR MAS ELEGIDO POR LOS CLIENTES: ");

        for (int y = 0; y < tamC; y++)
        {
            if (mayorCantidad == contador[y])
            {
                printf("%s ", listaC[y].nombreColor); // imprimo todos los colores que tienen la mayor cantidad de autos
            }
        }
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}

int marcaMasElegidaPorClientes(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM)
{
    int contador[tamM];
    int mayorCantidad;
    int todoOk = 0;

    for (int x = 0; x < tamM; x++)
    {
        contador[x] = 0;
    }

    if (listaA != NULL && tamA > 0 && listaC != NULL && tamM > 0 && listaM != NULL && tamM > 0)
    {
        for (int i = 0; i < tamA; i++)
        {
            for (int m = 0; m < tamM; m++)
            {
                if (!listaA[i].isEmpty && listaA[i].idMarca == listaM[m].id)
                {
                    contador[m]++; // vector paralelo a listaM[]
                    break;
                }
            }
        }
        for (int y = 0; y < tamM; y++)
        {
            printf("Cantidad autos %s: %d\n", listaM[y].descripcion, contador[y]);
            if (y == 0 || mayorCantidad < contador[y])
            {
                mayorCantidad = contador[y]; // determino la cantidad de autos que tiene la marca con mas autos
            }
        }

        printf("MARCA MAS ELEGIDA POR LOS CLIENTES: ");

        for (int y = 0; y < tamM; y++)
        {
            if (mayorCantidad == contador[y])
            {
                printf("%s ", listaM[y].descripcion); // imprimo todos los colores que tienen la mayor cantidad de autos
            }
        }
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}
