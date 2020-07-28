#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

int parser_VueloFromText(FILE* pArchivo,LinkedList* pListadoVuelos);
int parser_PilotoFromText(FILE* pArchivo,LinkedList* pListadoPilotos);

#endif // PARSER_H_INCLUDED
