#ifndef TDA_H_
#define TDA_H_

#include <stdlib.h>

#include "tda.c"

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

#endif // TDA_H_