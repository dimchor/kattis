#include <iostream>
#include <string>
#include <string_view>
#include <tuple>

std::pair<char, char> char_adder(char a, char b, char c) {
    uint8_t const a_int { static_cast<uint8_t>(a - 48) };
    uint8_t const b_int { static_cast<uint8_t>(b - 48) };
    uint8_t const c_int { static_cast<uint8_t>(c - 48) };
    uint8_t const sum { static_cast<uint8_t>(a_int + b_int + c_int) };
    return std::make_pair(sum <= 9 ? '0' : '1', sum <= 9 ? sum + 48 : sum + 38);
    // 38 = 48 (ASCII conversion) - 10 (keep the last digit)
}

std::string string_adder(std::string_view a, std::string_view b) {
    std::string r{};
    char c { '0' };
    auto it_a { a.rbegin() };
    auto it_b { b.rbegin() };
    {
        char s{};
        while (it_a != a.rend() and it_b != b.rend()) {
            std::tie(c, s) = char_adder(*it_a, *it_b, c);
            r.insert(0, 1, s);
            ++it_a; ++it_b;
        }
    }

    std::string_view::reverse_iterator it_c{};
    std::string_view::reverse_iterator it_c_rend{};
    if (it_a == a.rend() and it_b == b.rend() and c != '0') {
        r.insert(0, 1, c);
        return r;
    } else if (it_a == a.rend()) {
        it_c = it_b;
        it_c_rend = b.rend();
    } else {
        it_c = it_a;
        it_c_rend = a.rend();
    }

    {
        char s{};
        while (it_c != it_c_rend) {
            std::tie(c, s) = char_adder(*it_c, c, '0');
            r.insert(0, 1, s);
            ++it_c;
        }
    }

    if (c != '0') {
        r.insert(0, 1, c);
    }

    return r;
}

int main() {
    std::string a{}, b{};
    std::cin >> a >> b;
    std::cout << string_adder(a, b) << '\n';

    return 0;
}
