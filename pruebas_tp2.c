#include <stdio.h>
#include "tda.h"
#include "pa2m.h"
#include <stdbool.h>

void pruebas_tp2()
{
	pa2m_afirmar(
		pokemones_en_hospital(NULL) == ERROR,
		"No se pueden ver los nombres de un hospital con una estructura NULL");
	pa2m_afirmar(
		lista_pokemones(NULL) == ERROR,
		"No se pueden ver los datos de un hospital con una estructura NULL");
	pa2m_afirmar(menu_usuario(NULL) == ERROR,
		     "No se pueden acceder al menu con una estructura NULL");
	pa2m_afirmar(crear_hospital(NULL, 0, "hospital1.txt") == ERROR,
		     "No se puede crear un hospital con una estructura NULL");
	pa2m_afirmar(
		hospitales_activos(NULL) == ERROR,
		"No se pueden ver los hospitales activos con una estructura NULL");
	pa2m_afirmar(
		destruir_hospital(NULL) == ERROR,
		"No se puede destruir un hospital con una estructura NULL");
	pa2m_afirmar(activar_hospital(NULL) == ERROR,
		     "No se puede activar un hospital con una estructura NULL");
	pa2m_afirmar(
		menu_liberar_memoria(NULL, NULL) == ERROR,
		"No se puede liberar memoria de un hospital o menu con una estructura NULL");

	struct hospitales *hospitales = calloc(1, sizeof(struct hospitales));
	hospitales->hospitales_creados = malloc(sizeof(hospital_t));
	pa2m_afirmar(
		crear_menu(NULL) == NULL,
		"No se puede crear un menu con una estructura hospitales NULL");
	menu_t *menu = crear_menu(hospitales);
	menu->hospital_general = hospitales;
	pa2m_afirmar(menu != NULL, "Se crea el menu correctamente");
	pa2m_afirmar(
		ejecutar_opcion(NULL, 'c') == true,
		"No se puede ejecutar una opcion el una estructura menu NULL");

	pa2m_afirmar(menu->hospital_general->cant_hospitales == 0,
		     "Al inicio del programa la cantidad de hospitales es 0");
	pa2m_afirmar(crear_hospital(menu->hospital_general, 0, "hola") == ERROR,
		     "No se puede crear un hospital con un archivo invalido");
	pa2m_afirmar(crear_hospital(menu->hospital_general, 0,
				    "hospital1.txt") == EXITO,
		     "Se crea un hospital exitosamente");
	pa2m_afirmar(
		menu->hospital_general->cant_hospitales == 1,
		"Al crearse un hospital, la cantidad de hospitales es correcta");
	pa2m_afirmar(crear_hospital(menu->hospital_general, 1,
				    "ejemplos/grande.txt") == EXITO,
		     "Se crea el segundo hospital con exito");
	pa2m_afirmar(menu->hospital_general->cant_hospitales == 2,
		     "La cantidad de hospitales es correcta");

	printf("Despues de ordenar los pokemones por salud..\n");
	pa2m_afirmar(strcmp(menu->hospital_general->hospitales_creados[0]
				    ->pokemones[2]
				    ->nombre,
			    "Lapras") == 0,
		     "El nombre del primer pokemon es correcto");
	pa2m_afirmar(menu->hospital_general->hospitales_creados[0]
				     ->pokemones[2]
				     ->id == 2,
		     "El ID del primer pokemon es correcto");
	pa2m_afirmar(menu->hospital_general->hospitales_creados[0]
				     ->pokemones[2]
				     ->salud == 35,
		     "La salud del primer pokemon es correcto");
	pa2m_afirmar(strcmp(menu->hospital_general->hospitales_creados[0]
				    ->pokemones[2]
				    ->nombre_entrenador,
			    "Abril") == 0,
		     "El nombre del entrenador del primer pokemon es correcto");

	pa2m_afirmar(strcmp(menu->hospital_general->hospitales_creados[0]
				    ->pokemones[1]
				    ->nombre,
			    "Pikachu") == 0,
		     "El nombre del segundo pokemon es correcto");
	pa2m_afirmar(menu->hospital_general->hospitales_creados[0]
				     ->pokemones[1]
				     ->id == 1,
		     "El ID del segundo pokemon es correcto");
	pa2m_afirmar(menu->hospital_general->hospitales_creados[0]
				     ->pokemones[1]
				     ->salud == 20,
		     "La salud del segundo pokemon es correcto");
	pa2m_afirmar(
		strcmp(menu->hospital_general->hospitales_creados[0]
			       ->pokemones[1]
			       ->nombre_entrenador,
		       "Lucas") == 0,
		"El nombre del entrenador del segundo pokemon es correcto");

	pa2m_afirmar(strcmp(menu->hospital_general->hospitales_creados[0]
				    ->pokemones[0]
				    ->nombre,
			    "Jynx") == 0,
		     "El nombre del tercer pokemon es correcto");
	pa2m_afirmar(menu->hospital_general->hospitales_creados[0]
				     ->pokemones[0]
				     ->id == 3,
		     "El ID del tercer pokemon es correcto");
	pa2m_afirmar(menu->hospital_general->hospitales_creados[0]
				     ->pokemones[0]
				     ->salud == 2,
		     "La salud del tercer pokemon es correcto");
	pa2m_afirmar(strcmp(menu->hospital_general->hospitales_creados[0]
				    ->pokemones[0]
				    ->nombre_entrenador,
			    "Nico") == 0,
		     "El nombre del entrenador del tercer pokemon es correcto");

	for (size_t i = 0; i < menu->hospital_general->cant_hospitales; i++)
		hospital_destruir(
			menu->hospital_general->hospitales_creados[i]);

	free(hospitales->hospitales_creados);
	free(menu->hospital_general);
	free(menu);

	return;
}

int main()
{
	pa2m_nuevo_grupo("Pruebas TP2");

	pruebas_tp2();

	return pa2m_mostrar_reporte();
}