#include <iostream>
#include <utility>
#include <vector>

auto longest_collatz(unsigned long long const limit)
    -> std::pair<unsigned long long, long> {
  long length = 0;
  unsigned long long number = 0;

  std::vector<long> cache(limit + 1, 0);

  for (unsigned long long i = 2; i <= limit; i++) {
    auto n = i;
    long steps = 0;
    while (n != 1 && n >= i) {
      if ((n % 2) == 0) {
        n /= 2;
      } else {
        n = n * 3 + 1;
      }
      steps++;
    }
    cache[i] = steps + cache[n];

    if (cache[i] > length) {
      length = cache[i];
      number = i;
    }
  }

  return std::make_pair(number, length);
}

auto main(int /*argc*/, const char* /*argv*/[]) -> int {
  const unsigned long long limit = 1'000'000;
  auto [number, length] = longest_collatz(limit);
  std::cout << "Longest collatz seqeunce under " << limit << " is " << length
            << " for " << number << "." << std::endl;
}
