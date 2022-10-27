#pragma once

#include <chrono>
#include <cstdio>

struct Profiler {
    Profiler() {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Profiler() {
        auto dt = std::chrono::high_resolution_clock::now() - start;
        using std::chrono::duration_cast;
        using ms = std::chrono::duration<double, std::milli>;
        std::printf("%.6f ms\n", duration_cast<ms>(dt).count());
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
};
