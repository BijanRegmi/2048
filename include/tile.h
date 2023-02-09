#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Tile: public Sprite {
private:
    //Tile Properties
    int val;
    std::string name;

    //Render objects
    RectangleShape tile_rect;           //Inner rectangle
    Text tile_val;                      //Tile value holder
    Font tile_val_font;                 //Font for tile value
    Texture tile_rect_texture;          //Texture for the inner rectangle(wood texture currently)
    RenderTexture tile_texture;         //Texture for the whole tile body

    //Inner render functions
    void render_inner_objects(int v);   //Creates inner rectangle and text

public:
    //Constructor
    Tile(int v=0);

    //Render functions
    void render_tile();                 //Creates sprite

    //Helper Functions
    void setValue(int v);               //As the name says, it sets value of the tile
    int getValue();                     //Accessor function to get the value of the tile

};
#endif // TILE_H
