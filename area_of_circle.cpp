#include <iostream>
#include <cmath>

constexpr double area_of_circle(double radius) {
    return M_PI * std::pow(radius, 2);
}

constexpr double area_of_square(double side) {
    return std::pow(side, 2);
}

constexpr double area_of_circle_approx(
    double radius, uint32_t marked_points, uint32_t circle_points
) {
    // we give the diameter to get the area of the outer square 
    // and then we multiply by the ratio 
    return area_of_square(radius * 2) * circle_points / marked_points;
}

int main() {
    double r{};
    uint32_t m{}, c{};
    std::cin >> r >> m >> c;
    while(r != 0 and m != 0 and c != 0) {
        std::cout << area_of_circle(r) << ' ' << 
            area_of_circle_approx(r, m, c) << '\n';
        std::cin >> r >> m >> c;
    }
    return 0;
}
