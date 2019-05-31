#ifndef NODO_H
#define NODO_H

#include <iostream>

template < typename Dato >
class Nodo{

	private:
		
		Dato dato;
		
		Nodo<Dato>* siguiente;
		
	public:
		
		//Descripcion: Metodo constructor de objetos de clase Nodo.  
		//Precondiciones: Le llega como parametro el dato que se desea que almacene el nodo.
		//Postcondiciones: El atributo de un objeto de clase Nodo "dato" es igualado a "d", mientras
		//que el atributo "siguiente" es igualado a NULL.
		Nodo(Dato d);

		//Descripcion: El atributo de un objeto de clase Nodo "dato" es asignado a "d", valor que el 
		//metodo recibe como parametro.  
		//Precondiciones: -.
		//Postcondiciones: Se asigna correctamente el atributo de un objeto de clase Nodo "dato" al valor "d".
		void cambiar_dato(Dato d);

		//Descripcion: El atributo de un objeto de clase Nodo "siguiente" es asignado a "ps", valor que el 
		//metodo recibe como parametro. 
		//Precondiciones: Recibe el puntero al cual se desea igualar el atributo "siguiente" de un objeto
		//de clase Nodo. 
		//Postcondiciones: El atributo "siguiente" de un objeto de clase Nodo es asignado correctamente.
		void cambiar_siguiente(Nodo<Dato>* ps);

		//Descripcion: Devuelve el atributo "dato" de un objeto de clase Nodo. 
		//Precondiciones: -.
		//Postcondiciones: El atributo "dato" de un objeto de clase Nodo es devuelto correctamente.
		Dato obtener_dato();

		//Descripcion: Devuelve el atributo "siguiente" de un objeto de clase Nodo. 
		//Precondiciones: -.
		//Postcondiciones: El atributo "siguiente" de un objeto de clase Nodo es devuelto correctamente.
		Nodo* obtener_siguiente();
};

template < typename Dato >
Nodo<Dato>::Nodo(Dato d){
	dato = d;
	siguiente = NULL;
}

template < typename Dato >
void Nodo<Dato>::cambiar_dato(Dato d){
 	dato = d;
}

template < typename Dato >
void Nodo<Dato>::cambiar_siguiente(Nodo<Dato>* ps){
	siguiente = ps;
}

template < typename Dato >
Dato Nodo<Dato>::obtener_dato(){
	return dato;
}

template < typename Dato >
Nodo<Dato>* Nodo<Dato>::obtener_siguiente(){
	return siguiente;
}

#endif
