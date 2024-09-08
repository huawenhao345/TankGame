#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "player.h"
#include "map.h"

// /**
//  * @brief 暂不用
//  *
//  * @param x
//  * @param y
//  */
// void GoToxy(int x, int y) // 光标移动函数，X表示横坐标，Y表示纵坐标。
// {
//     COORD coord;                                // 使用头文件自带的坐标结构,下面的*CHARWHITH是坐标映射
//     coord.X = x * CHARWHITH;                    // 这里将int类型值传给short,不过程序中涉及的坐标值均不会超过short范围
//     coord.Y = y;                                // y不需要坐标映射
//     HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE); // 获得标准输出句柄
//     SetConsoleCursorPosition(a, coord);         // 以标准输出的句柄为参数设置控制台光标坐标
// }

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

int PlayerMove(Block Map[MAP_WIDTH][MAP_LENGTH], MoveState State)
{
    switch (State)
    {
    case UP:
        if (Map[PlayerPoint.y - 1][PlayerPoint.x] != empty) // 减1是上
        {
            return -1;
        }
        Map[PlayerPoint.y][PlayerPoint.x] = empty;
#ifdef TEST
        PrintMap(GameMap);
#endif
        Map[PlayerPoint.y - 1][PlayerPoint.x] = player;
        PlayerPoint.y = PlayerPoint.y - 1;

#ifdef TEST
        PrintMap(GameMap);
#endif
        break;
    case DOWN:
        if (Map[PlayerPoint.y + 1][PlayerPoint.x] != empty)
        {
            return -1;
        }
        Map[PlayerPoint.y][PlayerPoint.x] = empty;
#ifdef TEST
        PrintMap(GameMap);
#endif

        Map[PlayerPoint.y + 1][PlayerPoint.x] = player;
        PlayerPoint.y = PlayerPoint.y + 1;

#ifdef TEST
        PrintMap(GameMap);
#endif
        break;
    case LEFT:
        if (Map[PlayerPoint.y][PlayerPoint.x - 1] != empty) // 减1是左
        {
            return -1;
        }
        Map[PlayerPoint.y][PlayerPoint.x] = empty;
#ifdef TEST
        PrintMap(GameMap);
#endif
        Map[PlayerPoint.y][PlayerPoint.x - 1] = player;
        PlayerPoint.x = PlayerPoint.x - 1;

#ifdef TEST
        PrintMap(GameMap);
#endif
        break;
    case RIGHT:
        if (Map[PlayerPoint.y][PlayerPoint.x + 1] != empty)
        {
            return -1;
        }
        Map[PlayerPoint.y][PlayerPoint.x] = empty;
#ifdef TEST
        PrintMap(GameMap);
#endif
        Map[PlayerPoint.y][PlayerPoint.x + 1] = player;
        PlayerPoint.x = PlayerPoint.x + 1;

#ifdef TEST
        PrintMap(GameMap);
#endif
        break;
    default:
        return -1;
        break;
    }
    return 0;
}