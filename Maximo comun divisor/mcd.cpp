#include <iostream>
#include <chrono>
#include <unistd.h>
using namespace std;

int euclides1(int a, int b){

    while(a%b != 0){
        int c = a%b;
        a = b;
        b = c;
    }

    return b;
};

int euclides2(int a, int b){
    if(a%b != 0){
        return euclides2(b,a%b);
    }
    else{
        return b;
        
    }
};

int mcd(int endo, int sor){

//  Creo variable auxiliar para saber cual es el mas pequeno
    int aux;
    if(endo > sor){
        aux = sor;
    }
    else{
        aux = endo;
    }
    // Busco el primer divisor exacto entre ambos
    while(endo%aux !=0 || sor%aux != 0 ){
        aux = aux - 1;
    }
    return aux;
}

int main(){
    int a,b;
    cin >> a >>b;

    auto start = chrono::steady_clock::now();
    int e1 = euclides1(a,b);
    auto end = chrono::steady_clock::now();

    cout << "Euclides con while: " << e1 << " con tiempo " 
    << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

    start = chrono::steady_clock::now();
    int e2 = euclides2(a,b);
    end = chrono::steady_clock::now();

    cout << "Euclides recursivo " << e2 << " con tiempo " 
    << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

    start = chrono::steady_clock::now();
    int e3 = mcd(a,b);
    end = chrono::steady_clock::now();

    cout << "Fuerza bruta " << e3 << " con tiempo " 
    << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;



    return 0;
}
