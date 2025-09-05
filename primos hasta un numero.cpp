#include <iostream>
#include <string>

using namespace std;

int main() {
    
    int numero;
    cout << "ingresa un numero (que sea primo ps): ";
    cin >> numero;

    int actual = 2; 

    cout << "los primos hasta " << numero << " son:" << endl;

    while (actual <= numero) {
        int contador = 0;
        int divisor = 1;

        while (divisor <= actual) {
            if (actual % divisor == 0) {
                contador = contador + 1;
            }
            divisor = divisor + 1;
        }
        if (contador == 2) {
            cout << actual << " ";
        }   
        actual = actual + 1;
    }
    cout << endl;

    return 0;
}
