#include <iostream>
#include <string>
#include <cstring>
#include <string_view>
#include <vector>
#include <algorithm>

// bad idea, but it works
enum class Clue: unsigned {
    greater_than,
    less_than,
    divisible_by
};

constexpr char const* clues_strs[] = {
    "greater than ", 
    "less than ", 
    "divisible by "
};

constexpr unsigned max_n { 50001 };
constexpr unsigned min_n { 0 };

std::pair<Clue, unsigned> determine_clue(std::string_view input) {
    Clue clue{};
    unsigned n{};
    for (std::size_t i{}; i < sizeof(clues_strs) / sizeof(*clues_strs); ++i) {
        std::size_t pos { input.find(clues_strs[i]) };
        if (pos == std::string_view::npos) {
            continue;
        }
        clue = static_cast<Clue>(i);
        n = std::stoul(input.data() + std::strlen(clues_strs[i]));
    }

    return std::make_pair(clue, n);
}

template <typename Iterator>
constexpr bool is_divisible(Iterator first, Iterator last, unsigned n) {
    while (first != last) {
        if (n % *first++ != 0) {
            return false;
        }
    }
    return true;
}

int main() {    
    std::string s{};
    while (std::getline(std::cin, s)) {
        
        unsigned long n { std::stoul(s) };
        if (n == 0) {
            break;
        }

        std::vector<unsigned> less_than_clues{};
        std::vector<unsigned> greater_than_clues{};
        std::vector<unsigned> divisible_by_clues{};
        std::string in{};

        for (unsigned i{}; i < n; ++i) {
            std::getline(std::cin, in);
            auto [clue, m] { determine_clue(in) };
            switch (clue) {
            case Clue::greater_than:
                greater_than_clues.push_back(m);
                break;
            case Clue::less_than:
                less_than_clues.push_back(m);
                break;
            default:
                divisible_by_clues.push_back(m);
                break;
            }
        }

        unsigned less_than { max_n };
        unsigned greater_than { min_n };

        {
            auto min_it { 
                std::min_element(less_than_clues.begin(), less_than_clues.end()) 
            };
            if (min_it != less_than_clues.end() and *min_it < max_n) {
                less_than = *min_it;
            }

            auto max_it {
                std::max_element(greater_than_clues.begin(), 
                    greater_than_clues.end())
            };
            if (max_it != greater_than_clues.end() and *max_it > min_n) {
                greater_than = *max_it;
            }
        }

        if (less_than == max_n) {
            std::cout << "infinite\n";
            continue;
        } else if (greater_than >= less_than) {
            std::cout << "none\n";
            continue;
        }

        bool found_one { false };
        for (unsigned k { greater_than + 1}; k < less_than; ++k) {
            if (is_divisible(divisible_by_clues.begin(), 
                divisible_by_clues.end(), k)) 
            {   
                found_one = true;
                std::cout << k << ' ';
            }
        }
        if (found_one) {
            std::cout << '\n';
        } else {
            std::cout << "none\n";
        }

        /*
        if (greater_than < less_than) {
            bool found { false };
            for (unsigned k { greater_than + 1}; k < less_than; ++k) {
                if (is_divisible(divisible_by_clues.begin(), 
                    divisible_by_clues.end(), k)) 
                {
                    found = true;
                    std::cout << k << ' ';
                }
            }

            if (found) {
                std::cout << '\n';
            } else {
                std::cout << "none\n";
            }

        } else if (greater_than > less_than) {
            std::cout << "infinite\n";
        } else {
            std::cout << "none\n";
        }
        */
    }

    return 0;
}
