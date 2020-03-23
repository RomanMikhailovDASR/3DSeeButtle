//
// Created by xaero on 17.03.2020.
//

#ifndef INC_3DSEEBUTTLE_WORKWITHKEYS_H
#define INC_3DSEEBUTTLE_WORKWITHKEYS_H

#include "ChooseSide.h"

//функция взаимодействия с клавиатурой
void Keyboard(unsigned char key, int x, int y)
{
    if (key == 13 && forEnter == 1)
    {
        if (firstSide)
        {
            choose_first_side(r_rotate_x, r_rotate_y);
            a[4][4][4].setColor(1, 0, 0);
        } else if (secondSide)
        {
            choose_second_side(r_rotate_x, r_rotate_y);
            a[0][4][4].setColor(0, 1, 0);
        } else if (thirdSide)
        {
            choose_third_side(r_rotate_x, r_rotate_y);
            a[0][4][4].setColor(0, 0, 1);
        }
        forEnter = 2;
    }

    if (key == 27)
    {
        forEnter--;
        if (forEnter < 0)
            forEnter = 0;
        default_position(r_rotate_x, r_rotate_y);
        firstSide = false;
        secondSide = false;
        thirdSide = false;
    }


    glutPostRedisplay(); //а это просто обязательная функция
}

void specialKeys(int key, int x, int y)
{

    if (key == GLUT_KEY_RIGHT && forEnter <= 1) //если нажата клавиша "вправо", то поворачиваем
        rotate_y += 5;

    else if (key == GLUT_KEY_LEFT && forEnter <= 1)  //аналогично для левой клавиши
        rotate_y -= 5;

    else if (key == GLUT_KEY_UP && forEnter <= 1)  //это уже повороты  вверх и вниз
        rotate_x += 5;

    else if (key == GLUT_KEY_DOWN && forEnter <= 1)
        rotate_x -= 5;

    else if (key == GLUT_KEY_HOME && forEnter <= 1)
    {
        default_position(r_rotate_x, r_rotate_y);
    }

    if (key == GLUT_KEY_F7)
    {
        view_first_side(r_rotate_x, r_rotate_y);
        forEnter = 1;
        firstSide = true;
        thirdSide = false;
        secondSide = false;
    } else if (key == GLUT_KEY_F8)
    {
        view_second_side(r_rotate_x, r_rotate_y);
        forEnter = 1;
        secondSide = true;
        firstSide = false;
        thirdSide = false;
    } else if (key == GLUT_KEY_F9)
    {
        view_third_side(r_rotate_x, r_rotate_y);
        forEnter = 1;
        thirdSide = true;
        firstSide = false;
        secondSide = false;
    }

     if (key == GLUT_KEY_RIGHT && forEnter == 2) //если нажата клавиша "вправо", то поворачиваем
     {

     }

     else if (key == GLUT_KEY_LEFT && forEnter == 2)  //аналогично для левой клавиши
         rotate_y -= 5;

     else if (key == GLUT_KEY_UP && forEnter == 2)  //это уже повороты  вверх и вниз
         rotate_x += 5;

     else if (key == GLUT_KEY_DOWN && forEnter == 2)
         rotate_x -= 5;


    glutPostRedisplay(); //а это просто обязательная функция
}


#endif //INC_3DSEEBUTTLE_WORKWITHKEYS_H
