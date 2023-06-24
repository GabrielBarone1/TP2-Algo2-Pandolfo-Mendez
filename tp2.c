#include <stdio.h>
#include "tda.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hash.h"

#define ERROR -1
#define EXITO 0

int main()
{
	struct hospitales *hospitales = crear_hospital_general();
	hash_t *comandos = hash_crear(10);
	comandos = insertar_hash(comandos);
	menu_t *menu = crear_menu(hospitales);
	menu->comandos = comandos;
	if (!hospitales || !menu)
		return ERROR;
	printf("Bienvenido, ingrese una opcion valida, si no conoce los comandos presione 'H'\n");

	bool salir_programa = false;
	while (salir_programa == false) {
		struct nodo *comando = hash_obtener(menu->comandos, "menu");
		comando->funcion(menu->hospital_general);
		printf("\nIngrese una opcion valida: ");
		scanf(" %c", &menu->desicion_usuario);
		salir_programa = ejecutar_opcion(menu, menu->desicion_usuario);
	}

	menu_liberar_memoria(hospitales, menu);

	return EXITO;
}
