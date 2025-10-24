#include <iostream>
#include <cmath>
using namespace std;

class punto {
public:
    int x;
    int y;

    punto(int a, int b) : x(a), y(b) {};

float distancia(punto b){
    int resultado1= b.x - x;
    int resultado2 = b.y - y;

    float resultado = sqrt(resultado1 + resultado2);
    return resultado;
}

void imprimir(){
    cout << "punto: (" << x << ", " << y << ")" << endl;
}
};
class vector {
    public:
    punto inicio;
    punto fin;

    vector(punto a, punto b) : inicio(a), fin(b) {};

    float modulo(){
        int resultado1 = fin.x - inicio.x;
        int resultado2 = fin.y - inicio.y;
        float resultado = sqrt((resultado1*resultado1)+(resultado2*resultado2));
        return resultado;
    }

    void print() {
        inicio.imprimir();
        fin.imprimir();
    }

};


int main(){

// usar const cuando solo es LECTURA mas no modifica....
punto* ptr = new punto(4,5);  // crear clase con puntero
ptr->imprimir();              // usando funcion con puntero se cambio el objeto.funcion(...) => puntero->funcion(...)
punto* ptr1 = new punto(7,10);
ptr1->imprimir();
cout << "distancia: " << ptr->distancia(*ptr1);

cout << endl << "------------- OBJETO VECTOR----------" << endl;
vector* XD = new vector(*ptr, *ptr1);
XD->print();
cout << "modulo del vector :" << XD->modulo();



return 0;
}
