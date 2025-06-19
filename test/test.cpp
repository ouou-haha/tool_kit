#include "data_convert.h"
#include <cassert>
#include <iostream>

void test_bf16_to_float() {

    uint16_t bf16_value = 0x3F80; // bf16 表示的 1.0
    float result = bf16_to_float(bf16_value);
    assert(result == 1.0f); 

    std::cout << "Test passed: bf16_to_float works correctly!" << std::endl;
}

void test_print_uint8_bf16() {
    std::vector<uint8_t> data = {0x80, 0x3F, 0x00, 0x40, 0x00, 0x41}; // BF16 值 1.0, 2.0, 3.0

    std::cout << "Testing with default len (0):" << std::endl;
    print_uint8_bf16(data);

    std::cout << "\nTesting with len = 4:" << std::endl;
    print_uint8_bf16(data, 4);

    std::cout << "\nTesting with len = 3 (invalid):" << std::endl;
    print_uint8_bf16(data, 3);

    std::cout << "\nTesting with len = 8 (exceeds data size):" << std::endl;
    print_uint8_bf16(data, 8);
}

int main() {
    test_print_uint8_bf16();
    return 0;
}