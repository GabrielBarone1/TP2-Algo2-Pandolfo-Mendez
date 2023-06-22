#ifndef TDA_H_
#define TDA_H_

#include <stdlib.h>

#include "tda.c"

int menu_usuario(struct hospitales *hospitales);

void ayuda_usuario();

int crear_hospital(struct hospitales *hospitales, int id_hospital,
		   char nombre_hospital[50]);

int lista_pokemones(struct hospitales *hospitales);

int pokemones_en_hospital(struct hospitales *hospitales);

int hospitales_activos(struct hospitales *hospitales);

int destruir_hospital(struct hospitales *hospitales);

int activar_hospital(struct hospitales *hospitales);

#endif // TDA_H_