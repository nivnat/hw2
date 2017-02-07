#include <iostream>
#include "Cube.h"

int main() {
    Cube test(3);
    std::cout << test << "---" << std::endl;
    test=test.makeMove(LeftUp);
    std::cout << test << "---" << std::endl;
    test=test.makeMove(TopLeft);
    std::cout << test << "---" << std::endl;
    test=test.makeMove(LeftDown);
    std::cout << test << "---" << std::endl;
    test=test.makeMove(TopLeft);
    std::cout << test << "---" << std::endl;
    test=test.makeMove(LeftDown);
    std::cout << test << "---" << std::endl;
    test=test.makeMove(TopLeft);
    std::cout << test << "---" << std::endl;
    test=test.makeMove(LeftDown);
    std::cout << test << "---" << std::endl;
    test=test.makeMove(LeftUp);
    std::cout << test << "---" << std::endl;
    return 0;
}