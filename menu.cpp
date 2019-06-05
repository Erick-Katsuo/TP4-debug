#include "menu.h"

Menu::Menu(){
	peliculas_vistas = new Lista<Pelicula*>();
	peliculas_no_vistas = new Lista<Pelicula*>();
	peliculas_recomendadas = new Lista<Pelicula*>();
}

void Menu::crear_lista_de_peliculas(char const* peliculas_vistas_txt,char const* peliculas_no_vistas_txt){

	leer_archivo(peliculas_vistas_txt,peliculas_vistas);

	leer_archivo(peliculas_no_vistas_txt,peliculas_no_vistas);
}

void Menu::leer_archivo(char const* archivo_txt, Lista<Pelicula*>* lista_de_peliculas){
	string actor,nombre,genero,director;
	int puntaje;
	ifstream archivo(archivo_txt);
	archivo >> nombre;
	Pelicula* pelicula;
	while(archivo >> nombre){
		archivo >> genero;
		archivo >> puntaje;
		archivo >> director;
		pelicula = new Pelicula(nombre,genero,director,puntaje);
		while(archivo >> actor && actor != "-"){
			pelicula->agregar_actor(actor);
		}
		lista_de_peliculas->agregar(pelicula,lista_de_peliculas->tamanio() + 1);
	}
	archivo.close();
}

void Menu::interfaz(){
	int opcion;

	do{
		cout <<endl<<"*" << "******************************************"<< endl;
		cout <<"*" << "........MENU DE OPCIONES................." <<"*"<< endl;
		cout <<"*" << " Mostrar peliculas vistas............[1] " <<"*"<< endl;
		cout <<"*" << " Mostrar peliculas no vistas.........[2] " <<"*"<< endl;
		cout <<"*" << " Generar peliculas recomendadaas.....[3] " <<"*"<< endl;
		cout <<"*" << " Mostrar peliculas recomendadas......[4] " <<"*"<< endl;
		cout <<"*" << " Salir...............................[5] " <<"*"<< endl;
		cout <<"*" << ".....Elija una de las opciones.......... " <<"*"<< endl;
		cout <<"*" << "******************************************"<< endl << endl;
		cin >> opcion;
		if(opcion!=OPCION_MOSTRAR_VISTAS and opcion!=OPCION_MOSTRAR_NO_VISTAS and opcion!=OPCION_GENERAR_RECOMENDADAS
			and opcion!=OPCION_MOSTRAR_RECOMENDADAS and opcion!=SALIR){
			cout<<endl<<"Recuerde que las opciones validas son 1, 2, 3, 4 y 5. Intentelo nuevamente."<<endl<<endl;
		}
		ejecutar_opcion(opcion);
	}while(opcion != 5);
}

void Menu::ejecutar_opcion(int opcion){
	switch(opcion){
			case 1:
				cout <<endl<< "Lista de peliculas vistas:" << endl<< endl;
				mostrar_lista_de_peliculas(peliculas_vistas);
			break;

			case 2:
				cout <<endl<< "Lista de peliculas no vistas:" << endl<< endl;
				mostrar_lista_de_peliculas(peliculas_no_vistas);
			break;

			case 3:
				crear_lista_de_peliculas_recomendadas();
				cout<<endl<<"Lista de peliculas recomendadas creada :)"<<endl;
			break;

			case 4:
				if(peliculas_recomendadas->tamanio()!=0){
					cout <<endl<< "Lista de peliculas recomendadas:" << endl<< endl;
					mostrar_lista_de_peliculas(peliculas_recomendadas);
				}else{
					cout<<endl<<"No ha creado la lista de peliculas recomendadas. Intentelo nuevamente."<<endl;
				}
			break;

		}
}

void Menu::mostrar_actores(Lista<string>* lista){
	cout << endl <<"Actores de la pelicula:"<< endl;
	for (int i = 1; i <= lista->tamanio(); ++i){
		cout << lista->consultar(i) << endl;
	}
}

void Menu::mostrar_pelicula(Pelicula* pelicula){
	cout << "Nombre:  " << pelicula->obtener_nombre() << endl;
	cout << "Genero:  " << pelicula->obtener_genero() << endl;
	cout << "Director:  " << pelicula->obtener_director() << endl;
	cout << "Puntaje:  " << pelicula->obtener_puntaje() << endl;
	mostrar_actores(pelicula->obtener_lista_de_actores());
	cout << ".............................." << endl;
}

void Menu::mostrar_lista_de_peliculas(Lista<Pelicula*>* lista){
	for (int i = 1; i <= lista->tamanio(); ++i){
		Pelicula* pelicula = lista->consultar(i);
		mostrar_pelicula(pelicula);
	}
}

void Menu::crear_lista_de_peliculas_recomendadas(){
	for (int i = 1; i <= peliculas_no_vistas->tamanio(); ++i){
		Pelicula* peli_nv = peliculas_no_vistas->consultar(i);
		if(es_pelicula_recomendada(peli_nv)){
			peliculas_recomendadas->agregar(peli_nv,peliculas_recomendadas->tamanio()+1);
		}
	}
}

bool Menu::es_pelicula_recomendada(Pelicula* peli_nv){
	for (int i = 1; i <= peliculas_vistas->tamanio(); ++i){
		Pelicula* peli_v = peliculas_vistas->consultar(i);
		if(peli_v->obtener_genero() == peli_nv->obtener_genero() && cumple_condiciones_peli_recomendable(peli_v,peli_nv)){
			return true;
		}
	}
	return false;
}

bool Menu::coinciden_actores(Pelicula* peli_v,Pelicula* peli_nv){
	Lista<string>* act_v = peli_v->obtener_lista_de_actores();
	Lista<string>* act_nv = peli_nv->obtener_lista_de_actores();
	for (int i = 1; i <= act_v->tamanio(); ++i){
		for (int j = 1; j <= act_nv->tamanio(); ++j){
			if(act_v->consultar(i) == act_nv->consultar(j)){
				return true;
			}
		}
	}
	return false;
}

bool Menu::cumple_condiciones_peli_recomendable(Pelicula* peli_v,Pelicula* peli_nv){
	if(peli_nv->obtener_puntaje() >= PUNTAJE_ALTO) return true;
	else{

		if(peli_v->obtener_director() == peli_nv->obtener_director() || coinciden_actores(peli_v,peli_nv)){
			return true;
		}
	}
	return false;
}

void Menu::limpiar_listas(Lista<Pelicula*>* aux_lista){
    while(!(aux_lista->lista_vacia())){
        delete aux_lista->consultar(1);
        aux_lista->eliminar(1);
    }
}

Menu::~Menu(){
	Lista<Pelicula*>* aux_lista = peliculas_vistas;
	limpiar_listas(aux_lista);
	aux_lista = peliculas_no_vistas;
	limpiar_listas(aux_lista);
	delete peliculas_vistas;
	delete peliculas_no_vistas;
	delete peliculas_recomendadas;
}