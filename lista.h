#include <stdio.h>
#include "listaStruct.h"

/* Prototipos */

void inserta_Horario(Clase p, nodo_clase *&lista, int b);
/*
* Nombre de la función: inserta_Horario.
* Tipo de función: void.
* Parámetros: “p” de tipo Clase.
* 	      “lista” de tipo nodo_clase.
*	      “b” de tipo int.
* Descripción de la función: La función inserta_Horario()
* pide tres parámetros para ingresar ordenadamente el contenido
* a la lista correspondiente
*/

void inserta_Evento(Evento p, nodo_evento *&lista);
/*
* Nombre de la función: inserta_Evento.
* Tipo de función: void.
* Parámetros: “p” de tipo Evento.
* 	      “lista” de tipo nodo_evento.
* Descripción de la función: La función inserta_Evento()
* pide dos parámetros para ingresar ordenadamente el contenido
* a la lista correspondiente
*/

void imprimir_Horario(Ramo Ramos[8] , Clase p[5], nodo_clase *&lista);
/*
* Nombre de la función: imprimir_Horario.
* Tipo de función: void.
* Parámetros: “Ramos[8]” de tipo Ramo.
* 	      “p” de tipo Clase.
*	      “lista” de tipo nodo_clase.
* Descripción de la función: La función imprimir_Horario()
* pide tres parámetros para imprimir la lista ordenada ya en 
* anteriores funciones
*/
void imprimir_Eventos(Evento p, nodo_evento *&lista);
/*
* Nombre de la función: imprimir_Eventos.
* Tipo de función: void.
* Parámetros: “p” de tipo Evento.
*	      “lista” de tipo nodo_evento.
* Descripción de la función: La función imprimir_Eventos()
* pide dos parámetros para imprimir la lista ordenada ya en 
* anteriores funciones
*/

void eliminar_Lista(int i,nodo_clase *&lista, Clase z[5]);
/*
* Nombre de la función: eliminar_Lista.
* Tipo de función: void.
* Parámetros: “i” de tipo int.
*	      “lista” de tipo nodo_clase.
*	      “z[5]” de tipo Clase.
* Descripción de la función: La función eliminar_Lista()
* pide tres parámetros para eliminar la lista correspondiente
* creada en anteriores funciones
*/

void eliminar_Lista_Eventos(int i, nodo_evento *&lista, Evento z[7]);
/*
* Nombre de la función: eliminar_Lista_Eventos.
* Tipo de función: void.
* Parámetros: “i” de tipo int.
*	      “lista” de tipo nodo_evento.
*	      “z[7]” de tipo Evento.
* Descripción de la función: La función eliminar_Lista_Eventos()
* pide tres parámetros para eliminar la lista correspondiente
* creada en anteriores funciones
*/
