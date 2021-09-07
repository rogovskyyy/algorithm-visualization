#include "Insertionsort.hpp";
#include <SFML/Graphics.hpp>;

void Insertionsort::sort(std::vector<int>& arr, int& accesses) {
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        accesses++;
        sf::sleep(sf::milliseconds(10));
        auto const insertion_point = std::upper_bound(arr.begin(), it, *it);
        std::rotate(insertion_point, it, it + 1);
    }
}