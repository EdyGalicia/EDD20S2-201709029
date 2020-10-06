// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include"Arbol.h"
using namespace std;

int main()
{
    Arbol* arbol = new Arbol();
    Arbol* arbolEspejo = new Arbol();

    arbol->insertar(10, arbolEspejo);
    arbol->insertar(2, arbolEspejo);
    arbol->insertar(8, arbolEspejo);

    arbol->generar();
    arbolEspejo->generar2();
    delete arbol;

}

