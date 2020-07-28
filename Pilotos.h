#ifndef PILOTOS_H_INCLUDED
#define PILOTOS_H_INCLUDED
typedef struct
{
    int idPiloto;
    char nombre[100];
}Piloto;

Piloto* piloto_new();
Piloto* piloto_newParametros(char* idPilotoStr, char* nombreStr);
void piloto_delete(Piloto* this);

int piloto_setIdPiloto(Piloto* this,int idPiloto);
int piloto_getIdPiloto(Piloto* this,int* idPiloto);

int piloto_setNombre(Piloto* this,char* nombre);
int piloto_getNombre(Piloto* this,char* nombre);

Piloto* piloto_getPilotoById(LinkedList* pListadoPilotos,int id);
int piloto_getIdByNombre(LinkedList* pListadoPilotos, char* nombre);

int piloto_filterPiloto(void* pElement, char* nombre);

#endif // PILOTOS_H_INCLUDED
