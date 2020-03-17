//
// Created by alik on 13.03.2020.
//

// по-хорошему заголовочный файл - это только описание функций, но так как OpenGL возмущается и не хочет работать
// то я напишу здесь сразу реализацию и не буду создавать .cpp файлы (незачем)


#ifndef INC_3DSEEBUTTLE_PAINTING_H
#define INC_3DSEEBUTTLE_PAINTING_H

#include "ChooseSide.h"
#include <iostream>

double rotate_y=135;  //начальный поворот куба по у
double rotate_x=325; //начальный поворот куба по х
double sizeCell = -0.05; //размеры кубиков
double stepCell = 0.1; //шаг при определении
double quantityCell = 0.5-0.25; //количестве кубиков, тоесть их всего  (quantityCell/stepCell)   #### вычел 0.4, чтобы сместить кубики и чтобы крутились вокруг центра
double transparency = 0.3; //прозрачность кубиков
double r = 0.5, g = 0.5, b = 0.5;
double red = 1, green = 1, blue = 0;
//функция рисует 3Д кубики на экране
bool show_first_cube = true; //определяет поле игрока
bool show_second_cube = false;

float i_min = -1, i_max = 1, j_min = -1, j_max = 1, y_min = -1, y_max = 1;

float& r_i_min = i_min;
float& r_j_min = j_min;
float& r_y_min = y_min;
float& r_i_max = i_max;
float& r_j_max = j_max;
float& r_y_max = y_max;
double& r_r = r;
double& r_g = g;
double& r_b = b;
double& r_rotate_x = rotate_x;
double& r_rotate_y = rotate_y;

////////////////////////////////////////////////////////////////////////
////////////////переходим к плоскому виду///////////////////////////////
////////////////////////////////////////////////////////////////////////

void displayCell() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //очищаем экран, чтобы картинки "не размножались"
    glLoadIdentity();
    glRotatef(rotate_x, 1.0, 0.0, 0.0);  //функция, поворачивающая кубики по х
    glRotatef(rotate_y, 0.0, 1.0, 0.0);  //а это для у

    glEnable(GL_ALPHA_TEST); //включаем прозрачность
    glEnable(GL_BLEND);  //разрешаем мешать цвета
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  //устанавдиваем уровень прозрачности - пока до конца не разобрался

    if (show_first_cube == true) {
        red = r;
        green = g;
        blue = b;
        for (float i = -0.25; i < quantityCell; i += stepCell)  //опять же начинаю с -0.25  ### это чтобы сместить кубики и чтобы крутились вокруг центра
        {
            for (float j = -0.25; j < quantityCell; j += stepCell)  //аналогия
            {
                for (float y = -0.25; y < quantityCell; y += stepCell)   //аналогия
                {
                    //std::cout<<y;
                    if ((i > i_min && i < i_max) && (j > j_min && j < j_max) && (y > y_min && y < y_max)) {

                        glBegin(GL_POLYGON);  //начинаем рисовать грань
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);  //здесь и далее сначала цвет
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i, sizeCell + j,-sizeCell + y);  //(красный, зеленый, синий, прозрачность)
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);  //потом идет положение точки
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);  //4 точки - 1 грань
                        glEnd();  //закончили рисовать одну грань

                        glBegin(GL_POLYGON);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i, sizeCell + j, -sizeCell + y);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i, sizeCell + j, -sizeCell + y);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glEnd();

                        //пошли ребра
                        glBegin(GL_LINES);  //начинаем рисовать рёбра
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);  //здесь и далее сначала цвет
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, sizeCell + j,-sizeCell + y);  //(красный, зеленый, синий, прозрачность)
                        glEnd();  //одно ребро
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, sizeCell + j,-sizeCell + y);  //(красный, зеленый, синий, прозрачность)
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);  //потом идет положение точки
                        glEnd();  //второе ребро
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);  //потом идет положение точки
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);  //4 точки - 1 грань
                        glEnd();  //третье ребро
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);  //4 точки - 1 грань
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);  //здесь и далее сначала цвет
                        glEnd();  //четвёртое ребро

                        //следующая грань
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
                        glEnd();

                        //следующая
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, sizeCell + j, -sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, sizeCell + j, -sizeCell + y);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
                        glEnd();

                        //ещё одна
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glEnd();

                        //немного осталось
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, sizeCell + j, -sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, sizeCell + j, -sizeCell + y);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
                        glEnd();

                        //последняя
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glEnd();

                    } else {
                        glBegin(GL_POLYGON);  //начинаем рисовать грань
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);  //здесь и далее сначала цвет
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i, sizeCell + j,
                                   -sizeCell + y);  //(красный, зеленый, синий, прозрачность)
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);  //потом идет положение точки
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);  //4 точки - 1 грань
                        glEnd();  //закончили рисовать одну грань

                        glBegin(GL_POLYGON);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i, sizeCell + j, -sizeCell + y);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i, sizeCell + j, -sizeCell + y);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glEnd();

                        //пошли ребра
                        glBegin(GL_LINES);  //начинаем рисовать рёбра
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);  //здесь и далее сначала цвет
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, sizeCell + j,
                                   -sizeCell + y);  //(красный, зеленый, синий, прозрачность)
                        glEnd();  //одно ребро
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, sizeCell + j,
                                   -sizeCell + y);  //(красный, зеленый, синий, прозрачность)
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);  //потом идет положение точки
                        glEnd();  //второе ребро
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);  //потом идет положение точки
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);  //4 точки - 1 грань
                        glEnd();  //третье ребро
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);  //4 точки - 1 грань
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);  //здесь и далее сначала цвет
                        glEnd();  //четвёртое ребро

                        //следующая грань
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
                        glEnd();

                        //следующая
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, sizeCell + j, -sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, sizeCell + j, -sizeCell + y);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
                        glEnd();

                        //ещё одна
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glEnd();

                        //немного осталось
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, sizeCell + j, -sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, sizeCell + j, -sizeCell + y);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, sizeCell + j, -sizeCell + y);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, sizeCell + j, sizeCell + y);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, sizeCell + j, sizeCell + y);
                        glEnd();

                        //последняя
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, -sizeCell + j, sizeCell + y);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, -sizeCell + j, sizeCell + y);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i, -sizeCell + j, -sizeCell + y);
                        glEnd();
                    }

                }
            }
        }
    }

    else if (show_second_cube == true) {
        r = 0;
        g = 0;
        b = 1;
        for (float i2 = -0.25; i2 < quantityCell; i2 += stepCell)  //опять же начинаю с -0.25  ### это чтобы сместить кубики и чтобы крутились вокруг центра
        {
            for (float j2 = -0.25; j2 < quantityCell; j2 += stepCell)  //аналогия
            {
                for (float y2 = -0.25; y2 < quantityCell; y2 += stepCell)   //аналогия
                {
                    //std::cout<<y;
                    if (i2 > -0.26 && i2 < 0 && j2 > -0.06 && j2 < 0 && y2 > -0.26 && y2 < 0) {
                    //if (i2 == 0.1) {
                        glBegin(GL_POLYGON);  //начинаем рисовать грань
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, -sizeCell + y2);  //здесь и далее сначала цвет
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i2, sizeCell + j2,-sizeCell + y2);  //(красный, зеленый, синий, прозрачность)
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, -sizeCell + y2);  //потом идет положение точки
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, -sizeCell + y2);  //4 точки - 1 грань
                        glEnd();  //закончили рисовать одну грань

                        glBegin(GL_POLYGON);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glColor4f(r, g, b, transparency);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glEnd();

                        //пошли ребра
                        glBegin(GL_LINES);  //начинаем рисовать рёбра
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, -sizeCell + y2);  //здесь и далее сначала цвет
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, sizeCell + j2,-sizeCell + y2);  //(красный, зеленый, синий, прозрачность)
                        glEnd();  //одно ребро
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, sizeCell + j2,-sizeCell + y2);  //(красный, зеленый, синий, прозрачность)
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, -sizeCell + y2);  //потом идет положение точки
                        glEnd();  //второе ребро
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, -sizeCell + y2);  //потом идет положение точки
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, -sizeCell + y2);  //4 точки - 1 грань
                        glEnd();  //третье ребро
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, -sizeCell + y2);  //4 точки - 1 грань
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, -sizeCell + y2);  //здесь и далее сначала цвет
                        glEnd();  //четвёртое ребро

                        //следующая грань
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glEnd();

                        //следующая
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glEnd();

                        //ещё одна
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glEnd();

                        //немного осталось
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glEnd();

                        //последняя
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(r, g, b);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glColor3f(r, g, b);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glEnd();

                    } else {
                        glBegin(GL_POLYGON);  //начинаем рисовать грань
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, -sizeCell + y2);  //здесь и далее сначала цвет
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i2, sizeCell + j2,
                                   -sizeCell + y2);  //(красный, зеленый, синий, прозрачность)
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, -sizeCell + y2);  //потом идет положение точки
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, -sizeCell + y2);  //4 точки - 1 грань
                        glEnd();  //закончили рисовать одну грань

                        glBegin(GL_POLYGON);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glEnd();

                        glBegin(GL_POLYGON);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glColor4f(0.5, 0.5, 0.5, transparency);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glEnd();

                        //пошли ребра
                        glBegin(GL_LINES);  //начинаем рисовать рёбра
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, -sizeCell + y2);  //здесь и далее сначала цвет
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, sizeCell + j2,
                                   -sizeCell + y2);  //(красный, зеленый, синий, прозрачность)
                        glEnd();  //одно ребро
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, sizeCell + j2,
                                   -sizeCell + y2);  //(красный, зеленый, синий, прозрачность)
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, -sizeCell + y2);  //потом идет положение точки
                        glEnd();  //второе ребро
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, -sizeCell + y2);  //потом идет положение точки
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, -sizeCell + y2);  //4 точки - 1 грань
                        glEnd();  //третье ребро
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, -sizeCell + y2);  //4 точки - 1 грань
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, -sizeCell + y2);  //здесь и далее сначала цвет
                        glEnd();  //четвёртое ребро

                        //следующая грань
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glEnd();

                        //следующая
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glEnd();

                        //ещё одна
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glEnd();

                        //немного осталось
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, -sizeCell + y2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, sizeCell + j2, sizeCell + y2);
                        glEnd();

                        //последняя
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, sizeCell + y2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glEnd();
                        glBegin(GL_LINES);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glColor3f(0.5, 0.5, 0.5);
                        glVertex3f(-sizeCell + i2, -sizeCell + j2, -sizeCell + y2);
                        glEnd();
                    }

                }
            }
        }
    }

        glFlush();
        glutSwapBuffers();
    }


void changeSize(int w, int h)
{
    if (h == 0)
        h=1;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float ratio = w/(float)h;
    if (w<=h)
        glOrtho (-1,1,-1/ratio, 1/ratio, 1,-1);
    else
        glOrtho (-1*ratio,1*ratio, -1,1,1,-1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


/////////////////////////////////////////////////////////////////


#endif //INC_3DSEEBUTTLE_PAINTING_H