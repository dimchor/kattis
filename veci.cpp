#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

int main() {
    std::string str{};
    std::cin >> str;

    // if all the digits of the number are in decreasing order then it's
    // impossible to make a larger number out of them
    if (std::is_sorted(str.rbegin(), str.rend())) { 
        std::cout << "0\n"; 
        return 0;    
    }

    std::string res { str };
    
    {
        char prev { *res.rbegin() };
        auto pivot { std::find_if(std::next(res.rbegin()), res.rend(), 
            [&prev] (char current) {
                if (prev <= current) {
                    prev = current;
                    return false;
                }
                return true;
            }) };

        
        auto right_most_successor { std::find_if(res.rbegin(), res.rend(), 
            [&pivot] (char c) {
                if (c > *pivot) {
                    return true;
                }
                return false;
            }) };

        std::swap(*pivot, *right_most_successor);
        std::reverse(res.rbegin(), pivot);
    }

    
    // alternatively...
    //std::next_permutation(res.begin(), res.end());
    std::cout << res << '\n';

    return 0;
}
