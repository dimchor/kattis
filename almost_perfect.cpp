#include <iostream>
#include <cmath>

enum class Perfectness {
    perfect,
    almost_perfect,
    not_perfect
};

Perfectness is_perfect(unsigned n) {
	unsigned sum { 1 };
    for (unsigned i { 2 }; std::pow(i, 2) <= n; ++i) {
        if (n % i == 0) {
            if (std::pow(i, 2) != n) {
                sum += i + n / i;
            } else {
                sum += i;
            }
        }
    }

    if (sum == n) {
        return Perfectness::perfect;
    } else if (std::abs(static_cast<int>(sum - n)) <= 2) {
        return Perfectness::almost_perfect;
    } else {
        return Perfectness::not_perfect;
    }

}

int main() {
    unsigned n{};
    while (std::cin >> n) {
        switch (is_perfect(n)) {
        case Perfectness::perfect:
            std::cout << n << " perfect\n";
            break;
        case Perfectness::almost_perfect:
            std::cout << n << " almost perfect\n";
            break;
        default:
            std::cout << n << " not perfect\n";
            break;
        }
    }
    return 0;
}
