
#include <iostream>
#include <string>
using namespace std;

class nodoLDProducto {
   public:
   	nodoLDProducto()
    {
    	cod = -1;
    	nomProd = "";
		kcal = -1;
    	precio = -1;
    	siguiente = NULL;
    	anterior =NULL;
	}
    nodoLDProducto(int codigo, string nombre,int cal, int price)
    {
       cod = codigo;
       nomProd = nombre;
       kcal = cal;
       precio = price;
       siguiente = NULL;
       anterior =NULL;
    }

nodoLDProducto(int codigo, string nombre, int kcal, int precio, nodoLDProducto * signodo)
    {
       cod = codigo;
       nomProd = nombre;
       kcal = kcal;
       precio = precio;
       siguiente = signodo;
    }

   private:
    int cod,kcal,precio;
    string nomProd;
    nodoLDProducto *siguiente;
    nodoLDProducto *anterior;
    
        
   friend class listaDProducto;
};

typedef nodoLDProducto *pnodoProd;

class listaDProducto {
   public:
    listaDProducto() { primero =  NULL; }
    ~listaDProducto();
    
    void InsertarInicio(int codigo, string nombre, int kcal, int precio);
    void InsertarFinal(int codigo, string nombre, int kcal, int precio);
    void InsertarPos (int codigo, string nombre, int kcal, int precio, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
    pnodoProd EntregarListaProd();

    
   private:
    pnodoProd primero;
  
};
listaDProducto::~listaDProducto()
{
   pnodoProd aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   primero=NULL;
}

int listaDProducto::largoLista(){
    int cont=0;

    pnodoProd aux;
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

void listaDProducto::InsertarInicio(int codigo, string nombre, int kcal, int precio)
{
   if (ListaVacia())
   {
   
     primero = new nodoLDProducto( codigo, nombre, kcal, precio);
     primero->anterior=NULL;     
   }
   else
   {
     primero=new nodoLDProducto (codigo, nombre, kcal, precio, primero);
     primero->siguiente->anterior=primero;
   }
}

void listaDProducto::InsertarFinal(int codigo, string nombre, int kcal, int precio)
{
   if (ListaVacia())
   {
   
     primero = new nodoLDProducto(codigo, nombre, kcal, precio);
       
   }
   else
     { pnodoProd aux = primero;
     if(aux->cod!=codigo){
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodoLDProducto(codigo, nombre, kcal, precio);
        aux->siguiente->anterior=aux;       
      }
}
}

void listaDProducto::InsertarPos(int codigo, string nombre, int kcal, int precio,int pos)
{
   if (ListaVacia())
    {
   
     primero = new nodoLDProducto(codigo, nombre, kcal, precio);
     primero->anterior=NULL;     
   }
   else{
        if(pos <=1)
          InsertarInicio(codigo, nombre, kcal, precio);    
        else
        {
             pnodoProd aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodoProd nuevo= new nodoLDProducto(codigo, nombre, kcal, precio);
             nuevo->siguiente=aux->siguiente;
			 nuevo->anterior=aux;
			   nuevo->siguiente->anterior=nuevo;
			   aux->siguiente=nuevo;                      
        }
        }
}
      
void listaDProducto::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL)//solo un nodo
		 {
        	pnodoProd temp=primero;
            primero= NULL;
            delete temp;
            } 
			else 
			{

                pnodoProd aux = primero;
                while (aux->siguiente->siguiente != NULL) 
                {
                    aux = aux->siguiente;
                }
                
              pnodoProd temp = aux->siguiente;
              aux->siguiente= NULL;
                      
                delete temp;
            }
        }
}

void listaDProducto::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
            pnodoProd temp=primero;
            primero= NULL;
            delete temp;
            } 
			else
			{

                pnodoProd aux = primero;
                primero=primero->siguiente;   
				primero->anterior=NULL;            
                delete aux;
            }
        }
}



void listaDProducto:: BorrarPosicion(int pos)
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
            pnodoProd aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            pnodoProd temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            aux->siguiente->anterior=aux;
            delete temp;
          }//else
        }//else
      }//else
    }//else
}
 

void listaDProducto::Mostrar()
{
   nodoLDProducto *aux;
   //int codigo, string nombre, int kcal, int precio
   aux = primero;
   while(aux) {
      cout << aux->cod << ":"<<aux->nomProd<<":"<<aux->kcal<<":"<<aux->precio<< "\n";
      aux = aux->siguiente;
   }
   cout << endl;
}

pnodoProd listaDProducto::EntregarListaProd(){
	return primero;
}

/*
int main()
{
   listaDProducto Lista;
   
    
   Lista.InsertarFinal(109, "BigMac", 480 ,2300);
   Lista.InsertarFinal(78, "MacPapasPequeñas" , 197, 1200);
   Lista.InsertarFinal(65, "McNuggets4", 166, 3590);
   Lista.InsertarFinal(543, "PapasKids", 87, 590);
   Lista.InsertarFinal(704, "CrispyChicken", 623, 4900);  
   Lista.Mostrar();
	cout << Lista.largoLista();
	Lista.~listaDProducto();

   
  
  
 //  cin.get();
   return 0;
}*/
