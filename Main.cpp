#include <iostream>
#include "Source/BoxKernel.h"
int main() {
    EdgeDetections::BoxKernel kernel = {{1,2}, {2}};
    std::cout << "Hello world ! Total = " << kernel.GetTotal()  << std::endl;
}
