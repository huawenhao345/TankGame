#ifndef _MAP_H_
#define _MAP_H_ 1

#define MAP_LENGTH 22
#define MAP_WIDTH 22

//test define
// #define TEST 1

typedef enum block
{
    empty = 0,
    wall,
    player,
    enemy
} Block;

typedef struct
{
    int x;
    int y;
    Block statu;
} Point;

int PrintMap(Block Map[MAP_WIDTH][MAP_LENGTH]);
int RcursiveMapGenerate(Block Map[MAP_WIDTH][MAP_LENGTH]);
void ScreenClear(void);

extern Block GameMap[MAP_WIDTH][MAP_LENGTH];

#endif