#include <cmath>
#include <iostream>

auto sum_proper_divisors(int const number) -> int {
  int result = 1;
  int const root = static_cast<int>(std::sqrt(number));
  for (int i = 2; i <= root; i++) {
    if (number % i == 0) {
      result += (i == (number / i)) ? i : (i + number / i);
    }
  }
  return result;
}

auto print_amicables(int const limit) -> void {
  for (int number = 4; number < limit; ++number) {
    if (auto sum1 = sum_proper_divisors(number);
        number < sum1 && sum1 < limit) {
      if (auto sum2 = sum_proper_divisors(sum1);
          sum2 == number && number != sum1) {
        std::cout << number << "," << sum1 << std::endl;
      }
    }
  }
}

auto main(int /*argc*/, const char* /*argv*/[]) -> int {
  int limit = 0;
  std::cout << "Upper limit:";
  std::cin >> limit;

  print_amicables(limit);
}
