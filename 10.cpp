#include <bitset>
#include <iostream>
#include <string>

auto gray_encode(unsigned int const num) -> unsigned int {
  return num ^ (num >> 1);
}

auto gray_decode(unsigned int gray) -> unsigned int {
  for (unsigned int bit = 1U << 31; bit > 1; bit >>= 1) {
    if ((gray & bit) != 0U) {
      gray ^= bit >> 1;
    }
  }
  return gray;
}

auto to_binary(unsigned int const value, int const digits) -> std::string {
  return std::bitset<32>(value).to_string().substr(32 - digits, digits);
}

auto main(int /*argc*/, const char* /*argv*/[]) -> int {
  std::cout << "Number\tBinary\tGray\tDecoded" << std::endl;
  std::cout << "------\t------\t----\t-------" << std::endl;

  for (unsigned int n = 0; n < 32; ++n) {
    auto encg = gray_encode(n);
    auto decg = gray_decode(encg);

    std::cout << n << "\t" << to_binary(n, 5) << "\t" << to_binary(encg, 5)
              << "\t" << decg << std::endl;
  }
}
