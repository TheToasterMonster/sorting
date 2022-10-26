#pragma once

#include <utility>
#include <vector>

template <typename T>
struct selection_sort {
    void operator()(std::vector<T>& arr) {
        for (size_t i = arr.size() - 1; i > 0; i--) {
            size_t mxI = 0;
            for (size_t j = 0; j <= i; j++) {
                if (arr[j] > arr[mxI]) {
                    mxI = j;
                }
            }
            std::swap(arr[mxI], arr[i]);
        }
    }
};
