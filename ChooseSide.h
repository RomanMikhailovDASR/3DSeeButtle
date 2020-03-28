//
// Created by xaero on 17.03.2020.
//

#ifndef INC_3DSEEBUTTLE_CHOOSESIDE_H
#define INC_3DSEEBUTTLE_CHOOSESIDE_H


#include "Cube.h"
#include "Painting.h"


void choose_first_side(double &rotateX, double &rotateY)
{

    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }
    for (int j = 0; j < 5; j++)
        for (int k = 0; k < 5; k++)
        {
            a[4][j][k].setColor(0.2, 0, 0);
            a[4][j][k].setTransparency(0.5);
        }

    rotateX = 0;
    rotateY = 90;
}

void choose_second_side(double &rotateX, double &rotateY)
{
    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }
    for (auto &j : a)
        for (int k = 0; k < 5; k++)
        {
            j[4][k].setColor(0, 0.2, 0);
            j[4][k].setTransparency(0.5);
        }
    rotateX = -90;
    rotateY = 180;
}

void choose_third_side(double &rotateX, double &rotateY)
{
    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }
    for (int j = 0; j < 5; j++)
        for (auto &k : a)
        {
            k[j][4].setColor(0, 0, 0.2);
            k[j][4].setTransparency(0.5);
        }
    rotateX = 0;
    rotateY = 180;
}

void default_position(double &rotateX, double &rotateY)
{
    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
                k.setColor(0.5, 0.5, 0.8);
                k.setTransparency(0.11);
            }

    rotateX = 325;
    rotateY = 135;
}

void view_first_side(double &rotateX, double &rotateY)
{
    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }
    for (int j = 0; j < 5; j++)
        for (int k = 0; k < 5; k++)
        {
            a[4][j][k].setColor(1, 0, 0);
        }
    rotateX = 325;
    rotateY = 135;
}

void view_second_side(double &rotateX, double &rotateY)
{
    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }
    for (auto &j : a)
        for (int k = 0; k < 5; k++)
        {
            j[4][k].setColor(0, 1, 0);
        }
    rotateX = 325;
    rotateY = 135;
}

void view_third_side(double &rotateX, double &rotateY)
{
    for (auto &i : a)
        for (auto &j : i)
            for (auto &k : j)
            {
                k.forTransparancy = 0;
            }
    for (int j = 0; j < 5; j++)
        for (auto &k : a)
        {
            k[j][4].setColor(0, 0, 1);
        }
    rotateX = 325;
    rotateY = 135;
}


#endif //INC_3DSEEBUTTLE_CHOOSESIDE_H
