#include <iostream>
#include <string>

using namespace std;

int main() {
    
    int numero;
    cout << "ingresa un numero (que sea primo ps): ";
    cin >> numero;
    int contador = 0;
    int divisor = 1;
    while ( divisor <= numero) {
        if ( numero % divisor == 0) {
            contador = contador + 1;
            }
        divisor = divisor + 1;
          
    }
     if ( contador == 2) {
            cout << "es primo bro" << endl;
            }else {
                cout << "no es primo bro"<< endl;
    
                }
    
    
 return 0;     
}
