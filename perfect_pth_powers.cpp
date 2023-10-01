#include <iostream>
#include <map>
#include <cmath>
#include <numeric>

using ull = unsigned long long;

std::map<ull, ull> pf(ull n) {
    std::map<ull, ull> pfm{};
    for (ull i { 2 }; i <= std::sqrt(n); ++i) {
        if (n % i == 0) {
            ull e{};
            while (n % i == 0) { ++e; n /= i; }
            pfm[i] = e;
        }
    }
    if (n > 1) {
        pfm[n] = 1;
    }
    return pfm;
}

int main() {
    long long n{};
    std::cin >> n;
    while (n != 0) {
        if (n == 1 or n == -1) {
            std::cout << "1\n";
            std::cin >> n;
            continue;
        }


        bool positive { true };
        if (n < 0) {
            n *= -1;
            positive = false;
        }

        auto m { pf(n) };
        
        ull result { m.begin()->second };
        if (m.size() > 1) {
            for (auto it { std::next(m.begin()) }; it != m.end(); ++it) {
                result = std::gcd(result, it->second);
            }
        }

        if (not positive) {
            while (result % 2 == 0) {
                result /= 2;
            }
        }

        std::cout << result << '\n';

        std::cin >> n;
    }

    return 0;
}
