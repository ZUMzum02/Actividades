
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class numero {
    public:
    int a;
    numero(int x): a(x){}
    void corroborar(){
        if ( a <=9999 && a>= 1000){
            int m = a / 1000;
            cout << m << endl;
            int c = (a - m*1000) / 100; 
            cout << c << endl;
            int d = (a - m*1000 - c*100) /10;
            cout << d << endl;
            int s = a-m*1000-c*100-d*10;
            cout << s << endl;  
            // ------------------------------------ 
            cout << "otra forma de hacerlo" << endl;
            cout << (a / 1000) << endl;
            cout << (a % 1000) / 100 << endl;
            cout << (a % 100) / 10 << endl;
            cout << a & 10 << endl;
            
        }else {cout <<"solo cuatro digitos pa" << endl;}
        
    }
}; 

int main(){
    numero* ptr = new numero(1234);
    ptr->corroborar();
}
