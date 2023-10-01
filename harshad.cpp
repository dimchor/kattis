#include <iostream>
#include <vector>
#include <numeric>

std::vector<uint8_t> split_into_digits(unsigned n, unsigned b) {
	std::vector<uint8_t> digits{};
	while (n > 0) {
		digits.push_back(n % b);
		n /= b;
	}
	return digits;
} 

bool is_harshad(unsigned n) {
	std::vector<uint8_t> digits { split_into_digits(n, 10) };
	return n % std::accumulate(digits.begin(), digits.end(), 0) == 0; 
}

int main() {
    unsigned n{};
    std::cin >> n;

    while (not is_harshad(n)) { ++n; };

    std::cout << n << '\n';

    return 0;
}
