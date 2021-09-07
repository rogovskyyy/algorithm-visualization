#include "Selectionsort.hpp";
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

void Selectionsort::sort(std::vector<int>& arr, int& accesses)
{
    int vecsize = arr.size();
    for (int j = 0; j < vecsize - 1; ++j) 
    {
        int min = j;
        for (int i = j + 1; i < vecsize; ++i) 
        {
            if (arr.at(min) > arr.at(i)) 
            {
                min = i;
                accesses++;
                sf::sleep(sf::milliseconds(10));
            }

        }
        if (min != j)
        {
            std::swap(arr.at(j), arr.at(min));
        }
    }
}