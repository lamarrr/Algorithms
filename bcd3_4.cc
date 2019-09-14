
#include <cinttypes>
#include <cstdio>

namespace bcd3_4 {
inline static uint8_t Encode(uint8_t num) noexcept {
  uint8_t t = (num / 10U) & 0b111U;
  uint8_t u = num % 10U;  // definitely not exceeding 4 bits
  return (t << 4U) | u;
};

inline static uint8_t Decode(uint8_t bcd) noexcept { return 0; }
}  // namespace bcd3_4

int main() {
  for (int i = (8 * sizeof(uint8_t)) - 1; i >= 0; i--) {
    printf("%u", (bcd3_4::Encode(10U) >> i) & (0b1U));
  }
}