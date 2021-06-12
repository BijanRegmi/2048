#ifndef CONSTANTS_H
#define CONSTANTS_H

const int FRAME_RATE_LIMIT = 60;

const int GRID_X = 4;
const int GRID_Y = 4;

const float TILE_HEIGHT = 100.f;
const float TILE_WIDTH = 100.f;

const std::string TILE_FONT = "res/font.ttf";

const int CHARACTER_SIZE = 0.9*std::min(TILE_HEIGHT, TILE_WIDTH);


#endif // CONSTANTS_H


/*
//Grey
2
4
//Orange
8
16
32
64
//Yellow
128
256
512
1024
//Red
2048
4096
8192
16384
//Blue
32768
65536
131072
262144
//Green
524288
1048576
2097152
4194304
*/
