#ifndef TDA_H_
#define TDA_H_

#include <stdlib.h>

#include "tda.c"

//Crea y devuelve la estructura menu para el programa.
menu_t *crear_menu(struct hospitales *hospital_general);

//Crea y devuelve la estructura hospitales(el hospital general del programa que almacena los hospitales).
struct hospitales *crear_hospital_general();

//Muestra la interfaz del menu para que el usuario se guie como usar el programa.
//Retorna -1 en caso de error o retorna 0 en caso de exito.
bool menu_usuario(void *contexto);

//Muestra todas las opciones disponibles detalladamente para que el usuario sepa como usar el programa.
bool ayuda_usuario();

//Crea un hospital y lo agrega a la estructura global donde se guardan todos los hospitales.
//Retorna -1 en caso de error o retorna 0 en caso de exito.
int crear_hospital(struct hospitales *hospitales, int id_hospital,
		   char nombre_hospital[50]);

//Muestra todos los detalles de los pokemones almacenados en el hospital activo.
//Retorna -1 en caso de error o retorna 0 en caso de exito.
bool lista_pokemones(void *contexto);

//Muestra todos los nombres de los pokemones almacenados en el hospital activo.
//Retorna -1 en caso de error o retorna 0 en caso de exito.
bool pokemones_en_hospital(void *contexto);

//Muestra todos los hospitales disponibles y el activo.
//Retorna -1 en caso de error o retorna 0 en caso de exito.
bool hospitales_activos(void *contexto);

//Destruye el hospital activo y le pregunta al usuario que hospital desea activar.
//Retorna -1 en caso de error o retorna 0 en caso de exito.
bool destruir_hospital(void *contexto);

//Activa el hospital que el usuario desee.
//Retorna -1 en caso de error o retorna 0 en caso de exito.
bool activar_hospital(void *contexto);

//Ejecuta la opcion que el usuario eligio por pantalla, devuelve un booleano para determinar si
//seguir o no con el programa.
bool ejecutar_opcion(menu_t *menu, char desicion_usuario);

//Libera toda la memoria del programa.
//Retorna -1 en caso de error o retorna 0 en caso de exito.
int menu_liberar_memoria(struct hospitales *hospitales, menu_t *menu);

#endif // TDA_H_