#include <iostream>
#include <cstddef>
#include <iomanip>

int main() {
    unsigned restaurants{};
    //std::cin >> restaurants;
    {
        std::string restaurants_str{};
        std::getline(std::cin, restaurants_str);
        restaurants = std::stoi(restaurants_str);
    }
    for (unsigned i = 0; i < restaurants; ++i) {
        //std::cout << "Restaurant: " << i << '\n';
        unsigned items{};
        std::string name{};
        //std::cin >> items >> name;
        {
            std::string items_str{};
            std::getline(std::cin, items_str);
            items = std::stoi(items_str);
            std::getline(std::cin, name);
        }
        
        std::byte favourite_dishes{ 0b0 };
        std::string item{};
        for (unsigned j = 0; j < items; ++j) {
            //std::cin >> item;
            //std::getline(std::cin, item);
            std::getline(std::cin, item);
            //std::cout << "Item: " << std::quoted(item) << '\n';
            if (item == "pea soup") {
                favourite_dishes |= std::byte{ 0b1 };
            }
            if (item == "pancakes") {
                favourite_dishes |= std::byte{ 0b10 };
            }
        }
        if (favourite_dishes == std::byte{ 0b11 }) {
            std::cout << name << '\n';
            return 0;
        }
    }
    std::cout << "Anywhere is fine I guess\n";
    return 0;
}
