#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myMenu.h"
#include "myGets.h"

int menu()
{
    int opcion;

    printf("\n1- Cargar archivo."); /// Se pedirá el nombre del archivo y se cargará en un LinkedList los elementos del mismo.
    printf("\n2- Imprimir vuelos."); ///Se imprimirá por pantalla la tabla con los datos de los vuelos indicando el nombre del piloto (no el número)
    printf("\n3- Cantidad de pasajeros."); /// Cantidad de pasajeros totales
    printf("\n4- Cantidad de pasajeros a Irlanda."); /// cantidad de pasajeros a irlanda.
    printf("\n5- Filtrar vuelos cortos."); ///Generar un archivo de iguales características que el original, con los datos de los vuelos cuya duración sea inferior a 3 horas.
    printf("\n6- Listar vuelos a Portugal."); ///Generar un listado que solo incluya los vuelos con destino a Portugal.
    printf("\n7- Filtrar a Alex Lifeson."); ///Necesitamos un listado de vuelos que no incluya al chofer Alex Lifeson
    printf("\n8- Filtrar por nombre del piloto(Excluir)(pilotos)."); ///Necesitamos una lista de pilotos donde NO incluya al piloto que ingresamos por teclado( informar si el piloto ingresado no existe).
    printf("\n9- Filtrar por nombre del piloto(Incluir)(vuelos)."); ///Necesitamos una lista de vuelos donde SOLO incluya al piloto que ingresamos por teclado( informar si el piloto ingresado no existe).
    printf("\n10- Salir.");
    opcion = getInt("\nIngrese una opcion: ");

    return opcion;
}
