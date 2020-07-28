#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Vuelos.h"
#include "Pilotos.h"
#include "myMenu.h"
#include "myGets.h"

int main()
{
    LinkedList* listadoVuelos = ll_newLinkedList();
    LinkedList* listadoPilotos = ll_newLinkedList();

    int opcion;

    int flagLoad = 0;

    int retornoLoadVuelos;
    int retornoLoadPilotos;
    int retornoListVuelos;
    int retornoCountCantPasajeros;
    int retornoCountDestinoIrlanda;
    int retornoSave;
    int retornoListVuelosPortugal;
    int retornoListAlexLifeson;
    int retornoListPilotoFilter;
    int retornoListVuelosPilotoFilter;

    do
    {
        opcion = menu();

        switch(opcion)
        {
        case 1:
            if(flagLoad == 0)
            {
                retornoLoadVuelos = controller_Reynoso_loadFromTextVuelos("Vuelos.csv",listadoVuelos);
                retornoLoadPilotos = controller_Reynoso_loadFromTextPilotos("Pilotos.csv",listadoPilotos);

                if(retornoLoadVuelos == 1)
                {
                    printf("\nEl archivo  ha sido cargado exitosamente(vuelos).\n\n");
                }
                else
                {
                    printf("\nError al cargar el archivo(vuelos).\n\n");
                }

                if(retornoLoadPilotos == 1)
                {
                    printf("\nEl archivo  ha sido cargado exitosamente(pilotos).\n\n");

                }
                else
                {
                    printf("\nError al cargar el archivo(pilotos).\n\n");
                }

                flagLoad = 1;
            }
            else if(flagLoad == 1)
            {
                printf("\nEl archivo fue cargado anteriormente.\n\n");
            }
            break;
        case 2:
            retornoListVuelos = controller_Reynoso_listVuelos(listadoVuelos, listadoPilotos);

            if(retornoListVuelos == 1)
            {
                printf("\nMostrando vuelos.\n\n");
            }
            else
            {
                printf("\nError al mostrar vuelos.\n\n");
            }
            break;
        case 3:
            retornoCountCantPasajeros = controller_Reynoso_countCantPasajerosTotales(listadoVuelos);

            if(retornoCountCantPasajeros == 1)
            {
                printf("\nConteo exitoso.\n\n");
            }
            else
            {
                printf("\nError al contar cantidad total de pasajeros.\n\n");
            }
            break;
        case 4:
            retornoCountDestinoIrlanda = controller_Reynoso_countDestinoIrlanda(listadoVuelos);

            if(retornoCountDestinoIrlanda == 1)
            {
                printf("\nConteo exitoso.\n\n");
            }
            else
            {
                printf("\nError al contar cantidad de pasajeros con destino a Irlanda.\n\n");
            }
            break;
        case 5:
            retornoSave = controller_Reynoso_saveVuelosCortos(listadoVuelos);

            if(retornoSave == 1)
            {
                printf("\nNueva lista filtrada exitosamente.\n\n");
            }
            else
            {
                printf("\nError al filtrar\n\n");
            }
            break;
        case 6:
            retornoListVuelosPortugal =  controller_Reynoso_listVuelosDestinoPortugal(listadoVuelos,listadoPilotos);

            if(retornoListVuelosPortugal == 1)
            {
                printf("\nMostrando vuelos filtrados.\n\n");
            }
            else
            {
                printf("\nError al mostrar vuelos filtrados.\n\n");
            }
            break;
        case 7:
            retornoListAlexLifeson = controller_Reynoso_listVuelosWithoutAlexLifeson(listadoVuelos,listadoPilotos);

            if(retornoListAlexLifeson == 1)
            {
                printf("\nMostrando vuelos filtrados.\n\n");
            }
            else
            {
                printf("\nError al mostrar vuelos filtrados.\n\n");
            }
            break;
        case 8:
            retornoListPilotoFilter = controller_Reynoso_listPilotosFilter(listadoPilotos);

            if(retornoListPilotoFilter == 1)
            {
                printf("\nMostrando pilotos filtrados.\n\n");
            }
            else
            {
                printf("\nError al mostrar pilotos filtrados.\n\n");
            }
            break;
        case 9:
            retornoListVuelosPilotoFilter = controller_Reynoso_listVuelosPilotoFilter(listadoVuelos,listadoPilotos);

            if(retornoListVuelosPilotoFilter == 1)
            {
                printf("\nMostrando vuelos filtrados.\n\n");
            }
            else
            {
                printf("\nError al mostrar vuelos filtrados.\n\n");
            }
            break;
        case 10:
            printf("\nCerrando...\n");
            break;
        default:
            printf("\nOpcion incorrecta.\n");
            break;
        }

        system("pause");
        system("cls");
    }
    while(opcion != 10);

    return 0;
}
