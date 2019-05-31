#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"

template < typename Dato >
class Lista{

	private:

		Nodo<Dato>* primero;
		int tam;
	
	public:
		
		//Descripcion: Metodo constructor de objetos de clase Lista. 
		//Precondiciones: -.
		//Postcondiciones: Los atributos "primero" y "tam" de un objeto de clase Lista son igualados a
		//NULL y cero respectivamente.
		Lista();

		//Descripcion: Metodo destructor de objetos de clase Lista. 
		//Precondiciones: -.
		//Postcondiciones: Se eliminan todos los nodos correspondientes a una lista. La liberacion de memoria
		//se realiza en otro metodo que es llamado por este mismo.
		~Lista();

		//Descripcion: Se agrega un nuevo nodo con el dato que le llega como parametro a un objeto de clase
		//Lista en la posicion que tambien el metodo recibe como parametro. 
		//Precondiciones: Recibe el dato a agregar y la posicion en la lista en la cual se desea agregar este dato.
		//"pos" es mayor o igual que uno, y menor o igual a "tam" mas uno.
		//Postcondiciones: El dato es agregado correctamente al objeto de clase Lista.
		void agregar(Dato d,int pos);

		//Descripcion: Devuevle el tammanio del objeto de clase Lista. 
		//Precondiciones: -.
		//Postcondiciones: El tamanio de la lista es devuelto correctamente.
		int tamanio();

		//Descripcion: Se devuelve el dato ubicado en la posicion "pos" de la lista. Esta posicion "pos" es 
		//recibida por el metodo como parametro. 
		//Precondiciones: Le llega como parametro la posicion de la cual se desea obtener el dato.
		//"pos" es mayor o igual que uno, y menor o igual que "tam".
		//Postcondiciones: El dato de la posicion "pos" de la lista es devuelto correctamente.
		Dato consultar(int pos);

		//Descripcion: Se elimina un nodo, correspondiente a la posicion "pos" de un objeto de clase Lista. 
		//"pos" es recibido por el metodo como parametro. 
		//Precondiciones: Le llega como parametro la posicion de la cual se desea eliminar un nodo.
		//"pos" es mayor o igual que uno, y menor o igual que "tam".
		//Postcondiciones: El nodo de la posicion "pos" es eliminado correctamente.
		void eliminar(int pos);

		//Descripcion: Verifica si el objeto de clase Lista tiene al menos un nodo. 
		//Precondiciones: -.
		//Postcondiciones: En caso de que el tamanio de la lista sea cero devuelve true, o false en caso 
		//contrario.
		bool lista_vacia();

	private:

		//Descripcion: Se encarga de obtener el nodo correspondiente a la posicion "pos" de un objeto de 
		//clase Lista. "pos" es recibido por el metodo como parametro. 
		//Precondiciones: Le llega como parametro la posicion de la cual se desea obtener el nodo.
		//"pos" es mayor o igual que uno, y menor o igual que "tam".
		//Postcondiciones: El nodo correspondiente a la posicion "pos" de un objeto de clase Lista es 
		//devuelto correctamente.
		Nodo<Dato>* obtener_nodo(int pos);

		

};

template < typename Dato >
Lista<Dato>::Lista(){
	primero = NULL;
	tam = 0;
}

template < typename Dato >
Nodo<Dato>* Lista<Dato>::obtener_nodo(int pos){
	int j = 1;
	Nodo<Dato>* aux = primero;
	while(j<pos and aux->obtener_siguiente()){
		j++;
		aux = aux->obtener_siguiente();
	}

	return aux;
}

template < typename Dato >
void Lista<Dato>::agregar(Dato d,int pos){

	Nodo<Dato>* nuevo_nodo = new Nodo<Dato>(d);
	if(pos == 1){
		nuevo_nodo->cambiar_siguiente(primero);
		primero = nuevo_nodo;
	}
	else{
		Nodo<Dato>* aux = obtener_nodo(pos-1);
		nuevo_nodo->cambiar_siguiente(aux->obtener_siguiente());
		aux->cambiar_siguiente(nuevo_nodo);
	}
	tam++;
}

template < typename Dato >
int Lista<Dato>::tamanio(){
	return tam;
}

template < typename Dato >
Dato Lista<Dato>::consultar(int pos){
	Nodo<Dato>* aux = obtener_nodo(pos);
	return aux->obtener_dato();
}

template < typename Dato >
bool Lista<Dato>::lista_vacia(){
	return tam == 0;
}

template < typename Dato >
void Lista<Dato>::eliminar(int pos) {
	Nodo<Dato>* aux;
	if(pos == 1){
		aux = primero;
		primero = aux->obtener_siguiente();
	}
	else{
		Nodo<Dato>* anterior = obtener_nodo(pos-1);
		aux = anterior ->obtener_siguiente();
		anterior ->cambiar_siguiente(aux->obtener_siguiente());
	}
	tam--;

	delete aux;
}

template < typename Dato >
Lista<Dato>::~Lista(){
	while(!lista_vacia()){
		eliminar(1);
	}
}

#endif