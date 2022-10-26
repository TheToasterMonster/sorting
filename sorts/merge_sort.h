#pragma once

#include <vector>

template <typename T>
struct merge_sort {
    void operator()(std::vector<T>& arr) {
        std::vector<T> tmp;
        tmp.reserve(arr.size());
        m_sort(0, arr.size() - 1, arr, tmp);
    }
private:
    void m_sort(size_t L, size_t R, std::vector<T>& arr, std::vector<T>& tmp) {
        if (R - L > 0) {
            size_t mid = L + (R - L) / 2;
            m_sort(L, mid, arr, tmp);
            m_sort(mid + 1, R, arr, tmp);
            merge(L, mid, R, arr, tmp);
        }
    }

    void merge(size_t left, size_t mid, size_t right, std::vector<T>& arr, std::vector<T>& tmp) {
        size_t L = left;
        size_t R = mid + 1;
        size_t i = left;
        while (L <= mid && R <= right) {
            if (arr[L] <= arr[R]) {
                tmp[i++] = arr[L++];
            } else {
                tmp[i++] = arr[R++];
            }
        }
        if (L > mid) {
            for (size_t j = R; j <= right; j++) {
                tmp[i++] = arr[j];
            }
        } else if (R > mid) {
            for (size_t j = L; j <= mid; j++) {
                tmp[i++] = arr[j];
            }
        }
        for (size_t i = left; i <= right; i++) {
            arr[i] = tmp[i];
        }
    }
};
