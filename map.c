#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "map.h"

int MapInitialize(Block Map[MAP_WIDTH][MAP_LENGTH])
{
    for (int x = 0; x < MAP_LENGTH; x++)
    {
        for (int y = 0; y < MAP_WIDTH; y++)
        {
            Map[y][x] = empty;
        }
    }
    // PrintMap(Map); // use for test
}

/**
 * @brief 采用递归分割算法随机生成地图
 *
 * @param Map
 * @param UpLeft
 * @param DownRight
 * @return int
 */
int BuildWall(Block Map[MAP_WIDTH][MAP_LENGTH], Point UpLeft, Point DownRight)
{
    int x_gap = DownRight.x - UpLeft.x;
    int y_gap = DownRight.y - UpLeft.y;

    if (x_gap < 2 || y_gap < 2)
    {
        return -1;
    }

    int x_ = UpLeft.x + 1 + rand() % (x_gap - 1);
    int y_ = UpLeft.y + 1 + rand() % (y_gap - 1);
    // DownRight = (Point){MAP_LENGTH - 2, MAP_WIDTH - 2, empty};
    // printf("%d", DownRight.x);//use for test

    // 画中间的线
    /*实际上，map[][]的正确方向应该是这样的  map[y][x]才匹配下图
    e.g. --------------------------------->x
        |
        |
        |
        |
        |
        |
        |
        |
        |
        |
       y^
    */
    for (int x = 0; x <= x_gap + 1; x++) // x方向打印
    {
        Map[y_][UpLeft.x + x] = wall;

        // PrintMap(Map);
        // use for test
    }
    for (int y = 0; y <= y_gap + 1; y++) // y方向打印
    {
        Map[UpLeft.y + y][x_] = wall;

        // PrintMap(Map);
        // use for test
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
            int rx = x_;
            int ry = y_;
            switch (i)
            {
            case 0: // 0号墙
                do
                {
                    rx = UpLeft.x + rand() % (x_ - UpLeft.x + 1);
                } while (Map[ry - 1][rx] + Map[ry + 1][rx] + Map[ry][rx - 1] + Map[ry][rx + 1] > 2 * wall); // 解决位于顶点出处的路的生成
                break;
            case 1: // 1号墙
                do
                {
                    ry = UpLeft.y + rand() % (y_ - UpLeft.y + 1);
                } while (Map[ry - 1][rx] + Map[ry + 1][rx] + Map[ry][rx - 1] + Map[ry][rx + 1] > 2 * wall);
                break;
            case 2: // 2号墙
                do
                {
                    rx = x_ + rand() % (x_ - UpLeft.x + 1);
                } while (Map[ry - 1][rx] + Map[ry + 1][rx] + Map[ry][rx - 1] + Map[ry][rx + 1] > 2 * wall);
                break;
            case 3: // 3号墙
                do
                {
                    ry = y_ + rand() % (y_ - UpLeft.y + 1);
                } while (Map[ry - 1][rx] + Map[ry + 1][rx] + Map[ry][rx - 1] + Map[ry][rx + 1] > 2 * wall);
                break;
            default:
                break;
            }
            Map[ry][rx] = empty;
        }
        // PrintMap(Map); // use for test
    }

    return 0;
}

/**
 * @brief 随机生成地图
 *
 * @param Map
 * @return int
 */
int RcursiveMapGenerate(Block Map[MAP_WIDTH][MAP_LENGTH])
{
    // 初始化
    srand((unsigned)time(NULL));
    MapInitialize(Map);

    // 四周墙壁x，y
    for (int x = 0; x < MAP_LENGTH; x++)
    {
        Map[0][x] = wall;
        Map[MAP_WIDTH - 1][x] = wall;
    }
    for (int y = 0; y < MAP_LENGTH; y++)
    {
        Map[y][0] = wall;
        Map[y][MAP_LENGTH - 1] = wall;
    }

    // PrintMap(Map);//use for test

    Point UpLeft = {1, 1, empty}, DownRight = {MAP_LENGTH - 2, MAP_WIDTH - 2, empty}; // 左上和右下的点确定矩形 (1,1)~(MAP_LENGTH - 2, MAP_WIDTH - 2)为可用范围

    BuildWall(Map, UpLeft, DownRight);

    return 0;
}

/**
 * @brief 打印当前地图
 *
 * @param Map
 * @return int
 */
int PrintMap(Block Map[MAP_WIDTH][MAP_LENGTH])
{

    // 打印x数轴
    //  printf("  ");
    //  for (int i = 0; i < 10; i++) // use for test
    //  {
    //      printf(" %d", i);
    //  }
    //  for (int i = 10; i < MAP_LENGTH; i++) // use for test
    //  {
    //      printf("%d", i);
    //  }
    //  printf("\n");

    for (int y = 0; y < MAP_WIDTH; y++)
    {
        // 打印y数轴
        // if (y < 10)
        // {
        //     printf(" %d", y);
        // }
        // else
        // {
        //     printf("%d", y);
        // }

        for (int x = 0; x < MAP_LENGTH; x++)
        {
            switch (Map[y][x])
            {
            case 0:           // empty
                printf("  "); // CHARWHITH的依据是这里多少字符
                break;
            case 1:           // wall
                printf("OO"); // CHARWHITH的依据是这里多少字符
                break;
            case 2:           // player
                printf("@@"); // CHARWHITH的依据是这里多少字符
                break;
            case 3:           // ememy
                printf("&&"); // CHARWHITH的依据是这里多少字符
                break;
            // case 4:
            //     break;
            // case 5:

            //     break;
            default:
                break;
            }
        }
        if (y < MAP_LENGTH - 1)
        {
            printf("\n");
        }
    }
    return 0;
}