#include <future>
#include <iostream>
#include <random>
#include <stdio.h>
#include <string.h>
#include <SFML/Graphics.hpp>
#include "Engine.hpp";
#include "Bubblesort.hpp";
#include "Heapsort.hpp";
#include "Insertionsort.hpp";
#include "Mergesort.hpp";
#include "Quicksort.hpp";
#include "Selectionsort.hpp";

using namespace std;

Engine::Engine(int width, int height, int algorithm, int items, int inputType)
{
    this->w = width;
    this->h = height;
    this->a = algorithm;
    this->i = items;
    this->t = inputType;
}

void Engine::start()
{
    sf::RenderWindow window(sf::VideoMode(this->w, this->h),
        "Algorithm sorting visualization by BR",
        sf::Style::Default);

    if (this->t == 0) {
        for (int j = 0; j < this->i; j++) {
            this->arr.push_back(j + 1);
        }
    }
    else if (this->t == 1) {
        for (int j = this->i; j > 0; j--) {
            this->arr.push_back(j + 1);
        }
    }
    else if (this->t == 2) {
        for (int j = 0; j < this->i; j++) {
            this->arr.push_back(j + 1);
        }
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(this->arr.begin(), this->arr.end(), g);
    }

    float width = (float)this->w / (float)this->arr.size();
    float height = (float)this->h / (float)this->arr.size();

    int accesses = 0;

    char buffer[128];
    sprintf_s(buffer, "%d x %d", this->w, this->h);

    std::string buffer2;
    switch (this->a) {
    case 0:
        buffer2 = "SELECTION_SORT";
        break;
    case 1:
        buffer2 = "BUBBLE_SORT";
        break;
    case 2:
        buffer2 = "INSERTION_SORT";
        break;
    case 3:
        buffer2 = "MERGE_SORT";
        break;
    case 4:
        buffer2 = "QUICK_SORT";
        break;
    case 5:
        buffer2 = "HEAP_SORT";
        break;
    }

    char buffer3[128];
    switch (this->t) {
    case 0:
        strcpy_s(buffer3, "Ascending");
        break;
    case 1:
        strcpy_s(buffer3, "Descending");
        break;
    case 2:
        strcpy_s(buffer3, "Random");
        break;
    }

    char buffer4[128];
    sprintf_s(buffer4, "%d items @ %s", this->i, buffer3);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
    }

    sf::Text text;
    text.setFont(font);
    text.setString("Total array access : ");
    text.setCharacterSize(14);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(10, 10));

    sf::Text text2;
    text2.setFont(font);
    text2.setString(std::to_string(accesses));
    text2.setCharacterSize(14);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(sf::Vector2f(150, 10));

    sf::Text text3;
    text3.setFont(font);
    text3.setString(buffer);
    text3.setCharacterSize(14);
    text3.setFillColor(sf::Color::White);
    text3.setPosition(sf::Vector2f(10, 30));

    sf::Text text4;
    text4.setFont(font);
    text4.setString(buffer2);
    text4.setCharacterSize(14);
    text4.setFillColor(sf::Color::White);
    text4.setPosition(sf::Vector2f(10, 50));

    sf::Text text5;
    text5.setFont(font);
    text5.setString(buffer4);
    text5.setCharacterSize(14);
    text5.setFillColor(sf::Color::White);
    text5.setPosition(sf::Vector2f(10, 70));

    sf::Thread* thread;
    Selectionsort ss;
    thread = new sf::Thread(
        std::bind(&ss.sort, std::ref(this->arr), std::ref(accesses)));

    switch (this->a) {
    case 0:
        Selectionsort ss;
        thread = new sf::Thread(
            std::bind(&ss.sort, std::ref(this->arr), std::ref(accesses)));
        break;
    case 1:
        Bubblesort bs;
        thread = new sf::Thread(
            std::bind(&bs.sort, std::ref(this->arr), std::ref(accesses)));
        break;
    case 2:
        Insertionsort is;
        thread = new sf::Thread(
            std::bind(&is.sort, std::ref(this->arr), std::ref(accesses)));
        break;
    case 3:
        Mergesort ms;
        thread = new sf::Thread(
            std::bind(&ms.sort, std::ref(this->arr), std::ref(accesses)));
        break;
    case 4:
        Quicksort qs;
        thread = new sf::Thread(std::bind(&qs.sort, std::ref(this->arr), 0,
            this->arr.size() - 1, std::ref(accesses)));
        break;
    case 5:
        Heapsort hs;
        thread = new sf::Thread(
            std::bind(&hs.sort, std::ref(this->arr), std::ref(accesses)));
        break;
    }

    thread->launch();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(0));

        for (int i = 0; i < this->arr.size(); i++) {
            sf::RectangleShape rectangle(
                sf::Vector2f(width, -(height * this->arr[i])));
            rectangle.setPosition(sf::Vector2f(width * i, this->h));
            rectangle.setFillColor(sf::Color(255, 255, 255));
            window.draw(rectangle);
        }

        window.draw(text);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(text5);
        window.display();

        text2.setString(std::to_string(accesses));
    }
}
