#include <iostream>
#include <string>
#include <string_view>
#include <vector>

constexpr unsigned rune_to_value(char rune) {
    return static_cast<unsigned>(rune) - 32;
}

constexpr unsigned rune_to_value(std::string_view rune) {
    unsigned value{};
    for (char const& c: rune) {
        value += rune_to_value(c);
    }
    return value;
}

std::vector<std::string> tokenize(std::string_view rune_script) {
    std::vector<std::string> tokens{};
    std::string token{};
    for (char const& c: rune_script) {
        if (c == ' ') {
            tokens.emplace_back(std::move(token));
            continue;
        }
        token += c;
    }
    tokens.emplace_back(std::move(token));
    return tokens;
}

std::string parse_rune_script(std::string_view rune_script, unsigned offset) {
    std::string translated_text{};
    auto tokens { tokenize(rune_script) };
    for (auto const& token: tokens) {
        if (token == "0") {
            translated_text += ' ';
        } else if (token == "<") {
            translated_text += ',';
        } else if (token == ">") {
            translated_text += '.';
        } else {
            unsigned letter_value { rune_to_value(token) + offset };
            if (letter_value < static_cast<unsigned>('a')) {
                letter_value = static_cast<unsigned>('z') - 
                    (static_cast<unsigned>('a') - letter_value) + 1;
            } else if (letter_value > static_cast<unsigned>('z')) {
                letter_value = static_cast<unsigned>('a') + (letter_value - 
                    static_cast<unsigned>('z')) - 1;
            }
            translated_text += static_cast<char>(letter_value);
        }
    }
    return translated_text;
}

int main() {
    std::string in{};
    std::getline(std::cin, in);
    auto tokens { tokenize(in) };
    std::string sample_rune { tokens[0] };
    char sample_char { tokens[1][0] };

    unsigned const offset { static_cast<unsigned>(sample_char) - 
        rune_to_value(sample_rune) };
    std::string rune_script{};
    while (std::getline(std::cin, rune_script)) {
        std::cout << parse_rune_script(rune_script, offset) << '\n';
    }
    return 0;
}
