#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "tile.h"
#include "constants.h"

class grid: public sf::Sprite{
private:
    //Render objects
    sf::RenderTexture grid_texture;     //Main grid texture
    Tile tile_grid[GRID_X][GRID_Y];     //Inner tiles array

    //Inner render functions
    void render_inner_tiles();

    //Inner move functions
    void swipe_left();                  //Move left
    void swipe_right();                 //Move right
    void swipe_up();                    //Move up
    void swipe_down();                  //Move down

    //Helper functions
    void place_tile(int x, int y, int val);                 //Place a tile in given position with given value
    void remove_tile(int x, int y);                         //Remove a tile from given position
    void spawn_tile();                                      //Spawn a new tile in an empty spot
    void move_tile(int x, int y, int dir_x, int dir_y);     //Moves a tile at given position in given direction
public:
    //Constructor
    grid();

    //Move function
    void swipe(char dir);       //Moves the board in given direction

    //Render function
    void render_grid();

};
#endif // GRID_H
