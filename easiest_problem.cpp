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

int main() {
    unsigned n{};
    std::cin >> n;
    while (n != 0) {
        {
            auto const digits_n { split_into_digits(n, 10) };
            int const sum_n { std::accumulate(digits_n.begin(), digits_n.end(), 0) };
            
            unsigned m { 11 };
            while (true) {
                auto const digits_p { split_into_digits(m * n, 10) };
                int const sum_p { 
                    std::accumulate(digits_p.begin(), digits_p.end(), 0) 
                };
                if (sum_p == sum_n) {
                    break;
                }
                ++m;
            }

            std::cout << m << '\n';
        }
        std::cin >> n;
    }

    return 0;
}