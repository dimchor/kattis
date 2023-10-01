#include <iostream>
#include <cmath>
#include <list>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>



bool is_prime(unsigned n) {
    if (n == 2) { return true; }

    if (n == 0 or n == 1 or n % 2 == 0) { return false; } 

    unsigned const sqrt_n { static_cast<unsigned>(std::sqrt(n)) + 1 };
    for (unsigned i { 3 }; i <= sqrt_n; i += 2) {
        if (n % i == 0) { return false; }
    }

    return true;
}


int main() {
    std::size_t n{};
    std::cin >> n;

    for (std::size_t i{}; i < n; ++i) {
        unsigned x{};
        std::cin >> x;
        
        std::vector<std::pair<unsigned, unsigned>> v{};

        if (x == 4) {
            v.push_back(std::make_pair(2, 2));
        }

        for (std::size_t i { 3 }; i <= x / 2; i += 2) {
            if (is_prime(i) and is_prime(x - i)) {
                v.push_back(std::make_pair<unsigned, unsigned>(i, x - i));
            }
        }

        std::cout << x << " has " << v.size() << " representation(s)\n";
        for (auto i{0}; i < v.size(); ++i) {
            std::cout << v[i].first << '+' << v[i].second << '\n';
        }
        
    }

    return 0;
}
