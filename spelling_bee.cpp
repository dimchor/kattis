#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>

bool contains_letters(std::string_view word, std::string_view letters) {
    for (char const& c: word) {
        if (std::find(letters.begin(), letters.end(), c) == letters.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string letters{};
    std::size_t dictionary_size{};
    std::cin >> letters >> dictionary_size;
    std::vector<std::string> dictionary{};
    dictionary.reserve(dictionary_size); // important!!!
    {
        std::string word{};
        for (std::size_t i{}; i < dictionary_size; ++i) {
            std::cin >> word;
            dictionary.emplace_back(std::move(word));
        }
    }
    
    for (auto const& word: dictionary) {
        if (contains_letters(word, letters) and word.size() >= 4 and 
            (std::find(word.begin(), word.end(), letters[0]) != word.end())) 
        {
            std::cout << word << '\n';
        }
    }

    return 0;
}
