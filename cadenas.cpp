#include <iostream>
#include <string>
using namespace std;

int main() {
string palabra;
int contador{0};
cout << "ingresa tu cadena de palabras :";
cin >> palabra;
char elemento;
cout << "ingresa el elemento: ";
cin >> elemento;

for(int i=0; i <palabra.length; i++){
    if(palabra.at(i) == elemento){
        contador++;
    }
}
cout << contador << endl;

return 0;
}
