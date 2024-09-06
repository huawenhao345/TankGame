#ifndef _MAP_H_
#define _MAP_H_ 1

#define MAP_LENGTH 12
#define MAP_WIDTH 12
typedef enum block
{
    empty = 0,
    wall,
    tank,
    enemy
} Block;

typedef struct
{
    int x;
    int y;
    Block statu;
} Point;

int PrintMap(Block Map[MAP_WIDTH][MAP_LENGTH]);
int RandomMapGenerate(Block Map[MAP_WIDTH][MAP_LENGTH]);

extern Block GameMap[MAP_WIDTH][MAP_LENGTH];

#endif