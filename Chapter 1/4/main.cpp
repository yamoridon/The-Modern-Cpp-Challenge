#include <iostream>

auto is_prime(int const num) -> bool {
    if (num <= 3) {
        return num > 1;
    } if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

auto main() -> int {
    int limit = 0;
    std::cout << "Upper limit:";
    std::cin >> limit;

    for (int i = limit; i > 1; i--) {
        if (is_prime(i)) {
            std::cout << "Largest prime:" << i << std::endl;
            return 0;
        }
    }
}
