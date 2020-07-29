#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_Reynoso_loadFromTextVuelos(char* path, LinkedList* pListadoVuelos);
int controller_Reynoso_loadFromTextPilotos(char* path, LinkedList* pListadoPilotos);
int controller_Reynoso_listVuelos(LinkedList* pListadoVuelos, LinkedList* pListadoPilotos);
int controller_Reynoso_countCantPasajerosTotales(LinkedList* pListadoVuelos);
int controller_Reynoso_countDestinoIrlanda(LinkedList* pListadoVuelos);
int controller_Reynoso_saveAsTextVuelos(char* path, LinkedList* pListadoVuelos);
int controller_Reynoso_saveVuelosCortos(LinkedList* pListadoVuelos);
int controller_Reynoso_listVuelosDestinoPortugal(LinkedList* pListadoVuelos, LinkedList* pListadoPilotos);
int controller_Reynoso_listVuelosWithoutAlexLifeson(LinkedList* pListadoVuelos, LinkedList* pListadoPilotos);
int controller_Reynoso_listPilotos(LinkedList* pListadoPilotos);
int controller_Reynoso_listPilotosFilter(LinkedList* pListadoPilotos);
int controller_Reynoso_listVuelosPilotoFilter(LinkedList* pListadoVuelos, LinkedList* pListadoPilotos);

int controller_Reynoso_listVuelosMod(LinkedList* pListadoVuelos);
int controller_Reynoso_listMap(LinkedList* pListadoVuelos);
int controller_Reynoso_saveAsTextVuelosMod(char* path, LinkedList* pListadoVuelos);
#endif // CONTROLLER_H_INCLUDED
