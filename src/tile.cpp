#include <sstream>
#include <iostream>
#include "tile.h"
#include "constants.h"

Tile::Tile(int v){
    /**
     * Set the value of tile
     * Create tile texture
     * Set the texture to own sprite
     */

    setValue(v);
    tile_texture.create(TILE_WIDTH, TILE_HEIGHT);
    this->setTexture(tile_texture.getTexture());

}

void Tile::render_tile(){
    /**
     * Clear the tile texture first
     * Render inner objects to the texture
     * Display the objects on the texture
     */

    tile_texture.clear();
    render_inner_objects(val);
    tile_texture.display();

}

void Tile::render_inner_objects(int v){

    //Configure tile inner rectangle
    tile_rect.setSize(sf::Vector2f(TILE_WIDTH, TILE_HEIGHT));
    if(!tile_rect_texture.loadFromFile(name)){
        tile_rect.setFillColor(sf::Color::Black);
    }
    else
        tile_rect.setTexture(&tile_rect_texture);

    //Load and set font for tile_val
    if(tile_val_font.loadFromFile(TILE_FONT))
        tile_val.setFont(tile_val_font);

    //Convert value int to string for further processing
    std::stringstream ss;
    std::string tile_str;
    ss << v;
    ss >> tile_str;

    //Configure tile value
    tile_val.setString(tile_str);
    tile_val.setFillColor(sf::Color::White);

    //Text allignment {Pain in ass}
    tile_val.setCharacterSize(CHARACTER_SIZE/tile_str.length());
    float tile_val_width = tile_val.getLocalBounds().width;
    float tile_val_height = tile_val.getLocalBounds().height;
    float tile_rect_width = tile_rect.getLocalBounds().width;
    float tile_rect_height = tile_rect.getLocalBounds().height;
    float tile_val_left = tile_val.getLocalBounds().left;
    float tile_val_top = tile_val.getLocalBounds().top;
    float posX = (tile_rect_width - tile_val_width)/2.f - tile_val_left;
    float posY = (tile_rect_height - tile_val_height)/2.f;

    tile_val.setOrigin(tile_val_left, tile_val_top);
    tile_val.setPosition(sf::Vector2f(posX, posY));

    tile_texture.draw(tile_rect);
    tile_texture.draw(tile_val);
}

void Tile::setValue(int val){
    this->val = val;
    std::stringstream ss;
    ss << "res/" << val << ".jpg";
    ss >> name;
}

int Tile::getValue(){
    return val;
}
