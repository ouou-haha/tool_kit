#ifndef BF16_TOOLKIT_H
#define BF16_TOOLKIT_H

#include <cstdint>
#include <vector>
#include <iostream>

float bf16_to_float(uint16_t bf16_value);
void print_uint8_bf16(const std::vector<uint8_t>& data, size_t len = 0);

#endif // BF16_TOOLKIT_HPP
