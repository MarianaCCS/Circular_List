#include "node.h"

template <class T>
class CircularList{

    private:

    Node<T>* head; //nodo sentinela (cabeza sin valor)
    int nodes; // cantidad de nodos

    public:
    CircularList(){
        head = new Node<T>(); 

        //sentinela siempre se apunta a sí mismo (al inicio)
        head->prev = head->next = head;
        nodes = 0;
    }

    ~CircularList(){
        while (head->next !=head){ //mientra que no esté vacio
            pop_front(); // también se puede hacer pop_back()
        }
        delete head; // <-> head->killSelf();
    }


    T front(){ // 1er elemento
        if (head->next == head || !head) cerr<<"La lista se encuentra vacía\n"; //exception
        return head->next->data;
    }


    T back(){ // último elemento
        if (head->prev == head || !head) cerr<<"La lista se encuentra vacía\n"; //exception
        return head->prev->data;
    }

    T pop_front(){ // elimina primer elemento (despues el sentinel-head)
        if (nodes==0) cerr<<"Lista no tiene elementos"; //exception

        Node<T>* elim = head->next;
        T result = elim->data;
        elim->killSelf();

        nodes--;
        return result;
    }

    T pop_back(){ // elimina ultimo elemento (antes del sentinel-head)
        if (nodes==0) cerr<<"Lista no tiene elementos"; //exception

        Node<T>* elim = head->prev;
        T result = elim->data;
        elim->killSelf();

        nodes--;
        return result;
    }

    void push_front(T value){ //inserta al frente ("siguiente" a sentinel)
        Node<T>* nuevo = new Node<T>(value); //nuevo nodo (a insertar)
        
        // nodo se cuelga a sus proximos vecinos
        nuevo->prev = head;
        nuevo->next = head->next;

        //sus vecinos ayudan al nodo a colgarse
        head->next->prev = nuevo;
        head->next = nuevo;

        nodes++; // aumenta en 1 la cantidad
    }

    void push_back(T value){ // inserta al final ("atras" de sentinel)
        Node<T>* nuevo = new Node<T>(value); //nuevo nodo (a insertar)

        // nodo se cuelga a sus proximos vecinos
        nuevo->next = head;
        nuevo->prev = head->prev;

        //sus vecinos ayudan al nodo a colgarse
        head->prev->next = nuevo;
        head->prev = nuevo;

        nodes++; // aumenta en 1 la cantidad
    }


    void insert(T value, int pos){ // inserta en una posicion fija
        if (pos<0 || pos>nodes) cerr<<"Posición no válida\n"; //verificar
        else if (pos==0) push_front(value); // inserta al inicio
        else if(pos==nodes) push_back(value); // inserta al final
        else{ // inserta en cualquier posicion
            int index = 0; // indice
            Node<T>* temp = head->next; //puntero al 1er elemento
            
            while (index<pos){
                temp = temp->next;
                index++;
            } // temp es la posicion es la que se insertará el nuevo nodo

            Node<T>* newNode = new Node<T> (value); //nuevo nodo

            // nodo se cuelga a sus vecinos
            newNode->prev = temp->prev;
            newNode->next = temp;

            // sus vecinos lo ayudan a colgarse
            temp->prev->next = newNode;
            temp->prev = newNode;

            nodes++; //cantidad de nodos aumenta
        }
    }

    void remove(int pos){ // remueve en la posicion dada
        if (pos<0 || pos>=nodes) cerr<<"Posición no válida\n";
        else if(pos==0) pop_front();
        else if(pos==nodes-1) pop_back();
        else{ // elimina en cualquier posicion
            int index = 0;

            Node<T>* elim = head->next; // nodo al primer elemento

            while (index<pos){
                elim = elim->next;
                index++;
            } // elim es el nodo a eliminar

            elim->killSelf(); // vecinos descuelgan al nodo y la direccion se elimina
        }
    }

    int size(){ // cantidad de elementos
        return nodes;
    }

    T& operator[](int pos){ // retorna la posicion
        if (pos<0 || pos>=nodes) cerr<<"Posición no válida\n";
        int index = 0;
        Node<T>* temp = head->next;

        while (index<pos){
            temp = temp->next;
            index++;
        }

        return temp->data;
    }

    bool is_empty(){
        return nodes==0;
    }

    void display(){ //imprime elementos
        Node<T>* temp = head->next;

        while(temp!=head){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }

    void sort(){
        if (is_empty()) return; // caso vacío

        
        for (Node<T>* i=head; i->next!=head; i=i->next){ // Bubble Sort
            Node<T>* menor = i; // vamos a enviar los menores a la izquierda
            for (Node<T>* j=i->next; j!=head; j=j->next){
                if (menor->data>j->data){ // se actualiza valor del menor
                    menor = j;
                }
            }
            if (menor!=i){ // vamos a enviar los menores a la izquierda
                T temp = i->data;
                i->data = menor->data;
                menor->data = temp;
            }
        }
    }

    void clear(){
        while(!is_empty()) pop_back(); // o pop_front()
    }

    bool is_sorted(){
        Node<T>* temp = head->next; // nodo para recorrido
        for (int i=0;i<nodes-1;i++){ // verifica orden ascendente
            if(temp->data>temp->next->data) return false;
            temp = temp->next;
        }
        return true;
    }

    void reverse(){
        if (nodes<2) return;

        Node<T>* temp = head;

        /*
        do{
            Node<T>* t = temp->next;
            temp->next = temp->prev;
            temp->prev = t;
            temp = t;
        } while(temp!=head);
        */

        // solo hay que revertir los punteros (prev y next) por nodo
        display();
        for (Node<T>* i=head; i->next!=head; i=i->prev){ // se avanza "hacia atras"(por la reversion)
            Node<T>* temp = i->prev;
            i->prev = i->next;
            i->next = temp;
        }

    }
};