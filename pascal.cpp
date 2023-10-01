#include <iostream>
#include <cmath>

using ull = unsigned long long;

ull pascal(ull n) {
    ull c{};
    for (ull i { n - 1 }; i >= 1; --i) {
        ++c;
        if (n % i == 0) {
            break;
        }
    }
    return c;    
}

ull pascal_optimized(ull n) {
    //ull const sqrt_n { static_cast<ull>(sqrt(n)) + 1ull };
    //ull n_copy { n };
    for (ull i { 2ull }; i <= std::sqrt(n); i++) {
        if (n % i == 0) {
            //ull e { 0ull };
            //while (n % i == 0) { n /= i; }
            return n - (n / i);
        }
    }
    return n - 1;
}

int main() {
    /*
    for (ull i { 1 }; i <= 1000000000; ++i) {
        ull const pascal_res { pascal(i) };
        ull const pascal_opt_res { pascal_optimized(i) };
        if (pascal_res != pascal_opt_res) {
            std::cout << i << ": pascal: " << pascal_res << ", pascal opt.: " << pascal_opt_res << '\n';
            break;
        }
    } 
    */
   
    ull n{};
    std::cin >> n;
    std::cout << pascal_optimized(n) << '\n';
    
    return 0;
}
