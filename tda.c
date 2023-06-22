#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/tp1.h"
#include "src/tp1.c"
#include "src/pokemon.h"
#include "src/pokemon.c"

#define ERROR -1
#define EXITO 0

struct hospitales {
	size_t cant_hospitales;
	size_t valor_actual;
	hospital_t **hospitales_creados;
};

int menu_usuario(struct hospitales *hospitales)
{
	if (!hospitales)
		return ERROR;

	if (hospitales->cant_hospitales > 0) {
		printf("Hospital actual: %s\n",
		       hospitales->hospitales_creados[hospitales->valor_actual]
			       ->nombre_archivo);
		printf("ID del hospital actual: %i\n",
		       hospitales->hospitales_creados[hospitales->valor_actual]
			       ->numero_id);
	}

	printf("\n");
	printf("Opciones Disponibles: \n");
	printf("-H (ayuda/help)\n");
	printf("-C (Crear un hospital)\n");
	printf("-E (Estado del hospital)\n");
	printf("-A (Activar un hospital)\n");
	printf("-M (Mostrar nombres del hospital)\n");
	printf("-L (Listar datos del hospital)\n");
	printf("-D (Destruir el hospital)\n");
	printf("-S (salir/exit)\n");

	return EXITO;
}

void ayuda_usuario()
{
	printf("Los comandos disponibles son:\n");
	printf("- H (ayuda/help): Muestra un menú de ayuda con los comandos disponibles.\n");
	printf("- C (cargar): Pide un nombre de archivo e intenta cargarlo creando un hospital. El hospital queda identificado con un número y el nombre del archivo.\n");
	printf("- E (estado): Muestra un listado con los hospitales cargados.\n");
	printf("- A (activar): Pide un número de identificación y activa el hospital. El resto de las operaciones se realizan sobre el hospital activo.\n");
	printf("- M (mostrar): Muestra un listado con los nombres de todos los pokemones en el hospital.\n");
	printf("- L (listar): Muestra un listado detallado de todos los pokemones en el hospital.\n");
	printf("- D (destruir): Destruye el hospital activo.\n");
	printf("- S (salir/exit): Sale del programa (obviamente que libera toda la memoria).\n");

	return;
}

int crear_hospital(struct hospitales *hospitales, int id_hospital,
		   char nombre_hospital[50])
{
	if (!hospitales)
		return ERROR;

	hospital_t *hospital = hospital_crear_desde_archivo(nombre_hospital);
	if (!hospital)
		return ERROR;

	printf("Creando hospital..\n");
	printf("El hospital se ha creado con exito!\n");
	if (hospitales->cant_hospitales >= 1) {
		hospital_t **hospitales_aux = realloc(
			hospitales->hospitales_creados,
			sizeof(hospital_t) * (hospitales->cant_hospitales + 1));
		if (hospitales_aux == NULL) {
			free(hospitales->hospitales_creados);
			free(hospitales);
			return ERROR;
		}
		hospitales->hospitales_creados = hospitales_aux;
	}

	strcpy(hospital->nombre_archivo, nombre_hospital);
	hospital->numero_id = id_hospital;
	hospitales->hospitales_creados[hospitales->cant_hospitales] = hospital;
	hospitales->cant_hospitales++;

	return EXITO;
}

int lista_pokemones(struct hospitales *hospitales)
{
	if (!hospitales)
		return ERROR;

	printf("Lista de Pokemones del Hospital con ID : %zu\n",
	       hospitales->valor_actual);
	printf("\n");
	for (size_t i = 0;
	     i < hospitales->hospitales_creados[hospitales->valor_actual]
			 ->cantidad_pokemon;
	     i++) {
		printf("Nombre del pokemon: %s\n",
		       hospitales->hospitales_creados[hospitales->valor_actual]
			       ->pokemones[i]
			       ->nombre);
		printf("ID del pokemon: %zu\n",
		       hospitales->hospitales_creados[hospitales->valor_actual]
			       ->pokemones[i]
			       ->id);
		printf("Salud del pokemon: %zu\n",
		       hospitales->hospitales_creados[hospitales->valor_actual]
			       ->pokemones[i]
			       ->salud);
		printf("Nombre del entrenador: %s\n",
		       hospitales->hospitales_creados[hospitales->valor_actual]
			       ->pokemones[i]
			       ->nombre_entrenador);
		printf("\n");
	}

	return EXITO;
}

int pokemones_en_hospital(struct hospitales *hospitales)
{
	if (!hospitales)
		return ERROR;

	printf("\n");
	printf("Nombres de todos los Pokemones del Hospital\n");
	for (size_t i = 0;
	     i < hospitales->hospitales_creados[hospitales->valor_actual]
			 ->cantidad_pokemon;
	     i++) {
		printf("- %s\n",
		       hospitales->hospitales_creados[hospitales->valor_actual]
			       ->pokemones[i]
			       ->nombre);
	}

	return EXITO;
}

int hospitales_activos(struct hospitales *hospitales)
{
	if (!hospitales)
		return ERROR;

	printf("\n");
	printf("Hospitales Disponibles:\n");
	for (size_t i = 0; i < hospitales->cant_hospitales; i++) {
		printf("Nombre Hospital: %s",
		       hospitales->hospitales_creados[i]->nombre_archivo);
		if (hospitales->hospitales_creados[i]->numero_id ==
		    hospitales->valor_actual) {
			printf(" (Hospital actualmente activo)");
		}
		printf("\n");
		printf("ID del hospital: %i\n",
		       hospitales->hospitales_creados[i]->numero_id);
		printf("\n");
	}

	return EXITO;
}

int destruir_hospital(struct hospitales *hospitales)
{
	if (!hospitales)
		return ERROR;

	if (hospitales->cant_hospitales == 1) {
		hospital_destruir(hospitales->hospitales_creados[0]);
		hospitales->cant_hospitales--;
	} else if (hospitales->cant_hospitales > 1) {
		hospital_t *hospital_aux =
			hospitales->hospitales_creados
				[hospitales->cant_hospitales - 1];
		hospital_destruir(
			hospitales
				->hospitales_creados[hospitales->valor_actual]);
		hospitales->hospitales_creados[hospitales->valor_actual] =
			hospital_aux;
		hospitales->cant_hospitales--;
	}

	bool id_encontrado = false;
	int valor_hospital;

	if (hospitales->cant_hospitales > 0) {
		while (id_encontrado == false) {
			printf("Ingrese que hospital quiere activar: ");
			scanf(" %i", &valor_hospital);
			for (size_t i = 0; i < hospitales->cant_hospitales;
			     i++) {
				if (hospitales->hospitales_creados[i]
					    ->numero_id == valor_hospital) {
					id_encontrado = true;
				}
			}

			if (id_encontrado == false) {
				printf("Ingrese un ID de un hospital valido\n");
			}
		}
		hospitales->valor_actual = (size_t)valor_hospital;
	}

	return EXITO;
}

int activar_hospital(struct hospitales *hospitales)
{
	if (!hospitales)
		return ERROR;

	bool id_encontrado = false;
	int valor_hospital;

	while (id_encontrado == false) {
		printf("Ingrese que hospital quiere activar: ");
		scanf(" %i", &valor_hospital);
		for (size_t i = 0; i < hospitales->cant_hospitales; i++) {
			if (hospitales->hospitales_creados[i]->numero_id ==
			    valor_hospital) {
				id_encontrado = true;
			}
		}

		if (id_encontrado == false) {
			printf("Ingrese un ID de un hospital valido\n");
		}
	}

	hospitales->valor_actual = (size_t)valor_hospital;

	return EXITO;
}

int liberar_memoria(struct hospitales *hospitales)
{
	if (!hospitales)
		return ERROR;

	if (hospitales->cant_hospitales > 0) {
		for (size_t i = 0; i < hospitales->cant_hospitales; i++) {
			if (hospitales->hospitales_creados[i] != NULL) {
				hospital_destruir(
					hospitales->hospitales_creados[i]);
			}
		}
	}

	free(hospitales->hospitales_creados);
	free(hospitales);

	return EXITO;
}