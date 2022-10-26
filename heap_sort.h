#include <vector>
#include <utility>

// max heap
template <typename T>
struct heap_sort {
    void operator()(std::vector<T>& arr) {
        buildHeap(arr);
        for (size_t i = arr.size() - 1; i > 0; i--) {
            std::swap(arr[0], arr[i]);
            downHeap(0, arr, i);
        }
    }
private:
    static void downHeap(size_t i, std::vector<T>& arr, size_t sz) {
        size_t left = 2 * i + 1;  // ((i + 1) * 2) - 1
        size_t right = left + 1;
        bool hasLeft = left < sz;
        bool hasRight = right < sz;
        bool leftBad = hasLeft ? (arr[i] < arr[left]) : false;
        bool rightBad = hasRight ? (arr[i] < arr[right]) : false;
        if (leftBad && rightBad) {
            if (arr[left] > arr[right]) {
                std::swap(arr[i], arr[left]);
                downHeap(left, arr, sz);
            } else {
                std::swap(arr[i], arr[right]);
                downHeap(right, arr, sz);
            }
        } else if (leftBad) {
            std::swap(arr[i], arr[left]);
            downHeap(left, arr, sz);
        } else if (rightBad) {
            std::swap(arr[i], arr[right]);
            downHeap(right, arr, sz);
        }
    }

    static void buildHeap(std::vector<T>& arr) {
        for (int i = arr.size() / 2; i < arr.size(); i--) {
            downHeap(i, arr, arr.size());
        }
    }
};
