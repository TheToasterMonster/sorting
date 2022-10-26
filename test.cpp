#include <iostream>
#include <vector>

#include "heap_sort.h"

int main() {
    std::vector<int> arr = { 10, 9, 8, 7, 6, 3, 2 };

    heap_sort<int>()(arr);
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}
