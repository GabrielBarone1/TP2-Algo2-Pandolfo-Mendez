#ifndef TDA_H_
#define TDA_H_

#include <stdlib.h>

#include "tda.c"

//Crea y devuelve la estructura menu para el programa.
menu_t *crear_menu(struct hospitales *hospital_general);

//Crea y devuelve la estructura hospitales(el hospital general del programa que almacena los hospitales).
struct hospitales *crear_hospital_general();

//Muestra la interfaz del menu para que el usuario se guie como usar el programa.
int menu_usuario(struct hospitales *hospitales);

//Muestra todas las opciones disponibles detalladamente para que el usuario sepa como usar el programa.
void ayuda_usuario();

//Crea un hospital y lo agrega a la estructura global donde se guardan todos los hospitales.
int crear_hospital(struct hospitales *hospitales, int id_hospital,
		   char nombre_hospital[50]);

//Muestra todos los detalles de los pokemones almacenados en el hospital activo.
int lista_pokemones(struct hospitales *hospitales);

//Muestra todos los nombres de los pokemones almacenados en el hospital activo.
int pokemones_en_hospital(struct hospitales *hospitales);

//Muestra todos los hospitales disponibles y el activo.
int hospitales_activos(struct hospitales *hospitales);

//Destruye el hospital activo y le pregunta al usuario que hospital desea activar.
int destruir_hospital(struct hospitales *hospitales);

//Activa el hospital que el usuario desee.
int activar_hospital(struct hospitales *hospitales);

//Ejecuta la opcion que el usuario eligio por pantalla, devuelve un booleano para determinar si
//seguir o no con el programa.
bool ejecutar_opcion(menu_t *menu, char desicion_usuario);

//Libera toda la memoria del programa.
int menu_liberar_memoria(struct hospitales *hospitales, menu_t *menu);

#endif // TDA_H_