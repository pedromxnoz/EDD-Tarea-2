/* Estructuras*/
struct Ramo
{
	char nombre_ramo[30];
	char nombre_profe[30];
	char link_clase[120];
};

struct Clase
{
	int ramo_asociado;
	int hora_inicio;
	int minuto_inicio;
	int hora_termino;
	int minuto_termino;
};

struct Evento
{
	int hora_evento;
	int minuto_evento;
	char descripcion[100];
};

#ifndef LISTA_STRUCT_H
#define LISTA_STRUCT_H

struct nodo_clase{
	Clase dato;
	struct nodo_clase* next;
};

struct nodo_evento{
	Evento dato;
	struct nodo_evento* next;
};

#endif