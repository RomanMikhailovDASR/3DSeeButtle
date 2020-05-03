//
// Created by alik on 13.03.2020.
//

// по-хорошему заголовочный файл - это только описание функций, но так как OpenGL возмущается и не хочет работать
// то я напишу здесь сразу реализацию и не буду создавать .cpp файлы (незачем)


#ifndef INC_3DSEEBUTTLE_PAINTING_H
#define INC_3DSEEBUTTLE_PAINTING_H

#include <iostream>
#include <random>
#include "Cube.h"
#include "PaintingCubes.h"
#include <math.h>

double rotate_y = 135;  //начальный поворот куба по у
double rotate_x = 0; //начальный поворот куба по х
double &r_rotate_x = rotate_x;
double &r_rotate_y = rotate_y;

bool movement = true;
bool isPlayer1 = true;
bool forCubeA = true;

bool help = false;          // Help доступна всегда нажатием F1. Но информация для каждого случая своя:
bool hello_screen = true;   // Help во время выбора стороны
bool placing_ships = false; // Help во время расстановки кораблей

Cube a[LengthBigCube][LengthBigCube][LengthBigCube];
Cube Player1[LengthBigCube][LengthBigCube][LengthBigCube];
Cube Player2[LengthBigCube][LengthBigCube][LengthBigCube];

/*void Rotate(int value)
{
    if (forEnter != -1)
        return;
    glLoadIdentity();
    glRotatef(rotate_x, 1.0, 0.0, 0.0);  //функция, поворачивающая кубики по х
    glRotatef(rotate_y, 0.0, 1.0, 0.0);  //а это для у
    if (forEnter == -1)
        rotate_y++;
    glutPostRedisplay();
    glutTimerFunc(2, Rotate, 1);
}
*/

void renderBitmapString(    // Помещает строку в указанном месте с указанным шритом и содержимым
        float x,
        float y,
        void *font,
        char *string) {

    char *c;
    if (cos(rotate_y) == 0) {
        if (cos(rotate_x) == 0) {
            glRasterPos3f(y, 0, -x);
        } else {
            glRasterPos3f(0,y / cos(rotate_x / 57.3),-x);
        }
    } else {
        if (cos(rotate_x) == 0) {
            glRasterPos3f(x / cos(rotate_y / 57.3),0,y);
        } else {
            glRasterPos3f(x / cos(rotate_y * 3.14/180),y / cos(rotate_x * 3.14/180),0);
        }
    };

    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void displayCell()
{
    if (forEnter == -1)
        glClearColor(0.07, 0.07, 0.25, 0.f);  //меняем цвет фона

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //очищаем экран, чтобы картинки "не размножались"

    glLoadIdentity();
    glRotatef(rotate_x, 1.0, 0.0, 0.0);  //функция, поворачивающая кубики по х
    glRotatef(rotate_y, 0.0, 1.0, 0.0);  //а это для у

    glEnable(GL_ALPHA_TEST); //включаем прозрачность
    glEnable(GL_BLEND);  //разрешаем мешать цвета
    glBlendFunc(GL_SRC_ALPHA,
                GL_ONE_MINUS_SRC_ALPHA);  //устанавливаем уровень прозрачности - пока до конца не разобрался

    if (hello_screen)
    {
        glColor3d(1,1,1);
        renderBitmapString(-0.5,0,GLUT_BITMAP_TIMES_ROMAN_24,"Press F1 for help");
    }

    if (help)
    {
        glColor3d(1,1,1);
        if (hello_screen) {
            renderBitmapString(-0.9, 0.5, GLUT_BITMAP_TIMES_ROMAN_24, "Press Right/Left to switch between sides");
            renderBitmapString(0, 0.4, GLUT_BITMAP_TIMES_ROMAN_24, "Press Enter to choose");
        } else {
            if (placing_ships) {
                renderBitmapString(0.5,0, GLUT_BITMAP_TIMES_ROMAN_24, "Press Arrows to rotate the cube");
                renderBitmapString(0.5,0.5, GLUT_BITMAP_TIMES_ROMAN_24, "Press F7/F8/F9 to choose face");
            } else {
                renderBitmapString(0,0, GLUT_BITMAP_TIMES_ROMAN_24, "Not ready yet");
            }
        }
    }

    if (forOnePaint == 0 && (forEnter == 0))
    {
        for (int i = 0; i < LengthBigCube; i++)
            for (int j = 0; j < LengthBigCube; j++)
                for (int k = 0; k < LengthBigCube; k++)
                {
                    Player1[i][j][k] = Cube(1.1 / (LengthBigCube),
                                            i * 1.1 / LengthBigCube - LengthBigCube * 0.55 / LengthBigCube +
                                            0.55 / LengthBigCube,
                                            j * 1.1 / LengthBigCube - LengthBigCube * 0.55 / LengthBigCube +
                                            0.55 / LengthBigCube,
                                            k * 1.1 / LengthBigCube - LengthBigCube * 0.55 / LengthBigCube +
                                            0.55 / LengthBigCube, 0.11);

                    Player1[i][j][k].setColor(0.5, 0.5, 0.8);
                    Player2[i][j][k] = Cube(1.1 / (LengthBigCube),
                                            i * 1.1 / LengthBigCube - LengthBigCube * 0.55 / LengthBigCube +
                                            0.55 / LengthBigCube,
                                            j * 1.1 / LengthBigCube - LengthBigCube * 0.55 / LengthBigCube +
                                            0.55 / LengthBigCube,
                                            k * 1.1 / LengthBigCube - LengthBigCube * 0.55 / LengthBigCube +
                                            0.55 / LengthBigCube, 0.11);

                    Player2[i][j][k].setColor(0.5, 0.5, 0.8);
                    forOnePaint = 1;
                    forCubeA = true;
                }
    }
    if (forCubeA)
    {
        for (int i = 0; i < LengthBigCube; i++)
            for (int j = 0; j < LengthBigCube; j++)
                for (int k = 0; k < LengthBigCube; k++)
                {
                    if (isPlayer1)
                        a[i][j][k] = &Player1[i][j][k];
                    else a[i][j][k] = &Player2[i][j][k];
                    forCubeA = false;
                }
    }


    if (forOnePaint == 0 && (forEnter == -1 || forTwoPlayers == 2))
    {
        for (int i = 0; i < LengthBigCube; i++)
            for (int j = 0; j < LengthBigCube; j++)
                for (int k = 0; k < LengthBigCube; k++)
                {
                    Player1[i][j][k].changeCube(1.1 / (LengthBigCube * 1.4),
                                                i * 1.1 / (LengthBigCube * 1.4) - 0.55 + 0.55 / (LengthBigCube * 1.4) +
                                                0.95,
                                                j * 1.1 / (LengthBigCube * 1.4) - 0.55 + 0.55 / (LengthBigCube * 1.4) +
                                                0.5,
                                                k * 1.1 / (LengthBigCube * 1.4) - 0.55 + 0.55 / (LengthBigCube * 1.4),
                                                0.11);

                    Player2[i][j][k].changeCube(1.1 / (LengthBigCube * 1.4),
                                                i * 1.1 / (LengthBigCube * 1.4) - 0.55 + 0.55 / (LengthBigCube * 1.4) -
                                                0.25,
                                                j * 1.1 / (LengthBigCube * 1.4) - 0.55 + 0.55 / (LengthBigCube * 1.4) +
                                                0.28,
                                                k * 1.1 / (LengthBigCube * 1.4) - 0.55 + 0.55 / (LengthBigCube * 1.4) +
                                                0.785,
                                                0.11);
                    if (!forTwoPlayers)
                    {
                        Player1[i][j][k].setColor(1, 0, 0);
                        Player2[i][j][k].setColor(1, 1, 1);
                    }
                    forOnePaint = 1;
                }
    }
    if (forTwoPlayers < 2)
        for (auto &i : a)
            for (auto &j : i)
                for (auto &k : j)
                {
                    if (k.getHit() == 1)
                    {
                        k.setColor(0, 1, 0); // выбранные корабли закрашиваем зеленым
                    }
                    if (k.getPaint())
                    {
                        k.paintCube();
                        if (forEnter != -1 && k.getHit() != 1)
                            k.setTransparancyNothing();
                    }

                }


    if (forEnter == -1 || forTwoPlayers == 2)
        for (auto &i : Player2)
            for (auto &j : i)
                for (auto &k : j)
                {
                    if (k.getHit() == 3)
                    {
                        k.setColor(0, 0, 1);
                        k.setTransparency(1);
                    }
                    if (k.getHit() == 4)
                    {
                        k.setColor(1, 0, 0);
                        k.setTransparency(1);
                    }
                    k.paintCube();
                }

    if (forEnter == -1 || forTwoPlayers == 2)
        for (auto &i : Player1)
            for (auto &j : i)
                for (auto &k : j)
                {
                    if (k.getHit() == 3)
                    {
                        k.setColor(0, 0, 1);
                        k.setTransparency(1);
                    }
                    if (k.getHit() == 4)
                    {
                        k.setColor(1, 0, 0);
                        k.setTransparency(1);
                    }
                    k.paintCube();
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