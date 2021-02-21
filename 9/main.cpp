#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>

auto prime_factors(unsigned long long n) -> std::vector<unsigned long long> {
  std::vector<unsigned long long> factors;
  while (n % 2 == 0) {
    factors.push_back(2);
    n = n / 2;
  }

  int const root = static_cast<int>(std::sqrt(n));
  for (unsigned long long i = 3; i <= root; i += 2) {
    while (n % i == 0) {
      factors.push_back(i);
      n = n / i;
    }
  }

  if (n > 2) {
    factors.push_back(n);
  }

  return factors;
}

auto main(int /*argc*/, const char* /*argv*/[]) -> int {
  unsigned long long number = 0;
  std::cout << "number:";
  std::cin >> number;

  auto factors = prime_factors(number);

  std::copy(std::cbegin(factors), std::cend(factors),
            std::ostream_iterator<unsigned long long>(std::cout, " "));
}
