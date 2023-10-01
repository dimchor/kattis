#include <iostream>
#include <string> 
#include <string_view>
#include <algorithm>

unsigned calculate_lectures(std::string_view lectures) {
    uint8_t coffees{};
    return std::count_if(lectures.begin(), lectures.end(), 
        [&coffees] (char const& c) {
            if (c == '1') {
                coffees = 2;
                return true;
            } else {
                if (coffees > 0) {
                    --coffees;
                    return true;
                }
            }
            return false;
        }
    );
}

int main(int argc, char** argv) {
    uint32_t lectures{};
    std::string input{};
    std::cin >> lectures >> input;
    std::cout << calculate_lectures(input);
    return 0;
}
