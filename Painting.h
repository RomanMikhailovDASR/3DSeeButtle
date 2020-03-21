//
// Created by alik on 13.03.2020.
//

// по-хорошему заголовочный файл - это только описание функций, но так как OpenGL возмущается и не хочет работать
// то я напишу здесь сразу реализацию и не буду создавать .cpp файлы (незачем)


#ifndef INC_3DSEEBUTTLE_PAINTING_H
#define INC_3DSEEBUTTLE_PAINTING_H

#include "ChooseSide.h"
#include <iostream>
#include "Cube.h"

double rotate_y=135;  //начальный поворот куба по у
double rotate_x=325; //начальный поворот куба по х

double red = 0.5, green = 0.8, blue = 0.5;

float i_min = -1, i_max = 1, j_min = -1, j_max = 1, y_min = -1, y_max = 1;

float& r_i_min = i_min;
float& r_j_min = j_min;
float& r_y_min = y_min;
float& r_i_max = i_max;
float& r_j_max = j_max;
float& r_y_max = y_max;
double& r_r = red;
double& r_g = green;
double& r_b = blue;
double& r_rotate_x = rotate_x;
double& r_rotate_y = rotate_y;

void displayCell() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //очищаем экран, чтобы картинки "не размножались"
    glLoadIdentity();
    glRotatef(rotate_x, 1.0, 0.0, 0.0);  //функция, поворачивающая кубики по х
    glRotatef(rotate_y, 0.0, 1.0, 0.0);  //а это для у

    glEnable(GL_ALPHA_TEST); //включаем прозрачность
    glEnable(GL_BLEND);  //разрешаем мешать цвета
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  //устанавдиваем уровень прозрачности - пока до конца не разобрался

    Cube a[5][5][5];
    for (int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                a[i][j][k] = Cube(0.2, i / 5. - 0.4, j / 5. - 0.4, k / 5. - 0.4, red, blue, green, 0.11);
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

#endif //INC_3DSEEBUTTLE_PAINTING_H