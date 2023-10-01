#include <iostream>
#include <array>
#include <algorithm>
#include <optional>

struct Vector2 {
    uint8_t x{}, y {};

    friend std::ostream& operator<<(std::ostream&, Vector2 const&);
};

std::ostream& operator<<(std::ostream& os, Vector2 const& vector) {
    os << "[ " << +vector.x << ", " << +vector.y << " ]";
    return os;
}

struct House {
    static uint8_t const max_size = 20;
    static uint8_t const min_size = 5; 

    std::array<std::array<char, max_size>, max_size> arr{};
    uint8_t width{}, length{};

    friend std::ostream& operator<<(std::ostream&, House const&);
    Vector2 find_asterisk() const;
};

Vector2 House::find_asterisk() const {
    for (uint8_t i = 0; i < length; ++i) {
        for (uint8_t j = 0; j < width; ++j) {
            if (arr[i][j] == '*') {
                return { j, i };
            }
        }
    }
    return {};
}

std::ostream& operator<<(std::ostream& os, House const& house) {
    for (uint8_t i = 0; i < house.length; ++i) {
        for (uint8_t j = 0; j < house.width; ++j) {
            os << house.arr[i][j];
        }
        os << '\n';
    }
    return os;
}

std::optional<House> read_data() {
    unsigned width{}, length{};
    std::cin >> width >> length;
    if (
        width > House::max_size or width < House::min_size or 
        length > House::max_size or length < House::min_size
    ) {
        return {};
    }

    House house{};
    house.width = width;
    house.length = length;
    std::string line{};
    for (uint8_t i = 0; i < length; ++i) {
        std::cin >> line;
        if (line.size() > House::max_size) {
            return {};
        }
        std::copy(line.begin(), line.end(), house.arr[i].begin());
    }
    return house;
}

enum class Direction: char {
    up, down, left, right
};

struct Player {
    Direction direction{};
    Vector2 position{};
    House const& house;

    Player() = default;
    Player(House const&);

    void move();
    bool step();
};

Player::Player(House const& house): 
    position(house.find_asterisk()), house(house) 
{
    if (position.x == 0) {
        direction = Direction::right;
    } else if (position.x == house.length - 1) {
        direction = Direction::left;
    }

    if (position.y == 0) {
        direction = Direction::down;
    } else if (position.y == house.width - 1) {
        direction = Direction::up;
    }
}

void Player::move() {
    switch (direction) {
    case Direction::up:
        position.y--;
        break;
    case Direction::down:
        position.y++;
        break;
    case Direction::right:
        position.x++;
        break;
    case Direction::left:
        position.x--;
        break;
    default:
        break;
    }
}

// returns true if a step is made and false if a step cannot be made (exit is 
// found)
bool Player::step() {
    //std::cout << position << ' ' << house.arr[position.y][position.x] << '\n';
    if (house.arr[position.y][position.x] == 'x') {
        return false;
    }

    switch (direction) {
    case Direction::up:
        if (house.arr[position.y][position.x] == '\\') {
            direction = Direction::left;
        } else if (house.arr[position.y][position.x] == '/') {
            direction = Direction::right;
        }
        break;
    case Direction::down:
        if (house.arr[position.y][position.x] == '\\') {
            direction = Direction::right;
        } else if (house.arr[position.y][position.x] == '/') {
            direction = Direction::left;
        }
        break;
    case Direction::right:
        if (house.arr[position.y][position.x] == '\\') {
            direction = Direction::down;
        } else if (house.arr[position.y][position.x] == '/') {
            direction = Direction::up;
        }
        break;
    case Direction::left:
        if (house.arr[position.y][position.x] == '\\') {
            direction = Direction::up;
        } else if (house.arr[position.y][position.x] == '/') {
            direction = Direction::down;
        }
        break;
    default:
        break;
    }
    move();
    return true;
}

int main() {
    //House house = *read_data();
    uint8_t test_counter{ 1 };
    while (true) {
        auto opt = read_data();
        if (not opt.has_value()) {
            return 0;
        }
        std::cout << "HOUSE " << +(test_counter++) << '\n';
        House house = *opt;
        Player player { house };
        while(player.step());
        house.arr[player.position.y][player.position.x] = '&';
        std::cout << house;
    }
    return 0;
}
