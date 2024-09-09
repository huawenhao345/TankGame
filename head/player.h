#ifndef _PLAYER_H
#define _PLAYER_H 1

#include "map.h"

#define CHARWHITH 2
#define KEY_DOWN(VK) ((GetAsyncKeyState(VK) & 0x8000 ? 1 : 0))
#define KEY_DOWN_FOREGROUND(hwnd, vk) (KEY_DOWN(vk) && GetForegroundWindow() == hwnd) // 前景窗口判断

typedef enum
{
    UP,
    DOWN,
    LEFT,
    RIGHT
} MoveState;

extern Point PlayerPoint;

Point AddPlayer(Block Map[MAP_WIDTH][MAP_LENGTH]);
void GoToxy(int x, int y);
int PlayerMove(Block Map[MAP_WIDTH][MAP_LENGTH], Point *UserPoint, MoveState State);

#endif