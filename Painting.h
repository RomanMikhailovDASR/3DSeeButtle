//
// Created by alik on 13.03.2020.
//

// по-хорошему заголовочный файл - это только описание функций, но так как OpenGL возмущается и не хочет работать
// то я напишу здесь сразу реализацию и не буду создавать .cpp файлы (незачем)


#ifndef INC_3DSEEBUTTLE_PAINTING_H
#define INC_3DSEEBUTTLE_PAINTING_H


#include <iostream>
#include "Cube.h"


double rotate_y = 135;  //начальный поворот куба по у
double rotate_x = -35; //начальный поворот куба по х
double &r_rotate_x = rotate_x;
double &r_rotate_y = rotate_y;

bool movement = true;


Cube a[LengthBigCube][LengthBigCube][LengthBigCube];
Cube b[LengthBigCube][LengthBigCube][LengthBigCube];


void displayCell()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //очищаем экран, чтобы картинки "не размножались"
    glLoadIdentity();
    glRotatef(rotate_x, 1.0, 0.0, 0.0);  //функция, поворачивающая кубики по х
    glRotatef(rotate_y, 0.0, 1.0, 0.0);  //а это для у

    glEnable(GL_ALPHA_TEST); //включаем прозрачность
    glEnable(GL_BLEND);  //разрешаем мешать цвета
    glBlendFunc(GL_SRC_ALPHA,
                GL_ONE_MINUS_SRC_ALPHA);  //устанавдиваем уровень прозрачности - пока до конца не разобрался

    if (forOnePaint == 0)
    {
        for (int i = 0; i < LengthBigCube; i++)
            for (int j = 0; j < LengthBigCube; j++)
                for (int k = 0; k < LengthBigCube; k++)
                    if (a[i][j][k].getPaint())
                    {

                        a[i][j][k] = Cube(0.2, i / 5. - 0.4, j / 5. - 0.4, k / 5. - 0.4, 0.11);
                        a[i][j][k].setColor(0.5, 0.5, 0.8);
                        forOnePaint = 1;
                    }
    }

    for (int i = 0; i < LengthBigCube; i++)
        for (int j = 0; j < LengthBigCube; j++)
            for (int k = 0; k < LengthBigCube; k++)
            {
                a[i][j][k].paintCube();
                a[i][j][k].setTransparancyNothing();
            }

    glFlush();
    glutSwapBuffers();
}


void changeSize(int w, int h)
{
    if (h == 0)
        h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float ratio = (float) w / (float) h;
    if (w <= h)
        glOrtho(-1, 1, -1 / ratio, 1 / ratio, 1, -1);
    else
        glOrtho(-1 * ratio, 1 * ratio, -1, 1, 1, -1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

#endif //INC_3DSEEBUTTLE_PAINTING_H