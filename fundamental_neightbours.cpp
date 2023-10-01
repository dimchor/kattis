#include <iostream>
#include <unordered_map>
#include <cmath>

std::unordered_map<unsigned, unsigned> factorize(unsigned n) {
    std::unordered_map<unsigned, unsigned> m{};
    while (n % 2 == 0) {
        ++m[2];
        n /= 2;
    }
    unsigned const sqrt_n { static_cast<unsigned>(std::sqrt(n)) + 1 };
    for (unsigned index { 3 }; index <= sqrt_n; index += 2) {
        while (n % index == 0) {
            ++m[index];
            n /= index;
        }
    }
    if (n > 1) {
        ++m[n];
    }
    return m;
}

int main() {
    unsigned n{};
    while (std::cin >> n) {
        auto m { factorize(n) };

        unsigned prod { 1 };
        for (auto const& [f, e]: m) {
            prod *= std::pow(e, f);
        }

        std::cout << n << ' ' << prod << '\n';
    }
    
    return 0;
}
