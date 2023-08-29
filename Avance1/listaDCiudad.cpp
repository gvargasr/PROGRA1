
#include <iostream>
#include <string>
#include "listaDCRest.cpp"

using namespace std;

class nodoLDCiudad {
   public:
    nodoLDCiudad(int codigo, string nombre)
    {
       cod = codigo;
       ciudad = nombre;
       siguiente = NULL;
       anterior =NULL;
       listaRestaurante = new listaDCRest();
    }

nodoLDCiudad(int codigo, string nombre,  nodoLDCiudad * signodo)
    {
       cod = codigo;
       ciudad = nombre;
       siguiente = signodo;
       listaRestaurante = new listaDCRest();
    }

 //  private:
    int cod;
    string ciudad;
    listaDCRest *listaRestaurante = NULL;
    nodoLDCiudad *siguiente;
    nodoLDCiudad *anterior;
       
   friend class listaDCiudad;
};

typedef nodoLDCiudad *pnodoCiudad;

class listaDCiudad {
   public:
    listaDCiudad() { primero =  NULL; }
    ~listaDCiudad();
    
    void InsertarInicio(int codigo, string nombre);
    void InsertarFinal(int codigo, string nombre);
    void InsertarPos (int codigo, string nombre, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
	void InsertarRestaurante(int codigo, string nombre, listaDCRest listaR);
	void MostrarListaRest();
	pnodoRest GetListaRest();
	pnodoCiudad EntregarListaCiudad();
	bool buscarCiudad(int codigo);



	    
 //  private:
    pnodoCiudad primero;
  
};



//Insertar Restaurante desde ListaCiudad
void listaDCiudad::InsertarRestaurante(int codigo, string nombre, listaDCRest listaR){
	listaR.InsertarFinal(codigo,nombre);
}

//Mostrar Lista de Restaurantes
void listaDCiudad::MostrarListaRest(){
	pnodoCiudad aux = primero;
	aux->listaRestaurante->Mostrar();	
}

//Pedir Lista de Rest
pnodoRest listaDCiudad::GetListaRest(){
	pnodoCiudad aux = primero;
	return aux->listaRestaurante->EntregarListaRest();
}

//EntregaListaCiudad
pnodoCiudad listaDCiudad::EntregarListaCiudad(){
	return primero;
}

bool listaDCiudad::buscarCiudad(int codigo){
	if(ListaVacia()){
		//cout<<"El string "<<codigo<<" no se encuentra en la lista"<<endl;
		return false;
	}
	else
	{
		pnodoCiudad aux=primero;
		while(aux!=NULL)
		{
			if(aux->cod == codigo){
			//cout<<"El string "<<codigo<<" si se encuentra en la lista."<<endl;
			return true;
		}
			else
			aux=aux->siguiente;
		}
		//cout<<"El string "<<codigo<<" no se encuentra en la lista"<<endl;
		return false;
	}
}

listaDCiudad::~listaDCiudad()
{
   pnodoCiudad aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   primero=NULL;
}

int listaDCiudad::largoLista(){
    int cont=0;

    pnodoCiudad aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }
    
}

void listaDCiudad::InsertarInicio(int codigo, string nombre)
{
   if (ListaVacia())
   {
   
     primero = new nodoLDCiudad(codigo, nombre);
     primero->anterior=NULL;     
   }
   else
   {
     primero=new nodoLDCiudad (codigo, nombre, primero);
     primero->siguiente->anterior=primero;
   }
}

void listaDCiudad::InsertarFinal(int codigo, string nombre){
   if (ListaVacia())
   {
   
     primero = new nodoLDCiudad(codigo, nombre);
       
   }
   else{ 
		pnodoCiudad aux = primero;	  
        while ( aux->siguiente != NULL && aux->cod!=codigo)
          aux= aux->siguiente;
        if(aux->cod!=codigo){
        aux->siguiente=new nodoLDCiudad(codigo, nombre);
        aux->siguiente->anterior=aux;
		}	
	}
}


void listaDCiudad::InsertarPos(int codigo, string nombre,int pos)
{
   if (ListaVacia())
    {
   
     primero = new nodoLDCiudad(codigo, nombre);
     primero->anterior=NULL;     
   }
   else{
        if(pos <=1)
          InsertarInicio(codigo, nombre);    
        else
        {
             pnodoCiudad aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodoCiudad nuevo= new nodoLDCiudad(codigo, nombre);
             nuevo->siguiente=aux->siguiente;
			 nuevo->anterior=aux;
			   nuevo->siguiente->anterior=nuevo;
			   aux->siguiente=nuevo;                      
        }
        }
}
      
void listaDCiudad::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL)//solo un nodo
		 {
        	pnodoCiudad temp=primero;
            primero= NULL;
            delete temp;
            } 
			else 
			{

                pnodoCiudad aux = primero;
                while (aux->siguiente->siguiente != NULL) 
                {
                    aux = aux->siguiente;
                }
                
              pnodoCiudad temp = aux->siguiente;
              aux->siguiente= NULL;
                      
                delete temp;
            }
        }
}

void listaDCiudad::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
            pnodoCiudad temp=primero;
            primero= NULL;
            delete temp;
            } 
			else
			{

                pnodoCiudad aux = primero;
                primero=primero->siguiente;   
				primero->anterior=NULL;            
                delete aux;
            }
        }
}



void listaDCiudad:: BorrarPosicion(int pos)
{
     if(ListaVacia())
     {
              cout << "Lista vacia" <<endl;
     }
     else
     {
        if((pos>largoLista())||(pos<0))//no validas
        {
        cout << "Error en posicion" << endl;
        }
        else
        {
        if(pos==1)
           BorrarInicio();
        else
        {
          if (pos == largoLista())   
             BorrarFinal();
          else
          {   
            int cont=2;
            pnodoCiudad aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            pnodoCiudad temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            aux->siguiente->anterior=aux;
            delete temp;
          }//else
        }//else
      }//else
    }//else
}
 

void listaDCiudad::Mostrar()
{
   nodoLDCiudad *aux;
   
   aux = primero;
   while(aux) {
      cout << aux->cod << ":"<<aux->ciudad<< "\n";
      aux = aux->siguiente;
   }
   cout << endl;
}

/*
int main()
{
   listaDCiudad Lista;
   
    
   
   Lista.InsertarFinal(345, "David");    // 2 20 10 11
   Lista.InsertarFinal(987, "Orlando");
   Lista.InsertarFinal(234,"Guadalajara");
   Lista.InsertarFinal(34,"Bocas");
   Lista.InsertarFinal(40211,"Barva");

  Lista.Mostrar();

     cout << Lista.largoLista();
    Lista.~listaDCiudad();

   
  
  
 //  cin.get();
   return 0;
}
*/
