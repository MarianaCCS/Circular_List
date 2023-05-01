#include "circular.h"
#include "tester.h"

void test(CircularList<int>* list){   
    cout<<"*** Testing "<<"  *******"<<endl; 
    ASSERT(list->is_empty() == true, "The function is_empty is not working"); //1
    ASSERT(list->size() == 0, "The function size is not working");    //2
    list->push_front(5);
    list->push_front(10);
    ASSERT(list->pop_front() == 10, "The function push_front/pop_front is not working"); //3
    list->push_back(20);
    list->push_back(15);
    ASSERT(list->pop_back() == 15, "The function push_back/pop_back is not working"); //4
    list->push_back(30);
    list->push_back(8);
    list->insert(12, 2);
    ASSERT((*list)[2] == 12, "The operator [] is not working");    //5
    list->push_back(10);
    list->push_front(3);
    ASSERT(list->is_sorted() == false, "The function is_sorted is not working"); //6
    list->sort();
    ASSERT(list->is_sorted() == true, "The function sort is not working"); //7
    list->clear();
    ASSERT(list->is_empty() == true, "The function clear is not working"); //8
    delete list;
}

int main()
{    
    CircularList<int> *circular = new CircularList<int>();
    test(circular);
    
    return 0;
}