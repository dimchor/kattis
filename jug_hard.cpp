#include <iostream>
#include <algorithm>

int main() {
    unsigned t{};
    std::cin >> t;
    {
        unsigned a{}, b{}, d{};
        for (unsigned i{}; i < t; ++i) {
            std::cin >> a >> b >> d;
            // https://en.wikipedia.org/wiki/Diophantine_equation
            if (d % std::__gcd(a, b) == 0 ) {
                std::cout << "Yes\n";
            } else {
                std::cout << "No\n";
            }



        }
    }
    return 0;
}
