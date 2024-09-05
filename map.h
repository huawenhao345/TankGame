#ifndef _MAP_H_
#define _MAP_H_ 1

#define MAP_LENGTH 52
#define MAP_WIDTH 52

//(2,2)~(51,51)

typedef enum
{
    empty = 0,
    wall,
    tank,
    enemy
} Block;

int MapChange(Block Map[MAP_LENGTH][MAP_WIDTH], int x, int y, Block a);
int PrintMap(const Block Map[MAP_LENGTH][MAP_WIDTH]);
int RandomMapGenerate(Block Map[MAP_LENGTH][MAP_WIDTH]);

extern Block GameMap[MAP_LENGTH][MAP_WIDTH];

#endif