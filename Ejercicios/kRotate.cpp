#include <iostream>
#include <vector>
using namespace std;

/*
    Dado un vector y un entero k, elaborar una función que retorne una rotación k
    Input: {1 , 2 ,3 , 4} , x=2
    Output: {3, 4, 1, 2}
*/

template <class T>
vector<T> krotate(vector<T> v, int k){
    vector <T> result={};

    int n = v.size(); 
    k = k%n; // si k=n, el vector rota todos sus elementos y los tiene en el mismo lugar (inicial)

    /*

        Análisis (Caso):
            - Input: {1 ,3 ,5 ,7 , 9} , k=2
            - Output: {7 , 9 ,1, 3 , 5 } // notar que los "k" ultimos elem's van al inicio

            ** Evaluar caso en un papel y anotar los indices de cada inserción
    */

   for (int i=0;i<n;i++){
        if (i<k){ // i<k
            result.push_back(v[n-k+i]); // 0,1, ... ,k
        }
        else{
            result.push_back(v[i-k]); 
        }
   }
    return result;
}

int main(){
    vector <int> prueba = {1,3,5,7,9};
    vector <int> result = krotate(prueba,2);
    for (auto elem:result) cout<<elem<<" ";
}