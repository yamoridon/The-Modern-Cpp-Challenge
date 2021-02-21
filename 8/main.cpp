#include <iostream>

auto main(int /*argc*/, const char* /*argv*/[]) -> int {
  // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
  for (auto a = 1; a <= 9; a++) {
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    for (auto b = 0; b <= 9; b++) {
      // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
      for (auto c = 0; c <= 9; c++) {
        // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
        auto abc = a * 100 + b * 10 + c;
        auto arm = a * a * a + b * b * b + c * c * c;
        if (abc == arm) {
          std::cout << arm << std::endl;
        }
      }
    }
  }
}
