#include <iostream>
#include <cmath>

using ull = unsigned long long;

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

/*

    a^p ≡ a (mod p)

    a^p mod p = a mod p

*/

ull big_modulo(ull a, ull n, ull p) {
    if (n == 0) { return 1; }
    if (n == 1) { return a % p; }
    if (n % 2 == 0) {
        ull bm = big_modulo(a, n / 2ull, p);
        return (bm * bm) % p;
    } else {
        return ((a % p) * big_modulo(a, n - 1ull, p)) % p;
    }
}

int main() {
    ull p{}, a{};
    while(std::cin >> p >> a) {
        if (p == 0 and a == 0) {
            break;
        }

        if (not is_prime(p) and big_modulo(a, p, p) == a % p) {
            std::cout << "yes\n";
        } else {
            std::cout << "no\n";
        }
        
    }
    return 0;
}
