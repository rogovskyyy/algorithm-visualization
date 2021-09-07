#include "Bubblesort.hpp";
#include "SFML/Graphics.hpp"

void Bubblesort::sort(std::vector<int>& arr, int& accesses) 
{
    bool swapp = true;
    while (swapp) 
    {
        swapp = false;
        for (size_t i = 0; i < arr.size() - 1; i++) 
        {
            if (arr[i] > arr[i + 1]) 
            {
                sf::sleep(sf::milliseconds(10));
                accesses++;
                arr[i] += arr[i + 1];
                arr[i + 1] = arr[i] - arr[i + 1];
                arr[i] -= arr[i + 1];
                swapp = true;
            }
        }
    }
}