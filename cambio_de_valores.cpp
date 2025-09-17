#include <iostream>
#include <string>
using namespace std;

void cambio ( int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int numero1{1}, numero2{2};
    cout << numero1 << "    " << numero2 << endl;
    cambio(numero1, numero2);
    cout << numero1 << "    " << numero2 << endl;

    return 0;
}
