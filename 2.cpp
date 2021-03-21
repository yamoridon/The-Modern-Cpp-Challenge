#include <iostream>
#include <numeric>

auto gcd(unsigned int a, unsigned int b) -> unsigned int {
  while (b != 0) {
    unsigned int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

// NOLINTNEXTLINE(misc-no-recursion)
auto recursive_gcd(const unsigned int a, const unsigned int b) -> unsigned int {
  return (b == 0) ? a : recursive_gcd(b, a % b);
}

auto main(int /*argc*/, const char* /*argv*/[]) -> int {
  std::cout << "Input numbers:";
  int a = 0;
  int b = 0;
  std::cin >> a >> b;

  std::cout << "gcd(" << a << ", " << b << "):" << gcd(a, b) << std::endl;
  std::cout << "recursive_gcd(" << a << ", " << b << "):" << recursive_gcd(a, b)
            << std::endl;
  std::cout << "std::gcd(" << a << ", " << b << "):" << std::gcd(a, b)
            << std::endl;
}
