#include "menus.h"

void menu()
{
    system("cls");
    printf("--- LAVADERO DE AUTOS ---\n");
    printf("1. Alta auto\n");
    printf("2. Modificar auto\n");
    printf("3. Baja auto\n");
    printf("4. Listar autos\n");
    printf("5. Listar marcas\n");
    printf("6. Listar colores\n");
    printf("7. Listar servicios\n");
    printf("8. Alta trabajo\n");
    printf("9. Listar trabajos\n");
    printf("10. Informes\n");
    printf("11. Salir\n\n");
}

void menuModificar()
{
    system("cls");
    printf("------- MENU MODIFICAR -------\n");
    printf("1. Marca\n");
    printf("2. Modelo\n");
    printf("3. Salir\n\n");
}

void menuInformes()
{
    system("cls");
    printf("------- MENU INFORMES -------\n");
    printf("1. Listar autos de un color\n");
    printf("2. Listar autos de una marca\n");
    printf("3. Listar autos mas viejos\n");
    printf("4. Listar autos por marca\n");
    printf("5. Cantidad de autos de una marca y color\n");
    printf("6. Marca/s mas elegidas por los clientes\n\n");

    printf("7. Trabajos que se le hicieron a un auto\n");
    printf("8. Suma de importes que se le hicieron a un auto\n");
    printf("9. Autos a los que se le realizo un servicio\n");
    printf("10. Servicios realizados en un dia\n");
    printf("11. Salir\n\n");
}

