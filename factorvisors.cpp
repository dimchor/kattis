#include <iostream>
#include <map> 
#include <cmath>

std::map<unsigned long long, unsigned long long> factorize(unsigned long long n) {
    std::map<unsigned long long, unsigned long long> m{};
    while (n % 2 == 0) {
        ++m[2];
        n /= 2;
    }
    unsigned long long const sqrt_n { static_cast<unsigned long long>(std::sqrt(n)) };
    for (unsigned long long index { 3 }; index <= sqrt_n; index += 2) {
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


typedef unsigned long long ull;

std::map<ull, ull> pf(ull n) {
    std::map<ull, ull> pfm;
    for (ull i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ull e = 0;
            while (n % i == 0) { e++; n /= i; }
            pfm[i]=e;
        }
    }
    if (n>1) pfm[n]=1;
    return pfm;
}

ull legendre_formula(ull n, ull p) {
    ull tmp = (ull)(n / p);
    ull sum = 0;
    while(tmp != 0) {
        sum += tmp;
        tmp = (ull) tmp / p;
    }
    return sum;
}

int main() {
    unsigned long long n, m;
    while (std::cin >> n >> m) {


        std::map<ull, ull> mm = pf(m);

        bool okay = (m != 0);
        
        /*
        
        for (auto const& [p, e]: map) {
            if (!divides) {
                break;
            }

            if (legendre_formula(n, p) < e) {
                divides = false;
                break;
            }
        } 
        */
        std::map<ull, ull>::iterator it;
        for (it = mm.begin(); okay && it != mm.end(); it++) {
            if (legendre_formula(n, it->first) < it->second) {
                okay = false;
            }
        }


        if (okay) {
            std::cout << m << " divides " << n << "!\n";
        } else {
            std::cout << m << " does not divide " << n << "!\n";
        }

        //std::cout << m << (okay ? " divides " : " does not divide ") << n 
        //    << "!\n";

    }
    return 0;
}

