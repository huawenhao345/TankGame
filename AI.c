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
        return -1;
    }
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        return -1;
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
    // 1.初始化open表和close表
    node *open = CreateNode(AIPoint);
    node *close = NULL;
    node *current = NULL;
    node *end = open;
    Point tempPoint;
    int i, j;
    int G, H, F;
    int flag = 0;
    while (open != NULL)
    {
        current = open;
        end = open;
        while (current != NULL)
        {
            if (current->point.x == PlayerPoint.x && current->point.y == PlayerPoint.y)
            {
                flag = 1;
                break;
            }
            // 上
            tempPoint.x = current->point.x;
            tempPoint.y = current->point.y - 1;
            if (tempPoint.y >= 0 && Map[tempPoint.x][tempPoint.y] != wall && SearchNode(open, tempPoint) == NULL && SearchNode(close, tempPoint) == NULL)
            {
                end = AddList(end, tempPoint);
            }
            // 下
            tempPoint.x = current->point.x;
            tempPoint.y = current->point.y + 1;
            if (tempPoint.y < MAP_LENGTH && Map[tempPoint.x][tempPoint.y] != wall && SearchNode(open, tempPoint) == NULL && SearchNode(close, tempPoint) == NULL)
            {
                end = AddList(end, tempPoint);
            }
            // 左
            tempPoint.x = current->point.x - 1;
            tempPoint.y = current->point.y;
            if (tempPoint.x >= 0 && Map[tempPoint.x][tempPoint.y] != wall && SearchNode(open, tempPoint) == NULL && SearchNode(close, tempPoint) == NULL)
            {
                end = AddList(end, tempPoint);
            }
            // 右
            tempPoint.x = current->point.x + 1;
            tempPoint.y = current->point.y;
            if (tempPoint.x < MAP_WIDTH && Map[tempPoint.x][tempPoint.y] != wall && SearchNode(open, tempPoint) == NULL && SearchNode(close, tempPoint) == NULL)
            {
                end = AddList(end, tempPoint);
            }
            current = current->next;
        }
        if (flag == 1)
        {
            break;
        }
        // 将当前节点加入close表
        close = AddList(close, current->point);
        // 将当前节点从open表中删除
        RemoveNode(open, current->point);
    }
    if (flag == 0)
    {
        FreeList(open);
        FreeList(close);
        return -1;
    }
    // 找到路径
    node *path = CreateNode(PlayerPoint);
    while (current->point.x != AIPoint.x || current->point.y != AIPoint.y)
    {
        // 上
        tempPoint.x = current->point.x;
        tempPoint.y = current->point.y - 1;
        if (tempPoint.y >= 0 && SearchNode(close, tempPoint) != NULL)
        {
            path = AddList(path, tempPoint);
            current = SearchNode(close, tempPoint);
            continue;
        }
        // 下
        tempPoint.x = current->point.x;
        tempPoint.y = current->point.y + 1;
        if (tempPoint.y < MAP_LENGTH && SearchNode(close, tempPoint) != NULL)
        {
            path = AddList(path, tempPoint);
            current = SearchNode(close, tempPoint);
            continue;
        }
        // 左
        tempPoint.x = current->point.x - 1;
        tempPoint.y = current->point.y;
        if (tempPoint.x >= 0 && SearchNode(close, tempPoint) != NULL)
        {
            path = AddList(path, tempPoint);
            current = SearchNode(close, tempPoint);
            continue;
        }
        // 右
        tempPoint.x = current->point.x + 1;
        tempPoint.y = current->point.y;
        if (tempPoint.x < MAP_WIDTH && SearchNode(close, tempPoint) != NULL)
        {
            path = AddList(path, tempPoint);
            current = SearchNode(close, tempPoint);
            continue;
        }
    }
    // 移动
    while (path->next != NULL)
    {
        if (PlayerPoint.x == path->next->point.x && PlayerPoint.y == path->next->point.y)
        {
            break;
        }
        if (PlayerPoint.x == path->next->point.x && PlayerPoint.y == path->next->point.y - 1)
        {
            PlayerMove(Map, &PlayerPoint, UP);
        }
        else if (PlayerPoint.x == path->next->point.x && PlayerPoint.y == path->next->point.y + 1)
        {
            PlayerMove(Map, &PlayerPoint, DOWN);
        }
        else if (PlayerPoint.x == path->next->point.x - 1 && PlayerPoint.y == path->next->point.y)
        {
            PlayerMove(Map, &PlayerPoint, LEFT);
        }
        else if (PlayerPoint.x == path->next->point.x + 1 && PlayerPoint.y == path->next->point.y)
        {
            PlayerMove(Map, &PlayerPoint, RIGHT);
        }
        GoToxy(PlayerPoint.x * CHARWHITH, PlayerPoint.y);
        path = path->next;
    }
    FreeList(open);
    FreeList(close);
    FreeList(path);
    return 0;
}