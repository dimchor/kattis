#include <iostream>
#include <algorithm>

int main() {
    unsigned long long n{}, k{};
    std::cin >> n >> k;

    std::cout << std::min(n - 1, k + 1 + (n - 1) % k) << '\n';

    return 0;
}
