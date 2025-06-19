#include "data_convert.h"

float bf16_to_float(uint16_t bf16_value) {
    // bf16 的指数和尾数
    uint16_t bf16_sign = (bf16_value >> 15) & 0x1;
    uint16_t bf16_exponent = (bf16_value >> 7) & 0xFF;
    uint16_t bf16_mantissa = bf16_value & 0x7F;

    uint32_t float_sign = static_cast<uint32_t>(bf16_sign) << 31;
    uint32_t float_exponent = static_cast<uint32_t>(bf16_exponent - 127 + 127) << 23;
    uint32_t float_mantissa = static_cast<uint32_t>(bf16_mantissa) << 16;

    uint32_t float_raw = float_sign | float_exponent | float_mantissa;
    return *reinterpret_cast<float*>(&float_raw);
}

void print_uint8_bf16(const std::vector<uint8_t>& data, size_t len) {
    if (len == 0)
        len = data.size();

    if (len % 2 != 0) {
        std::cerr << "Error: Data length must be even for BF16 conversion." << std::endl;
        return;
    }

    for (size_t i = 0; i < len; i += 2) {
        uint16_t bf16_value = (static_cast<uint16_t>(data[i + 1]) << 8) | data[i];
        float fp32_value = bf16_to_float(bf16_value);
        std::cout << "BF16 Value: " << bf16_value << " -> FP32 Value: " << fp32_value << std::endl;
    }
}
