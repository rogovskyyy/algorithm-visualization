#include "Heapsort.hpp";
#include <SFML/Graphics.hpp>

void Heapsort::max_heapify(std::vector<int>& arr, int i, int size_, int& accesses) {

    int largest, l = (2 * i) + 1, r = l + 1;

    if (l < size_ && arr[l] > arr[i])
        largest = l;
    else
        largest = i;

    accesses += 1;
    sf::sleep(sf::milliseconds(10));

    if (r < size_ && arr[r] > arr[largest])
    {
        largest = r;

        accesses += 1;
        sf::sleep(sf::milliseconds(10));
    }

    if (largest != i)
    {
        accesses += 1;
        sf::sleep(sf::milliseconds(10));

        std::swap(arr[i], arr[largest]);
        max_heapify(arr, largest, size_, accesses);
    }
}

void Heapsort::build_max_heap(std::vector<int>& arr, int& accesses) {
    for (int i = (arr.size() / 2); i >= 0; i--)
    {
        accesses += 1;
        sf::sleep(sf::milliseconds(10));

        max_heapify(arr, i, arr.size(), accesses);
    }
}

void Heapsort::sort(std::vector<int>& arr, int& accesses) {
    build_max_heap(arr, accesses);
    int sz = arr.size();
    for (int i = arr.size() - 1; i > 0; i--)
    {
        accesses += 1;
        sf::sleep(sf::milliseconds(10));

        std::swap(arr[0], arr[i]);
        sz--;
        max_heapify(arr, 0, sz, accesses);
    }
}