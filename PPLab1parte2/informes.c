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
                printf("\nPATENTE     MARCA       COLOR      MODELO \n");
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
                printf("\nPATENTE     MARCA       COLOR      MODELO \n");
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

int listarAutosPorMarca(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM)
{
    int todoOk = 0;
    char marca[20];
    if (listaA != NULL && tamA > 0 && listaM != NULL && tamM > 0)
    {
        for (int j = 0; j < tamM; j++)
        {
            cargarDescripcionMarca(listaM[j].id, listaM, tamM, marca);
            printf("\nAutos %s:\n", marca);
            for (int i = 0; i < tamA; i++)
            {
                if (listaA[i].idMarca == listaM[j].id)
                {
                    mostrarAuto(listaA[i], listaM, tamM, listaC, tamC);
                }
            }
        }

        printf("\n");
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
            //printf("Cantidad autos %s: %d\n", listaM[y].descripcion, contador[y]);
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

int trabajosXAuto(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM)
{
    int todoOk;
    char patente[20];
    int indice;
    int flag =0;
    if(listaT != NULL && tamT > 0 && listaS != NULL && tamS > 0 && listaA != NULL && tamA > 0 && listaM != NULL && tamM > 0 && listaC != NULL && tamC >0)
    {
        mostrarAutos(listaA, tamA, listaM, tamM, listaC, tamC);
        if (getString(patente, 20, 3, "Ingrese la patente del Auto: ", "Error. "))
        {
            indice = buscarAuto(listaA, tamA, patente);
            if (indice != -1)
            {

                for(int t=0; t<tamT; t++)
                {
                    if(strcmp(listaT[t].patente, patente) == 0)
                    {
                        flag=1;
                    }
                }
                if(flag)
                {
                    printf("\nPatente   Servicio   Fecha \n");
                    for(int t=0; t<tamT; t++)
                    {
                        if(strcmp(listaT[t].patente, patente) == 0)
                        {
                            mostrarTrabajo(listaT[t], listaS, tamS);
                        }
                    }
                }
                else
                {
                    printf("No se le hicieron trabajos a este auto.\n");
                }
            }
        }
        printf("\n");
        todoOk =1;
    }
    return todoOk;
}

int totalImporteXAuto(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM)
{
    int todoOk;
    char patente[20];
    int indice;
    int flag =0;
    float importe;
    float totalImporte =0;
    char desc[20];
    if(listaT != NULL && tamT > 0 && listaS != NULL && tamS > 0 && listaA != NULL && tamA > 0 && listaM != NULL && tamM > 0 && listaC != NULL && tamC >0)
    {
        mostrarAutos(listaA, tamA, listaM, tamM, listaC, tamC);
        if (getString(patente, 20, 3, "Ingrese la patente del Auto: ", "Error. "))
        {
            indice = buscarAuto(listaA, tamA, patente);
            if (indice != -1)
            {
                for(int t=0; t<tamT; t++)
                {
                    if(strcmp(listaT[t].patente, patente) == 0)
                    {
                        cargarPrecioServicio(listaT[t].idServicio, listaS, tamS, &importe);
                        cargarDescripcionServicio(listaT[t].idServicio, listaS, tamS, desc);
                        printf("%s : %.2f\n", desc, importe);
                        totalImporte = totalImporte + importe;
                        flag=1;
                    }
                }
                if(flag)
                {
                    printf("Importe total del auto: %.2f", totalImporte);
                }
                else
                {
                    printf("No se le hicieron trabajos a este auto.\n");
                }
            }
        }
        else
        {
            printf("Ha excedido el limite de intentos.\n");
        }
        printf("\n");
        todoOk =1;
    }
    return todoOk;
}

int autosXServicio(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eAuto listaA[], int tamA)
{
    int idServicio;
    int todoOk =0;
    int flag =0;
    if(listaT != NULL && tamT > 0 && listaS != NULL && tamS > 0 && listaA != NULL && tamA > 0)
    {
        mostrarServicios(listaS,tamS);
        if (getInt(&idServicio, 20000, 20003, INTENTOS, "Ingrese id del servicio: ", "Error. "))
        {
            for(int t=0; t<tamT; t++)
            {
                if(idServicio == listaT[t].idServicio)
                {
                    flag =1;
                }
            }
            if(flag)
            {
                printf("\nPatente   Servicio   Fecha \n");
                for(int t=0; t<tamT; t++)
                {
                    if(idServicio == listaT[t].idServicio)
                    {
                        mostrarTrabajo(listaT[t], listaS, tamS);
                    }
                }
            }
            else
            {
                printf("No se le hizo este servicio a ningun auto.\n");
            }
        }
        else
        {
            printf("Ha excedido el limite de intentos.\n");
        }
        printf("\n");
        todoOk =1;
    }
    return todoOk;
}

int serviciosXFecha(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eAuto listaA[], int tamA)
{
    eFecha fecha;
    int todoOk =0;
    int flag =0;
    if(listaT != NULL && tamT > 0 && listaS != NULL && tamS > 0 && listaA != NULL && tamA > 0)
    {
        eFecha fechaHoy = {FECHA_ACTUAL};
        eFecha fechaMin = {FECHA_MIN};
        if (getFecha(&fecha, fechaHoy, fechaMin, 3, "Ingresar la fecha de hoy(DD/MM/AAAA): ", "Error. ") == 1)
        {
            for(int t=0; t<tamT; t++)
            {
                if(fecha.anio == listaT[t].fecha.anio && fecha.mes == listaT[t].fecha.mes && fecha.dia ==  listaT[t].fecha.dia)
                {
                    flag =1;
                }
            }
            if(flag)
            {
                printf("\nPatente   Servicio   Fecha \n");
                for(int t=0; t<tamT; t++)
                {
                    if(fecha.anio == listaT[t].fecha.anio && fecha.mes == listaT[t].fecha.mes && fecha.dia ==  listaT[t].fecha.dia)
                    {
                        mostrarTrabajo(listaT[t], listaS, tamS);
                    }
                }
            }
            else
            {
                printf("No se le hizo ningun servicio en esta fecha.\n");
            }
        }
        else
        {
            printf("Ha excedido el limite de intentos.\n");
        }
        printf("\n");
        todoOk =1;
    }
    return todoOk;
}
