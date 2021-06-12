#include <iostream>
#include "Game.h"
#include "grid.h"
#include "constants.h"

void Game::initVariables(){
    window = nullptr;
    board = new grid;
}

void Game::initWindow(){
    window = new sf::RenderWindow(sf::VideoMode(GRID_X*TILE_WIDTH, GRID_Y*TILE_HEIGHT), "2048");
    window->setFramerateLimit(FRAME_RATE_LIMIT);
}

Game::Game(){
    initVariables();
    initWindow();
}

Game::~Game(){
    delete window;
    delete board;
}

bool Game::running(){
    return window->isOpen();
}

void Game::update(){
    pollevents();
    board->render_grid();
}

void Game::render(){
    window->clear();
    window->draw(*board);
    window->display();
}

void Game::draw(){

}

void Game::pollevents(){
    while(window->pollEvent(ev)){
        switch (ev.type){
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape){
                    window->close();
                } else if (ev.key.code == sf::Keyboard::Up){
                    board->swipe('u');
                } else if (ev.key.code == sf::Keyboard::Down){
                    board->swipe('d');
                } else if (ev.key.code == sf::Keyboard::Right){
                    board->swipe('r');
                } else if (ev.key.code == sf::Keyboard::Left){
                    board->swipe('l');
                }
                break;
        }
    }
}
