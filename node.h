#include <iostream>
using namespace std;

template <class T>
struct Node{
    T data; // valor 
    Node<T>* prev; // nodo anterior
    Node<T>* next; // nodo siguiente

    Node(): prev(nullptr), next(nullptr){} //constructor por defecto
    Node(T value): data(value), prev(nullptr), next(nullptr){} //constructor 


    void killSelf(){ // nodo se elimina a sí mismo (sus vecinos deben "descolgar" al nodo)
        if (prev) prev->next = this->next; // si no es nulo, el next del anterior apunta al siguiente actual 
        if (next) next->prev = this->prev; // si no es nulo, el prev del siguiente apunta al anterior actual

        delete this; // se elimina a sí mismo
    }

    ~Node(){ //destructor
        prev = next = nullptr;
    }
};