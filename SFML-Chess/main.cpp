#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Engine.hpp";

int main(int argc, char** argv)
{
    std::string wWidth      = "1366";
    std::string wHeight     = "768";
    std::string wAlgorithm  = "0";
    std::string wItems      = "512";
    std::string wType       = "0";

    bool start = true;

    for (int i = 0; i < argc; i++) {

        std::string arg = argv[i];

        if(std::string(argv[i]) == "-w") 
        {
            wWidth = argv[i + 1];
        } 
        else if (std::string(argv[i]) == "-h") 
        {
            wHeight = argv[i + 1];
        } 
        else if (std::string(argv[i]) == "-a") 
        {
            wAlgorithm = argv[i + 1];
        } 
        else if (std::string(argv[i]) == "-i") 
        {
            wItems = argv[i + 1];
        } 
        else if (std::string(argv[i]) == "-t") 
        {
            wType = argv[i + 1];
        } 
        else if (std::string(argv[i]) == "-help") 
        {
            start = false;
            std::cout << "\n" << std::endl;
            std::cout << " ------------------ Command list   ------------------ " << std::endl;
            std::cout << "|                                                    |" << std::endl;
            std::cout << "|  -w   Window width (default 1366)                  |" << std::endl;
            std::cout << "|  -h   Window height (default 768)                  |" << std::endl;
            std::cout << "|  -a   Algorithm type (default 0)                   |" << std::endl;
            std::cout << "|                 SELECTION_SORT    = 0              |" << std::endl;
            std::cout << "|                 BUBBLE_SORT       = 1              |" << std::endl;
            std::cout << "|                 INSERTION_SORT    = 2              |" << std::endl;
            std::cout << "|                 MERGE_SORT        = 3              |" << std::endl;
            std::cout << "|                 QUICK_SORT        = 4              |" << std::endl;
            std::cout << "|                 HEAP_SORT         = 5              |" << std::endl;
            std::cout << "|  -i   Number of elements in array   (default 0)    |" << std::endl;
            std::cout << "|  -t   Sorting type (default 0)                     |" << std::endl;
            std::cout << "|                 Ascending         = 0              |" << std::endl;
            std::cout << "|                 Descending        = 1              |" << std::endl;
            std::cout << "|                 Random            = 2              |" << std::endl;
            std::cout << "|  -help   helper                                    |" << std::endl;
            std::cout << "|                                                    |" << std::endl;
            std::cout << " ---------------------------------------------------- " << std::endl;
            std::cout << "\n" << std::endl;
        }
    }

    int lwWidth     = (int) std::stoi(wWidth);
    int lwHeight    = (int) std::stoi(wHeight);
    int lwAlgorithm = (int) std::stoi(wAlgorithm);
    int lwItems     = (int) std::stoi(wItems);
    int lwType      = (int) std::stoi(wType);

    if (start == true) {
        Engine game(lwWidth, lwHeight, lwAlgorithm, lwItems, lwType);
        game.start();
    }

    return 0;
}