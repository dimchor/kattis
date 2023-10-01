#include <iostream>
#include <string_view>

unsigned find_water_consumption(std::string_view in) {
    unsigned shot_n{};
    if (in.size() >= 1) {
        unsigned value = (unsigned)in[0] - 48;
        if (not(value >= 1 and value <= 4)) {
            return 0;
        }
        shot_n = value;
    } else {
        return 0;
    }
    if (in.size() == 2 and in[1] == 'L') {
        return ++shot_n;
    }
    return shot_n;
}

int main() {
    unsigned n{}, s{};
    std::cin >> n >> s;
    unsigned water{ s }, refills{};
    std::string in{};
    for (unsigned i = 0; i < n; ++i) {
        std::cin >> in;
        unsigned water_consumption = find_water_consumption(in);
        if (static_cast<int>(water - water_consumption) < 0) {
            ++refills;
            water = s;
        }
        water -= water_consumption;
    }
    std::cout << refills << '\n';
    return 0;
}
