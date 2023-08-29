#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <math.h>
#include "listaDPais.cpp"

using namespace std;


class cargarArchivo {
   public:
    cargarArchivo() { listaPais = new listaDPais(); }
    ~cargarArchivo();
    void cargaInicial();
	
//	private:
    listaDPais *listaPais;
  
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
		getline(archivo, codigo, ';');
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

/* 	archivo.open("Archivos/Restaurantes.txt");
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
		int temp2 = stoi(codciudad);
		int temp3 = stoi(numRest);
		if(listaPais->buscarPais(temp)==true){
			while(aux!=NULL){
				if(aux->cod == temp){
					aux->listaCiudad->InsertarFinal(temp2,ciudad);
				}
			aux=aux->siguiente;
			}
			
		}
	}
	archivo.close();*/
}

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
//	cout<<"ListaCiudad"<<endl;
//	Inicio.listaPais->primero->listaCiudad->Mostrar();
//	Inicio.listaPais->primero->siguiente->listaCiudad->Mostrar();
//	Inicio.listaPais.Mostrar();

//	listaDPais root;
//	root->InsertarInicio(506, "Costa Rica");
//	root.GetListaCiudad()->InsertarInicio(123,"Chepe");

//	root
//	root.primero->listaCiudad.InsertarInicio(4, "Heredia");
//	root.Mostrar();
//	root->primero.Mostrar();
}



/*
int main(){
		cout<<"*************TAREA CORTA #1************************"<<endl<<endl;
		cout<<"Evaluacion en POSTFIJO"<<endl;
		cout<<"\nIntegrantes:\nGustavo Vargas Ramirez   --- 200409141 \nGabriel Campos Gutierrez --- 2023093692"<<endl;
	cargarArchivo postFijo;
	pnodoStr primeroL1=new nodoStr();
	pnodoStr primeroL2=new nodoStr();
	pnodoStr primeroL3=new nodoStr();
	pnodoStr primeroL4=new nodoStr();
	pnodoStr primeroL5=new nodoStr();
	
	pnodoStr Cola[5]={primeroL1,primeroL2,primeroL3,primeroL4,primeroL5};
	postFijo.crearCola(Cola);
	int i = 0;
	while(i<5){
		cout<<endl<<"************************************************************"<<endl;
		cout<<"\n                    ***LECTURA DE ARCHIVO "<<i+1<<".***\n\nExpresion original: "<<endl<<endl;
		postFijo.MostrarExpresionHuman(Cola[i]); 
		cout<<"\nExpresion como lista: "<<endl<<endl;
		postFijo.MostrarExpresion(Cola[i]);   
		cout<<endl;
		cout<<"Expresion creada en Postfijo: "<<endl<<endl;
		postFijo.crearPostfijo(Cola[i]);
		postFijo.Imprimir();
		cout<<endl;
		cout<<"Expresion postfijo 'Human readable': "<<endl<<endl;
		postFijo.Mostrar();
		cout<<endl;
		cout<<"Resultado Final: "<<endl<<endl;
		cout<<">>> ";
		postFijo.lectorListaPostfija();
		cout<<" <<< ";
		cout<<endl;
		i=i+1;
		postFijo.~cargarArchivo();	
	}
	
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
 */

/*
Leer Archivos---LISTO
Crear Cola (Arreglo)--- LISTO
Insertar Archivos en la Cola --- LISTO
Recorrer Arreglo de la Cola  --- LISTO
Crear Postfijo               --- LISTO
Evaluar Expresión en Postfijo --- LISTO
Imprimir Expresión Original, Expresión Postfijo y Evaluación  --- lISTO
*/





