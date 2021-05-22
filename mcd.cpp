
#include<iostream>
#include<cmath>
using namespace std;
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
    int endo, sor,r;
    cin >> endo >> sor;
    r = mcd(endo,sor);
    cout << endo/r<< " " << sor/r << endl;
    return 0;
}
