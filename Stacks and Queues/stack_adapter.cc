#include <iostream>

#include "stack_adapter.h"



int main(){

Stack<int> u;



u.Push(8);
u.Push(9);
std::cout << u.Pop() << std::endl;


}
