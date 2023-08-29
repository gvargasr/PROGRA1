#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <math.h>
#include "listaDPais.cpp"
#include "listaClientes.cpp"

using namespace std;


class cargarArchivo {
   public:
    cargarArchivo() {
	 listaPais = new listaDPais();
	 listaCliente = new listaClientes(); 
	 }
    ~cargarArchivo();
    void cargaInicial();
	
//	private:
    listaDPais *listaPais;
    listaClientes *listaCliente;
  
};

cargarArchivo::~cargarArchivo()
{
listaPais = NULL;
}



void cargarArchivo::cargaInicial(){
	pnodoPais aux = listaPais->primero;
	ifstream archivo;

	archivo.open("Archivos/Paises.txt");
	while(!archivo.eof()){
		string codigo;
		string pais;
		getline(archivo,codigo, ';');
		getline(archivo, pais);
			
		listaPais->InsertarFinal(stoi(codigo),pais);
	}
	archivo.close();

	archivo.open("Archivos/Ciudades.txt");
	while(!archivo.eof()){
		string codpais;
		string codigo;
		string ciudad ;
		getline(archivo, codpais, ';');
		getline(archivo, codigo, ';');
		getline(archivo, ciudad);
		pnodoPais aux = listaPais->primero;
		int temp = stoi(codpais);
		int temp2 = stoi(codigo);
		if(listaPais->buscarPais(temp)==true){
			while(aux!=NULL){
				if(aux->cod == temp){
					listaPais->InsertarCiudad(temp2,ciudad,aux->listaCiudad);
				}
			aux=aux->siguiente;
			}
		}			
	}
	archivo.close();


 	archivo.open("Archivos/Restaurantes.txt");
	while(!archivo.eof()){
		string codpais;
		string codCiudad;
		string numRest;
		string nombre;
		getline(archivo, codpais, ';');
		getline(archivo, codCiudad, ';');
		getline(archivo, numRest, ';');
		getline(archivo, nombre);
		pnodoPais aux = listaPais->primero;
		int temp = stoi(codpais);
		int temp2 = stoi(codCiudad);
		int temp3 = stoi(numRest);
		if(listaPais->buscarPais(temp)==true){
			while(aux!=NULL){
				if(aux->cod == temp){
					pnodoCiudad aux2 = aux->listaCiudad->primero;
					while(aux2!=NULL){
						if(aux2->cod == temp2){
							aux->listaCiudad->InsertarRestaurante(temp3,nombre, aux2->listaRestaurante);
						}
						aux2= aux2->siguiente;
					}
				}
			aux=aux->siguiente;
			}
			
		}
	}
	archivo.close();	

 	archivo.open("Archivos/Menu.txt");
 		while(!archivo.eof()){
		string codPais;
		string codCiudad;
		string codRest;
		string codMenu;
		string nombre;
		
		getline(archivo, codPais, ';');
		getline(archivo, codCiudad, ';');
		getline(archivo, codRest, ';');
		getline(archivo, codMenu, ';');
		getline(archivo, nombre);
		pnodoPais aux = listaPais->primero;
		int temp = stoi(codPais);
		int temp2 = stoi(codCiudad);
		int temp3 = stoi(codRest);
		int temp4 = stoi(codMenu);
		if(listaPais->buscarPais(temp)==true){
			while(aux!=NULL){
				if(aux->cod == temp){
					pnodoCiudad aux2 = aux->listaCiudad->primero;
					while(aux2!=NULL){
						if(aux2->cod == temp2){
							pnodoRest aux3 = aux2->listaRestaurante->primero;
							pnodoRest head = aux2->listaRestaurante->primero;
								while(aux3->siguiente!=head && aux3->cod!=temp3)
									aux3=aux3->siguiente;
								if(aux3->siguiente==head);
								aux2->listaRestaurante->InsertarMenu(temp4,nombre,aux3->listaMenu);
						}
						aux2= aux2->siguiente;
					}
				}
			aux=aux->siguiente;
			}
			
		}
	}
 	archivo.close();
	

 	archivo.open("Archivos/Productos.txt");
 		while(!archivo.eof()){
		string codPais;
		string codCiudad;
		string codRest;
		string codMenu;
		string codProd;
		string nombre;
		string kcal;
		string precio;
		 
		getline(archivo, codPais, ';');
		getline(archivo, codCiudad, ';');
		getline(archivo, codRest, ';');
		getline(archivo, codMenu, ';');
		getline(archivo, codProd, ';');
		getline(archivo, nombre, ';');
		getline(archivo, kcal, ';');
		getline(archivo, precio);
		
		pnodoPais aux = listaPais->primero;
		int temp = stoi(codPais);
		int temp2 = stoi(codCiudad);
		int temp3 = stoi(codRest);
		int temp4 = stoi(codMenu);
		int temp5 = stoi(codProd);
		int temp6 = stoi(kcal);
		int temp7 = stoi(precio);
		
		if(listaPais->buscarPais(temp)==true){
			while(aux!=NULL){
				if(aux->cod == temp){
					pnodoCiudad aux2 = aux->listaCiudad->primero;
					while(aux2!=NULL){
						if(aux2->cod == temp2){
							pnodoRest aux3 = aux2->listaRestaurante->primero;
							pnodoRest head = aux2->listaRestaurante->primero;
								while(aux3->siguiente!=head && aux3->cod!=temp3)
									aux3=aux3->siguiente;
								if(aux3->cod==temp);
									pnodoMenu aux4 = aux3->listaMenu->primero;
									while(aux4!=NULL){
										if(aux4->cod == temp4){
										aux3->listaMenu->InsertarProducto(temp5, nombre, temp6, temp7, aux4->listaProd);
										}
									aux4= aux4->siguiente;
									}
								
						}
					aux2= aux2->siguiente;
					}
				}
			aux=aux->siguiente;
			}
			
		}
	}
 	archivo.close();

	
	archivo.open("Archivos/Clientes.txt");
	while(!archivo.eof()){
		string cedula;
		string nombre;
		getline(archivo, cedula, ';');
		getline(archivo, nombre);
		int temp = stoi(cedula);
		listaCliente->InsertarFinal(temp,nombre);
	}
	archivo.close();
	
}
/*
int main(){
	cargarArchivo Inicio;
	Inicio.cargaInicial();
	Inicio.listaPais->Mostrar();
	cout<<"Lista Ciudades de panama"<<endl;
	Inicio.listaPais->primero->listaCiudad->Mostrar();
	cout<<"Lista Ciudades de Estados Unidos"<<endl;
	Inicio.listaPais->primero->siguiente->listaCiudad->Mostrar();
	cout<<"Lista Ciudades de Mexico"<<endl;
	Inicio.listaPais->primero->siguiente->siguiente->listaCiudad->Mostrar();
	cout<<"Lista Restaurantes Panama "<<endl;
	Inicio.listaPais->primero->listaCiudad->primero->listaRestaurante->Mostrar();
	cout<<"Lista Restaurantes EEUU "<<endl;
	Inicio.listaPais->primero->siguiente->listaCiudad->primero->siguiente->listaRestaurante->Mostrar();
	cout<<endl;
	cout<<"Lista Menu Panama "<<endl;
	Inicio.listaPais->primero->listaCiudad->primero->listaRestaurante->primero->listaMenu->Mostrar();
	cout<<endl;
	cout<<"Lista McPanama, menu HC"<<endl;
	Inicio.listaPais->primero->listaCiudad->primero->listaRestaurante->primero->listaMenu->primero->listaProd->Mostrar();
	cout<<endl<<endl;
	Inicio.listaCliente->Mostrar();

}
*/

void SubMenu1(){
		cout << endl << "----------------------------" << endl;
        cout << endl << "      1. Leer Archivos   " << endl;
        cout << endl << "----------------------------" << endl;
		cout << endl;
		cout << "1. Cargar Archivos"<<endl;
		cout << "2. Volver"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: "<<endl;		
		char opt;
		cin >> opt;
		
	switch(opt) {
		case '1':
			cout<<"SubMenu1 - opcion 1";
			break;
		case '2':
			cout<<"Volviendo a Main Menu"<<endl;
			break;	
	default:
		cout<<"!!! Valor incorrecto, ingresar un valor dentro del rango !!!"<<endl;
		SubMenu1();
	}
}

void SubMenu2(){
		cout << endl << "----------------------------" << endl;
        cout << endl << "      2. Insertar   " << endl;
        cout << endl << "----------------------------" << endl;
		cout << endl;
		cout << "1. Pais"<<endl;
		cout << "2. Ciudad"<<endl;
		cout << "3. Restaurante"<<endl;
		cout << "4. Menu"<<endl;
		cout << "5. Producto"<<endl;
		cout << "6. Cliente"<<endl;
		cout << "7. Volver"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: "<<endl;		
		char opt;
		cin >> opt;
		
	switch(opt) {
		case '1':
			cout<<"SubMenu2 - opcion 1";
			break;
		case '2':
			cout<<"SubMenu2 - opcion 2";
			break;
		case '3':
			cout<<"SubMenu2 - opcion 3"<<endl;
			break;	
		case '4':
			cout<<"SubMenu2 - opcion 4";
			break;
		case '5':
			cout<<"SubMenu2 - opcion 5"<<endl;
			break;	
		case '6':
			cout<<"SubMenu2 - opcion 6"<<endl;
			break;
		case '7':
			cout<<"Volviendo a Main Menu"<<endl;
			break;	
	default:
		cout<<"!!! Valor incorrecto, ingresar un valor dentro del rango !!!"<<endl;
		SubMenu1();
	}
}

/* TODO (guvargas#1#): Terminar el menu y las opciones */


void MainMenu(){
	while(true){
	    cout << endl << "----------------------------" << endl;
        cout << endl << "      Main Menu   " << endl;
        cout << endl << "----------------------------" << endl;
		cout << endl;
		cout << "1. Leer Archivos"<<endl;
		cout << "2. Insertar"<<endl;
		cout << "3. Eliminar"<<endl;
		cout << "4. Buscar"<<endl;
		cout << "5. Modificar"<<endl;
		cout << "6. Reportes"<<endl;
		cout << "7. Info"<<endl;
		cout << "8. Salir"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: "<<endl;
		
		char opt;
		cin >> opt;
    
    switch(opt) {
    	case '1' : 
			cout<<"Ingresando a Submenu 1...";
			SubMenu1();
			MainMenu();
			break;
    	case '2':
    		cout<<"Ingresando a Submenu 2...";
    		SubMenu2();
    		MainMenu();
    		break;
    	case '3':
    		cout<<"Ingresando a Submenu 3...";
    		break;
    	case '4':
    		cout<<"Ingresando a Submenu 4...";
    		break;
    	case '5':
    		cout<<"Ingresando a Submenu 5...";
    		break;
		case '6':
    		cout<<"Ingresando a Submenu 6...";
    		break;
		case '7':
    		cout<<"Ingresando a Submenu 7...";
    		break;
		case '8':
    		cout<<endl<<endl<<endl<<"##################      Good Bye!!     ####################";
    		break;
			exit(1);		
    default: 
    cout<<"!!! Valor incorrecto, ingresar un valor dentro del rango !!!"<<endl;
	MainMenu();
	}
	break;
	}
}


int main(){
		cout<<"*************PROGRA #1************************"<<endl<<endl<<endl;
//		cout<<"\nIntegrantes:\nGustavo Vargas Ramirez   --- 200409141 \nGabriel Campos Gutierrez --- 2023093692"<<endl;
	
	MainMenu();
    cout<<endl<<endl<<endl;
    cout<<"###########################################################"<<endl;
    cout<<"###########################################################"<<endl;
    cout<<"###########################################################"<<endl;
	cout<<"################## PROGRAMA FINALIZADO ####################"<<endl;
	cout<<"###########################################################"<<endl;
	cout<<"###########################################################"<<endl;
	cout<<"###########################################################"<<endl;
	return 0;
}







