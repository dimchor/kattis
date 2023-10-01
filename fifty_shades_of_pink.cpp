#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    uint16_t n{};
    std::cin >> n;
    uint16_t pink_buttons{};
    {
        std::string label{};
        for (uint16_t i{}; i < n; ++i) {
            std::cin >> label;
            std::transform(label.begin(), label.end(), label.begin(), 
                [] (char c) { return std::tolower(c); });
            if (label.find("pink") != std::string::npos or 
                label.find("rose") != std::string::npos) {
                ++pink_buttons;
            }
        }
    }
    if (not pink_buttons) {
        std::cout << "I must watch Star Wars with my daughter\n";
    } else {
        std::cout << pink_buttons << '\n';
    }
    return 0;
}
