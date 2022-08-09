#include<iostream>
#include <math.h> 
#include <stdexcept>

using namespace std;

class Point {

//Atributos
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

    //M�todos
    
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

class Nodo{
  
  Point* dato;
  Nodo* pointer;
  
public:
  
  Nodo(){
      dato = NULL;
      pointer = NULL;
  }
  
  ~Nodo(){
      delete dato;
  }
  
  Nodo(Point* d){
      dato = d;
      pointer = NULL;
  }
    
  Point* getDato(){
      return dato;
  }
  
  void setDato(Point* d){
      dato = d;
  }
  
  Nodo* getNext(){
      return pointer;
  }
  
  void setNext(Nodo* p){
      pointer = p;
  }
    
};

class Lista{
    
    Nodo* ptr;
    int size;

public:  

    Lista(){
        ptr = NULL;
        size = 0;
    }
    
    ~Lista(){
        /*Nodo* t = ptr;
        while(t->getNext() != NULL){
            t = t->getNext();    
        }*/
    }
    
    void push_back(Point* d){
        
        if(size == 0){
            ptr = new Nodo(d);
            size++;
        }else{
            Nodo* t = ptr;
            while(t->getNext() != NULL){
                t = t->getNext();    
            }
            t->setNext(new Nodo(d));
        }
        
    }
    
    int getSize(){
        return size;
    }
    
    void destroy_element_INEFICIENTE_NO_USAR(Nodo* d){
        Nodo* t = ptr;
        do {
            t = t->getNext();
        } while(t->getNext() != d);
        destroy_next(t);
    }
    
    void destroy_next(Nodo* d) {
        Nodo* n = d->getNext();
        d->setNext(n->getNext());
        delete n;
        size--;
    }
    
    Nodo* getNodo(int i) {
        if(size == 0) {
            throw invalid_argument("La lista no tienen nodos");
        } else {
            
        }
    }
    
    void print(){
        if(size == 0){
            cout<<"La lista está vacía"<<endl;
        }else{
            Nodo* t = ptr;
            do{
                cout<<"("<<(*t).getDato()->getX()<<", "<<t->getDato()->getY()<<"), ";
                t = t->getNext();
                
            }while(t != NULL);
            cout<<endl;
        }
    }
    
};


int main()
{
   
   Lista l = Lista();
   
   l.push_back(new Point(1,1));
   
   l.print();
   
   l.push_back(new Point(2,2));
   
   l.print();
   
   for(int i = 3; i<10; i++){
       l.push_back(new Point(i,i));
   }
   
   l.print();
   
   l.destroy_next()
   
    return 0;
}