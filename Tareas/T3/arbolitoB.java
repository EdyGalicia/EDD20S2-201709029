
package arbolb;


public class arbolitoB {
    NodoB root;
    int numMinimoDeHijos;

    //Constructor
    public arbolitoB(int t) {
        this.numMinimoDeHijos = t;
        root = new NodoB(t);
    }
    
    public int buscarClaveMayor() {
        int claveMaxima = getClaveMayor(this.root);

        return claveMaxima;
    }

    private int getClaveMayor(NodoB current) {
        if (current == null) {
            return 0;
        }

        while (!current.leaf) {
            current = current.child[current.n];
        }

        return claveMayorPorNodo(current);
    }
    
    private int claveMayorPorNodo(NodoB current) {
        return current.llaves[current.n - 1];
    }

    public void mostrarClavesNodoMinimo() {
        NodoB temp = buscarNodoMinimo(root);

        if (temp == null) {
            System.out.println("Sin minimo");
        } else {
            temp.imprimir();
        }
    }
    
    public NodoB buscarNodoMinimo(NodoB nodoActual) {
        if (root == null) {
            return null;
        }
        NodoB aux = root;
        while (!aux.leaf) {
            aux = aux.child[0];
        }
        return aux;
    }
    
    public void buscarNodoPorClave(int num) {
        NodoB temp = search(root, num);

        if (temp == null) {
            System.out.println("Nodo NO ENCONTRADO");
        } else {
            print(temp);
        }
    }

    private NodoB search(NodoB actual, int key) {
        int i = 0;

        while (i < actual.n && key > actual.llaves[i]) {
            i++;
        }

        if (i < actual.n && key == actual.llaves[i]) {
            return actual;
        }

        if (actual.leaf) {
            return null;
        } else {
            return search(actual.child[i], key);
        }
    }
    
    public void insertar(int key) {
        NodoB r = root;

        if (r.n == ((2 * numMinimoDeHijos) - 1)) {
            NodoB s = new NodoB(numMinimoDeHijos);
            root = s;
            s.leaf = false;
            s.n = 0;
            s.child[0] = r;
            split(s, 0, r);
            nonFullInsert(s, key);
        } else {
            nonFullInsert(r, key);
        }
    }

    private void split(NodoB x, int i, NodoB y) {
        NodoB z = new NodoB(numMinimoDeHijos);
        z.leaf = y.leaf;
        z.n = (numMinimoDeHijos - 1);
        
        for (int j = 0; j < (numMinimoDeHijos - 1); j++) {
            z.llaves[j] = y.llaves[(j + numMinimoDeHijos)];
        }

        if (!y.leaf) {
            for (int k = 0; k < numMinimoDeHijos; k++) {
                z.child[k] = y.child[(k + numMinimoDeHijos)];
            }
        }
        
        y.n = (numMinimoDeHijos - 1);
        
        for (int j = x.n; j > i; j--) {
            x.child[(j + 1)] = x.child[j];
        }
        
        x.child[(i + 1)] = z;
        
        for (int j = x.n; j > i; j--) {
            x.llaves[(j + 1)] = x.llaves[j];
        }

        x.llaves[i] = y.llaves[(numMinimoDeHijos - 1)];
        x.n++;
    }
    
    
    private void nonFullInsert(NodoB x, int key) {
        if (x.leaf) {
            int i = x.n;
            while (i >= 1 && key < x.llaves[i - 1]) {
                x.llaves[i] = x.llaves[i - 1];
                i--;
            }

            x.llaves[i] = key;
            x.n++;
        } else {
            int j = 0;
            while (j < x.n && key > x.llaves[j]) {
                j++;
            }

            if (x.child[j].n == (2 * numMinimoDeHijos - 1)) {
                split(x, j, x.child[j]);

                if (key > x.llaves[j]) {
                    j++;
                }
            }

            nonFullInsert(x.child[j], key);
        }
    }

    public void imprimirArbol() {
        print(root);
    }
    
    
    private void print(NodoB n) {
        n.imprimir();

        if (!n.leaf) {
            for (int j = 0; j <= n.n; j++) {
                if (n.child[j] != null) {
                    System.out.println();
                    print(n.child[j]);
                }
            }
        }
    }
    
}
