#include <iostream>
#include <vector>

unsigned gcd(unsigned a, unsigned b) {
	while (a != 0 && b != 0) {
		if (a > b) {
			a %= b;
		} else if (b > a) {
			b %= a; 
		} else {
			return a;
		}
	}

	if (a) {
		return a;
	}
	return b;
}

int main() {
    uint16_t n{};
    std::cin >> n;
    std::vector<uint16_t> circles{};
    circles.reserve(n);
    {
        uint16_t r{};
        for (uint16_t i{}; i < n; ++i) {
            std::cin >> r;
            circles.push_back(r);
        }
    }

    uint16_t const& first_circle { circles.front() };
    for (auto it { std::next(circles.begin()) }; it != circles.end(); ++it) {
        if (first_circle % *it == 0) {
            std::cout << first_circle / *it << "/1\n";
        } else {
            unsigned const d { gcd(first_circle, *it) };
            std::cout << first_circle / d << '/' << *it / d << '\n';
        }
    }

    return 0;
}
