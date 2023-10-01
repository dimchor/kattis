#include <iostream>

uint8_t last_factorial_digit(unsigned n) {
    switch (n) {
    case 0:
        return 1;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 6;
    case 4: // 4! = 24
        return 4;
    default:
        return 0;
    }
}

int main() {
    unsigned t{};
    std::cin >> t;

    {
        unsigned n{};
        for (uint8_t i{}; i < t; ++i) {
            std::cin >> n;
            std::cout << +last_factorial_digit(n) << '\n';
        }
    }

    return 0;
}
