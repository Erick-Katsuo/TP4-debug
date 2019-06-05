#include <iostream>
#include <stdlib.h>
#include "menu.h"

int const PELICULAS_VISTAS = 1;
int const PELICULAS_NO_VISTAS = 2;

//Ingresar por línea de comando luego de la ejecución del programa los nombres de los archivos de la siguiente forma:
//      ./"nombre_programa" peliculas_vistas peliculas_no_vistas

int main(int argc, char const *argv[]){

	system("clear");

	Menu menu;

	menu.crear_lista_de_peliculas(argv[PELICULAS_VISTAS],argv[PELICULAS_NO_VISTAS]);

	menu.interfaz();

	cout<<endl;
	
	return 0;
}