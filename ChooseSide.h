//
// Created by xaero on 17.03.2020.
//

#ifndef INC_3DSEEBUTTLE_CHOOSESIDE_H
#define INC_3DSEEBUTTLE_CHOOSESIDE_H


#include "Cube.h"
#include "Painting.h"



void choose_first_side (double& r_rotate_x, double& r_rotate_y) {

    for (int i = 0; i < LengthBigCube; i++)
        for (int j = 0; j < LengthBigCube; j++)
            for (int k = 0; k < LengthBigCube; k++)
            {
                a[i][j][k].forTransparancy = 0;
            }
    for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
            {
                a[4][j][k].setColor(1, 0, 0);
                a[4][j][k].setTransparency(0.5);
            }

    r_rotate_x = -180;
    r_rotate_y = -90;
}

void choose_second_side (double& r_rotate_x, double& r_rotate_y) {
    for (int i = 0; i < LengthBigCube; i++)
        for (int j = 0; j < LengthBigCube; j++)
            for (int k = 0; k < LengthBigCube; k++)
            {
                a[i][j][k].forTransparancy = 0;
            }
    for (int j = 0; j < 5; j++)
        for (int k = 0; k < 5; k++)
        {
            a[j][4][k].setColor(0, 1, 0);
            a[j][4][k].setTransparency(0.5);
        }
    r_rotate_x = -90;
    r_rotate_y = 270;
}

void choose_third_side (double& r_rotate_x, double& r_rotate_y) {
    for (int i = 0; i < LengthBigCube; i++)
        for (int j = 0; j < LengthBigCube; j++)
            for (int k = 0; k < LengthBigCube; k++)
            {
                a[i][j][k].forTransparancy = 0;
            }
    for (int j = 0; j < 5; j++)
        for (int k = 0; k < 5; k++)
        {
            a[k][j][4].setColor(0, 0, 1);
            a[k][j][4].setTransparency(0.5);
        }
    r_rotate_x = -180;
    r_rotate_y = 0;
}

void default_position (double& r_rotate_x, double& r_rotate_y) {
    for (int i = 0; i < LengthBigCube; i++)
        for (int j = 0; j < LengthBigCube; j++)
            for (int k = 0; k < LengthBigCube; k++)
            {
                a[i][j][k].forTransparancy = 0;
            }

    r_rotate_x = 325;
    r_rotate_y = 135;
}

void view_first_side (double& r_rotate_x, double& r_rotate_y) {
    for (int i = 0; i < LengthBigCube; i++)
        for (int j = 0; j < LengthBigCube; j++)
            for (int k = 0; k < LengthBigCube; k++)
            {
                a[i][j][k].forTransparancy = 0;
            }
    for (int j = 0; j < 5; j++)
        for (int k = 0; k < 5; k++)
        {
            a[4][j][k].setColor(1, 0, 0);
        }
    r_rotate_x = 325;
    r_rotate_y = 135;
}

void view_second_side (double& r_rotate_x, double& r_rotate_y) {
    for (int i = 0; i < LengthBigCube; i++)
        for (int j = 0; j < LengthBigCube; j++)
            for (int k = 0; k < LengthBigCube; k++)
            {
                a[i][j][k].forTransparancy = 0;
            }
    for (int j = 0; j < 5; j++)
        for (int k = 0; k < 5; k++)
        {
            a[j][4][k].setColor(0, 1, 0);
        }
    r_rotate_x=325;
    r_rotate_y=135;
}

void view_third_side (double& r_rotate_x, double& r_rotate_y) {
    for (int i = 0; i < LengthBigCube; i++)
        for (int j = 0; j < LengthBigCube; j++)
            for (int k = 0; k < LengthBigCube; k++)
            {
                a[i][j][k].forTransparancy = 0;
            }
    for (int j = 0; j < 5; j++)
        for (int k = 0; k < 5; k++)
        {
            a[k][j][4].setColor(0, 0, 1);
        }
    r_rotate_x=325;
    r_rotate_y=135;
}


#endif //INC_3DSEEBUTTLE_CHOOSESIDE_H
