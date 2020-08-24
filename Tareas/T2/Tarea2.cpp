#include <iostream>

using namespace std;

struct nodo{
	string nombre;
	string carne;
	nodo* siguiente;
}*cabeza, *cola, *clon, *colaClon;

void insertar();
void buscarEliminar();
void menu();
void imprimir();
void CLONAR();

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
		cout<<"\n4. Clonar ";
		cout<<"\n5. Salir ";
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
			case 4:
				CLONAR();
				break;
		}
	}while(opc != 5);
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

void CLONAR(){
		
		//recorro la lista a clonar
		nodo* actual = new nodo();
		actual = cabeza;
		if(cabeza!=NULL){
			while(actual !=NULL){							// ESTO SERIA HASTA N, POR LI MISMO T(n)=n
				
				//creo el nuevo nodo de la lista nueva
				nodo * nuevoNodo = new nodo();
				nuevoNodo -> nombre = actual->nombre;
				nuevoNodo -> carne = actual->carne;
				
				//inserto
				if(clon == NULL){
					clon = nuevoNodo;
					clon -> siguiente = NULL;
					colaClon = nuevoNodo;
					cout<<"\nPrimer nodo clonado"<<endl;
				}else{
					colaClon -> siguiente = nuevoNodo;
					nuevoNodo -> siguiente = NULL;
					colaClon = nuevoNodo;
					cout<<"\nclonado con exito"<<endl;
				}
				
			actual = actual -> siguiente;
		}
	}else{
		cout<<"No hay estudiantes registrados"<<endl;
	}
		
		
		
		
	//imprimir lista clonada	
	cout<<"\n\nLISTA CLONADA: \n\n"<<endl;
	
	nodo* aactual = new nodo();
	aactual = clon;
	if(clon!=NULL){
		while(aactual !=NULL){
			cout<<"\n [Nombre: "<< aactual -> nombre <<"\t Carne: "<< aactual->carne<<"]F";
			aactual = aactual -> siguiente;
		}
	}else{
		cout<<"No hay estudiantes registrados"<<endl;
	}
	
}








