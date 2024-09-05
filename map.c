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

int BuildWall(Block Map[MAP_LENGTH][MAP_WIDTH], Point UpLeft, Point DownRight)
{
    int x_gap = DownRight.x - UpLeft.x;
    int y_gap = DownRight.y - UpLeft.y;

    if (x_gap < 4 || y_gap < 4)
    {
        return -1;
    }

    srand((unsigned)time(NULL));

    int x_ = UpLeft.x + 1 + rand() % (x_gap - 1);
    int y_ = UpLeft.y + 1 + rand() % (y_gap - 1);

    // 画中间的线
    for (int x = UpLeft.x; x <= x_gap + 1; x++)
    {
        Map[x][y_] = wall;
    }
    for (int y = UpLeft.y; y <= y_gap + 1; y++)
    {
        Map[x_][y] = wall;
    }

    Point UpLeft_1 = {UpLeft.x, UpLeft.y, empty}, DownRight_1 = {x_ - 1, y_ - 1, empty};       // 左上
    Point UpLeft_2 = {UpLeft.x, y_ + 1, empty}, DownRight_2 = {x_ - 1, DownRight.y, empty};    // 左下
    Point UpLeft_3 = {x_ + 1, UpLeft.y, empty}, DownRight_3 = {DownRight.x, y_ - 1, empty};    // 右上
    Point UpLeft_4 = {x_ + 1, y_ + 1, empty}, DownRight_4 = {DownRight.x, DownRight.y, empty}; // 右下
    // 分开来的四个区域，递归分开
    BuildWall(Map, UpLeft_1, DownRight_1); // 左上
    BuildWall(Map, UpLeft_2, DownRight_2); // 左下
    BuildWall(Map, UpLeft_3, DownRight_3); // 右上
    BuildWall(Map, UpLeft_4, DownRight_4); // 右下

    // 随机三面墙里面打洞 从横的墙壁的顺时针编号为0,1,2,3
    int a[4] = {0};
    a[rand() % 4] = 1;
    for (int i = 0; i < 4; i++)
    {
        if (a[i] == 0)
        {
            switch (i)
            {
            case 0: // 0号墙
                Map[UpLeft.x + rand() % (x_ - UpLeft.x + 1)][y_] = empty;
                break;
            case 1: // 1号墙
                Map[x_][UpLeft.y + rand() % (y_ - UpLeft.y + 1)] = empty;
                break;
            case 2: // 2号墙
                Map[x_ + rand() % (x_ - UpLeft.x + 1)][y_] = empty;
                break;
            case 3: // 3号墙
                Map[x_][y_ + rand() % (y_ - UpLeft.y + 1)] = empty;
                break;
            default:
                break;
            }
        }
    }

    return 0;
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

    Point UpLeft = {1, 1, empty}, DownRight = {MAP_LENGTH - 2, MAP_WIDTH - 2, empty}; // 左上和右下的点确定矩形 (1,1)~(MAP_LENGTH - 2, MAP_WIDTH - 2)为可用范围
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