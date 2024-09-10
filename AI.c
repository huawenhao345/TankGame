#include "AI.h"
#include "map.h"
#include "player.h"

int AIMove(Block Map[MAP_WIDTH][MAP_LENGTH], Point *PlayerPoint, Point *AIPoint) // 使用自动寻路A*算法
{
}

// use A* algorithm to find the path
int AStar(Block Map[MAP_WIDTH][MAP_LENGTH], Point *PlayerPoint, Point *AIPoint)
{
    // init
    int OpenList[MAP_WIDTH][MAP_LENGTH] = {0};  // open list
    int CloseList[MAP_WIDTH][MAP_LENGTH] = {0}; // close list
    int Path[MAP_WIDTH][MAP_LENGTH] = {0};      // path
    int F[MAP_WIDTH][MAP_LENGTH] = {0};         // F
    int G[MAP_WIDTH][MAP_LENGTH] = {0};         // G
    int H[MAP_WIDTH][MAP_LENGTH] = {0};         // H
    int x, y;
    int x1, y1;
    int x2, y2;
    int x0, y0;
    int i;
    int j;
    int m;
    int n;
    int k;
    int t;
    int temp;
    int way;
    int flag;
    int step = 0;
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // right, down, left, up
    int startx = AIPoint->x;
    int starty = AIPoint->y;
    int endx = PlayerPoint->x;
    int endy = PlayerPoint->y;

    // init
    for (i = 0; i < MAP_WIDTH; i++)
    {
        for (j = 0; j < MAP_LENGTH; j++)
        {
            if (Map[i][j] == wall)
            {
                CloseList[i][j] = 1;
            }
        }
    }

    // start point
    x1 = startx;
    y1 = starty;
    // end point
    x2 = endx;
    y2 = endy;

    // init
    for (i = 0; i < MAP_WIDTH; i++)
    {
        for (j = 0; j < MAP_LENGTH; j++)
        {
            G[i][j] = 0;
            H[i][j] = abs(x2 - i) + abs(y2 - j);
            F[i][j] = G[i][j] + H[i][j];
        }
    }

    // init
    OpenList[x1][y1] = 1;
    flag = 0;
    way = 0;
}