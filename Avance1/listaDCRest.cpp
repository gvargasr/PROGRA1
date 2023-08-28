
#include <iostream>
#include "listaDMenu.cpp"

using namespace std;

class nodoLDCRest {
   public:
    nodoLDCRest(int codigo, string nombre)
    {
       cod = codigo;
       rest = nombre;
       siguiente = NULL;
       anterior =NULL;
       listaMenu = new listaDMenu();

    }

   nodoLDCRest(int codigo, string nombre, nodoLDCRest * signodo)
    {
       cod = codigo;
       rest = nombre;
       siguiente = signodo;
       listaMenu = new listaDMenu();

    }

 private:
    int cod;
    string rest;
    listaDMenu *listaMenu = NULL;
    nodoLDCRest *siguiente;
    nodoLDCRest *anterior;
    
        
   friend class listaDCRest;
};
typedef nodoLDCRest *pnodoRest;

class listaDCRest {
   public:
    listaDCRest() { primero = NULL; }
    ~listaDCRest();
    
    void InsertarInicio(int codigo, string nombre);
    void InsertarFinal(int codigo, string nombre);
    void InsertarPos (int codigo, string nombre, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Imprimir();
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    int largoLista();
    void InsertarMenu(int codigo, string nombre);
    void MostrarListaMenu();
	pnodoMenu GetListaMenu();
	pnodoRest EntregarListaRest();
    
   private:
    pnodoRest primero;
   
};

// Insertar menu desde ListaRest
void listaDCRest::InsertarMenu(int codigo, string nombre){
	pnodoRest aux = primero;
	aux->listaMenu->InsertarInicio(codigo,nombre);	
}

//Mostrar Lista de Menu
void listaDCRest::MostrarListaMenu(){
	pnodoRest aux = primero;
	aux->listaMenu->Mostrar();	
}

//Pedir Lista de Menu
pnodoMenu listaDCRest::GetListaMenu(){
	pnodoRest aux = primero;
	return aux->listaMenu->EntregarListaMenu();
}

//EntregaListaRest
pnodoRest listaDCRest::EntregarListaRest(){
	return primero;
}
                
listaDCRest::~listaDCRest()
{
   pnodoRest aux;
   pnodoRest temp;
   
   while(primero) {
      temp = primero;
      aux=primero;
      primero = primero->siguiente;
      while (aux->siguiente!=primero)
           aux= aux->siguiente;
      aux->siguiente=primero;
      
      delete temp;
      primero=NULL;
   }
   primero= NULL;
}
   

                        //  aux
int listaDCRest::largoLista() //3-4-5    cont=0 1 2 3
{
    int cont=0;

    pnodoRest aux = primero->siguiente;
    if(ListaVacia())
    {
        return cont;
    }
    else
    {   cont=cont+1;
        while(aux!=primero)
        {
          aux=aux->siguiente;
          cont++;
        }
    return cont;
    }
    
}

void listaDCRest::InsertarInicio(int codigo, string nombre)
{
  
   if (ListaVacia())
   {
     primero = new nodoLDCRest(codigo, nombre);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   {
     pnodoRest nuevo=new nodoLDCRest (codigo, nombre);//1
     nuevo->siguiente=primero;//2
     nuevo->anterior= primero->anterior;//3
     primero->anterior->siguiente=nuevo;//4
     nuevo->siguiente->anterior=nuevo;//5   se puede cambiar primero->anterior=nuevo;
     primero= nuevo;//6
   }
}
 
void listaDCRest::InsertarFinal(int codigo, string nombre)
{
   if (ListaVacia())
     {
     primero = new nodoLDCRest(codigo, nombre);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   {
     pnodoRest aux = primero;
     	if(aux->cod!=codigo){
     		while(aux->siguiente!=primero)
     		aux=aux->siguiente;
		pnodoRest nuevo = new nodoLDCRest(codigo, nombre);//1
   		nuevo->anterior = primero->anterior;//2
   		/*nuevo->siguiente=primero->anterior->siguiente;opcion para intruccion 3*/
		nuevo->siguiente=primero;// coloca alguna de la dos 3
  		primero->anterior->siguiente=nuevo;//4
 		primero->anterior=nuevo;//5	
	}

    }    
}


void listaDCRest::InsertarPos(int codigo, string nombre, int pos)
{
   if (ListaVacia())
   {
     primero = new nodoLDCRest(codigo, nombre);
     primero->anterior=primero;
     primero->siguiente=primero;
   } 
   else
   {
      if(pos <=1)
        InsertarInicio(codigo, nombre);    
       else
       {
        if (pos==largoLista())
          InsertarFinal(codigo, nombre);
        else
        {     
             pnodoRest aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= primero))
             {
                   i++;
                   aux=aux->siguiente;
             }
             pnodoRest nuevo= new nodoLDCRest(codigo, nombre);//1
             nuevo->siguiente=aux->siguiente;//2
             aux->siguiente=nuevo;//3
             aux->siguiente->anterior=aux;//4 o puede nuevo->anterio=aux
             nuevo->siguiente->anterior=nuevo;  //5                        
        }
       }
   }
}   

void listaDCRest::BorrarFinal()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
      if (primero->siguiente == primero)
      {
        pnodoRest temp= primero;
        primero= NULL;
        delete temp;
      }
      else 
      {
         pnodoRest aux = primero; //1
         while (aux->siguiente->siguiente != primero)
              aux = aux->siguiente;
         pnodoRest temp = aux->siguiente;//2
         aux->siguiente= primero;//3
         primero->anterior=aux;//4
         delete temp;//5
      }
    }
}

void listaDCRest::BorrarInicio()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
     if (primero->siguiente == primero)
     {
        pnodoRest temp= primero;
        primero= NULL;
        delete temp;
     }
     else
     {
        pnodoRest aux = primero->anterior;//1
        pnodoRest temp= primero;//2
        aux->siguiente=primero->siguiente;//3
        primero=primero->siguiente; //4
        primero->anterior=aux;//5
        delete temp;//6
      }
    }
}

void listaDCRest:: BorrarPosicion(int pos)
{
    
  if(ListaVacia())
    cout << "Lista vacia" <<endl;
  else
  {
   if((pos==1))
      
   {
   	BorrarInicio();
   	
   }
        
   else
   {
    if(pos>largoLista()||(pos<=0))
    {
       cout << "Error en posicion" << endl;
	}
        
    else
    {
       int cont=2;
       pnodoRest aux=  primero;
       while(cont<pos)
       {
         aux=aux->siguiente;
         cont++;
       }
       pnodoRest temp = aux->siguiente;
       aux->siguiente=aux->siguiente->siguiente;
       aux->siguiente->anterior=aux;
       delete temp;
     }
    }
  }
}

void listaDCRest::Mostrar()
{
   pnodoRest aux=primero;
   while(aux->siguiente!=primero)
     {
                                
      cout << aux->cod<<":"<<aux->rest << "\n";
      aux = aux->siguiente;
     }
     cout<<aux->cod<<":"<<aux->rest << "\n";
     //EXTRA
     cout<<endl;
    /* cout<< "primero";
     cout<<endl;
     cout<<aux->siguiente->valor<<"->";
     cout<<endl;
     cout<< "ultimo";
     cout<<endl;
     cout<<primero->anterior->valor<<"->";*/
}   

/*
int main()
{
   listaDCRest Lista;
   
    
   
   Lista.InsertarFinal(34, "McPanama");    // 2 20 10 11
   Lista.InsertarFinal(456, "Disney Springs");
   Lista.InsertarFinal(876,"Mac");
   Lista.InsertarFinal(234,"McBocas");
   Lista.InsertarFinal(2341,"X");
   Lista.InsertarMenu(1,"Combo1");
   Lista.MostrarListaMenu();
   Lista.Mostrar();
     cout << Lista.largoLista();
    Lista.~listaDCRest();
	
   
  
  
 //  cin.get();
   return 0;
}
*/
