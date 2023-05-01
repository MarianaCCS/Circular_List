#include <bits/stdc++.h>
using namespace std;

/*
    Input: 
        - n: 6
        - vector: 180 141 174 143 142 175

    Output:
        - string: 141-143 174 175 180  *(notar que 174 y 175 deben ir separando porque solo son dos numeros consecutivos. Si fueran más de dos, se usaría el guion)*
*/

int main(){
    // variables
    int n;
    int var;
    vector <int> numeros;

    // input
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>var; numeros.push_back(var);
    } 

    // -------------   algoritmo -------------------
    
    for (int i=0;i<n-1;i++){ //1. ordenar el array
        for (int j=i;j<n;j++){
            if (numeros[i]>numeros[j]){
                int temp = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = temp;
            }
        }
    }

    
    int count = 0; // 2. contabilizar la cantidad de elementos consecutivos
    string result = ""; 

    for (int i=0; i<n; i++){
        string number = to_string(numeros[i]); // opcional
        count = 1; 
        while(numeros[i+1]==numeros[i]+1) {count++;  i++; } // contador de consecutivos

        switch (count){ // evaluar string
        case 1:
            result += number + " ";
            break;

        case 2: 
            result += number + " ";
            result += to_string(numeros[i]) + " ";
            break;

        default:
            result += number + "-" + to_string(numeros[i]) + " ";
            break;
        }
    }

    cout<<result<<endl;

    return 0;
}