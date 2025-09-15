#include <iostream>
using namespace std;

int main() {
    int num, original, invertido = 0, resto;
    
    cout << "Ingresa tu numero: ";
    cin >> num;
    
    if (num < 0) {
        cout << "no es palindromo bro" << endl;
        return 0;
    }
    
    original = num;
    
    // Invertir el número
    while (num != 0) {
        resto = num % 10;
        invertido = invertido * 10 + resto;
        num /= 10;
    }
    
    if (original == invertido) {
        cout << "es palindromo" << endl;
    } else {
        cout << "no es palindromo bro" << endl;
    }
    
    return 0;
}