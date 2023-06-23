#include "tda.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ERROR -1
#define EXITO 0

int main()
{
	struct hospitales *hospitales = crear_hospital_general();
	menu_t *menu = crear_menu(hospitales);
	printf("Bienvenido, ingrese una opcion valida, si no conoce los comandos presione 'H'\n");

	bool salir_programa = false;
	while (salir_programa == false) {
		menu_usuario(menu->hospital_general);
		printf("\nIngrese una opcion valida: ");
		scanf(" %c", &menu->desicion_usuario);
		salir_programa = ejecutar_opcion(menu, menu->desicion_usuario);
	}

	menu_liberar_memoria(hospitales, menu);

	return EXITO;
}
