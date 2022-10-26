#pragma once

#include <utility>
#include <vector>

template <typename T>
struct bubble_sort {
    void operator()(std::vector<T>& arr) {
        size_t last_swapped = arr.size() - 1;
        while (last_swapped) {
            size_t curr_swap = 0;
            for (size_t i = 1; i <= last_swapped; i++) {
                if (arr[i - 1] > arr[i]) {
                    std::swap(arr[i - 1], arr[i]);
                    curr_swap = i - 1;
                }
            }
            last_swapped = curr_swap;
        }
    }
};
