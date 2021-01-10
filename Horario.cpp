/*
 * 	Universidad de La Frontera
 *	Ingenieria Civil Telematica
 *	
 *	IIE-344-1 ESTRUCURA DE DATOS Y ALGORITMOS
 *	
 *	Tarea 2
 *
 *	Autor 1: Pedro Paulo Enrique Muñoz Gatica 
 *	Autor 2: Benjamin Eduardo Lagos Roa
 *
 *	Fecha: 10/01/2020
 *
 * 	Proyecto Horario Personal: HORARIO VIRTUAL
 *
 * El proyecto consiste en solventar la falta de un horario personal universitario el cual almacena 
 * los horarios fijos ingresados uno a uno por el usuario, esto incluyendo el nombre del profesor que rinde la clase, 
 * el link de ingreso a clases y la hora de inicio y termino de la clase. Esto con el fin de sobrellevar de mejor manera este
 * periodo de pandemia el cual exige a los alumnos una organizacion personal completa y una mayor responsabilidad
 * con sus estudios.
 * 
*/

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "lista.h"

//Estructuras Añadidas en listaStruct.h

int seleccion_ramo(int cant_ramos, Ramo Ramos[8]);
/*
* Nombre de la función: seleccion_ramo.
* Tipo de función: int.
* Parámetros: “cant_ramos” de tipo Clase.
*	      “Ramos[8]” de tipo Ramos.
* Dato de retorno: “a” de tipo int.
* Descripción de la función: La función seleccion_ramo()
* pide dos parámetros para dar una cifra numerica a la seleccion
* del ramo que servirá para futuras operaciones.
*/

int main()
{
	nodo_clase *Horarios_Ordenados[5] = {NULL, NULL, NULL, NULL, NULL};
	nodo_evento *Eventos_Ordenados[7] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL};

	//Definicion de variables, se usaran en todo el programa.

	Clase Horarios_clases[5][12];
	Evento Eventos[20][7][20];
	Ramo Ramos[8];
	char semana[20][22] = {{"Semanas/Semana#1.txt"}, {"Semanas/Semana#2.txt"}, {"Semanas/Semana#3.txt"}, {"Semanas/Semana#4.txt"}, {"Semanas/Semana#5.txt"}, {"Semanas/Semana#6.txt"}, {"Semanas/Semana#7.txt"}, {"Semanas/Semana#8.txt"}, {"Semanas/Semana#9.txt"}, {"Semanas/Semana#10.txt"}, {"Semanas/Semana#11.txt"}, {"Semanas/Semana#12.txt"}, {"Semanas/Semana#13.txt"}, {"Semanas/Semana#14.txt"}, {"Semanas/Semana#15.txt"}, {"Semanas/Semana#16.txt"}, {"Semanas/Semana#17.txt"}, {"Semanas/Semana#18.txt"}, {"Semanas/Semana#19.txt"}, {"Semanas/Semana#20.txt"}};
	int cant_clases[7];
	char dia_semana[7][12] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
	int opcion_selec = 0;
	int Semana_evento, Dia_evento;
	int cant_semanas, cant_ramos;
	int cont;

	printf(" **=====================================**\n");
	printf(" ||\t      Bienvenido a tu\t\t||\n ||\tH O R A R I O  V I R T U A L\t||\n");
	printf(" **=====================================**\n\n");

	while (opcion_selec != 3)
	{ //Se realiza un while en caso de ingresar una entrada incorrecta.

		printf(" || Que desea realizar?\n\n");
		printf(" 1. Crear un horario fijo de estudio.\n");
		printf(" 2. Agendar evento o recordatorio.\n");
		printf(" 3. Salir del programa.\n");
		printf("\nIngrese una opcion: ");
		scanf("%d", &opcion_selec);
		system("cls");

		switch (opcion_selec)
		{ //Switch para la opcion seleccionada.

		case 1: //Caso 1: Crear un horario fijo de estudios el cual se mantendrá según la cantidad de semanas que ingrese el usuario.
		{
			{
				int c = 0;
				FILE *f = fopen("trash.txt", "r");
				if (f != NULL)
				{
					printf("Usted ya tiene un horario fijo creado, quiere sobreescribir el horario fijo anterior?\n");
					printf(" 1.Si\n");
					printf(" 2.No\n");
					scanf("%d", &c);
					if (c == 2)
					{
						system("cls");
						break;
					}
				}
				fclose(f);
			}
			printf(" || Cuantas semanas estara impartiendo esta rutina de estudios? (maximo 20 semanas)\n");
			printf("\nIngrese la cantidad de semanas: ");
			scanf("%d", &cant_semanas);
			system("cls");

			printf(" || A continuacion ingrese los datos solicitados:\n");
			printf("\nIngrese la cantidad de ramos a rendir en este periodo (maximo 8 ramos): ");
			scanf("%d", &cant_ramos);
			system("cls");

			for (int i = 0; i < cant_ramos; i++)
			{ //Solicitud de los datos de cada ramo para guardarlos
				//y posteriormente usarlos en el código.
				printf(" || RAMO %d\n", i + 1);
				fflush(stdin);
				printf("\nIngrese el nombre del RAMO %d: ", i + 1);
				scanf("%[^\n]", Ramos[i].nombre_ramo);
				fflush(stdin);
				printf("\nIngrese el nombre del profesor que rinde el RAMO %d: ", i + 1);
				scanf("%[^\n]", Ramos[i].nombre_profe);
				fflush(stdin);
				printf("\nPegue el link de ingreso a la clase del RAMO %d: ", i + 1);
				scanf("%[^\n]", Ramos[i].link_clase);
				system("cls");
			}

			int a;
			for (int i = 0; i <= 4; i++)
			{ //for que repite el ingreso de datos diarios la cantidad de dias de la semana.

				do
				{
					int b;
					a = 0;
					printf(" || DIA %s\n", dia_semana[i]);
					printf("\nIngrese la cantidad de clases a las que debe asistir el DIA %s: ", dia_semana[i]);
					scanf("%d", &cant_clases[i]);
					system("cls");
					cont = 0;

					for (int j = 0; j < cant_clases[i]; j++)
					{ //for que repite el ingreso de datos de cada clase asistida
						//segun la cantidad de clases diarias que tenga el usuario.

						printf(" || DIA %s\n", dia_semana[i]);
						printf("\nIngrese una clase del DIA %s:\n ", dia_semana[i]);			 //Se especifica el orden de entrada para no hacer
						Horarios_clases[i][j].ramo_asociado = seleccion_ramo(cant_ramos, Ramos); //tan complejo el ingreso de datos al .txt.

						do
						{
							b = 0;
							if (j != 0)
							{ //Se muestra por pantalla los horarios previamente ingresados para una mejor compresion de como se guardara el archivo.
								printf("\n\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
								//se imprimen los datos de los horarios ingresados con anterioridad
								imprimir_Horario(Ramos, Horarios_clases[i], Horarios_Ordenados[i]);
							}
							if (j != 0)
							{
								printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
							}
							//Ingreso de las horas de inicio y termino de cada una de las clases de un dia en especifico(esto se hace igual para todos los dias).
							printf("\n || A continuacion ingrese la hora de INICIO y TERMINO de '%s' (use formato 24hrs).\n", Ramos[Horarios_clases[i][j].ramo_asociado].nombre_ramo);

							printf("\nIngrese la hora de inicio en formato 'HH:MM': ");
							scanf("%d:%d", &Horarios_clases[i][j].hora_inicio, &Horarios_clases[i][j].minuto_inicio);

							printf("\nIngrese la hora de termino en formato 'HH:MM': ");
							scanf("%d:%d", &Horarios_clases[i][j].hora_termino, &Horarios_clases[i][j].minuto_termino);

							system("cls");
							for (int m = 0; m < cont; m++)
							{
								if (j == m)
								{
									continue;
								}

								if (((Horarios_clases[i][j].hora_inicio > Horarios_clases[i][m].hora_inicio) && (Horarios_clases[i][j].hora_inicio < Horarios_clases[i][m].hora_termino)) || ((Horarios_clases[i][j].hora_termino > Horarios_clases[i][m].hora_inicio) && (Horarios_clases[i][j].hora_termino < Horarios_clases[i][m].hora_termino)) || ((Horarios_clases[i][j].hora_inicio == Horarios_clases[i][m].hora_inicio) && (Horarios_clases[i][j].minuto_inicio >= Horarios_clases[i][m].minuto_inicio)) || ((Horarios_clases[i][j].hora_termino == Horarios_clases[i][m].hora_inicio) && (Horarios_clases[i][j].minuto_termino >= Horarios_clases[i][m].minuto_inicio)) || ((Horarios_clases[i][j].hora_inicio == Horarios_clases[i][m].hora_termino) && (Horarios_clases[i][j].minuto_inicio <= Horarios_clases[i][m].minuto_termino)) || ((Horarios_clases[i][j].hora_termino == Horarios_clases[i][m].hora_termino) && (Horarios_clases[i][j].minuto_termino <= Horarios_clases[i][m].minuto_termino)))
								{ //Este if corrobora que ninguno de los horarios anteriormente ingresados irrumpan con el actual, en el caso de que irrumpan se consulta al usuario si desea guardar igualmente el horario.
									printf("Este horario ingresado irrumpe con el horario: %s (%d:%d ~ %d:%d)\n", Ramos[Horarios_clases[i][m].ramo_asociado].nombre_ramo, Horarios_clases[i][m].hora_inicio, Horarios_clases[i][m].minuto_inicio, Horarios_clases[i][m].hora_termino, Horarios_clases[i][m].minuto_termino);
									printf("\nDesea continuar?\n");
									printf(" 1. Si\n");
									printf(" 2. No (ingresar un nuevo horario)\n");
									printf("\nIngrese una opcion: ");
									scanf("%d", &b);
									system("cls");
									break;
								}
							}
							cont++;

						} while (b == 2); //Este do while es en el caso de querer editar el horario ingresado de la ultima clase.

						//se insertan los datos en la lista
						inserta_Horario(Horarios_clases[i][j], Horarios_Ordenados[i], b);
					}
					printf(" || HORARIO DIA %s\n\n", dia_semana[i]);
					printf("El horario del DIA %s quedara de la siguiente manera:\n", dia_semana[i]); //Se muestra la vista previa del ingreso de horarios diarios.
					printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

					imprimir_Horario(Ramos, Horarios_clases[i], Horarios_Ordenados[i]);

					printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
					//Se consulta nuevamente por si se observa algun error en lo ingresado.

					printf("\nEs correcta la informacion?\n\n");
					printf(" 1. Si\n");
					printf(" 2. No (se realizara nuevamente)\n");
					printf("\nIngrese una opcion: ");
					scanf("%d", &a);
					system("cls");

					if (a == 2)
					{
						while (Horarios_Ordenados[i] != NULL)
						{
							eliminar_Lista(i, Horarios_Ordenados[i], Horarios_clases[i]);
						}
					}

				} while (a == 2); //Este do while es en el caso de que el usuario quiera ingresar desde 0 los horarios diarios.
			}

			for (int i = 0; i < cant_semanas; i++)
			{ //Pega los datos en los txt creados con el for en un formato especifico.

				FILE *arch = fopen(semana[i], "w");
				fprintf(arch, "Ramos:\n\n");
				for (int j = 0; j < cant_ramos; j++)
				{
					fprintf(arch, "(%d) %s / %s\n", j + 1, Ramos[j].nombre_ramo, Ramos[j].nombre_profe);
				}
				fprintf(arch, "\n~*~* HORARIOS Y EVENTOS *~*~\n\n");

				for (int k = 0; k <= 4; k++)
				{
					if (cant_clases[k] == 0)
					{
						continue;
					}

					fprintf(arch, "[HORARIOS] %s:\n", dia_semana[k]);
					//se crea una cadena de listas por dia para ingresar los datos ordenados
					nodo_clase *actual[7] = {new nodo_clase(), new nodo_clase(), new nodo_clase(), new nodo_clase(), new nodo_clase(), new nodo_clase(), new nodo_clase()};
					actual[k] = Horarios_Ordenados[k];

					for (int m = 0; actual[k] != NULL; m++)
					{
						fprintf(arch, " [%d] %s (%d:%d - %d:%d)\n", m + 1, Ramos[actual[k]->dato.ramo_asociado].nombre_ramo, actual[k]->dato.hora_inicio, actual[k]->dato.minuto_inicio, actual[k]->dato.hora_termino, actual[k]->dato.minuto_termino);
						actual[k] = actual[k]->next;
					}
					fprintf(arch, "[EVENTOS] %s:\n", dia_semana[k]);

					fprintf(arch, "\n----------------------------------------------\n");
				}

				fclose(arch);
			}

			for (int i = 0; i <= 4; i++)
			{
				while (Horarios_Ordenados[i] != NULL)
				{
					eliminar_Lista(i, Horarios_Ordenados[i], Horarios_clases[i]);
				}
			}

			{
				FILE *f = fopen("trash.txt", "w"); //Generamos un archivo trash que no tiene como objetivo ser abierto por el usuario, solamente con el fin de guardar datos que optimicen la funcionalidad del programa.
				fprintf(f, "%d %d\n", cant_semanas, cant_ramos);
				for (int i = 0; i <= 4; i++)
				{
					fprintf(f, "%d\n", cant_clases[i]);
				}
				for (int i = 0; i <= 4; i++)
				{
					for (int j = 0; j < cant_clases[i]; j++)
					{
						fprintf(f, "%d\n", Horarios_clases[i][j].ramo_asociado);
					}
				}
				for (int i = 0; i <= 4; i++)
				{
					for (int j = 0; j < cant_clases[i]; j++)
					{
						fprintf(f, "%d\n", Horarios_clases[i][j].hora_inicio);
					}
				}
				for (int i = 0; i <= 4; i++)
				{
					for (int j = 0; j < cant_clases[i]; j++)
					{
						fprintf(f, "%d\n", Horarios_clases[i][j].minuto_inicio);
					}
				}
				for (int i = 0; i <= 4; i++)
				{
					for (int j = 0; j < cant_clases[i]; j++)
					{
						fprintf(f, "%d\n", Horarios_clases[i][j].hora_termino);
					}
				}
				for (int i = 0; i <= 4; i++)
				{
					for (int j = 0; j < cant_clases[i]; j++)
					{
						fprintf(f, "%d\n", Horarios_clases[i][j].minuto_termino);
					}
				}
				for (int i = 0; i <= 4; i++)
				{
					for (int j = 0; j < cant_clases[i]; j++)
					{
						fprintf(f, "%s\n", Ramos[Horarios_clases[i][j].ramo_asociado].nombre_ramo);
					}
				}
				for (int i = 0; i <= 4; i++)
				{
					for (int j = 0; j < cant_clases[i]; j++)
					{
						fprintf(f, "%s\n", Ramos[Horarios_clases[i][j].ramo_asociado].link_clase);
					}
				}

				fclose(f);
			}

			printf(" **=====================================**\n");
			printf(" ||\t      Bienvenido a tu\t\t||\n ||\tH O R A R I O  V I R T U A L\t||\n");
			printf(" **=====================================**\n\n");

			break;
		}
		case 2:
		{
			{ //Caso 2: Crear un evento en una semana, dia y hora en especifico una vez realizado el horario fijo (caso 1).
				FILE *f0 = fopen("trash.txt", "r");
				if (f0 == NULL)
				{ //Se corrobora que el archivo trash esta creado, en el caso de que no lo esté, informar al usuario que todavia no tiene creado un Horario Fijo y enviarlo al menu principal.
					printf("Todavia no ha creado un horario fijo.\n");
					system("pause");
					system("cls");
					fclose(f0);
					break;
				}
				fscanf(f0, "%d %d\n", &cant_semanas, &cant_ramos); //Se leen los datos dentro del trash para ser utilizados en el programa.
				for (int i = 0; i <= 4; i++)
				{
					fscanf(f0, "%d\n", &cant_clases[i]);
				}
				for (int i = 0; i <= 4; i++)
				{
					for (int j = 0; j < cant_clases[i]; j++)
					{
						fscanf(f0, "%d\n", &Horarios_clases[i][j].ramo_asociado);
					}
				}
				for (int i = 0; i <= 4; i++)
				{
					for (int j = 0; j < cant_clases[i]; j++)
					{
						fscanf(f0, "%d\n", &Horarios_clases[i][j].hora_inicio);
					}
				}
				for (int i = 0; i <= 4; i++)
				{
					for (int j = 0; j < cant_clases[i]; j++)
					{
						fscanf(f0, "%d\n", &Horarios_clases[i][j].minuto_inicio);
					}
				}
				for (int i = 0; i <= 4; i++)
				{
					for (int j = 0; j < cant_clases[i]; j++)
					{
						fscanf(f0, "%d\n", &Horarios_clases[i][j].hora_termino);
					}
				}
				for (int i = 0; i <= 4; i++)
				{
					for (int j = 0; j < cant_clases[i]; j++)
					{
						fscanf(f0, "%d\n", &Horarios_clases[i][j].minuto_termino);
					}
				}
				for (int i = 0; i <= 4; i++)
				{
					for (int j = 0; j < cant_clases[i]; j++)
					{
						fscanf(f0, "%[^\n]\n", Ramos[Horarios_clases[i][j].ramo_asociado].nombre_ramo);
					}
				}
				for (int i = 0; i <= 4; i++)
				{
					for (int j = 0; j < cant_clases[i]; j++)
					{
						fscanf(f0, "%[^\n]\n", Ramos[Horarios_clases[i][j].ramo_asociado].link_clase);
					}
				}
				fclose(f0);
			}
			int d;

			printf("Ingrese la semana en la que quiere añadir un evento: "); //Inicio de el ingreso de datos para crear el evento.
			scanf("%d", &Semana_evento);
			{

				FILE *f;
				f = fopen(semana[Semana_evento - 1], "r+");
				if (f == NULL)
				{ //Se corrobora que la semana ingresada exista, de no ser asi, informar al usuario que no existe y enviarlo al menu anterior.
					printf("ERROR!! La semana seleccionada no existe\n");
					system("pause");
					system("cls");
					fclose(f);
					break;
				}
				fclose(f);
			}

			printf("Los dias son los siguientes:\n\n");
			printf("1. Lunes\n2. Martes\n3. Miercoles\n4. Jueves\n");
			printf("5. Viernes\n6. Sabado\n7. Domingo\n");
			printf("\nIngrese el dia en el que quiere ingresar el evento: ");
			scanf("%d", &Dia_evento);

			int cantidad_eventos[7];

			int cont1 = 0;
			int cont2 = 0;
			int cont3 = 0;

			char aux1[150];
			char indicador1[30] = "[EVENTOS] ";
			char dos_puntos[3] = ":\n";
			char indicador2[48] = "----------------------------------------------\n";
			strcat(indicador1, dia_semana[Dia_evento - 1]);
			strcat(indicador1, dos_puntos);
			{
				FILE *f = fopen(semana[Semana_evento - 1], "r+");

				//dentro del archivo se busca el lugar donde se quiereempezar a contar la cantidad de archivos
				while (!feof(f))
				{
					fgets(aux1, 150, f);
					if (strcmp(aux1, indicador1) == 0)
					{
						break;
					}
				}
				//con cont3 se cuentan la cantidad de lineas que hay desde el lugar anteriormente buscado hasta el siguente dia de evento

				while (!feof(f))
				{
					fgets(aux1, 150, f);
					cont3++;
					if (strcmp(aux1, indicador2) == 0)
					{
						break;
					}
				}
				//se le otorga la cantidad de eventos que hay en ese dia en especifico a cantidad_eventos[Dia_evento-1] y se le resta 2 dado el formato del archivo
				cantidad_eventos[Dia_evento - 1] = cont3 - 2;
				int posicion;
				//aqui se guardan los eventos que ya se encuentran en el archivo para posteriormente ingresarlos en una lista creada para ordenar los eventos
				fseek(f, 0, SEEK_SET);
				while (!feof(f))
				{
					fgets(aux1, 150, f);
					if (strcmp(aux1, indicador1) == 0)
					{
						for (int p = 0; p < cantidad_eventos[Dia_evento - 1]; p++)
						{
							fscanf(f, " [%d] (%d:%d) %[^\n]\n", &posicion, &Eventos[Semana_evento - 1][Dia_evento - 1][p].hora_evento, &Eventos[Semana_evento - 1][Dia_evento - 1][p].minuto_evento, &Eventos[Semana_evento - 1][Dia_evento - 1][p].descripcion);

							inserta_Evento(Eventos[Semana_evento - 1][Dia_evento - 1][p], Eventos_Ordenados[Dia_evento - 1]);
						}
						break;
					}
				}

				fclose(f);
			}

			do
			{
				d = 0;
				if ((cantidad_eventos[Dia_evento - 1]) > 0)
				{ //Se muestra por pantalla los horarios previamente ingresados para una mejor compresion de como se guardara el archivo.
					printf("\n\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
					//se imprimen los datos de los horarios ingresados con anterioridad
					imprimir_Eventos(Eventos[Semana_evento - 1][Dia_evento - 1][cantidad_eventos[Dia_evento - 1]], Eventos_Ordenados[Dia_evento - 1]);
				}
				if (cantidad_eventos[Dia_evento - 1] > 0)
				{
					printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				}

				printf("\nIngrese hora del evento en formato (HH:MM): ");
				scanf("%d:%d", &Eventos[Semana_evento - 1][Dia_evento - 1][cantidad_eventos[Dia_evento - 1] + 1].hora_evento, &Eventos[Semana_evento - 1][Dia_evento - 1][cantidad_eventos[Dia_evento - 1] + 1].minuto_evento);

				if (!(Dia_evento == 6 || Dia_evento == 7))
				{ //Ya que los dias sabados y domingos no son parte del horario regular de un estudiante se dejan apartados, ademas, dado que los datos en el trash solo guardan informacion de lunes a viernes daría error al inlcuirlos aqui.

					for (int k = 0; k < cant_clases[Dia_evento - 1]; k++)
					{

						if ((Eventos[Semana_evento - 1][Dia_evento - 1][cantidad_eventos[Dia_evento - 1] + 1].hora_evento > Horarios_clases[Dia_evento - 1][k].hora_inicio) && (Eventos[Semana_evento - 1][Dia_evento - 1][cantidad_eventos[Dia_evento - 1] + 1].hora_evento < Horarios_clases[Dia_evento - 1][k].hora_termino))
						{ //Este if corrobora que ninguno de los horarios anteriormente ingresados en el horario fijo irrumpan con el evento, en el caso de que irrumpan se consulta al usuario si desea guardar igualmente el evento.

							printf("\nEl evento ingresado irrumpe con el ramo: %s (%d:%d ~ %d:%d)\n", Ramos[Horarios_clases[Dia_evento - 1][k].ramo_asociado].nombre_ramo, Horarios_clases[Dia_evento - 1][k].hora_inicio, Horarios_clases[Dia_evento - 1][k].minuto_inicio, Horarios_clases[Dia_evento - 1][k].hora_termino, Horarios_clases[Dia_evento - 1][k].minuto_termino);
							printf("Desea continuar?\n");
							printf(" 1. Si\n");
							printf(" 2. No (Ingresar otra hora y minuto del evento)\n");
							scanf("%d", &d);
							break;
						}
						else if ((Eventos[Semana_evento - 1][Dia_evento - 1][cantidad_eventos[Dia_evento - 1] + 1].hora_evento == Horarios_clases[Dia_evento - 1][k].hora_inicio) && (Eventos[Semana_evento - 1][Dia_evento - 1][cantidad_eventos[Dia_evento - 1] + 1].minuto_evento >= Horarios_clases[Dia_evento - 1][k].minuto_inicio))
						{

							printf("\nEl evento ingresado irrumpe con el ramo: %s (%d:%d ~ %d:%d)\n", Ramos[Horarios_clases[Dia_evento - 1][k].ramo_asociado].nombre_ramo, Horarios_clases[Dia_evento - 1][k].hora_inicio, Horarios_clases[Dia_evento - 1][k].minuto_inicio, Horarios_clases[Dia_evento - 1][k].hora_termino, Horarios_clases[Dia_evento - 1][k].minuto_termino);
							printf("Desea continuar?\n");
							printf(" 1. Si\n");
							printf(" 2. No (Ingresar otra hora y minuto del evento)\n");
							scanf("%d", &d);
							break;
						}
						else if ((Eventos[Semana_evento - 1][Dia_evento - 1][cantidad_eventos[Dia_evento - 1] + 1].hora_evento == Horarios_clases[Dia_evento - 1][k].hora_termino) && (Eventos[Semana_evento - 1][Dia_evento - 1][cantidad_eventos[Dia_evento - 1] + 1].minuto_evento <= Horarios_clases[Dia_evento - 1][k].minuto_termino))
						{

							printf("\nEl evento ingresado irrumpe con el ramo: %s (%d:%d ~ %d:%d)\n", Ramos[Horarios_clases[Dia_evento - 1][k].ramo_asociado].nombre_ramo, Horarios_clases[Dia_evento - 1][k].hora_inicio, Horarios_clases[Dia_evento - 1][k].minuto_inicio, Horarios_clases[Dia_evento - 1][k].hora_termino, Horarios_clases[Dia_evento - 1][k].minuto_termino);
							printf("Desea continuar?\n");
							printf(" 1. Si\n");
							printf(" 2. No (Ingresar otra hora y minuto del evento)\n");
							scanf("%d", &d);
							break;
						}
					}
				}
			} while (d == 2); //Este es el while que envia al usuario a ingresar nuevamente la hora del evento.
			{
				printf("Ingrese la descripcion del evento: ");
				fflush(stdin);
				scanf("%[^\n]", Eventos[Semana_evento - 1][Dia_evento - 1][cantidad_eventos[Dia_evento - 1] + 1].descripcion);
				system("cls");

				//se añade el evento recien ingresado a la lista
				inserta_Evento(Eventos[Semana_evento - 1][Dia_evento - 1][cantidad_eventos[Dia_evento - 1] + 1], Eventos_Ordenados[Dia_evento - 1]);

				//Se realizan 2 contadores para distintos txt (uno reemplazara a otro luego de copiar la informacion y añadir el nuevo evento de forma ordenada) los cuales contaran el numero de
				//lineas que tiene cada uno, esto con el fin de verificar cuando uno de los dias no tiene generado un horario fijo y asi añadir igualmente los eventos de forma agrupada por dia.

				FILE *f = fopen(semana[Semana_evento - 1], "r+");
				FILE *f1 = fopen("Semanas/Semana_Auxiliar.txt", "a+");

				fseek(f, 0, SEEK_SET);
				while (!feof(f))
				{ //Se realiza el conteo de el primer archivo y se copia la informacion del archivo original.
					fgets(aux1, 150, f);
					cont1++;
				}
				fseek(f, 0, SEEK_SET);
				while (fgets(aux1, 150, f) != NULL)
				{ //Se realiza el conteo del archivo auxiliar y se pega lo del primer archivo en el archivo auxiliar.
					cont2++;
					fprintf(f1, "%s", aux1);
					if (strcmp(aux1, indicador1) == 0)
					{
						for (int l = 0; l < cantidad_eventos[Dia_evento - 1]; l++)
						{
							fgets(aux1, 150, f);
						}

						break;
					}
				}

				if (cont1 == cont2)
				{ //En el caso de que el dia especificado no tenga una seccion en el archivo se crea una con el nombre del dia y se guarda el evento en esta nueva seccion.
					fprintf(f1, "\n%s", indicador1);
					fprintf(f1, " [%d] (%d:%d) %s \n\n", 1, Eventos[Semana_evento - 1][Dia_evento - 1][cantidad_eventos[Dia_evento - 1] + 1].hora_evento, Eventos[Semana_evento - 1][Dia_evento - 1][cantidad_eventos[Dia_evento - 1] + 1].minuto_evento, Eventos[Semana_evento - 1][Dia_evento - 1][cantidad_eventos[Dia_evento - 1] + 1].descripcion);
					fprintf(f1, "----------------------------------------------\n");
				}
				else
				{ //En el caso de que el dia especificado tenga una seccion en el archivo se añade el evento y ademas el resto de lo almacenado en el archivo original.

					nodo_evento *actual[7] = {new nodo_evento(), new nodo_evento(), new nodo_evento(), new nodo_evento(), new nodo_evento(), new nodo_evento(), new nodo_evento()};
					actual[Dia_evento - 1] = Eventos_Ordenados[Dia_evento - 1];

					for (int p = 0; p < cantidad_eventos[Dia_evento - 1] + 1; p++)
					{
						for (int m = 0; actual[Dia_evento - 1] != NULL; m++)
						{

							fprintf(f1, " [%d] (%d:%d) %s\n", m + 1, actual[Dia_evento - 1]->dato.hora_evento, actual[Dia_evento - 1]->dato.minuto_evento, actual[Dia_evento - 1]->dato.descripcion);
							actual[Dia_evento - 1] = actual[Dia_evento - 1]->next;
						}
					}
					//se copia el resto del archivo original en el auxiliar
					while (fgets(aux1, 150, f) != NULL)
					{
						fprintf(f1, "%s", aux1);
					}
				}
				//se borra a la lista para en un futuro poder ingresar otro evento sin que hayan problemas
				for (int i = 0; i <= 6; i++)
				{
					while (Eventos_Ordenados[i] != NULL)
					{
						eliminar_Lista_Eventos(i, Eventos_Ordenados[i], Eventos[Semana_evento - 1][i]);
					}
				}

				fclose(f1);
				fclose(f);
			}
			remove(semana[Semana_evento - 1]);								  //Se elimina el archivo original.
			rename("Semanas/Semana_Auxiliar.txt", semana[Semana_evento - 1]); //Se renombra el archivo auxiliar por el del archivo original.
			//system("cls");
			printf(" **=====================================**\n");
			printf(" ||\t      Bienvenido a tu\t\t||\n ||\tH O R A R I O  V I R T U A L\t||\n");
			printf(" **=====================================**\n\n");
		}

		break;

		case 3: //Caso 3: Salir del programa.
		{
			return 0;
		}
		break;

		default:
		{
			if ((opcion_selec < 1) || (opcion_selec > 3))
			{ //Entrega un mensaje de error en caso de una entrada erronea.
				system("cls");
				printf(" **=====================================**\n");
				printf(" ||\t      Bienvenido a tu\t\t||\n ||\tH O R A R I O  V I R T U A L\t||\n");
				printf(" **=====================================**\n\n");

				printf("ERROR!! Ingrese una opcion valida.\n\n");
			}
		}

		break;
		}
	}

	return 0;
}

int seleccion_ramo(int cant_ramos, Ramo Ramos[8])
{
	int a;

	for (int i = 0; i < cant_ramos; i++)
	{
		printf("\n %d. %s\n", i + 1, Ramos[i].nombre_ramo);
	}

	printf("\nIngrese la opcion de su ramo: ");
	scanf("%d", &a);

	while ((a <= 0) || (a > (cant_ramos + 1)))
	{
		printf("ERROR!! Ingrese una opcion valida: ");
		scanf("%d", &a);
		system("cls");
	}
	a = a - 1;
	return a;
}
