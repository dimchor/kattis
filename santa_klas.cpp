#include <iostream>
#include <cmath>

constexpr double deg_to_rad(double degrees) {
    return degrees * (M_PI / 180);
}

int main() {
    uint16_t height{}, angle{};
    std::cin >> height >> angle;

    if (angle <= 180) {
        std::cout << "safe\n";
    } else {
        double const hypotenuse{ height / std::sin(deg_to_rad(-angle)) };
        std::cout << static_cast<unsigned>(hypotenuse) << '\n';
    } 
    return 0;
}
