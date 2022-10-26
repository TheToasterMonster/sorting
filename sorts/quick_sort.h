#pragma once

#include <chrono>
#include <random>
#include <utility>
#include <vector>

template <typename T>
struct quick_sort {
    void operator()(std::vector<T>& arr) {
        static std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
        qsort(0, arr.size() - 1, arr, rng);
    }
private:
    void qsort(size_t left, size_t right, std::vector<T>& arr, std::mt19937_64& rng) {
        if (left >= right) {
            return;
        }

        size_t pivot = rng() % (right - left + 1) + left;
        std::swap(arr[pivot], arr[left]);
        size_t i = left + 1;
        size_t j = right;
        do {
            while (i <= right && arr[i] < arr[left]) i++;
            while (j < arr.size() && arr[j] > arr[left]) j--;
            if (i < j) {
                std::swap(arr[i], arr[j]);
            }
        } while (i < j);
        std::swap(arr[left], arr[j]);
        qsort(left, (j > 0) ? (j - 1) : 0, arr, rng);
        qsort(j + 1, right, arr, rng);
    }
};
