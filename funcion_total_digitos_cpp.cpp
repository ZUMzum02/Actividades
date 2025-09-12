#include <iostream>

using namespace std;

void calcular_digitos(int num){
int n{1};
int contador {0};
if (num >= 0 && num <= 9){
    contador ++;
}else{
while ( n <= num){
    n = n*10;
    contador ++;
}}
cout << "total de digitos: " << contador;
}

int main(){
    int num;
cout << "ingresa un numero: " << endl;
cin >> num;
calcular_digitos(num);
return 0;
}
