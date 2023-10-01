#include <iostream>
#include <cmath>

constexpr double find_median(unsigned a, unsigned b, unsigned c) {
    return std::sqrt(
        (2 * std::pow(a, 2) + 2 * std::pow(b, 2) - std::pow(c, 2)) / 4
    );
}

int main() {
    unsigned n{}, a{}, b{}, c{};
    double r{}, l{};
    std::cin >> n;
    for (unsigned i{}; i < n; ++i) {
        std::cin >> a >> b >> c;
        if (a == b) {
            r = c;
        } else {
            /*      C
                    |
               a   *|*   b
                  **|**
                B***-***A
                    M
                    c
            */

            /*
                Find the median first
            */
            double const m { find_median(a, b, c) };
            double cos{};
            if (a < b) {
                cos = (std::pow(static_cast<double>(c) / 2, 2) + std::pow(m, 2) 
                    - std::pow(static_cast<double>(a), 2)) / 
                    (m * static_cast<double>(c));
            } else {
                cos = (std::pow(m, 2) + std::pow(static_cast<double>(c) / 2, 2) 
                    - std::pow(static_cast<double>(b), 2)) /
                    (m * static_cast<double>(c));
            }
            r = c * std::sin(std::acos(cos));
        }
        l += r;
    }
    std::cout << l << '\n';

    return 0;
}
