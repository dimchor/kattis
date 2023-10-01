#include <iostream>

using ull = unsigned long long;

int main() {
    /*

    N = a + (a + 1) + (a + 2) + ... + (a + k)
    N = (k + 1) * a + (1 + 2 + ... + k)
    N = (k + 1) * a + k(k + 1) / 2 

    N - (k*(k + 1) / 2) = (k + 1) * a
    (N - (k*(k+1) / 2))/(k + 1) = a

    */

    /*
    unsigned n{};
    std::cin >> n;

    unsigned k { 1 };
    unsigned sum { k * (k + 1) / 2 };
    bool found { false };
    while (not found) {
        unsigned const a { (n - sum) / (k + 1) };
        if ((n - sum) % (k + 1) == 0) {
            found = true;
            std::cout << n << " = " << a;
            for (unsigned i { 1 }; i <= k; ++i) {
                std::cout << " + " << a + i;
            }
            std::cout << '\n';
        } else {
            ++k;
            sum = k * (k + 1) / 2;
            found = (sum <= n);
        }
    }
    if (not found) {
        std::cout << "IMPOSSIBLE\n";
    }
    */
    
    uint16_t t{};
    std::cin >> t;
    for (uint16_t i{}; i < t; ++i) {
        ull n{};
        std::cin >> n;
        ull k { 1 };
        ull sum { k * (k + 1) / 2 };
        bool found { false };
        while (not found and n > sum) {
            if ((n - sum) % (k + 1) == 0) {
                found = true;
                ull const a { (n - sum) / (k + 1) };
                std::cout << n << " = " << a;
                for (ull i { 1 }; i <= k; ++i) {
                    std::cout << " + " << a + i;
                }
                std::cout << '\n';
            }
            ++k;
            sum = k * (k + 1) / 2;
        }

        if (not found) {
            std::cout << "IMPOSSIBLE\n";
        }
    }
    
    return 0;
}
