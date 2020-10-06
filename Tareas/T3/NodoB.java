
package arbolb;

public class NodoB {
    int n;
    boolean leaf;
    int llaves[];
    NodoB child[];
    
    //Constructores
    public NodoB(int t) {
        n = 0;
        leaf = true;
        llaves = new int[((2 * t) - 1)];
        child = new NodoB[(2 * t)];
    }
    
    public void imprimir() {
        System.out.print("[");
        //recorro el arreglo del nodo
        for (int i = 0; i < n; i++) {
            if (i < n - 1) {
                System.out.print(llaves[i] + " | ");
            } else {
                System.out.print(llaves[i]);
            }
        }
        System.out.print("]");
    }
    
    public int find(int k) {
        for (int i = 0; i < n; i++) {
            if (llaves[i] == k) {
                return i;
            }
        }
        return -1;
    }
    
}
