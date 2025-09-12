#include <iostream>

using namespace std;

void Identificador( int numero) {
    bool es_primo = true;
    if ( numero <= 1){
        es_primo = false;
    }else{
    for (int i=2; i < numero; i++){
        if (numero % i == 0){
                es_primo = false;
                break;
            }
    }
    }
    if (es_primo == true){
        cout << "es primo de chill"<< endl;
    }else { cout << " no es primo bro" << endl;
    }
};

int main(){
int num;
cout << "ingresa un numero" << endl;
cin >> num;
Identificador(num);


return 0;
}
