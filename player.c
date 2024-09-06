#include <stdio.h>
#include <stdlib.h>
#include "map.h"

Point AddPlayer(Block Map[MAP_WIDTH][MAP_LENGTH])
{
    int rx = 0, ry = 0;
    Point PlayerPoint;
    do
    {
        rx = (rand() % (MAP_WIDTH - 1)) + 1; // 不在边框生成
        ry = (rand() % (MAP_WIDTH - 1)) + 1;
    } while (Map[ry][rx] == wall);
    Map[ry][rx] = player;
    PlayerPoint = (Point){rx, ry, player};
    return PlayerPoint;
}