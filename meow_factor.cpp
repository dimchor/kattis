#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

typedef unsigned long long ull;

std::map<ull, ull> pf(ull n) {
    std::map<ull, ull> pfm;
    for (ull i = 2; i <= std::pow(n, 1.0 / 9) + 1; i++) {
        if (n % i == 0) {
            ull e = 0;
            while (n % i == 0) { e++; n /= i; }
            pfm[i]=e;
        }
    }
    if (n>1) pfm[n]=1;
    return pfm;
}


int main() {
    ull n{};
    std::cin >> n;

    auto factors_and_powers { pf(n) };
    
    ull r { 1 };

    for (auto const& [p, e]: factors_and_powers) {
        r *= std::pow(p, e / 9);
    }

    std::cout << r << '\n';

    return 0;
}

