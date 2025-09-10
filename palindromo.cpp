#include <iostream>

using namespace std;
int exponencial (int base, int exponente){
int resultado = 1;
for (int i = 0; i < exponente; i++){
    resultado *= base;
}
return resultado;
}

int main() {
int num;
cout << "ingresa tu numero: " << endl;
cin >> num;
int contador{0};
int temp {1};

while (temp < num){
    temp *= 10;
    contador += 1;
}
cout << "largo del numero: " << contador << endl;
bool espalindromo = true;
for (int i=0; i < contador/2; i++){
    if (contador / 2 == 1){
            int primer = num / 10;
            int segundo = num - primer*10;
            ...
    int primer = num / (exponencial(10, contador-1-i)) % 10;
    int segundo = num / (exponencial(10, i)) % 10;
    if ( primer != segundo) {
        cout << "no es palindromo bro" << endl;
        espalindromo = false;
        break;
    }
}
if (espalindromo == true){
    cout << "es palindromo" <<endl;
}
return 0;
}
