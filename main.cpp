#include <iostream>
#include <stdlib.h>
#include "menu.h"

//Ingresar por línea de comando luego de la ejecución del programa los nombres de los archivos de la siguiente forma:
//      ./"nombre_programa" peliculas_vistas peliculas_no_vistas

int main(int argc, char const *argv[]){

	system("clear");

	Menu menu;

	menu.crear_lista_de_peliculas(argv[1],argv[2]);

	menu.interfaz();

	cout<<endl;
	
	return 0;
}