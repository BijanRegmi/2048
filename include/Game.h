#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "grid.h"

class Game{
private:
    sf::RenderWindow* window;   //Main Window
    sf::Event ev;               //Event Handler
    grid* board;                //Game board

    //Initializers
    void initVariables();
    void initWindow();

    void pollevents();          //Event Handler function
    void draw();                //Drawing Function
public:
    //Constructors and destructors
    Game();
    ~Game();

    //Accessors
    bool running();

    //Core functions
    void update();
    void render();
};
#endif // GAME_H
