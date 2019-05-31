#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "lista.h"
#include "pelicula.h"

class Menu{

	private:

			Lista<Pelicula*>* peliculas_vistas;
			Lista<Pelicula*>* peliculas_no_vistas;
			Lista<Pelicula*>* peliculas_recomendadas;
	
	public:

		//Descripcion: Metodo constructor de objetos de clase Menu. 
		//Precondiciones: -.
		//Postcondiciones: Le destina espacio del Heap a los atributos "peliculas_vistas", "peliculas_no_vistas"
		//"peliculas_recomendadas" de un objeto de clase Menu.
		Menu();

		//Descripcion: Se encarga de crear las listas de películas vistas y no vistas a partir de los archivos
		//"peliculas_vistas.txt" y "peliculas_no_vistas.txt".
		//Precondiciones: Le llegan como parametros, los nombres de los archivos de las peliculas vistas y no vistas.
		//Postcondiciones: Las listas de peliculas vistas y no vistas son cargadas correctamente.
		void crear_lista_de_peliculas(char const* peliculas_vistas_txt,char const* peliculas_no_vistas_txt);

		//Descripcion: Muestra por pantalla el menu principal, requiriendole al usuario que ingrese la opcion deseada.
		//Precondiciones: -.
		//Postcondiciones: El menu correspondiente es visualizado por el usuario.
		void interfaz();

		//Descripcion: Metodo destructor de objetos de clase Menu.
		//Precondiciones: -. 
		//Postcondiciones: Se libera la memoria destinada a alocar los atributos de un objeto de clase Menu 
		//"peliculas_vistas", "peliculas_no_vistas" y "peliculas_recomendadas".
		~Menu();

	private:

		//Descripcion: Se encarga de leer los datos de los archivos ingresados por el usuario y guardarlos
		//correctamente en las correspondientes listas de un objeto de clase Menu. 
		//Precondiciones: Le llegan como parametros, el nombre del archivo a analizar, junto con la lista en la cual se 
		//desean guardar los datos del correspondiente archivo.
		//Postcondiciones: Los datos de los archivos son guardados eficientemente en las correspondientes listas.
		void leer_archivo(char const* archivo_txt,Lista<Pelicula*>* lista_de_peliculas);

		//Descripcion: Se imprimen por pantalla todos los datos correspondientes a una determinada pelicula.
		//Precondiciones: Le llega como parametro la pelicula que se desea mostrar por pantalla.
		//Postcondiciones: Los datos de la pelicula pasada como parametro son visualizados por el usuario.
		void mostrar_pelicula(Pelicula* pelicula);

		//Descripcion: Se muestran por pantalla la lista de actores de una determinada pelicula. 
		//Precondiciones: Le llega como parametro, la lista de actores a mostrar por pantalla. 
		//Postcondiciones: La lista de actores pasada como parametro es visualizada por el usuario.
		void mostrar_actores(Lista<string>* lista);

		//Descripcion: De acuerdo con la opcion ingresada por el usuario, se efectua una determinada tarea correspondiente
		//al menu principal. 
		//Precondiciones: Le llega como parametro la opcion ingresada por el usuario.
		//Postcondiciones: Se ejecuta la tarea requerida por el usuario.
		void ejecutar_opcion(int opcion);

		//Descripcion: A partir de una pelicula vista y una no vista, se fija si hay coicidencia en, al menos, uno de los
		//actores de estas dos peliculas. 
		//Precondiciones: Recibe una pelicula vista y una pelicula no vista.
		//Postcondiciones: Devuelve true en caso de que, al menos, coincida un actor de ambas peliculas, o false
		//en caso contrario.
		bool coinciden_actores(Pelicula* peli_v,Pelicula* peli_nv);

		//Descripcion: Se fija si el puntaje de una pelicula no vista que le llega como parametro es alto. Además, revisa
		//si el director de la pelicula no vista coincide con el de la pelicula vista, que tambien le llega como parametro. 
		//Y tambien chequea si alguno de los actores coincide entre estas dos peliculas. 
		//Precondiciones: Recibe una pelicula vista y una pelicula no vista.
		//Postcondiciones: En caso de cumpla alguna de estas condiciones de pelicula recomendable, devuelve true, o 
		//false en caso contrario.
		bool cumple_condiciones_peli_recomendable(Pelicula* peli_v,Pelicula* peli_nv);

		//Descripcion: Determina si una pelicula no vista puede considerarse como pelicula recomendable.
		//Precondiciones: Le llega como paramatro la susodicha pelicula no vista.
		//Postcondiciones: Devuelve true en caso de que la pelicula pueda considerarse recomendable, o false en caso contrario.
		bool es_pelicula_recomendada(Pelicula* peli_nv);

		//Descripcion: Muestra por pantalla todas las peliculas de una lista de peliculas determinada. 
		//Precondiciones: Le llega como parametro la lista de pelicula que se desea mostrar.
		//Postcondiciones: Muestra por pantalla todas las peliculas pertenecientes a la lista que se pasa como parametro.
		void mostrar_lista_de_peliculas(Lista<Pelicula*>* lista);

		//Descripcion: Agrega todas las peliculas que puedan considerarse recomendables, al atributo de un objeto de clase
		//Menu "peliculas_recomendadas". 
		//Precondiciones: Las listas de peliculas vistas y no vistas tienen, al menos, una pelicula cada una.
		//Postcondiciones: La lista de peliculas recomendadas es generada correctamente.
		void crear_lista_de_peliculas_recomendadas();
		
		void limpiar_listas(Lista<Pelicula*>* aux_lista);
};