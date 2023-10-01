#include <iostream>

int main() {
    unsigned r{}, b{};
    std::cin >> r >> b;

    unsigned const n { r + b };

    for (unsigned i { 1 }; i * i <= n; ++i) {
        if (n % i == 0 and 2 * n / i + 2 * i - 4 == r) {
            std::cout << n / i << ' ' << i << '\n';
            break;
        }
    }

    return 0;
}
