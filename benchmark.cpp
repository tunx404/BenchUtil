#include <unistd.h>
#include <chrono>
#include <iostream>

#define NUM_OPS_PER_LOOP 100.0
const unsigned long NUM_OPS = 67108864;

void benchmark_int8() {
    int8_t temp = 1;
    int8_t a = 1, b = 1;
    for (unsigned long i = 0; i < NUM_OPS; i++) {
        temp *= a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b;
    }
}

void benchmark_int32() {
    int32_t temp = 1;
    int32_t a = 1, b = 1;
    for (unsigned long i = 0; i < NUM_OPS; i++) {
        temp *= a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b;
    }
}

void benchmark_int64() {
    int64_t temp = 1;
    int64_t a = 1, b = 1;
    for (unsigned long i = 0; i < NUM_OPS; i++) {
        temp *= a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b;
    }
}

void benchmark_float32() {
    float temp = 1.0f;
    float a = 1.0f, b = 1.0f;
    for (unsigned long i = 0; i < NUM_OPS; i++) {
        temp *= a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b;
    }
}

void benchmark_float64() {
    double temp = 1.0f;
    double a = 1.0f, b = 1.0f;
    for (unsigned long i = 0; i < NUM_OPS; i++) {
        temp *= a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b*a*b;
    }
}

float benchmark(void (* function)()) {
	auto start = std::chrono::high_resolution_clock::now();
	function();
	auto stop = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    std::cout << duration.count() << " ns \t";
    return NUM_OPS_PER_LOOP*(float)NUM_OPS/duration.count();
}

int main() {
    std::cout << "Number of ops: " << NUM_OPS*NUM_OPS_PER_LOOP << std::endl;

    std::cout << "int8:   \t" << benchmark(&benchmark_int8)    << " G" << std::endl;
    std::cout << "int32:  \t" << benchmark(&benchmark_int32)   << " G" << std::endl;
    std::cout << "int64:  \t" << benchmark(&benchmark_int64)   << " G" << std::endl;
    std::cout << "float32:\t" << benchmark(&benchmark_float32) << " G" << std::endl;
    std::cout << "float64:\t" << benchmark(&benchmark_float64) << " G" << std::endl;

	return 0;
}
