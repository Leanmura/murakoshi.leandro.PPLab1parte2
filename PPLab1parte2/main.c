#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"
#include "inputs_lean.h"
#include "marca.h"
#include "auto.h"
#include "color.h"
#include "menus.h"
#include "dataWareHouse.h"
#include "servicio.h"
#include "trabajo.h"
#include "informes.h"

#define INTENTOS 3

#define TAMT 30
#define TAMA 10
#define TAMC 5
#define TAMM 5
#define TAMS 4


int main()
{

    int opcion;
    char salir = 'n';
    int nextIdAuto = 2000;
    int flag = 0;
    int nextIdTrabajo = 3000;
    int flagTrabajo = 0;
    int opcionInformes;

    eMarca marcas[TAMM] =
    {
        {1000, "Renault"},
        {1001, "Fiat"},
        {1002, "Ford"},
        {1003, "Chevrolet"},
        {1004, "Peugeot"}
    };

    eColor colores[TAMC] =
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Gris"},
        {5003, "Rojo"},
        {5004, "Azul"}
    };

    eServicio servicios[TAMS] =
    {
        {20000, "Lavado", 250},
        {20001, "Pulido", 300},
        {20002, "Encerado", 400},
        {20003, "Completo", 600}
    };

    eAuto autos[TAMA];

    eTrabajo trabajos[TAMT];

    inicializarTrabajos(trabajos,TAMT);
    flagTrabajo =1;
    hardcodearTrabajos(trabajos, TAMT,10, &nextIdTrabajo);

    inicializarAutos(autos, TAMA);
    flag =1;
    hardcodearAutos(autos, TAMA, 10, &nextIdAuto);
    do
    {
        menu();
        if (!getInt(&opcion, 1, 11, INTENTOS, "Ingrese lo que desea hacer: ", "Error. "))
        {
            printf("Ha excedido el limite de intentos. Se finalizara el programa.\n\n");
            salir = 's';
        }

        switch (opcion)
        {
        case 1:
            system("cls");
            printf("--- ALTA AUTO ---\n");
            printf("Id: #%d\n", nextIdAuto);

            if (altaAuto(autos, TAMA, &nextIdAuto, marcas, TAMM, colores, TAMC))
            {
                printf("Alta exitosa!!!\n\n");
                flag = 1;
            }
            else
            {
                printf("Hubo un error en el alta.\n\n");
            }

            system("PAUSE");
            break;

        case 2:
            system("cls");
            if (flag)
            {
                printf("--- MODIFICAR AUTO ---\n\n");
                if (modificarAuto(autos, TAMA, marcas, TAMM, colores, TAMC))
                {
                    printf("modificacion exitosa!!!\n\n");
                }
                else
                {
                    printf("Hubo un error en la modificacion.\n\n");
                }
            }
            else
            {
                printf("No puede modificar un auto si no hay autos.\n\n");
            }
            system("PAUSE");
            break;

        case 3:
            system("cls");
            if (flag)
            {
                printf("--- BAJA AUTO ---\n\n");
                if (bajaAuto(autos, TAMA, marcas, TAMM, colores, TAMC))
                {
                    printf("Baja exitosa!!!\n\n");
                }
                else
                {
                    printf("Hubo un error en la baja.\n\n");
                }
            }
            else
            {
                printf("No puede dar de baja un auto si no hay autos.\n\n");
            }
            system("PAUSE");
            break;

        case 4:
            system("cls");
            if (flag)
            {
                ordenarAutosMarcaPatente(autos,TAMA, marcas, TAMM);
                if(!mostrarAutos(autos, TAMA, marcas, TAMM, colores, TAMC))
                {
                    printf("Hubo un error al mostrar.\n\n");
                }
            }
            else
            {
                printf("No puede listar los autos si no hay autos.\n\n");
            }
            system("PAUSE");
            break;

        case 5:
            system("cls");

            if(!mostrarMarcas(marcas, TAMM))
            {
                printf("Hubo un error al mostrar marcas.\n\n");
            }

            system("PAUSE");
            break;

        case 6:
            system("cls");

            if(mostrarColores(colores, TAMC))
            {
                printf("Hubo un error al mostrar colores.\n\n");
            }

            system("PAUSE");
            break;
        case 7:
            system("cls");

            if(mostrarServicios(servicios, TAMS))
            {
                printf("Hubo un error al mostrar servicios.\n\n");
            }

            system("PAUSE");
            break;

        case 8:
            system("cls");
            if (flag)
            {
                printf("--- ALTA TRABAJO ---\n");
                printf("Id: #%d\n", nextIdTrabajo);

                if (altaTrabajo(trabajos, TAMT, &nextIdTrabajo, servicios, TAMS, autos, TAMA, marcas, TAMM, colores, TAMC))
                {
                    printf("Alta exitosa!!!\n\n");
                    flagTrabajo = 1;
                }
                else
                {
                    printf("Hubo un error en el alta.\n\n");
                }
            }
            else
            {
                printf("No puede dar de alta trabajos si no hay Autos.\n\n");
            }

            system("PAUSE");
            break;

        case 9:
            system("cls");
            if(flagTrabajo)
            {
                if(!mostrarTrabajos(trabajos, TAMT, servicios, TAMS))
                {
                    printf("Hubo un error al mostrar trabajos.\n\n");
                }
            }
            else
            {
                printf("No puede listar los trabajos si no hay trabajos.\n\n");
            }
            system("PAUSE");

            break;

        case 10:
            system("cls");
            if(flag)
            {
                menuInformes();
                getInt(&opcionInformes, 1, 11, INTENTOS,"Ingrese lo que desea hacer: ", "Error. ");
                switch(opcionInformes)
                {
                case 1:
                    system("cls");
                    printf("--- LISTAR AUTOS DE UN COLOR ---\n");
                    if(!listarAutosUnColor(autos, TAMA, colores, TAMC, marcas, TAMM))
                    {
                        printf("Hubo un error.\n\n");
                    }
                    break;

                case 2:
                    system("cls");
                    printf("--- LISTAR AUTOS DE UNA MARCA ---\n");
                    if(!listarAutosUnaMarca(autos, TAMA, colores, TAMC, marcas, TAMM))
                    {
                        printf("Hubo un error.\n\n");
                    }
                    break;

                case 3:
                    system("cls");
                    printf("--- LISTAR AUTOS DE MODELO MAS VIEJO ---\n");
                    if(!listarAutosModeloMasViejo(autos, TAMA, colores, TAMC, marcas, TAMM))
                    {
                        printf("Hubo un error.\n\n");
                    }
                    break;

                case 4:
                    system("cls");
                    printf("--- LISTAR AUTOS POR MARCA ---\n");
                    if(!listarAutosPorMarca(autos, TAMA, colores, TAMC, marcas, TAMM))
                    {
                        printf("Hubo un error.\n\n");
                    }
                    break;

                case 5:
                    system("cls");
                    if(cantidadAutosMarcaColor(autos, TAMA, colores, TAMC, marcas, TAMM, 1003, 5003) == -1)
                    {
                        printf("Hubo un error.\n\n");
                    }

                    break;

                case 6:
                    system("cls");
                    if(!marcaMasElegidaPorClientes(autos, TAMA, colores, TAMC, marcas, TAMM ))
                    {
                        printf("Hubo un error.\n\n");
                    }
                    break;

                case 7:
                    system("cls");
                    printf("--- LISTAR TRABAJOS QUE SE LE HICIERON A UN AUTO ---\n\n");
                    if(!trabajosXAuto(trabajos,TAMT, servicios, TAMS, autos ,TAMA, colores, TAMC, marcas, TAMM))
                    {
                        printf("Hubo un error.\n\n");
                    }

                    break;

                case 8:
                    system("cls");
                    printf("--- SUMA DE IMPORTES QUE SE LE HICIERON A UN AUTO ---\n\n");
                    if(!totalImporteXAuto(trabajos,TAMT, servicios, TAMS, autos ,TAMA, colores, TAMC, marcas, TAMM))
                    {
                        printf("Hubo un error.\n\n");
                    }

                    break;

                case 9:
                    system("cls");
                    printf("--- AUTOS A LOS QUE SE LE REALIZO X SERVICIO ---\n");
                    if(!autosXServicio(trabajos,TAMT, servicios, TAMS, autos ,TAMA))
                    {
                        printf("Hubo un error.\n\n");
                    }

                    break;

                case 10:
                    system("cls");
                    printf("--- SERVICIOS REALIZADOS EN X FECHA ---\n");
                    if(!serviciosXFecha(trabajos,TAMT, servicios, TAMS, autos ,TAMA))
                    {
                        printf("Hubo un error.\n\n");
                    }

                    break;

                }
            }
            else
            {
                printf("No puede hacer informes si no hay autos.\n\n");
            }
            system("PAUSE");

            break;

        case 11:
            system("cls");
            printf("--------- Salir ---------\n");

            if (!getLetra(&salir, 3, "Confirmar salida? [s/n] ", "Error. "))
            {
                printf("Ha excedido el limite de intentos se cerrara el programa.\n\n");
            }
            break;
        }
    }
    while (salir == 'n');
    return 0;
}






