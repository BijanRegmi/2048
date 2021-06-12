#include "grid.h"
#include <cstdlib>

grid::grid(){
    /**
     * Create grid texture
     * Set tile positions
     * Set sprite texture
     * Spawn starting tiles
     */

    grid_texture.create(GRID_X*TILE_WIDTH, GRID_Y*TILE_HEIGHT);

    for(int i = 0; i < GRID_X; i++)
        for(int j = 0; j < GRID_Y; j++)
            tile_grid[i][j].setPosition( i*TILE_WIDTH, j*TILE_HEIGHT );

    this->setTexture(grid_texture.getTexture());

    spawn_tile();
    spawn_tile();

    /* View more tile*/
    place_tile(0,0,2);
    place_tile(0,1,4);
    place_tile(0,2,8);
    place_tile(0,3,16);
    place_tile(1,3,32);
    place_tile(1,2,64);
    place_tile(1,1,128);
    place_tile(1,0,256);
    place_tile(2,0,512);
    place_tile(2,1,1024);
    place_tile(2,2,2048);
    place_tile(2,3,4096);
    place_tile(3,3,8192);
    place_tile(3,2,16384);
    place_tile(3,1,32768);
    place_tile(3,0,65536);/**/

}

void grid::swipe(char dir){
    /**
     * Swipes the board to the given direction..
     * @param dir direction to which board is to be swiped.
     * 'l' : left
     * 'r' : right
     * 'd' : down
     * 'u' : up
     */

    switch (dir){
    case 'l':
        swipe_left();
        break;
    case 'r':
        swipe_right();
        break;
    case 'd':
        swipe_down();
        break;
    case 'u':
        swipe_up();
        break;
    }
    spawn_tile();

}

void grid::swipe_up(){
    for (int i=0; i<GRID_X; i++){
        for (int j=0; j<GRID_Y; j++){
            if(tile_grid[i][j].getValue()!=0)
                move_tile(i,j,0,-1);
        }
    }

}

void grid::swipe_down(){
    for (int i=0; i<GRID_X; i++){
        for (int j=GRID_Y-1; j>=0; j--){
            if (tile_grid[i][j].getValue()!=0)
                move_tile(i,j,0,1);
        }
    }

}

void grid::swipe_left(){
    for(int j=0;j<GRID_Y;j++){
        for(int i=0;i<GRID_X;i++){
            if (tile_grid[i][j].getValue()!=0)
                move_tile(i, j, -1, 0);
        }
    }

}

void grid::swipe_right(){
    for (int j=0;j<GRID_Y;j++){
        for (int i=GRID_X-1; i>=0; i--){
            if(tile_grid[i][j].getValue()!=0)
                move_tile(i,j,1,0);
        }
    }

}

void grid::move_tile(int source_x, int source_y, int dir_x, int dir_y){
    /**
     * Moves the tile
     * @param source_x, source_y The position of the tile to be moved
     * @param dir_x, dir_y direction in x and y axis. Origin at top left.
     */

    int des_x = source_x+dir_x;
    int des_y = source_y+dir_y;

    if (des_x<0 || des_y<0 || des_x>=GRID_X || des_y>=GRID_Y)
        return;

    int des_val = tile_grid[des_x][des_y].getValue();
    int source_val = tile_grid[source_x][source_y].getValue();

    if (des_val==0){
        remove_tile(source_x, source_y);
        place_tile(des_x, des_y, source_val);
        move_tile(des_x, des_y, dir_x, dir_y);
    } else if (des_val == source_val){
        remove_tile(source_x, source_y);
        place_tile(des_x, des_y, source_val*2);
    }

}

void grid::spawn_tile(){
    /**
     * Find empty positions
     * Place tile in one of the empty pos
     */

    std::vector<sf::Vector2i> empty_pos;
    for(int i=0; i<GRID_X; i++)
        for(int j=0; j<GRID_Y; j++)
            if(tile_grid[i][j].getValue()==0)
                empty_pos.push_back(sf::Vector2i(i, j));

    if (empty_pos.size() != 0){
        int new_val, prob, pos;

        prob = std::rand() % 101;
        pos = std::rand() % empty_pos.size();

        new_val = (prob<=90) ? 2 : 4;                               //90% chance of getting 2

        place_tile( empty_pos[pos].x, empty_pos[pos].y, new_val );

    } else
        std::cout << "Oops! Can't move in that direction." << std::endl;

}

void grid::place_tile(int x, int y, int val){
    tile_grid[x][y].setValue(val);

}

void grid::remove_tile(int x, int y){
    tile_grid[x][y].setValue(0);

}

void grid::render_grid(){
    /**
     * Clear the grid texture first
     * Render inner tiles to the texture
     * Display the objects on the texture
     */

    grid_texture.clear();
    render_inner_tiles();
    grid_texture.display();

}

void grid::render_inner_tiles(){
    /**
     * Loops through all the tiles in the grid and calls their respective render function.
     * Then draw them on the grid texture
     */

    for(int i = 0; i < GRID_X; i++)
        for(int j = 0; j < GRID_Y; j++)
            if(tile_grid[i][j].getValue()!=0){
                tile_grid[i][j].render_tile();
                grid_texture.draw(tile_grid[i][j]);
            }

}
