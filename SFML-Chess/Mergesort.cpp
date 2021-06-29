#include <vector>
#include <SFML/Graphics.hpp>
#include "Mergesort.hpp";

void Mergesort::sort(std::vector<int>& bar, int& accesses) {
    if (bar.size() <= 1) return;

    int mid = bar.size() / 2;
    std::vector<int> left;
    std::vector<int> right;

    for (size_t j = 0; j < mid; j++)
        left.push_back(bar[j]);
    for (size_t j = 0; j < (bar.size()) - mid; j++)
        right.push_back(bar[mid + j]);

    sort(left, accesses);
    sort(right, accesses);
    mergeSort(left, right, bar, accesses);
}

void Mergesort::mergeSort(std::vector<int>& left, std::vector<int>& right, std::vector<int>& bars, int& accesses)
{
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;

    while (j < nL && k < nR)
    {
        if (left[j] < right[k]) {
            bars[i] = left[j];
            j++;
        }
        else {
            bars[i] = right[k];
            k++;
        }
        i++;

        accesses += 1;
        sf::sleep(sf::milliseconds(10));
    }
    while (j < nL) {
        bars[i] = left[j];
        j++; i++;
        accesses += 1;
        sf::sleep(sf::milliseconds(10));
    }
    while (k < nR) {
        bars[i] = right[k];
        k++; i++;
        accesses += 1;
        sf::sleep(sf::milliseconds(10));
    }
}