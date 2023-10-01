#include <iostream>
#include <vector>
#include <cmath>

template<typename T>
std::vector<T> factorize(T n) {
    std::vector<T> v{};
    while (n % 2 == 0) {
        v.push_back(2);
        n /= 2;
    }
    T const sqrt_n { static_cast<T>(std::sqrt(n)) + 1 };
    for (T index { 3 }; index <= sqrt_n; index += 2) {
        while (n % index == 0) {
            v.push_back(index);
            n /= index;
        }
    }
    if (n > 1) {
        v.push_back(n);
    }
    return v;
}

template<typename Iterator>
constexpr bool is_homogeneous(Iterator first, Iterator last) {
    if (std::distance(first, last) == 0) {
        return false;
    }

    Iterator prev { first++ };
    while (first != last) {
        if (*prev != *first) {
            return false;
        }
        ++prev;
        ++first;
    }
    return true;
}

int main() {
    unsigned long long q{};
    std::cin >> q;

    auto factors { factorize(q) };
    if (factors.empty() or not is_homogeneous(factors.begin(), factors.end())) {
        std::cout << "no\n";
    } else {
        std::cout << "yes\n";
    }

    return 0;
}
