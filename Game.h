//
// Created by Сергей on 30.03.2020.
//

#pragma once
#include <string>

using namespace std;

class Game
{
private:
    int x, y;
    char player;
public:
    void (*Message[2])(int x, int y, char player);
    void Move(int x, int y, char player)
    {
        this->x = x;
        this->y = y;
        this->player = player;
        for (int i = 0; i < 2 ; ++i)
        {
            Message[i](this->x,this->y,this->player);
        }
    }
};
