#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "map.h"
/**
 * @brief
 * 0 空格
 * 1 砖
 * 2 坦克
 */

Block GameMap[MAP_LENGTH][MAP_WIDTH] = {};

int MapChange(Block Map[MAP_LENGTH][MAP_WIDTH], int x, int y, Block a)
{
    Map[x][y] = a;
    return 0;
}

int BuildWall(Block Map[MAP_LENGTH][MAP_WIDTH], Point UpLeft, Point DownRight)
{
    if (DownRight.x - UpLeft.x < 2 || DownRight.y - UpLeft.y < 2)
    {
        return -1;
    }

    int x_ = UpLeft.x + 1 + rand() % (DownRight.x - UpLeft.x - 1);
    int y_ = UpLeft.y + 1 + rand() % (DownRight.y - UpLeft.y - 1);

    // 画中间的线
    for (int x = UpLeft.x; x <= (DownRight.x - UpLeft.x); x++)
    {
        Map[x][y_] = wall;
    }
    for (int y = UpLeft.y; y <= (DownRight.y - UpLeft.y); y++)
    {
        Map[x_][y] = wall;
    }
}

int RandomMapGenerate(Block Map[MAP_LENGTH][MAP_WIDTH])
{
    // 初始化
    for (int x = 0; x < MAP_LENGTH; x++)
    {
        for (int y = 0; y < MAP_WIDTH; y++)
        {
            Map[x][y] = empty;
        }
    }

    // 四周墙壁x，y
    for (int x = 0; x < MAP_LENGTH; x++)
    {
        Map[x][0] = wall;
        Map[x][MAP_WIDTH - 1] = wall;
    }
    for (int y = 0; y < MAP_LENGTH; y++)
    {
        Map[0][y] = wall;
        Map[MAP_LENGTH - 1][y] = wall;
    }

    Point UpLeft = {1, 1, empty}, DownRight = {50, 50, empty}; // 左上和右下的点确定矩形 (1,1)~(50,50)为可用范围
    BuildWall(Map, UpLeft, DownRight);

    return 0;
}

int PrintMap(Block Map[MAP_LENGTH][MAP_WIDTH])
{
    for (int x = 0; x < MAP_LENGTH; x++)
    {
        for (int y = 0; y < MAP_WIDTH; y++)
        {
            switch (Map[x][y])
            {
            case 0:
                printf("  ");
                break;
            case 1:
                printf(" O");
                break;
            case 2:
                printf("-");
                break;
            // case 3:

            //     break;
            // case 4:
            //     break;
            // case 5:

            //     break;
            default:
                break;
            }
        }
        printf("\n");
    }
    return 0;
}