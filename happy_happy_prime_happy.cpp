#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using ull = unsigned long long;

template<typename T>
bool contains(std::set<T> s, T t) {
    return s.count(t) > 0;
}

std::vector<uint8_t> split_into_digits(ull n, ull b) {
	std::vector<uint8_t> digits{};
	while (n > 0) {
		digits.push_back(n % b);
		n /= b;
	}
	return digits;
} 

ull pdif(ull n, ull p, ull b) {
	ull sum{};
	std::vector<uint8_t> digits = split_into_digits(n, b);
	std::for_each(digits.begin(), digits.end(), [&sum, p] (uint8_t const& d) {
		sum += std::pow(d, p);
	});
	return sum;
}

bool is_happy(ull n, ull b = 10) {
	std::set<ull> checked_numbers{};
	while (n > 1 && !contains(checked_numbers, n)) {
		checked_numbers.insert(n);
		n = pdif(n, 2, b);
	}
	return n == 1;
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
    uint16_t p{};
    std::cin >> p;
    for (uint16_t i{}; i < p; ++i) {
        uint16_t k{}, m{};
        std::cin >> k >> m;
        std::cout << k << ' ' << m << ' ' << 
            (m != 1 and is_prime(m) and is_happy(m) ? "YES" : "NO") << '\n';
    }

    return 0;
}
