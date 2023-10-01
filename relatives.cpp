#include <iostream>
#include <map>
#include <cmath>

using ull = unsigned long long;

std::map<ull, ull> pf(ull n) {
    std::map<ull, ull> pfm;
    for (ull i = 2; i <= std::sqrt(n); i++) {
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
    while (true) {
        ull n{};
        std::cin >> n;
        if (n == 0) {
            break;
        }

        auto m { pf(n) };

        ull r { n };
        for (auto const& [p, e]: m) {
            r = (r / p) * (p - 1);
        }

        std::cout << r << '\n';

    }
    return 0;
}
