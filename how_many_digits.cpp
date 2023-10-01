#include <iostream>
#include <cmath>

int main() {
    unsigned n{};
    while (std::cin >> n) {
        if (n == 0 or n == 1) {
            std::cout << "1\n";
        } else {
            std::cout << static_cast<unsigned>(std::floor(
                (std::log(2 * M_PI * n) / 2 + n * (std::log(n) - 1)) / 
                std::log(10))) + 1 << '\n';
        }
    }

    return 0;
}
