#pragma once
#include<iostream>
#include"NodoAVL.h"
#include<stdbool.h>
#include<string>
#include <ostream>
#include <sstream>
#include <fstream>
using namespace std;

class Arbol
{
public:
	Arbol();
	~Arbol();
	NodoAVL* getRaiz();
	void setRaiz(NodoAVL* n);
	void insertar(int valor, Arbol* espejo);
	void generar();
	void generar2();
private:
	NodoAVL* raiz;
	NodoAVL* insertar(NodoAVL* raiz, int dato, bool& hc);
	NodoAVL* insertarEspejo(NodoAVL* raiz, int dato, bool& hc);
	NodoAVL* rotacionII(NodoAVL* n, NodoAVL* n1);
	NodoAVL* rotacionDD(NodoAVL* n, NodoAVL* n1);
	NodoAVL* rotacionID(NodoAVL* n, NodoAVL* n1);
	NodoAVL* rotacionDI(NodoAVL* n, NodoAVL* n1);
	void Delete(NodoAVL* raiz);

	void generar(stringstream* cadena, NodoAVL* padre, NodoAVL* actual, bool izquierda);

};
