#include "AI.h"
#include "map.h"
#include "player.h"
#include <stdlib.h>

node *CreateNode(Point StartPoint)
{
    node *n = (node *)malloc(sizeof(node));
    n->point = StartPoint;
    n->next = NULL;
    return n;
}

int FreeList(node *list)
{
    while (list != NULL)
    {
        node *p = list;
        list = list->next;
        free(p);
    }
    return 0;
}

int AddList(node *lastnode, Point point)
{
}

int RemoveNode(node *list, Point point)
{
}

node *SearchNode()
{
}

int AIMove(Block Map[MAP_WIDTH][MAP_LENGTH], Point PlayerPoint, Point AIPoint) // 使用自动寻路A*算法
{
}