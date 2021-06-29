#include <vector>

#include <SFML/Graphics.hpp>

#include "Engine.hpp";

int main(int argc, char* argv[])
{
    Engine game(1366, 768);
    game.start();
    return 0;
}