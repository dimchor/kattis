#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Person {
    std::string name{};
    std::string has{};
    std::string wants{};

    friend std::istream& operator>>(std::istream&, Person&);
    friend std::ostream& operator<<(std::ostream&, Person const&);
};

std::istream& operator>>(std::istream& is, Person& person) {
    is >> person.name >> person.has >> person.wants;
    return is;
}

std::ostream& operator<<(std::ostream& os, Person const& person) {
    os << person.name << ' ' << person.has << ' ' << person.wants;
    return os;
}

template<typename Iterator>
Iterator find_person(Iterator first, Iterator last, Iterator person_who_wants) {
    return std::find_if(first, last, 
    [&person_who_wants] (Person const& person_who_has) {
        if (person_who_wants->wants == person_who_has.has) {
            return true;
        }
        return false;
    });
}

template<typename Iterator>
std::size_t do_math_trade(Iterator first, Iterator last) {
    unsigned most_trades{};
    for (Iterator i{ first }; i != last; ++i) {
        Iterator const first_person{ i };
        Iterator j{ i };
        unsigned trades{};
        while ((j = find_person(first, last, j)) != last) {
            ++trades;
            if (j == first_person) {
                if (trades > most_trades) {
                    most_trades = trades;
                }
                break;
                //return trades;
            }
        }
    }
    return most_trades;
}

int main() {
    std::size_t size{};
    std::cin >> size;
    std::vector<Person> people;
    people.reserve(size);
    Person p{};
    for (std::size_t i = 0; i < size; ++i) {
        std::cin >> p;
        people.emplace_back(std::move(p));
    }

    std::size_t trades = do_math_trade(people.begin(), people.end());
    if (trades) {
        std::cout << trades << '\n';
    } else {
        std::cout << "No trades possible\n";
    }
    return 0;
}
