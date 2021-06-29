#include <algorithm>
#include <chrono>
#include <ctime>
#include <future>   // std::async, std::future
#include <iostream>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <thread>

#include <SFML/Graphics.hpp>

#include "Engine.hpp";
#include "Quicksort.hpp";
#include "Selectionsort.hpp";
#include "Bubblesort.hpp";
#include "Insertionsort.hpp";
#include "Mergesort.hpp";

using namespace std;

enum Algorithm {
    SELECTION_SORT, //  Ready
    BUBBLE_SORT,    //  Ready
    INSERTION_SORT, //  Ready
    MERGE_SORT,     //  not
    QUICK_SORT,     //  Ready
    HEAPT_SORT,     //  not
    COUNTING_SORT,  //  not
    RADIX_SORT,     //  not
    BUCKET_SORT     //  not
};

Engine::Engine(int w, int h) 
{
	this->w = w;
	this->h = h;
}

void Engine::start() 
{ 
    sf::RenderWindow window(sf::VideoMode(this->w, this->h), "Algorithm sorting visualization by BR", sf::Style::Default);

    for (int i = 0; i < 64; i++) {
        this->arr.push_back(i + 1);
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(this->arr.begin(), this->arr.end(), g);

    float width  = (float) this->w / (float) this->arr.size();
    float height = (float) this->h / (float) this->arr.size();

    int accesses = 0;

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) { }

    sf::Text text;
    text.setFont(font);
    text.setString("Total array access : ");
    text.setCharacterSize(16);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(10, 10));

    sf::Text text2;
    text2.setFont(font);
    text2.setString(std::to_string(accesses));
    text2.setCharacterSize(16);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(sf::Vector2f(160, 10));

    // MutexGuard
    sf::Mutex mutex;
    sf::Thread* thread;

    //Quicksort qs;
    //thread = new sf::Thread(std::bind(&qs.quicksort, std::ref(this->arr), 0, this->arr.size() - 1, std::ref(accesses)));
    
    //Selectionsort ss;
    //thread = new sf::Thread(std::bind(&ss.sort, std::ref(this->arr), std::ref(accesses)));

    //Bubblesort ss;
    //thread = new sf::Thread(std::bind(&ss.sort, std::ref(this->arr), std::ref(accesses)));

    //Insertionsort is;
    //thread = new sf::Thread(std::bind(&is.sort, std::ref(this->arr), std::ref(accesses)));
    
    Mergesort ms;
    thread = new sf::Thread(std::bind(&ms.sort, std::ref(this->arr), std::ref(accesses)));
    
    thread->launch();

    while (window.isOpen())
    {   
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(0));

        //mutex.lock();

        for (int i = 0; i <= this->arr.size() - 1; i++)
        {
            sf::RectangleShape rectangle(sf::Vector2f(width, -(height * this->arr[i])));
            rectangle.setPosition(sf::Vector2f(width * i, this->h));
            rectangle.setFillColor(sf::Color(255, 255, 255));
            window.draw(rectangle);
        }

        //mutex.unlock();

        window.draw(text);
        window.draw(text2);
        window.display();

        text2.setString(std::to_string(accesses));

        //for (int i = 0; i < this->arr.size(); ++i)
        //    std::cout << this->arr[i] << ' ';
    }
}