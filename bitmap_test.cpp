#include <iostream>

#include "bitmap.h"

#define SIZE (530941lu)

int main()
{
    Bitmap b(SIZE);

    std::cout << "[all1 test]" << std::endl;
    b.all1();
    for (uint64_t i=0; i<SIZE; i++) {
        if (!b.get(i)) {
            std::cout << i << " is not 1" << std::endl;
        }
    }

    std::cout << "[all0 test]" << std::endl;
    b.all0();
    for (uint64_t i=0; i<SIZE; i++) {
        if (b.get(i)) {
            std::cout << i << " is not 0" << std::endl;
        }
    }

    std::cout << "[set0/set1 test]" << std::endl;
    for (uint64_t i=0; i<SIZE; i++) {
        if (i % 3 == 0) {
            b.set1(i);
        }
        if (i % 9 == 0) {
            b.set0(i);
        }
    }

    for (uint64_t i=0; i<SIZE; i++) {
        if (i % 3 == 0 && i % 9!= 0) {
            if (!b.get(i)) {
                std::cout << i << " is not 1" << std::endl;
            }
        } else {
            if (b.get(i)) {
                std::cout << i << " is not 0" << std::endl;
            }
        }
    }

    return 0;
}
