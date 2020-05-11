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
#include <cstdio>   // Эта штука переводит числа в строки

double rotate_y = 135;  //начальный поворот куба по у
double rotate_x = -35; //начальный поворот куба по х
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

void renderBitmapString(float x, float y, void *font, char *string)
{                        // Помещает строку в указанном месте с указанным шрифтом и содержимым
    char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void displayCell()
{
    if (end1)
        glClearColor(135 / 256., 206 / 256., 250 / 256., 0.f);  //меняем цвет фона
    if (end2)
        glClearColor(10 / 256., 254 / 256., 189 / 256., 0.f);  //меняем цвет фона
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
        glColor3d(1, 1, 1);
        renderBitmapString(0.22, 0.9, GLUT_BITMAP_TIMES_ROMAN_24, "Press F1 for help");
    }

    if (help)
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(1, 1, 1, 1);  //Для написания помощи временно делаем проекцию 2D
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        //glClearColor(1,1,1,0);
        glColor3d(1, 1, 1);

        if (hello_screen)
        {
            renderBitmapString(-0.9, 0.8, GLUT_BITMAP_TIMES_ROMAN_24, "Press Right/Left to switch between sides");
            renderBitmapString(-0.9, 0.65, GLUT_BITMAP_TIMES_ROMAN_24, "Press Enter to choose");
        } else
        {
            if (placing_ships)
            {
                renderBitmapString(-0.9, 0.8, GLUT_BITMAP_TIMES_ROMAN_24, "Press Arrows to rotate the cube");
                renderBitmapString(-0.9, 0.65, GLUT_BITMAP_TIMES_ROMAN_24, "Press F7/F8/F9 to choose face");
            } else
            {
                renderBitmapString(0, 0, GLUT_BITMAP_TIMES_ROMAN_24, "Not ready yet");
            }
        }
    } else
    {        // После отключения справки возвращаемся в 3D
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-1.5, 1.5, -1, 1, 1, -1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        //glClearColor(0.07, 0.07, 0.25, 0.f);  //меняем цвет фона, чтобы картинки "не размножались")
        glRotatef(rotate_x, 1.0, 0.0, 0.0);  //функция, поворачивающая кубики по х
        glRotatef(rotate_y, 0.0, 1.0, 0.0);  //а это для у
    }

    if (forOnePaint == 0 && (forEnter == 0 && forTwoPlayers != 2))
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

                    Player1[i][j][k].setColor(135 / 256., 206 / 256., 250 / 256.);
                    Player2[i][j][k] = Cube(1.1 / (LengthBigCube),
                                            i * 1.1 / LengthBigCube - LengthBigCube * 0.55 / LengthBigCube +
                                            0.55 / LengthBigCube,
                                            j * 1.1 / LengthBigCube - LengthBigCube * 0.55 / LengthBigCube +
                                            0.55 / LengthBigCube,
                                            k * 1.1 / LengthBigCube - LengthBigCube * 0.55 / LengthBigCube +
                                            0.55 / LengthBigCube, 0.11);

                    Player2[i][j][k].setColor(10 / 256., 254 / 256., 189 / 256.);
                    forOnePaint = 1;
                    forCubeA = true;
                }
    }
    if (forCubeA && forTwoPlayers < 2)
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
                                                0.6,
                                                j * 1.1 / (LengthBigCube * 1.4) - 0.55 + 0.55 / (LengthBigCube * 1.4) +
                                                0.15,
                                                k * 1.1 / (LengthBigCube * 1.4) - 0.55 + 0.55 / (LengthBigCube * 1.4) -
                                                0.35,
                                                0.11);

                    Player2[i][j][k].changeCube(1.1 / (LengthBigCube * 1.4),
                                                i * 1.1 / (LengthBigCube * 1.4) - 0.55 + 0.55 / (LengthBigCube * 1.4) -
                                                0.25,
                                                j * 1.1 / (LengthBigCube * 1.4) - 0.55 + 0.55 / (LengthBigCube * 1.4) +
                                                0.28,
                                                k * 1.1 / (LengthBigCube * 1.4) - 0.55 + 0.55 / (LengthBigCube * 1.4) +
                                                0.785,
                                                0.11);
                    if (forTwoPlayers == 2 || forTwoPlayers == 0)
                    {
                        Player1[i][j][k].setColor(135 / 256., 206 / 256., 250 / 256.);
                        Player2[i][j][k].setColor(10 / 256., 254 / 256., 189 / 256.);
                    }
                    forOnePaint = 1;
                }
    }
    if (forTwoPlayers < 2)
        for (auto &i : a)
            for (auto &j : i)
                for (auto &k : j)
                {
                    if (forEnter > 3 && k.getHit() == 2)
                        k.setPaint(false);
                    if (k.getHit() == 1 && !k.getRed())
                    {
                        k.setColor(0, 1, 0); // выбранные корабли закрашиваем зеленым
                    }

                    if (k.getPaint() && !help)
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
                    if (space)
                    {
                        if (k.getHit() == 1)
                            k.setColor(0, 1, 0);
                    }
                    if (k.getHit() == 3 && !k.getRed())
                    {
                        k.setColor(0, 0, 1);
                        k.setTransparency(0.15);
                    }
                    if (k.getHit() == 4 && !k.getRed())
                    {
                        k.setColor(1, 0, 0);
                        k.setTransparency(0.35);
                    }
                    if (k.getPaint())
                    {
                        k.paintCube();
                        k.setTransparancyNothing();
                    }
                }

    if (forEnter == -1 || forTwoPlayers == 2)
        for (auto &i : Player1)
            for (auto &j : i)
                for (auto &k : j)
                {
                    if (space)
                    {
                        if (k.getHit() == 1)
                            k.setColor(0, 1, 0);
                    }
                    if (k.getHit() == 3 && !k.getRed())
                    {
                        k.setColor(0, 0, 1);
                        k.setTransparency(0.15);
                    }
                    if (k.getHit() == 4 && !k.getRed())
                    {
                        k.setColor(1, 0, 0);
                        k.setTransparency(0.4);
                    }
                    if (k.getPaint())
                    {
                        k.paintCube();
                        k.setTransparancyNothing();
                    }
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
