#include "tda.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ERROR -1
#define EXITO 0

int main()
{
	struct hospitales *hospitales = malloc(sizeof(struct hospitales));
	if (!hospitales)
		return ERROR;
	hospitales->hospitales_creados = malloc(sizeof(hospital_t));
	if (!hospitales->hospitales_creados) {
		free(hospitales);
		return ERROR;
	}
	hospitales->cant_hospitales = 0;
	hospitales->valor_actual = 0;
	int id_hospital = 0;
	char desicion_usuario;

	printf("Bienvenido, ingrese una opcion valida, si no conoce los comandos presione 'H'\n");
	bool usuario_eligio_salir = false;

	while (usuario_eligio_salir == false) {
		menu_usuario(hospitales);
		printf("Ingrese una opcion valida: ");
		scanf(" %c", &desicion_usuario);
		system("clear");

		if (desicion_usuario == 's' || desicion_usuario == 'S') {
			usuario_eligio_salir = true;
		} else if (desicion_usuario == 'h' || desicion_usuario == 'H') {
			printf("\n");
			ayuda_usuario();
		} else if (desicion_usuario == 'c' || desicion_usuario == 'C') {
			char nombre_hospital[50];
			printf("Ingrese el nombre del archivo: ");
			scanf(" %s", nombre_hospital);

			int resultado_crear = crear_hospital(
				hospitales, id_hospital, nombre_hospital);

			if (resultado_crear == ERROR) {
				printf("Hubo un error al cargar el archivo, asegurese que sea valido");
			} else if (resultado_crear == EXITO) {
				id_hospital++;
			}
		} else if (desicion_usuario == 'e' || desicion_usuario == 'E') {
			printf("\n");
			if (hospitales->cant_hospitales == 0) {
				printf("No hay ningun hospital cargado!");
			} else if (hospitales->cant_hospitales > 0) {
				hospitales_activos(hospitales);
			}
		} else if (desicion_usuario == 'a' || desicion_usuario == 'A') {
			printf("\n");
			if (hospitales->cant_hospitales > 0) {
				activar_hospital(hospitales);
			} else if (hospitales->cant_hospitales == 0) {
				printf("No hay ningun hospital disponible para activar!");
			}

		} else if (desicion_usuario == 'm' || desicion_usuario == 'M') {
			if (hospitales->cant_hospitales > 0) {
				pokemones_en_hospital(hospitales);
			} else if (hospitales->cant_hospitales == 0) {
				printf("\n");
				printf("No hay ningun hospital disponible para mostrar!");
			}
		} else if (desicion_usuario == 'l' || desicion_usuario == 'L') {
			if (hospitales->cant_hospitales > 0) {
				lista_pokemones(hospitales);
			} else if (hospitales->cant_hospitales == 0) {
				printf("\n");
				printf("No hay ningun hospital disponible para mostrar!");
			}
		} else if (desicion_usuario == 'd' || desicion_usuario == 'D') {
			destruir_hospital(hospitales);
		}

		printf("\n");
	}

	liberar_memoria(hospitales);

	return EXITO;
}
