#include "List.h"
#include "Sorted_list.h"

int main() {
    list<int> list;
    list.Push(10);
    list.Push(3);
    list.Push(5);
    list.Push(13);
    list.Push(12);
    list.Push(15);
    list.Push(2);
    list.Print();
    std::cout<<std::endl;
    list.Delete(15);
    list.Print();

    std::cout <<"\nSorted list: " << std::endl;
    Sorted_list<int> list1;
    list1.Push(10);
    list1.Push(3);
    list1.Push(5);
    list1.Push(13);
    list1.Push(12);
    list1.Push(15);
    list1.Push(2);
    list1.Print();

    return 0;
}
