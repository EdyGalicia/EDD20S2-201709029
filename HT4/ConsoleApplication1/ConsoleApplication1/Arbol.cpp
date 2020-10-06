#include "Arbol.h"


using namespace std;

Arbol::Arbol() {
	this->raiz = NULL;
}

Arbol::~Arbol() {
	Delete(this->raiz);
}

void Arbol::Delete(NodoAVL* raiz) {
	if (raiz == NULL)
	{
		return;
	}
	else
	{
		Delete(raiz->getIzquierda());
		Delete(raiz->getDerecha());
		delete raiz;
	}
}


//ROTACIONES
NodoAVL* Arbol::rotacionII(NodoAVL* n, NodoAVL* n1) {
	n->setIzquierda(n1->getDerecha());
	n1->setDerecha(n);
	if (n1->getFactor() == -1) // va a ser -1 cuando n1 no tenga hijo derecho
	{
		n->setFactor(0);
		n1->setFactor(0);
	}
	else
	{
		n->setFactor(-1);
		n1->setFactor(1);
	}
	return n1;
}

NodoAVL* Arbol::rotacionDD(NodoAVL* n, NodoAVL* n1) {
	n->setDerecha(n1->getIzquierda());
	n1->setIzquierda(n);
	if (n1->getFactor() == 1)//n1 va a tener factor 1 cuando no tenga hijo izquierdo
	{
		n->setFactor(0);
		n1->setFactor(0);
	}
	else
	{
		n->setFactor(1);
		n1->setFactor(-1);
	}
	return n1;
}

NodoAVL* Arbol::rotacionID(NodoAVL* n, NodoAVL* n1) {
	NodoAVL* n2 = n1->getDerecha();
	n->setIzquierda(n2->getDerecha());
	n2->setDerecha(n);
	n1->setDerecha(n2->getIzquierda());
	n2->setIzquierda(n1);

	//corregir factores de equilibrio
	if (n2->getFactor() == 1)//si n2 solo trae un hijo derecho
	{
		n1->setFactor(-1);
	}
	else//si trae dos o ningun hijo
	{
		n1->setFactor(0);
	}

	//si n2 solo trae un hijo izquierdo
	if (n2->getFactor() == -1)
	{
		n->setFactor(1);
	}
	else
	{
		n->setFactor(0);
	}
	n2->setFactor(0);
	return n2;
}

NodoAVL* Arbol::rotacionDI(NodoAVL* n, NodoAVL* n1) {
	NodoAVL* n2 = n1->getIzquierda();
	n->setDerecha(n2->getIzquierda());
	n2->setIzquierda(n);
	n1->setIzquierda(n2->getDerecha());
	n2->setDerecha(n1);

	//corregir factores de equilibrio
	if (n2->getFactor() == 1)//si solo trae un hijo derecho
	{
		n->setFactor(-1);
	}
	else//si trae dos o ningun hijo
	{
		n->setFactor(0);
	}

	//si n2 solo trae un hijo izquierdo
	if (n2->getFactor() == -1)
	{
		n1->setFactor(1);
	}
	else
	{
		n1->setFactor(0);
	}
	n2->setFactor(0);
	return n2;
}


//INSERTAR
NodoAVL* Arbol::insertar(NodoAVL* raiz, int dato, bool& hc) {
	NodoAVL* n1;
	if (raiz == NULL)
	{
		raiz = new NodoAVL(dato);
		hc = true;
	}
	else if (dato < raiz->getDato())
	{
		NodoAVL* izq = insertar(raiz->getIzquierda(), dato, hc);
		raiz->setIzquierda(izq);
		if (hc)
		{
			switch (raiz->getFactor())
			{
			case 1:
				raiz->setFactor(0);
				hc = false;
				break;
			case 0://si no llevaba ningun hijo
				raiz->setFactor(-1);
				break;
			case -1:
				n1 = raiz->getIzquierda();
				if (n1->getFactor() == -1)
				{
					raiz = rotacionII(raiz, n1);
				}
				else
				{
					raiz = rotacionID(raiz, n1);
				}
				hc = false;
				break;
			default:
				break;
			}
		}
	}
	else if (dato > raiz->getDato())
	{
		NodoAVL* der = insertar(raiz->getDerecha(), dato, hc);
		raiz->setDerecha(der);//raiz va a ser el nodo que mandamos a insertar
		if (hc)//si estamos creciendo
		{
			switch (raiz->getFactor())
			{
			case 1://si es uno, crecio hacia la derecha
				n1 = raiz->getDerecha();
				if (n1->getFactor() == 1)//si crecio dos veces a la derecha
				{
					raiz = rotacionDD(raiz, n1);
				}
				else
				{
					raiz = rotacionDI(raiz, n1);
				}
				hc = false;
				break;
			case 0://si no llevaba ningun hijo
				raiz->setFactor(1);
				break;
			case -1:
				raiz->setFactor(0);
				hc = false;
				break;
			default:
				break;
			}
		}
	}
	return raiz;
}
NodoAVL* Arbol::insertarEspejo(NodoAVL* raiz, int dato, bool& hc) {
	NodoAVL* n1;
	if (raiz == NULL)
	{
		raiz = new NodoAVL(dato);
		hc = true;
	}
	else if (dato > raiz->getDato())
	{
		NodoAVL* izq = insertar(raiz->getIzquierda(), dato, hc);
		raiz->setIzquierda(izq);
		if (hc)
		{
			switch (raiz->getFactor())
			{
			case 1:
				raiz->setFactor(0);
				hc = false;
				break;
			case 0://si no llevaba ningun hijo
				raiz->setFactor(-1);
				break;
			case -1:
				n1 = raiz->getIzquierda();
				if (n1->getFactor() == -1)
				{
					raiz = rotacionII(raiz, n1);
				}
				else
				{
					raiz = rotacionID(raiz, n1);
				}
				hc = false;
				break;
			default:
				break;
			}
		}
	}
	else if (dato < raiz->getDato())
	{
		NodoAVL* der = insertar(raiz->getDerecha(), dato, hc);
		raiz->setDerecha(der);//raiz va a ser el nodo que mandamos a insertar
		if (hc)//si estamos creciendo
		{
			switch (raiz->getFactor())
			{
			case 1://si es uno, crecio hacia la derecha
				n1 = raiz->getDerecha();
				if (n1->getFactor() == 1)//si crecio dos veces a la derecha
				{
					raiz = rotacionDD(raiz, n1);
				}
				else
				{
					raiz = rotacionDI(raiz, n1);
				}
				hc = false;
				break;
			case 0://si no llevaba ningun hijo
				raiz->setFactor(1);
				break;
			case -1:
				raiz->setFactor(0);
				hc = false;
				break;
			default:
				break;
			}
		}
	}
	return raiz;
}


void Arbol::insertar(int valor, Arbol* espejo) {
	bool b = false;
	bool* a = &b;
	bool c = false;
	bool* d = &c;
	this->raiz = insertar(this->raiz, valor, *a);
	espejo->raiz = insertarEspejo(espejo->raiz, valor, *d);
}


//RAIZ
NodoAVL* Arbol::getRaiz() { return this->raiz; }
void Arbol::setRaiz(NodoAVL* n) { this->raiz = n; }

void Arbol::generar()
{
	stringstream cadena;
	cadena << "digraph G{\n" << endl;
	cadena << "node[shape=\"record\"];" << endl;
	if (raiz != NULL) {
		cadena << "node" << &(*this->raiz) << "[label = \"<f0>|<f1>" << this->raiz->getDato() << "factor:" << this->raiz->getFactor() << "|<f2>\"];\n" << endl;
		this->generar(&cadena, this->raiz, this->getRaiz()->getIzquierda(), true);
		this->generar(&cadena, this->raiz, this->getRaiz()->getDerecha(), false);
	}
	cadena << "}" << endl;
	cout << cadena.str() << endl;
	ofstream file("salida.dot");
	file << cadena.str();
	file.close();
	system("dot -Tpng salida.dot -o salida.png");
}

void Arbol::generar2()
{
	stringstream cadena;
	cadena << "digraph G{\n" << endl;
	cadena << "node[shape=\"record\"];" << endl;
	if (raiz != NULL) {
		cadena << "node" << &(*this->raiz) << "[label = \"<f0>|<f1>" << this->raiz->getDato() << "factor:" << this->raiz->getFactor() << "|<f2>\"];\n" << endl;
		this->generar(&cadena, this->raiz, this->getRaiz()->getIzquierda(), true);
		this->generar(&cadena, this->raiz, this->getRaiz()->getDerecha(), false);
	}
	cadena << "}" << endl;
	cout << cadena.str() << endl;
	ofstream file("salida2.dot");
	file << cadena.str();
	file.close();
	system("dot -Tpng salida2.dot -o salida2.png");
}


//GRAPHVIZ
void Arbol::generar(stringstream* cadena, NodoAVL* padre, NodoAVL* actual, bool izquierda) {
	if (actual != NULL)
	{
		*cadena << "node" << &(*actual) << "[label= \"<f0> | <f1>" << actual->getDato() << " factor:" << actual->getFactor() << " | <f2>\"];" << endl;
		if (izquierda) {
			*cadena << "node" << &(*padre) << ":f0-> node" << &(*actual) << ":f1;" << endl;
		}
		else
		{
			*cadena << "node" << &(*padre) << ":f2-> node" << &(*actual) << ":f1;" << endl;
		}
		generar(cadena, actual, actual->getIzquierda(), true);
		generar(cadena, actual, actual->getDerecha(), false);
	}
}
