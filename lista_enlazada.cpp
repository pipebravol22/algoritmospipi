// Online C++ compiler to run C++ program online
#include <iostream>
#include <math.h> 
using namespace std;


class Point {
    int x;
    int y;

    const int rmax = 1;

public:
    
    //Constructores
    Point(int xc, int yc) {
        x = xc;
        y = yc;

    }

    Point() {
        x = 0;
        y = 0;
    }
    
    Point ofuscacion() {
        return Point(x + 2 * (rand() % rmax) - rmax, y + 2 * (rand() % rmax) - rmax);
    }
    
    double dist() {
        return dist(0,0);
    }

    double dist(int xc, int yc) {
        return sqrt(pow(x-xc, 2) + pow(y-yc, 2));
    }

    double dist(Point p) {
        return dist(p.x, p.y);
    }

    //Getters
    int getX() {
        return x;
    }

    int getY() {
        return y;
    }


    //Setters
    void setX(int xc) {
        x = xc;
    }

    void setY(int yc) {
        y = yc;
    }
    
    Point& operator=(const Point& f) { 
		setX(f.x);
		setY(f.y);
		return *this; 
	
    }
};

	
class Nodo {
    Point* dato;
    Nodo* pointer;
    
public:
    Nodo(Point *d) {
        dato = d;
        pointer = NULL;
    }
    
    
    Point getDato() {
        return *dato;
    }
    
    void setDato(Point* d) {
        dato = d;
    }
    
    Nodo* getNext() {
        return pointer;
    }
    
    void setNext(Nodo* p) {
        pointer = p;
    }
};


class Lista {
    Nodo* ptr;
    int size;

public:
    Lista() {
        ptr = NULL;
        size = 0;
    }
    
    void pushBack(Point* d) {
        if (size == 0) {
            ptr = new Nodo(d);
            size ++;
        } else {
            Nodo* t = ptr;
            while(t->getNext() != NULL) {
                t = t->getNext();
            }
            
        }
    }
    
    void print() {
        if (size == 0) {
            cout << "La lista esta vacia" << endl;
        } else {
            Nodo* t = ptr;
            do {
                cout <<"(" << t->getDato().getX() << ", " << t->getDato().getY() << "), ";
                t = t->getNext();
            } while (t->getNext() == NULL);
        }
    }
};


int main() {
    // Write C++ code here
    Lista lista = Lista();

    lista.pushBack(new Point(1,1));
    
    lista.print();

    return 0;
}
