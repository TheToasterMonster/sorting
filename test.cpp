#include <chrono>
#include <iostream>
#include <limits>
#include <random>
#include <vector>

#include "sorts/sorting.h"
#include "Profiler.h"

void error() {
    std::printf("usage: \"./test size mode\"\n");
    std::printf("  size: positive 32-bit integer denoting size of array to sort\n");
    std::printf("  mode: type of array, one of [\"sorted\", \"reverse\", \"random\"]\n");
    exit(1);
}

bool eq(const std::vector<int>& lhs, const std::vector<int>& rhs) {
    if (lhs.size() != rhs.size()) {
        return false;
    }
    for (size_t i = 0; i < lhs.size(); i++) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char** argv) {
    if (argc != 3) {
        error();
    }

    int sz = std::atoi(argv[1]);
    if (sz <= 0) {
        error();
    }

    std::vector<int> orig(sz);
    std::string mode = argv[2];
    if (mode == "sorted") {
        int start = (rng() % (std::numeric_limits<int>::max() - sz));
        for (int i = 0; i < sz; i++) {
            orig[i] = start + i;
        }
    } else if (mode == "reverse") {
        int start = (rng() % (std::numeric_limits<int>::max() - sz));
        for (int i = 0; i < sz; i++) {
            orig[i] = -(start + i);
        }
    } else if (mode == "random") {
        for (int i = 0; i < sz; i++) {
            orig[i] = rng();
        }
    } else {
        error();
    }

    std::printf("sorting %d integers in %s mode...\n", sz, mode.c_str());
    std::vector<int> sorted(orig);
    {
        std::cout << "  std::sort:      ";
        {
            Profiler profile;
            std::sort(sorted.begin(), sorted.end());
        }
    }
    {
        std::vector<int> arr(orig);
        std::cout << "  bubble sort:    ";
        {
            Profiler profile;
            bubble_sort<int>()(arr);
        }
        assert(eq(sorted, arr) && "bubble sort failed");
    }
    {
        std::vector<int> arr(orig);
        std::cout << "  insertion sort: ";
        {
            Profiler profile;
            insertion_sort<int>()(arr);
        }
        assert(eq(sorted, arr) && "insertion sort failed");
    }
    {
        std::vector<int> arr(orig);
        std::cout << "  selection sort: ";
        {
            Profiler profile;
            selection_sort<int>()(arr);
        }
        assert(eq(sorted, arr) && "selection sort failed");
    }
    {
        std::vector<int> arr(orig);
        std::cout << "  heap sort:      ";
        {
            Profiler profile;
            heap_sort<int>()(arr);
        }
        assert(eq(sorted, arr) && "heap sort failed");
    }
    {
        std::vector<int> arr(orig);
        std::cout << "  merge sort:     ";
        {
            Profiler profile;
            merge_sort<int>()(arr);
        }
        assert(eq(sorted, arr) && "merge sort failed");
    }
    {
        std::vector<int> arr(orig);
        std::cout << "  quick sort:     ";
        {
            Profiler profile;
            quick_sort<int>()(arr);
        }
        assert(eq(sorted, arr) && "quick sort failed");
    }
}
