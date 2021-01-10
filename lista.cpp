#include <stdio.h>
#include <string.h>
#include "lista.h"

void inserta_Horario(Clase p, nodo_clase *&lista, int b)
{
	nodo_clase *nuevo = new nodo_clase();
	nuevo->dato.hora_inicio = p.hora_inicio;
	nuevo->dato.hora_termino = p.hora_termino;
	nuevo->dato.minuto_inicio = p.minuto_inicio;
	nuevo->dato.minuto_termino = p.minuto_termino;
	nuevo->dato.ramo_asociado = p.ramo_asociado;

	nodo_clase *aux1 = lista;
	nodo_clase *aux2;
	if (b == 1)
	{

		while ((aux1 != NULL) && ((aux1->dato.hora_inicio < p.hora_inicio) || ((aux1->dato.hora_inicio == p.hora_inicio) && (aux1->dato.minuto_inicio < p.minuto_inicio))))
		{
			aux2 = aux1;
			aux1 = aux1->next;
		}
	}
	else
	{

		while ((aux1 != NULL) && ((aux1->dato.hora_inicio < p.hora_inicio) || ((aux1->dato.hora_termino == p.hora_inicio) && (aux1->dato.minuto_termino < p.minuto_inicio))))
		{
			aux2 = aux1;
			aux1 = aux1->next;
		}
	}

	if (lista == aux1)
	{
		lista = nuevo;
	}
	else
	{
		aux2->next = nuevo;
	}
	nuevo->next = aux1;
}

void inserta_Evento(Evento p, nodo_evento *&lista)
{
	nodo_evento *nuevo = new nodo_evento();
	nuevo->dato.hora_evento = p.hora_evento;
	nuevo->dato.minuto_evento = p.minuto_evento;
	strcpy(nuevo->dato.descripcion, p.descripcion);

	nodo_evento *aux1 = lista;
	nodo_evento *aux2;

	while ((aux1 != NULL) && ((aux1->dato.hora_evento < p.hora_evento) || ((aux1->dato.hora_evento == p.hora_evento) && (aux1->dato.minuto_evento < p.minuto_evento))))
	{
		aux2 = aux1;
		aux1 = aux1->next;
	}

	if (lista == aux1)
	{
		lista = nuevo;
	}
	else
	{
		aux2->next = nuevo;
	}
	nuevo->next = aux1;
}

void imprimir_Horario(Ramo Ramos[8], Clase p[5], nodo_clase *&lista)
{
	nodo_clase *actual = new nodo_clase();
	actual = lista;
	int i = 0;

	while (actual != NULL)
	{

		if ((p[i].minuto_inicio == 0 && p[i].minuto_termino == 0) || (p[i].minuto_inicio < 10 && p[i].minuto_termino < 10) || (p[i].minuto_inicio < 10 && p[i].minuto_termino == 0) || (p[i].minuto_inicio == 0 && p[i].minuto_termino < 10))
		{
			printf(" [%d] %s (%d:0%d - %d:0%d)\n", i + 1, Ramos[actual->dato.ramo_asociado].nombre_ramo, actual->dato.hora_inicio, actual->dato.minuto_inicio, actual->dato.hora_termino, actual->dato.minuto_termino);
		}
		else if (p[i].minuto_inicio == 0 && p[i].minuto_termino > 10)
		{
			printf(" [%d] %s (%d:0%d - %d:%d)\n", i + 1, Ramos[actual->dato.ramo_asociado].nombre_ramo, actual->dato.hora_inicio, actual->dato.minuto_inicio, actual->dato.hora_termino, actual->dato.minuto_termino);
		}
		else if (p[i].minuto_termino == 0 && p[i].minuto_inicio > 10)
		{
			printf(" [%d] %s (%d:%d - %d:0%d)\n", i + 1, Ramos[actual->dato.ramo_asociado].nombre_ramo, actual->dato.hora_inicio, actual->dato.minuto_inicio, actual->dato.hora_termino, actual->dato.minuto_termino);
		}
		else
		{
			printf(" [%d] %s (%d:%d - %d:%d)\n", i + 1, Ramos[actual->dato.ramo_asociado].nombre_ramo, actual->dato.hora_inicio, actual->dato.minuto_inicio, actual->dato.hora_termino, actual->dato.minuto_termino);
		}
		i++;
		actual = actual->next;
	}
}

void imprimir_Eventos(Evento p, nodo_evento *&lista)
{
	nodo_evento *actual = new nodo_evento();
	actual = lista;
	while (actual != NULL)
	{
		for (int m = 0; actual != NULL; m++)
		{
			printf(" [%d] (%d:%d) %s\n", m + 1, actual->dato.hora_evento, actual->dato.minuto_evento, actual->dato.descripcion);
			actual = actual->next;
		}
	}
}

void eliminar_Lista(int i, nodo_clase *&lista, Clase z[5])
{
	nodo_clase *aux = lista;
	z[i].hora_inicio = aux->dato.hora_inicio;
	z[i].hora_termino = aux->dato.hora_termino;
	z[i].minuto_inicio = aux->dato.minuto_inicio;
	z[i].minuto_termino = aux->dato.minuto_termino;
	z[i].ramo_asociado = aux->dato.ramo_asociado;
	lista = aux->next;
	delete aux;
}

void eliminar_Lista_Eventos(int i, nodo_evento *&lista, Evento z[7])
{
	nodo_evento *aux = lista;
	z[i].hora_evento = aux->dato.hora_evento;
	z[i].minuto_evento = aux->dato.minuto_evento;
	strcpy(z[i].descripcion, aux->dato.descripcion);

	lista = aux->next;
	delete aux;
}
