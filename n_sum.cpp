#include <iostream>

int main() {
    unsigned size{};
    std::cin >> size;

    unsigned sum{};
    {
        uint16_t in{};
        for (unsigned i{}; i < size; ++i) {
            std::cin >> in;
            sum += in;
        }
    }

    std::cout << sum;

    return 0;
}
