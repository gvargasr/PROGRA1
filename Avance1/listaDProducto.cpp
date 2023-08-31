 
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

//   private:
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
    pnodoProd GetPrimero();
    int buscarPos(int codigo);


    
 //  private:
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



void listaDProducto::InsertarFinal(int codigo, string nombre,int kcal, int precio){
   if (ListaVacia()){
    	primero = new nodoLDProducto(codigo, nombre, kcal, precio);
     	cout<<"Producto agregado: "<<codigo<<":"<<nombre<<":"<<kcal<<":"<<precio<<endl;
   }
   else{ 
		pnodoProd aux = primero;	  
        while ( aux->siguiente != NULL && aux->cod!=codigo)
        aux= aux->siguiente;
        if(aux->cod!=codigo){
        	aux->siguiente=new nodoLDProducto(codigo, nombre, kcal, precio);
        	aux->siguiente->anterior=aux;
			cout<<"Producto agregado: "<<codigo<<":"<<nombre<<":"<<kcal<<":"<<precio<<endl;
		}
		else{
		cout<<"Codigo de producto ya se encuentra, no fue agregado"<<endl;	
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
            cout << "Producto borrado: "<<temp->cod<<":"<<temp->nomProd<< endl;
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
                cout << "Producto borrado: "<<aux->cod<<":"<<aux->nomProd<< endl;            
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
            cout << "Producto borrado: "<<temp->cod<<":"<<temp->nomProd<< endl;
            delete temp;
            } 
			else
			{

                pnodoProd aux = primero;
                primero=primero->siguiente;   
				primero->anterior=NULL;
				cout << "Producto borrado: "<<aux->cod<<":"<<aux->nomProd<< endl;            
                delete aux;
            }
        }
}

int listaDProducto::buscarPos(int codigo){
	if(ListaVacia()){
		return -1;
	}
	else
	{
		pnodoProd aux=primero;
		int cont = 1;
		while(aux!=NULL)
		{
			if(aux->cod == codigo){
			//cout<<"El string "<<codigo<<" si se encuentra en la lista."<<endl;
			return cont;
		}
			else{
			aux=aux->siguiente;
			cont=cont+1;
			}
		}
		//cout<<"El string "<<codigo<<" no se encuentra en la lista"<<endl;
		return -1;
	}
}

void listaDProducto:: BorrarPosicion(int pos)
{
     if(ListaVacia())
     {
              cout << "Aun no hay productos registrados." <<endl;
     }
     else
     {
        if((pos>largoLista())||(pos<0))//no validas
        {
        cout << "Producto no se encuentra." << endl;
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
            cout << "Producto borrado: "<<temp->cod<<":"<<temp->nomProd<< endl;
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

pnodoProd listaDProducto::GetPrimero(){
	return primero;
}

/*
int main()
{
   listaDProducto Lista;
   
    
   Lista.InsertarFinal(109, "BigMac", 480 ,2300);
   Lista.InsertarFinal(78, "MacPapasPeque�as" , 197, 1200);
   Lista.InsertarFinal(65, "McNuggets4", 166, 3590);
   Lista.InsertarFinal(543, "PapasKids", 87, 590);
   Lista.InsertarFinal(704, "CrispyChicken", 623, 4900);  
   Lista.Mostrar();
	cout << Lista.largoLista();
	Lista.~listaDProducto();

   
  
  
 //  cin.get();
   return 0;
}*/
