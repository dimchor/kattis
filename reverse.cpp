#include <iostream>
#include <vector>

int main() {
    std::size_t n{};
    std::cin >> n;
    
    std::vector<int> v{};
    v.reserve(n);

    {
        int input{};
        for (std::size_t i{}; i < n; ++i) {
            std::cin  >> input;
            v.push_back(input);
        }
    }

    for (auto it { v.rbegin() }; it != v.rend(); ++it) {
        std::cout << *it << '\n';
    }

    return 0;
}
