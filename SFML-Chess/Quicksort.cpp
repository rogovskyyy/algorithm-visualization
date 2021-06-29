#include "Quicksort.hpp";
#include <iostream>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>

int Quicksort::partition(std::vector<int>& values, int left, int right) 
{
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = values[pivotIndex];
    int i = left, j = right;
    int temp;
    while (i <= j) {
        while (values[i] < pivotValue) 
        {
            i++;
        }
        while (values[j] > pivotValue) 
        {
            j--;
        }
        if (i <= j) 
        {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            i++;
            j--;
        }
    }

    return i;
}

void Quicksort::quicksort(std::vector<int>& values, int left, int right, int& accesses)
{
    accesses += 1;
    sf::sleep(sf::milliseconds(10));

    //for (int i = 0; i < values.size(); ++i)
    //    std::cout << values[i] << ' ';

    if (left < right) 
    {
        int pivotIndex = Quicksort::partition(values, left, right);
        Quicksort::quicksort(values, left, pivotIndex - 1, accesses);
        Quicksort::quicksort(values, pivotIndex, right, accesses);
    }
}