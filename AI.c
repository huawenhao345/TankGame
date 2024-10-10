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

node *AddList(node *endNode, Point newPoint)
{
    if (endNode == NULL)
    {
        return NULL;
    }
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        return NULL;
    }
    newnode->point = newPoint;
    newnode->next = NULL;
    endNode->next = newnode;
    endNode = newnode;
    return endNode;
}

int RemoveNode(node *list, Point cpoint)
{
    if (list == NULL)
    {
        return -1;
    }

    node *current = list;

    while (current->next != NULL)
    {
        if (current->next->point.x == cpoint.x && current->next->point.y == cpoint.y)
        {
        }
        current = current->next;
    }
    return -1;
}

node *SearchNode(node *list, Point cpoint)
{
    if (list == NULL)
    {
        return NULL;
    }

    node *current = list;
    while (current != NULL)
    {
        if (current->point.x == cpoint.x && current->point.y == cpoint.y)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int AIMove(Block Map[MAP_WIDTH][MAP_LENGTH], Point PlayerPoint, Point AIPoint) // 使用自动寻路A*算法
{
}