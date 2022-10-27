#pragma once

#include <utility>
#include <vector>

template <typename T>
struct insertion_sort {
    void operator()(std::vector<T>& arr) {
        for (size_t i = 1; i < arr.size(); i++) {
            size_t j = i;
            while (j > 0 && arr[j - 1] > arr[j]) {
                std::swap(arr[j - 1], arr[j]);
                j--;
            }
        }
    }
};
