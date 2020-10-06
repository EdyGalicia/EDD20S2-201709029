
package arbolb;

public class ArbolB {

    public static void main(String[] args) {
        
        //INGRESAR EL Tamanio minimo de hijos, esto se multiplicara por dos para saber el numero de hijos MAX
        // y a eso se le restara 1 para obtener el numero de claves
        int tam = 3;
        //en cada nodo cabran 2*3-1=5 numeros
        //el nodo tendra 2*3 hijos
        arbolitoB arbolB = new arbolitoB(tam);

        
        System.out.println("Insertando el 6");
        arbolB.insertar(6);
        System.out.println("Insertando el 11");
        arbolB.insertar(11);
        System.out.println("Insertando el 5");
        arbolB.insertar(5);
        System.out.println("Insertando el 4");
        arbolB.insertar(4);
        System.out.println("Insertando el 8");
        arbolB.insertar(8);
        //imprimo en PREORDEN
        System.out.println("MI ARBOL B QUEDA:");
        arbolB.imprimirArbol();
        System.out.println("");
        
        System.out.println("Insertando el 9");
        arbolB.insertar(9);

        System.out.println("MI ARBOL B QUEDA:");
        arbolB.imprimirArbol();
        System.out.println("");
    }
    
}
