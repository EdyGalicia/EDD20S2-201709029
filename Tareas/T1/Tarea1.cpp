#include <iostream>

using namespace std;

struct nodo{
	string nombre;
	string carne;
	nodo* siguiente;
}*cabeza, *cola;

void insertar();
void buscarEliminar();
void menu();
void imprimir();

int main(){

	menu();
	return 0;
}

void menu(){
	int opc = 0;
	do{
		cout<<"\n\n\n============= TAREA 1 =============="<<endl;
		cout<<"\n1. Ingresar estudiante"<<endl;
		cout<<"\n2. Buscar y eliminar estudiante"<<endl;
		cout<<"\n3. Imprimir lista ";
		cout<<"\n4. Salir ";
		cout<<"\nIngrese una opcion: ";
		cin>> opc;
		switch(opc){
			case 1:
					insertar();
				break;
			case 2:
					buscarEliminar();
				break;
			case 3:
				imprimir();
				break;
		}
	}while(opc != 4);
}

void insertar(){
	string nombre = "";
	string carne = "";
	
	cout<<"Ingrese el nombre del estudiante: ";
	cin>> nombre;
	cout<<"\nIngrese el carne del estudiante: ";
	cin>> carne;
	
	nodo * nuevoNodo = new nodo();
	nuevoNodo -> nombre = nombre;
	nuevoNodo -> carne = carne;
	
	if(cabeza == NULL){
		cabeza = nuevoNodo;
		cabeza -> siguiente = NULL;
		cola = nuevoNodo;
		cout<<"\nESTUDIANTE INSERTADO CON EXITO"<<endl;
	}else{
		cola -> siguiente = nuevoNodo;
		nuevoNodo -> siguiente = NULL;
		cola = nuevoNodo;
		cout<<"\nESTUDIANTE INSERTADO CON EXITO"<<endl;
	}

}

void imprimir(){
	nodo* actual = new nodo();
	actual = cabeza;
	if(cabeza!=NULL){
		while(actual !=NULL){
			cout<<"\n [Nombre: "<< actual -> nombre <<"\t Carne: "<< actual->carne<<"]";
			actual = actual -> siguiente;
		}
	}else{
		cout<<"No hay estudiantes registrados"<<endl;
	}
}



void buscarEliminar(){
	nodo* actual = new nodo();
	actual = cabeza;
	nodo* anterior = new nodo();
	anterior = NULL;
	string carne = "";
	cout<<"\nCarne a eliminar: ";
	cin>>carne;
	
	bool yape = false;
	
	if(cabeza != NULL){
		
		while(actual != NULL && yape == false){
			if(actual -> carne == carne){
				if(actual == cabeza){
					cabeza = cabeza -> siguiente;
				}else if(actual == cola){
					cola = anterior;
					anterior -> siguiente = NULL;
				}else{
					anterior->siguiente = actual->siguiente;
				}
				cout<<"\nEstudiante encontrado y eliminado."<<endl;
				yape = true;
			}else{
				anterior = actual;
				actual = actual->siguiente;
			}
		}
		if(yape == false){
			cout<<"\nNo se encontro el estudiante con carne: "<<carne<<endl;
		}
		
	}else{
		cout<<"\nNo hay elementos en la lista "<<endl;
	}
	
}










