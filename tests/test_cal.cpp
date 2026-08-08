#include "cal.h"

#include <cassert>
#include <iostream>

int main() {
    assert(add(2, 3) == 5);
    assert(add(-1, 1) == 0);
    assert(add(0, 0) == 0);

    std::cout << "All tests passed\n";
}