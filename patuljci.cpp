#include <iostream>
#include <unordered_set>
#include <vector>
#include <numeric>

template<typename T>
std::vector<std::vector<T>> find_combinations(
    typename std::vector<T>::const_iterator first, 
    typename std::vector<T>::const_iterator const last, 
    std::vector<T> const set = std::vector<T>{})
{
    if (first == last) {
        return {};
    }

    std::vector<T> new_set { set };
    new_set.push_back(*first++);

    std::vector<std::vector<T>> v { set, new_set };
    std::vector<std::vector<T>> a { 
        find_combinations(first, last, set) 
    };
    std::vector<std::vector<T>> b { 
        find_combinations(first, last, new_set) 
    };
    v.reserve(a.size() + b.size());
    std::move(a.begin(), a.end(), std::back_inserter(v));
    std::move(b.begin(), b.end(), std::back_inserter(v));

    return v;
}  

int main() {
    std::vector<unsigned> hat_numbers{};
    hat_numbers.reserve(9);

    {
        unsigned n{};
        for (uint8_t i{}; i < 9; ++i) {
            std::cin >> n;
            hat_numbers.push_back(n);
        }
    }

    auto v { find_combinations<unsigned>(hat_numbers.begin(), 
        hat_numbers.end()) };

    for (auto const& set: v) {
        if (set.size() == 7 and 
            std::accumulate(set.begin(), set.end(), 0) == 100) 
        {
            for (unsigned n: set) {
                std::cout << n << '\n';
            }
            break;
            //std::cout << '\n';
        }
        
    }

    return 0;
}
