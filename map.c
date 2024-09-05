#include <stdio.h>
#include <time.h>
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

int RandomMapGenerate(Block Map[MAP_LENGTH][MAP_WIDTH])
{
    Point UpLeft = {0, 0, empty}, DownRight = {0, 0, empty};
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

    return 0;
}

int BuildWall(Point UpLeft, Point DownRight)
{

    if (DownRight.x - UpLeft.x < 2 || DownRight.y - UpLeft.y < 2)
    {
        return -1;
    }


    while (/* condition */)
    {
        /* code */
    }
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