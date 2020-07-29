#ifndef VUELOS_H_INCLUDED
#define VUELOS_H_INCLUDED
typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[100];
    char destino[100];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    int importeTotal;
} Vuelo;

Vuelo* vuelo_new();
Vuelo* vuelo_newParametros(char* idVueloStr,char* idAvionStr,char* idPilotoStr,char* fecha,char* destinoStr,char* cantPasajerosStr,char* horaDespegueStr,char* horaLlegadaStr);
void vuelo_delete(Vuelo* this);

int vuelo_setIdVuelo(Vuelo* this,int idVuelo);
int vuelo_getIdVuelo(Vuelo* this,int* idVuelo);

int vuelo_setIdAvion(Vuelo* this,int idAvion);
int vuelo_getIdAvion(Vuelo* this,int* idAvion);

int vuelo_setIdPiloto(Vuelo* this,int idPiloto);
int vuelo_getIdPiloto(Vuelo* this,int* idPiloto);

int vuelo_setFecha(Vuelo* this,char* fecha);
int vuelo_getFecha(Vuelo* this,char* fecha);

int vuelo_setDestino(Vuelo* this,char* destino);
int vuelo_getDestino(Vuelo* this,char* destino);

int vuelo_setCantPasajeros(Vuelo* this,int cantPasajeros);
int vuelo_getCantPasajeros(Vuelo* this,int* cantPasajeros);

int vuelo_setHoraDespegue(Vuelo* this,int horaDespegue);
int vuelo_getHoraDespegue(Vuelo* this,int* horaDespegue);

int vuelo_setHoraLlegada(Vuelo* this,int horaLlegada);
int vuelo_getHoraLlegada(Vuelo* this,int* horaLlegada);

int vuelo_cantPasajerosParaContar(void* pElement);

int vuelo_filterCortos(void* pElement);
int vuelo_filterIrlanda(void* pElement);
int vuelo_filterPortugal(void* pElement);
int vuelo_filterAlexLifeson(void* pElement);
int vuelo_filterPiloto(void* pElement, int idPiloto);

int vuelo_setImporteTotal(Vuelo* this,int importeTotal);
int vuelo_getImporteTotal(Vuelo* this,int* importeTotal);

void* vuelo_criterioImporteFinal(void* pElemento);


#endif // VUELOS_H_INCLUDED
