
#include <iostream>
#include <vector>

#include "recursive_max.h"



int main(){

std::vector<int> yh {9,1,2,3,8,4,4,5,6};

int x = RecursiveMax(yh,yh.size());
std::cout << x << std::endl;


}
