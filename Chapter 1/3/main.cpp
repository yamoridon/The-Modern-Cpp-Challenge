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

auto lcm(unsigned int const a, unsigned int const b) -> unsigned int {
    unsigned int h = gcd(a, b);
    return h != 0 ? (a * (b / h)) : 0;
}

auto main(int  /*argc*/, const char *  /*argv*/[]) -> int {
    std::cout << "Input numbers:";
    int a = 0;
    int b = 0;
    std::cin >> a >> b;
    
    std::cout << "lcm(" << a << ", " << b << "):" << lcm(a, b) << std::endl;
    std::cout << "std::lcm(" << a << ", " << b << "):" << std::lcm(a, b) << std::endl;
}
