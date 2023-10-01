#include <iostream> 
#include <map>
#include <cmath>

using ull = unsigned long long;

std::map<ull, ull> pf(ull n) {
    std::map<ull, ull> pfm{};
    for (ull i { 2 }; i <= std::sqrt(n); ++i) {
        if (n % i == 0) {
            ull e {};
            while (n % i == 0) { ++e; n /= i; }
            pfm[i] = e;
        }
    }
    if (n > 1) { pfm[n] = 1; }
    return pfm;
}

constexpr bool is_prime(ull const n) {
    if (n == 2 or n == 3) {
        return true;
    }
    if (n % 2 == 0 or n % 3 == 0) {
        return false;
    }
    for (ull i { 5ull }; i * i <= n; i += 6) {
        if (n % i == 0 or n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
} 

int main() {
    ull n{};
    while (std::cin >> n) {
        if (n == 4) {
            break;
        }

        ull c { 1ull };
        while (not is_prime(n)) {
            ++c;
            std::map<ull, ull> const m { pf(n) };
            n = 0;
            
            for (std::map<ull, ull>::const_iterator it { m.begin() }; 
                it != m.end(); ++it) 
            {
                n += it->first * it->second;
            }
            
        }
        std::cout << n << ' ' << c << '\n';

    }

    return 0;
}
