#ifndef _PELICULA_H_
#define _PELICULA_H_

#include <iostream>
#include <string>
#include "lista.h"

using namespace std;

class Pelicula{

	private:

		string nombre;
		string genero;
		int puntaje;
		string director;
		Lista<string>* actores;

	public:

		//Descripcion: Metodo constructor de objetos de clase Pelicula. 
		//Precondiciones: Recibe el nombre, genero, director y puntaje de la pelicula que se desea
		//crear. Todos los valores que le llegan como parametro pertencen al dominio de los correspondientes
		//atributos de un objeto de clase Pelicula.
		//Postcondiciones: Los atributos de un objeto de clase Pelicula son asignados a las respectivas 
		//variables que se pasan como parametro. 
		Pelicula(string nombre,string genero,string director,int puntaje);

		//Descripcion: Devuelve el atributo "nombre" de un objeto de clase Pelicula.  
		//Precondiciones: -.
		//Postcondiciones: El atributo "nombre" de un objeto de clase Pelicula es devuelto correctamente.
		string obtener_nombre();

		//Descripcion: Devuelve el atributo "genero" de un objeto de clase Pelicula.  
		//Precondiciones: -.
		//Postcondiciones: El atributo "genero" de un objeto de clase Pelicula es devuelto correctamente.
		string obtener_genero();

		//Descripcion: Devuelve el atributo "director" de un objeto de clase Pelicula.  
		//Precondiciones: -.
		//Postcondiciones: El atributo "director" de un objeto de clase Pelicula es devuelto correctamente.
		string obtener_director();

		//Descripcion: Devuelve el atributo "puntaje" de un objeto de clase Pelicula.  
		//Precondiciones: -.
		//Postcondiciones: El atributo "puntaje" de un objeto de clase Pelicula es devuelto correctamente.
		int obtener_puntaje();

		//Descripcion: Agrega un actor a la lista de string "actores" de un objeto de clase Pelicula.  
		//Precondiciones: Le llega como parametro un actor, cuyo nombre pertenece al dominio del atributo
		//"nombre" de un objeto de clase Pelicula.
		//Postcondiciones: El actor es agregado correctamente a la lista de actores de un objeto de clase
		//Pelicula.
		void agregar_actor(string nuevo_actor);

		//Descripcion: Devuelve el atributo "actores" de un objeto de clase Pelicula.  
		//Precondiciones: -.
		//Postcondiciones: El atributo "actores" de un objeto de clase Pelicula es devuelto correctamente.
		Lista<string>* obtener_lista_de_actores();

		~Pelicula();
};


#endif 