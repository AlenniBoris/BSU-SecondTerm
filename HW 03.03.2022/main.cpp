#include "List.h"
#include "Sorted_List.h"
#include "Stack.h"

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

    std::cout <<"\nSorted list: " << std::endl;
    list.Sort(list);
    list.Print();




//    std::cout << std::endl;
//    std::cout << std::endl;
//
//
//    Stack<int> stack;
//    stack.Push(5);
//    stack.Push(100);
//    stack.Push(56556);
//    stack.Push(77);
//    stack.Push(1);
//    stack.Push(0);
//
//    stack.Print();
//    std::cout<<std::endl;
//    std::cout << stack.Top()<<std::endl;
//    stack.Pop();
//    stack.Print();

    return 0;
}
