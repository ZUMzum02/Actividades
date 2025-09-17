#include <iostream>
#include <string>
using namespace std;

// funcion
void verificacion_palindromo(string XD){
bool es_palindromo = true;
for (int i = 0; i< XD.length() / 2; i++){
    if (XD.at(i) != XD.at(XD.length()-1-i)){
        es_palindromo = false;
    }
}
if (es_palindromo) {
        cout << "Es palindromo bro" << endl;
    } else {
        cout << "No es palindromo :(" << endl;
    }
};

int main() {
    string palabra;
    cout << "Ingresa tu palabra: ";
    cin >> palabra;

    bool es_palindromo = true;
    for (int i = 0; i < palabra.length() / 2; i++) {
        if (palabra.at(i) != palabra.at(palabra.length() - 1 - i)) {
            es_palindromo = false;
            break;
        }
    }
    if (es_palindromo) {
        cout << "Es palindromo bro" << endl;
    } else {
        cout << "No es palindromo :(" << endl;
    }
    verificacion_palindromo(palabra);
    return 0;

}
