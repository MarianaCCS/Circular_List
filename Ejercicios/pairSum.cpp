#include <bits/stdc++.h>
using namespace std;

/*
    Dado un array ordenando y un numero x. Encontrar dos valores que al sumarlos dé como resultado un valor cercano al x
        - Input: (10,22, 28,29,30,40), x=54
        - Output: 22,30
*/
pair<int,int> pairSum(vector<int> v,int x){
    int r1,r2; // indices que se rtornan (es necesario tenerlos separados)
    int n = v.size();

    //direcciones (analisis de punteros)
    int left = 0 ;
    int right = n-1;
    int min = INT_MAX; // valor entero maximo (de std)

    while (right>left){ // mientras que puntero derecho es mayor 
        int temp = v[right] + v[left]; // suma de dos valores del array
        if (abs(temp-x)<min){ // debe evaluar si la diferencia entre la suma es la minima
            r1 = left; // si es menor, los indices a retornar cambian
            r2 = right;
            min = abs(temp-x); // la distancia minima a la suma cambia
        }

        // notar que esto no altera a r1 ni r2 
        if (v[right]+v[left]>x){ // si la suma es mayor el de la derecha disminuye
            right--; 
        }
        else{
            left++; // si la suma es menor o igual, derecha aumenta
        }
    }
    return pair<int,int>(v[r1],v[r2]);
}

int main(){
    vector <int> v = {10,22,28,29,30,40};
    pair<int,int> numeros = pairSum(v,54);
    cout<<numeros.first<<" and "<<numeros.second<<endl;
}