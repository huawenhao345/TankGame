#ifndef _PLAYER_H
#define _PLAYER_H 1

#include "map.h"

#define CHARWHITH 2

typedef enum
{
    UP,
    DOWN,
    LEFT,
    RIGHT
} MoveState;

Point AddPlayer(Block Map[MAP_WIDTH][MAP_LENGTH]);
void GoToxy(int x, int y);
int PlayerMove(Block Map[MAP_WIDTH][MAP_LENGTH], Point PlayerPoint, MoveState State);

#endif