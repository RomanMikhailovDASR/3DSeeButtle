//
// Created by xaero on 17.03.2020.
//

#ifndef INC_3DSEEBUTTLE_WORKWITHKEYS_H
#define INC_3DSEEBUTTLE_WORKWITHKEYS_H

#include "ChooseSide.h"

//введем координаты кубиков, которые подкрашиваются первыми при выборе фронтального вида
int i_first_side = 4, j_first_side = 0, k_first_side = 0;
int i_second_side = 4, j_second_side = 4, k_second_side = 4;
int i_third_side = 4, j_third_side = 0, k_third_side = 4;
int y1 = j_first_side, z1 = k_first_side;
int x2 = i_second_side, z2 = k_second_side;
int x3 = i_third_side, y3 = j_third_side;
bool forProbel = false; //защита от дурака (так себе защита, разве уж совсем дурак попадется)
int p1 = 0, p2 = 0, p3 = 0;

//функция взаимодействия с клавиатурой
void Keyboard(unsigned char key, int x, int y)
{
    if (key == 13)
    {
        if (firstSide)
        {
            choose_first_side(r_rotate_x, r_rotate_y);
            a[4][0][0].setColor(1, 0, 0);
        } else if (secondSide)
        {
            choose_second_side(r_rotate_x, r_rotate_y);
            a[4][4][4].setColor(0, 1, 0);
        } else if (thirdSide)
        {
            choose_third_side(r_rotate_x, r_rotate_y);
            a[4][0][4].setColor(0, 0, 1);
        }
        forEnter = 2;
        movement = false;
    }

    if (key == 32) {
        forProbel = true;
        movement = true;
        for (int i = 0; i < LengthBigCube; i++)
            for (int j = 0; j < LengthBigCube; j++)
                for (int k = 0; k < LengthBigCube; k++)
                {
                    a[i][j][k].setColor(0.5, 0.5, 0.8);
                    a[i][j][k].setTransparency(0.1);
                }

        if (firstSide) {
            for (int i = 0; i < LengthBigCube; i++)
                a[i][y1][z1].setColor(1, 1, 0);
            a[0][y1][z1].setTransparency(1);
            r_rotate_x = 325;
            r_rotate_y = 135;
        }

        else if (secondSide) {
            for (int j = 0; j < LengthBigCube; j++)
                a[x2][j][z2].setColor(1, 1, 0);
            a[x2][0][z2].setTransparency(1);
            r_rotate_x = 325;
            r_rotate_y = 135;
        }

        else if (thirdSide) {
            for (int k = 0; k < LengthBigCube; k++)
                a[x3][y3][k].setColor(1, 1, 0);
            a[x3][y3][0].setTransparency(1);
            r_rotate_x = 325;
            r_rotate_y = 135;
        }
    }

    if (key == 'F' || key == 'f' || key == 'а' || key == 'А')
        {//FIRE!!! (типа пыжь пыжь и все покраснело)
            if (firstSide) {
                for(int i = 0; i < LengthBigCube; i++) {
                    a[i][y1][z1].setColor(0.5, 0.5, 0.8);
                    a[i][y1][z1].setTransparency(0.1);
                }
                a[p1][y1][z1].setColor(1, 0, 0);
                a[p1][y1][z1].setTransparency(0.5);
                a[p1][y1][z1].setIsHitten(1);
            }
            else if (secondSide) {
                for(int j = 0; j < LengthBigCube; j++) {
                    a[x2][j][z2].setColor(0.5, 0.5, 0.8);
                    a[x2][j][z2].setTransparency(0.1);
                }
                a[x2][p2][z2].setColor(1, 0, 0);
                a[x2][p2][z2].setTransparency(0.5);
                a[x2][p2][z2].setIsHitten(1);
            }
            else if (thirdSide) {
                for(int k = 0; k < LengthBigCube; k++) {
                    a[x3][y3][k].setColor(0.5, 0.5, 0.8);
                    a[x3][y3][k].setTransparency(0.1);
                }
                a[x3][y3][p3].setColor(1, 0, 0);
                a[x3][y3][p3].setTransparency(0.5);
                a[x3][y3][p3].setIsHitten(1);
            }
        }

            if (key == 27)
            {
                movement = true;
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

void ChooseColumn(int arrow) {
    if (firstSide) {
        a[4][4][4].setTransparency(0.5);
        a[4][4][4].setColor(0.2, 0.0, 0.0);


        if (arrow == 4) {//работает стрелочка вправо
            a[4][y1][z1].setTransparency(0.5);
            a[4][y1][z1].setColor(0.2, 0.0, 0.0);
            z1++;
            if (z1 > 4)
                z1 = 0;
            a[4][y1][z1].setColor(1, 0.0, 0.0);
        }

        else if (arrow == 2) {//стрелочка вверх
            a[4][y1][z1].setTransparency(0.5);
            a[4][y1][z1].setColor(0.2, 0.0, 0.0);
            y1++;
            if (y1 > 4)
                y1 = 0;
            a[4][y1][z1].setColor(1, 0.0, 0.0);
        }

        else if (arrow == 1) {//стрелочка влево
            a[4][y1][z1].setTransparency(0.5);
            a[4][y1][z1].setColor(0.2, 0.0, 0.0);
            z1--;
            if (z1 < 0)
                z1 = 4;
            a[4][y1][z1].setColor(1, 0.0, 0.0);
        }

        else if (arrow == 3) {
            a[4][y1][z1].setTransparency(0.5);
            a[4][y1][z1].setColor(0.2, 0.0, 0.0);
            y1--;
            if (y1 < 0)
                y1 = 4;
            a[4][y1][z1].setColor(1, 0.0, 0.0);

        }
    }

    else if (secondSide) {
        a[0][4][4].setTransparency(0.5);
        a[0][4][4].setColor(0.0, 0.2, 0.0);


        if (arrow == 2) {//работает стрелочка вправо
            a[x2][4][z2].setTransparency(0.5);
            a[x2][4][z2].setColor(0.0, 0.2, 0.0);
            z2--;
            if (z2 < 0)
                z2 = 4;
            a[x2][4][z2].setColor(0, 1, 0.0);
        }

        else if (arrow == 1) {//стрелочка вверх
            a[x2][4][z2].setTransparency(0.5);
            a[x2][4][z2].setColor(0.0, 0.2, 0.0);
            x2++;
            if (x2 > 4)
                x2 = 0;
            a[x2][4][z2].setColor(0, 1, 0.0);
        }

        else if (arrow == 3) {//стрелочка влево
            a[x2][4][z2].setTransparency(0.5);
            a[x2][4][z2].setColor(0.0, 0.2, 0.0);
            z2++;
            if (z2 > 4)
                z2 = 0;
            a[x2][4][z2].setColor(0, 1, 0.0);
        }

        else if (arrow == 4) {//стрелочка вниз
            a[x2][4][z2].setTransparency(0.5);
            a[x2][4][z2].setColor(0.0, 0.2, 0.0);
            x2--;
            if (x2 < 0)
                x2 = 4;
            a[x2][4][z2].setColor(0, 1, 0.0);

        }

    }

    else if (thirdSide) {
        a[0][4][4].setTransparency(0.5);
        a[0][4][4].setColor(0.0, 0.0, 0.2);


        if (arrow == 1) {//работает стрелочка вправо
            a[x3][y3][4].setTransparency(0.5);
            a[x3][y3][4].setColor(0.0, 0.0, 0.2);
            x3++;
            if (x3 > 4)
                x3 = 0;
            a[x3][y3][4].setColor(0, 0, 1);
        }

        else if (arrow == 3) {//стрелочка вверх
            a[x3][y3][4].setTransparency(0.5);
            a[x3][y3][4].setColor(0.0, 0.0, 0.2);
            y3--;
            if (y3 < 0)
                y3 = 4;
            a[x3][y3][4].setColor(0, 0, 1);
        }

        else if (arrow == 4) {//стрелочка влево
            a[x3][y3][4].setTransparency(0.5);
            a[x3][y3][4].setColor(0.0, 0.0, 0.2);
            x3--;
            if (x3 < 0)
                x3 = 4;
            a[x3][y3][4].setColor(0, 0, 1);
        }

        else if (arrow == 2) {//стрелочка вниз
            a[x3][y3][4].setTransparency(0.5);
            a[x3][y3][4].setColor(0.0, 0.0, 0.2);
            y3++;
            if (y3 > 4)
                y3 = 0;
            a[x3][y3][4].setColor(0, 0, 1);
        }
    }

}

void ChooseCube(int page) {
    if (firstSide) {
        a[p1][y1][z1].setTransparency(1);

        if (page == 1) {
            a[p1][y1][z1].setTransparency(0.2);
            p1++;
            if (p1 > 4)
                p1 = 0;
            a[p1][y1][z1].setTransparency(1);
        }
        else if (page == 2) {
            a[p1][y1][z1].setTransparency(0.2);
            p1--;
            if (p1 < 0)
                p1 = 4;
            a[p1][y1][z1].setTransparency(1);
        }
    }

    else if (secondSide) {
        a[x2][p2][z2].setTransparency(1);

        if (page == 1) {
            a[x2][p2][z2].setTransparency(0.2);
            p2++;
            if (p2 > 4)
                p2 = 0;
            a[x2][p2][z2].setTransparency(1);
        }
        else if (page == 2) {
            a[x2][p2][z2].setTransparency(0.2);
            p2--;
            if (p2 < 0)
                p2 = 4;
            a[x2][p2][z2].setTransparency(1);
        }
    }

    else if (thirdSide) {
        a[x3][y3][p3].setTransparency(1);

        if (page == 1) {
            a[x3][y3][p3].setTransparency(0.2);
            p3++;
            if (p3 > 4)
                p3 = 0;
            a[x3][y3][p3].setTransparency(1);
        }
        else if (page == 2) {
            a[x3][y3][p3].setTransparency(0.2);
            p3--;
            if (p3 < 0)
                p3 = 4;
            a[x3][y3][p3].setTransparency(1);
        }

    }
}
// 1 == left, 2 == up, 3 == down, 4 == right
void specialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT) {
        if (movement == true) {
            if (rotate_y <= 175)
                rotate_y += 5;
        }
        else
            ChooseColumn(4);
    }//если нажата клавиша "вправо", то поворачиваем

    else if (key == GLUT_KEY_LEFT) {
        if (movement == true) {
            if (rotate_y >= 95)
                rotate_y -= 5;
        }
        else
            ChooseColumn(1);
    }//аналогично для левой клавиши

    else if (key == GLUT_KEY_UP) {
        if (movement == true) {
            if (rotate_x <= -5)
                rotate_x += 5;
        }
        else
            ChooseColumn(2);
    } //это уже повороты  вверх и вниз

    else if (key == GLUT_KEY_DOWN) {
        if(movement == true) {
            if (rotate_x >= -85)
                rotate_x -= 5;
        }
        else
            ChooseColumn(3);
    }

    else if (key == GLUT_KEY_HOME && forEnter <= 1)
    {
        default_position(r_rotate_x, r_rotate_y);
    }

    else if (key == GLUT_KEY_PAGE_UP && forProbel == true) {
        ChooseCube(1);
    }

    else if (key == GLUT_KEY_PAGE_DOWN && forProbel == true) {
        ChooseCube(2);
    }


    if (key == GLUT_KEY_F7)
    {
        view_first_side(r_rotate_x, r_rotate_y);
        movement = false;
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

    /*if (key == GLUT_KEY_RIGHT && forEnter == 2) //если нажата клавиша "вправо", то поворачиваем
    {}

    else if (key == GLUT_KEY_LEFT && forEnter == 2)  //аналогично для левой клавиши
        rotate_y -= 5;

    else if (key == GLUT_KEY_UP && forEnter == 2)  //это уже повороты  вверх и вниз
        rotate_x += 5;

    else if (key == GLUT_KEY_DOWN && forEnter == 2)
        rotate_x -= 5;

   */
    glutPostRedisplay(); //а это просто обязательная функция
}


#endif //INC_3DSEEBUTTLE_WORKWITHKEYS_H