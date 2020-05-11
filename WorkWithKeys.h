//
// Created by xaero on 17.03.2020.
//

#ifndef INC_3DSEEBUTTLE_WORKWITHKEYS_H
#define INC_3DSEEBUTTLE_WORKWITHKEYS_H

#include "ChooseSide.h"

int shipsLifeFirst = 0;
int shipsLifeSecond = 0;
//введем координаты кубиков, которые подкрашиваются первыми при выборе фронтального вида
int i_first_side = LengthBigCube - 1, j_first_side = 0, k_first_side = 0;
int i_second_side = LengthBigCube - 1, j_second_side = LengthBigCube - 1, k_second_side = LengthBigCube - 1;
int i_third_side = LengthBigCube - 1, j_third_side = 0, k_third_side = LengthBigCube - 1;
int yf = j_first_side, z1 = k_first_side;
int x2 = i_second_side, z2 = k_second_side;
int x3 = i_third_side, y3 = j_third_side;
int p1 = 0, p2 = 0, p3 = 0;

int ship = LengthBigCube - 2; // счетчик для расстановки кораблей
int number_of_ships = 1; // счетчик числа кораблей с определенным кол-вом палуб (самый большой корабль всегда один)
bool correct = true; // переменная, отвечающая за честность расстановки
int saveLengthBigCube = 1; // переменная, необходимая для цикла расстановки кораблей
bool statistics = false;

//функция взаимодействия с клавиатурой
void Keyboard(unsigned char key, int x, int y)
{
    if (key == 13)
    {
        if (hello_screen)
        {
            hello_screen = false;
            placing_ships = true;
        }
    }

    if (key == 13 && forEnter == -1)
    {
        forEnter = 0;
        forOnePaint = 0;
    }
    if (key == 32)
        space = !space;
    if (key == 13 && forEnter == 1)
    {
        if (firstSide)
        {
            if (forTwoPlayers == 2)
            {
                if (isPlayer1)
                {
                    choose_first_side_Player1(r_rotate_x, r_rotate_y);
                    Player1[i_first_side][j_first_side][k_first_side].setColor(1, 1, 0);
                    Player1[i_first_side][j_first_side][k_first_side].setTransparency(0.5);
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[i][yf][z1].setColor(1, 1, 0);
                        Player1[i][yf][z1].setTransparency(0.3);
                    }
                } else
                {
                    choose_first_side_Player2(r_rotate_x, r_rotate_y);
                    Player2[i_first_side][j_first_side][k_first_side].setColor(1, 1, 0);
                    Player2[i_first_side][j_first_side][k_first_side].setTransparency(0.5);
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[i][yf][z1].setColor(1, 1, 0);
                        Player2[i][yf][z1].setTransparency(0.3);
                    }

                }
            } else
            {
                choose_first_side(r_rotate_x, r_rotate_y);
                if (a[i_first_side][j_first_side][k_first_side].getHit() == 0)
                    a[i_first_side][j_first_side][k_first_side].setColor(1, 1, 0);
                else
                {
                    a[i_first_side][j_first_side][k_first_side].setColor(255 / 255., 105 / 255., 60 / 255.);
                    a[i_first_side][j_first_side][k_first_side].setRed(true);
                }
                a[i_first_side][j_first_side][k_first_side].setPaint(true);
                a[i_first_side][j_first_side][k_first_side].setTransparency(0.5);
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    if (a[i][yf][z1].getHit() == 0)
                        a[i][yf][z1].setColor(1, 1, 0);
                    else
                    {
                        a[i][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[i][yf][z1].setPaint(true);
                        a[i][yf][z1].setRed(true);
                    }
                    a[i][yf][z1].setTransparency(0.3);
                }
            }
        } else if (secondSide)
        {
            if (forTwoPlayers == 2)
            {
                if (isPlayer1)
                {
                    choose_second_side_Player1(r_rotate_x, r_rotate_y);
                    Player1[i_second_side][j_second_side][k_second_side].setColor(1, 1, 0);
                    Player1[i_second_side][j_second_side][k_second_side].setTransparency(0.5);
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[x2][i][z2].setColor(1, 1, 0);
                        Player1[x2][i][z2].setTransparency(0.3);
                    }
                } else
                {
                    choose_second_side_Player2(r_rotate_x, r_rotate_y);
                    Player2[i_second_side][j_second_side][k_second_side].setColor(1, 1, 0);
                    Player2[i_second_side][j_second_side][k_second_side].setTransparency(0.5);
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[x2][i][z2].setColor(1, 1, 0);
                        Player2[x2][i][z2].setTransparency(0.3);
                    }

                }
            } else
            {
                choose_second_side(r_rotate_x, r_rotate_y);
                if (a[i_second_side][j_second_side][k_second_side].getHit() == 0)
                    a[i_second_side][j_second_side][k_second_side].setColor(1, 1, 0);
                else
                {
                    a[i_second_side][j_second_side][k_second_side].setColor(255 / 255., 105 / 255., 60 / 255.);
                    a[i_second_side][j_second_side][k_second_side].setRed(true);
                }
                a[i_second_side][j_second_side][k_second_side].setPaint(true);
                a[i_second_side][j_second_side][k_second_side].setTransparency(0.5);
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    if (a[x2][i][z2].getHit() == 0)
                        a[x2][i][z2].setColor(1, 1, 0);
                    else
                    {
                        a[x2][i][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x2][i][z2].setPaint(true);
                        a[x2][i][z2].setRed(true);
                    }
                    a[x2][i][z2].setTransparency(0.3);
                }
            }
        } else if (thirdSide)
        {
            if (forTwoPlayers == 2)
            {
                if (isPlayer1)
                {
                    choose_third_side_Player1(r_rotate_x, r_rotate_y);
                    Player1[i_third_side][j_third_side][k_third_side].setColor(1, 1, 0);
                    Player1[i_third_side][j_third_side][k_third_side].setTransparency(0.5);
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[x3][y3][i].setColor(1, 1, 0);
                        Player1[x3][y3][i].setTransparency(0.3);
                    }
                } else
                {
                    choose_third_side_Player2(r_rotate_x, r_rotate_y);
                    Player2[i_third_side][j_third_side][k_third_side].setColor(1, 1, 0);
                    Player2[i_third_side][j_third_side][k_third_side].setTransparency(0.5);
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[x3][y3][i].setColor(1, 1, 0);
                        Player2[x3][y3][i].setTransparency(0.3);
                    }

                }
            } else
            {
                choose_third_side(r_rotate_x, r_rotate_y);
                if (a[i_third_side][j_third_side][k_third_side].getHit() == 0)
                    a[i_third_side][j_third_side][k_third_side].setColor(1, 1, 0);
                else
                {
                    a[i_third_side][j_third_side][k_third_side].setColor(255 / 255., 105 / 255., 60 / 255.);
                    a[i_third_side][j_third_side][k_third_side].setRed(true);
                }
                a[i_third_side][j_third_side][k_third_side].setPaint(true);
                a[i_third_side][j_third_side][k_third_side].setTransparency(0.5);
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    if (a[x3][y3][i].getHit() == 0)
                        a[x3][y3][i].setColor(1, 1, 0);
                    else
                    {
                        a[x3][y3][i].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x3][y3][i].setPaint(true);
                        a[x3][y3][i].setRed(true);
                    }
                    a[x3][y3][i].setTransparency(0.3);
                }
            }
        }
        forEnter = 2;
        movement = false;
    }

    if (key == 13 && forEnter == 3)
    {
        if (forTwoPlayers == 2)
        {
            if (isPlayer1)
            {
                movement = true;
                for (auto &i : Player1)
                    for (auto &j : i)
                        for (auto &k : j)
                        {
                            k.setColor(0.5, 0.5, 0.8);
                            k.setTransparency(0.1);
                        }

                if (firstSide)
                {
                    for (auto &i : Player1)
                        i[yf][z1].setColor(1, 1, 0);
                    Player1[0][yf][z1].setTransparency(0.7);
                } else if (secondSide)
                {
                    for (int j = 0; j < LengthBigCube; j++)
                        Player1[x2][j][z2].setColor(1, 1, 0);
                    Player1[x2][0][z2].setTransparency(0.7);
                    r_rotate_x = 325;
                    r_rotate_y = 135;
                } else if (thirdSide)
                {
                    for (int k = 0; k < LengthBigCube; k++)
                        Player1[x3][y3][k].setColor(1, 1, 0);
                    Player1[x3][y3][0].setTransparency(0.7);
                    r_rotate_x = 325;
                    r_rotate_y = 135;
                }
            } else
            {
                movement = true;
                for (auto &i : Player2)
                    for (auto &j : i)
                        for (auto &k : j)
                        {
                            k.setColor(0.5, 0.5, 0.8);
                            k.setTransparency(0.1);
                        }

                if (firstSide)
                {
                    for (auto &i : Player2)
                        i[yf][z1].setColor(1, 1, 0);
                    Player2[0][yf][z1].setTransparency(0.7);
                } else if (secondSide)
                {
                    for (int j = 0; j < LengthBigCube; j++)
                        Player2[x2][j][z2].setColor(1, 1, 0);
                    Player2[x2][0][z2].setTransparency(0.7);
                    r_rotate_x = 325;
                    r_rotate_y = 135;
                } else if (thirdSide)
                {
                    for (int k = 0; k < LengthBigCube; k++)
                        Player2[x3][y3][k].setColor(1, 1, 0);
                    Player2[x3][y3][0].setTransparency(0.7);
                    r_rotate_x = 325;
                    r_rotate_y = 135;
                }
            }
        } else
        {
            movement = true;
            for (auto &i : a)
                for (auto &j : i)
                    for (auto &k : j)
                    {
                        k.setColor(0.5, 0.5, 0.8);
                        k.setTransparency(0.1);
                    }

            if (firstSide)
            {
                for (auto &i : a)
                    i[yf][z1].setColor(1, 1, 0);
                for (int i = 0; i < ship; i++)
                {
                    a[i][yf][z1].setTransparency(0.7);
                }
                r_rotate_x = 325;
                r_rotate_y = 135;
            } else if (secondSide)
            {
                for (int j = 0; j < LengthBigCube; j++)
                    a[x2][j][z2].setColor(1, 1, 0);
                for (int j = 0; j < ship; j++)
                    a[x2][j][z2].setTransparency(0.7);
                r_rotate_x = 325;
                r_rotate_y = 135;
            } else if (thirdSide)
            {
                for (int k = 0; k < LengthBigCube; k++)
                    a[x3][y3][k].setColor(1, 1, 0);
                for (int k = 0; k < ship; k++)
                    a[x3][y3][k].setTransparency(0.7);
                r_rotate_x = 325;
                r_rotate_y = 135;
            }
        }
        forEnter = 4;
    }

    if (key == 13 && forEnter == 5 && forTwoPlayers < 2)
    {//FIRE!!! (типа пыжь пыжь и все покраснело)
        correct = true;
        if (firstSide)
            for (int i1 = p1; i1 < p1 + ship; i1++)
            {
                if (a[i1][yf][z1].getHit() == 2 || a[i1][yf][z1].getHit() == 1)
                    correct = false;
            }
        else if (secondSide)
            for (int j2 = p2; j2 < p2 + ship; j2++)
            {
                if (a[x2][j2][z2].getHit() == 2 || a[x2][j2][z2].getHit() == 1)
                    correct = false;
            }
        else if (thirdSide)
            for (int k3 = p3; k3 < p3 + ship; k3++)
            {
                if (a[x3][y3][k3].getHit() == 2 || a[x3][y3][k3].getHit() == 1)
                    correct = false;
            }

        if (correct)
        {
            if (firstSide)
            {
                for (auto &i : a)
                {
                    i[yf][z1].setColor(0.5, 0.5, 0.8);
                    i[yf][z1].setTransparency(0.1);
                }
                for (int i1 = p1; i1 < p1 + ship; i1++)
                {
                    a[i1][yf][z1].setColor(0, 1, 0);
                    a[i1][yf][z1].setTransparency(0.5);
                    a[i1][yf][z1].setIsHitten(1);
                    if (isPlayer1)
                        Player1[i1][yf][z1].setIsHitten(1);
                    else Player2[i1][yf][z1].setIsHitten(1);
                    a[i1][yf][z1].setPaint(true);
                }
                for (int i = p1 - 1; i <= p1 + ship; i++)
                    for (int j = yf - 1; j <= yf + 1; j++)
                        for (int k = z1 - 1; k <= z1 + 1; k++)
                            if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                k < LengthBigCube)
                            {
                                if (a[i][j][k].getHit() != 1)
                                {
                                    a[i][j][k].setPaint(false);
                                    a[i][j][k].setIsHitten(2);
                                    if (isPlayer1)
                                        Player1[i][j][k].setIsHitten(2);
                                    else Player2[i][j][k].setIsHitten(2);
                                }
                            }
                p1 = 0;
                yf = 0;
                z1 = 0;


            } else if (secondSide)
            {
                for (int j = 0; j < LengthBigCube; j++)
                {
                    a[x2][j][z2].setColor(0.5, 0.5, 0.8);
                    a[x2][j][z2].setTransparency(0.1);
                }
                for (int j2 = p2; j2 < p2 + ship; j2++)
                {
                    a[x2][j2][z2].setColor(0, 1, 0);
                    a[x2][j2][z2].setTransparency(0.5);
                    a[x2][j2][z2].setIsHitten(1);
                    if (isPlayer1)
                        Player1[x2][j2][z2].setIsHitten(1);
                    else Player2[x2][j2][z2].setIsHitten(1);
                    a[x2][j2][z2].setPaint(true);
                }
                for (int i = x2 - 1; i <= x2 + 1; i++)
                    for (int j = p2 - 1; j <= p2 + ship; j++)
                        for (int k = z2 - 1; k <= z2 + 1; k++)
                            if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                k < LengthBigCube)
                            {
                                if (a[i][j][k].getHit() != 1)
                                {
                                    a[i][j][k].setPaint(false);
                                    a[i][j][k].setIsHitten(2);
                                    if (isPlayer1)
                                        Player1[i][j][k].setIsHitten(2);
                                    else Player2[i][j][k].setIsHitten(2);
                                }
                            }
                x2 = LengthBigCube - 1;
                p2 = 0;
                z2 = LengthBigCube - 1;

            } else if (thirdSide)
            {
                for (int k = 0; k < LengthBigCube; k++)
                {
                    a[x3][y3][k].setColor(0.5, 0.5, 0.8);
                    a[x3][y3][k].setTransparency(0.1);
                }
                for (int k3 = p3; k3 < p3 + ship; k3++)
                {
                    a[x3][y3][k3].setColor(0, 1, 0);
                    a[x3][y3][k3].setTransparency(0.5);
                    a[x3][y3][k3].setIsHitten(1);
                    if (isPlayer1)
                        Player1[x3][y3][k3].setIsHitten(1);
                    else Player2[x3][y3][k3].setIsHitten(1);
                    a[x3][y3][k3].setPaint(true);
                }
                for (int i = x3 - 1; i <= x3 + 1; i++)
                    for (int j = y3 - 1; j <= y3 + 1; j++)
                        for (int k = p3 - 1; k <= p3 + ship; k++)
                            if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                k < LengthBigCube)
                            {
                                if (a[i][j][k].getHit() != 1)
                                {
                                    a[i][j][k].setPaint(false);
                                    a[i][j][k].setIsHitten(2);
                                    if (isPlayer1)
                                        Player1[i][j][k].setIsHitten(2);
                                    else Player2[i][j][k].setIsHitten(2);
                                }
                            }
                x3 = LengthBigCube - 1;
                y3 = 0;
                p3 = 0;
            }
            forEnter = 0;
            number_of_ships--;
            if(isPlayer1)
                shipsLifeFirst++;
            else shipsLifeSecond++;
            if (number_of_ships == 0)
            {
                saveLengthBigCube++;
                ship -= 1;
                number_of_ships = saveLengthBigCube;
            }
            if (ship == 0)
            {
                forCubeA = true;
                if (isPlayer1)
                {
                    isPlayer1 = false;
                    for (auto &i : Player1)
                        for (auto &j : i)
                            for (auto &k : j)
                                k.setColor(0.5, 0.5, 0.8);
                } else
                {
                    isPlayer1 = true;
                    for (auto &i : Player2)
                        for (auto &j : i)
                            for (auto &k : j)
                                k.setColor(0.5, 0.5, 0.8);
                }
                ship = LengthBigCube - 2;
                number_of_ships = 1; // счетчик числа кораблей с определенным кол-вом палуб (самый большой корабль всегда один)
                correct = true; // переменная, отвечающая за честность расстановки
                saveLengthBigCube = 1;
                forTwoPlayers++;
                if (forTwoPlayers == 2)
                {
                    forOnePaint = 0;
                    forEnter = 0;
                    movement = true;
                }

                //DAVID FUNCTION SHOULD BE HERE !!!!!!!!
            }
        } else
        {
            forEnter = 0;
            for (auto &i : a)
                for (auto &j : i)
                    for (auto &k : j)
                    {
                        if (k.getHit() != 2 && k.getHit() != 1)
                            k.setTransparency(0.1);
                        k.setColor(0.5, 0.5, 0.8);
                    }
        }
        correct = true;
        for (auto &i : a)
            for (auto &j : i)
                for (auto &k : j)
                    k.setTransparency(0.11);
    }

    if (key == 13 && forEnter == 5 && forTwoPlayers == 2)
    {//FIRE!!! (типа пыжь пыжь и все покраснело)
        if (isPlayer1)
        {
            if (firstSide && (Player1[p1][yf][z1].getHit() == 0 || Player1[p1][yf][z1].getHit() == 2))
            {

                for (auto &i : Player1)
                {
                    i[yf][z1].setColor(0.5, 0.5, 0.8);
                    i[yf][z1].setTransparency(0.11);
                }

                Player1[p1][yf][z1].setColor(0, 0, 1);
                Player1[p1][yf][z1].setTransparency(0.35);
                Player1[p1][yf][z1].setIsHitten(3);
                isPlayer1 = false;

            } else if (firstSide && Player1[p1][yf][z1].getHit() == 1)
            {
                for (auto &i : Player1)
                {
                    i[yf][z1].setColor(0.5, 0.5, 0.8);
                    i[yf][z1].setTransparency(0.11);
                }

                Player1[p1][yf][z1].setColor(1, 0, 0);
                Player1[p1][yf][z1].setTransparency(0.35);
                Player1[p1][yf][z1].setIsHitten(4);

                bool hit = true;
                if (p1 - 1 >= 0)
                    if (Player1[p1 - 1][yf][z1].getHit() == 1)
                        hit = false;
                if (p1 + 1 < LengthBigCube)
                    if (Player1[p1 + 1][yf][z1].getHit() == 1)
                        hit = false;
                if (yf - 1 >= 0)
                    if (Player1[p1][yf - 1][z1].getHit() == 1)
                        hit = false;
                if (yf + 1 < LengthBigCube)
                    if (Player1[p1][yf + 1][z1].getHit() == 1)
                        hit = false;
                if (z1 - 1 >= 0)
                    if (Player1[p1][yf][z1 - 1].getHit() == 1)
                        hit = false;
                if (z1 + 1 < LengthBigCube)
                    if (Player1[p1][yf][z1 + 1].getHit() == 1)
                        hit = false;

                if (hit)
                {
                    shipsLifeFirst--;
                    if (p1 - 1 >= 0 && Player1[p1 - 1][yf][z1].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = p1;
                            while (_x >= 0 && Player1[_x][yf][z1].getHit() == 4)
                            {
                                _x--;
                            }
                            _x++;
                            while (_x < LengthBigCube && Player1[_x][yf][z1].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            for (int i = _x - length - 1; i <= _x; i++)
                                for (int j = yf - 1; j <= yf + 1; j++)
                                    for (int k = z1 - 1; k <= z1 + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player1[i][j][k].getHit() != 4)
                                                Player1[i][j][k].setIsHitten(3);
                        }
                    } else
                        if (p1 + 1 < LengthBigCube && Player1[p1 + 1][yf][z1].getHit() == 4)
                        {
                            {
                                int length = 1;
                                int _x = p1;
                                while (_x < LengthBigCube && Player1[_x][yf][z1].getHit() == 4)
                                {
                                    _x++;
                                    length++;
                                }
                                _x--;
                                while (_x >= 0 && Player1[_x][yf][z1].getHit() == 4)
                                {
                                    _x--;
                                }

                                for (int i = _x + length - 1; i <= _x - length + 1; i++)
                                    for (int j = yf - 1; j <= yf + 1; j++)
                                        for (int k = z1 - 1; k <= z1 + 1; k++)
                                            if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                                k < LengthBigCube)
                                                if (Player1[i][j][k].getHit() != 4)
                                                    Player1[i][j][k].setIsHitten(3);
                            }
                    } else
                        if (yf - 1 >= 0 && Player1[p1][yf - 1][z1].getHit() == 4)
                        {
                            {
                                int length = 1;
                                int _x = yf;
                                while (_x >= 0 && Player1[p1][_x][z1].getHit() == 4)
                                {
                                    _x--;
                                }
                                _x++;
                                while (_x < LengthBigCube && Player1[p1][_x][z1].getHit() == 4)
                                {
                                    _x++;
                                    length++;
                                }
                                for (int i = p1 - 1; i <= p1 + 1; i++)
                                    for (int j = _x - length - 1; j <= _x; j++)
                                        for (int k = z1 - 1; k <= z1 + 1; k++)
                                            if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                                k < LengthBigCube)
                                                if (Player1[i][j][k].getHit() != 4)
                                                    Player1[i][j][k].setIsHitten(3);
                            }
                    } else
                    if (yf + 1 < LengthBigCube && Player1[p1][yf + 1][z1].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = yf;
                            while (_x < LengthBigCube && Player1[p1][_x][z1].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            _x--;
                            while (_x >= 0 && Player1[p1][_x][z1].getHit() == 4)
                            {
                                _x--;
                            }

                            for (int i = p1 - 1; i <= p1 + 1; i++)
                                for (int j = _x; j <= _x + length + 1; j++)
                                    for (int k = z1 - 1; k <= z1 + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player1[i][j][k].getHit() != 4)
                                                Player1[i][j][k].setIsHitten(3);
                        }
                    } else
                    if (z1 - 1 >= 0 && Player1[p1][yf][z1 - 1].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = z1;
                            while (_x >= 0 && Player1[p1][yf][_x].getHit() == 4)
                            {
                                _x--;
                            }
                            _x++;
                            while (_x < LengthBigCube && Player1[p1][yf][_x].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            for (int i = p1 - 1; i <= p1 + 1; i++)
                                for (int j = yf - 1; j <= yf + 1; j++)
                                    for (int k = _x - length - 1; k <= _x; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player1[i][j][k].getHit() != 4)
                                                Player1[i][j][k].setIsHitten(3);
                        }
                    } else
                    if (z1 + 1 < LengthBigCube && Player1[p1][yf][z1 + 1].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = z1;
                            while (_x < LengthBigCube && Player1[p1][yf][_x].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            _x--;
                            while (_x >= 0 && Player1[p1][yf][_x].getHit() == 4)
                            {
                                _x--;
                            }

                            for (int i = p1 - 1; i <= p1 + 1; i++)
                                for (int j = yf - 1; j <= yf + 1; j++)
                                    for (int k = _x; k <= _x + length + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player1[i][j][k].getHit() != 4)
                                                Player1[i][j][k].setIsHitten(3);
                        }
                    }
                    else
                    {
                        for (int i = p1 - 1; i <= p1 + 1; i++)
                            for (int j = yf - 1; j <= yf + 1; j++)
                                for (int k = z1 - 1; k <= z1 + 1; k++)
                                    if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                        k < LengthBigCube)
                                        if (Player1[i][j][k].getHit() != 4)
                                        {
                                            Player1[i][j][k].setIsHitten(3);
                                            Player1[i][j][k].setColor(0, 0, 1);
                                        }
                    }
                }
                if(shipsLifeFirst == 0)
                    end1 = true;
            } else if (secondSide && (Player1[x2][p2][z2].getHit() == 0 || Player1[x2][p2][z2].getHit() == 2))
            {
                for (int j = 0; j < LengthBigCube; j++)
                {
                    Player1[x2][j][z2].setColor(0.5, 0.5, 0.8);
                    Player1[x2][j][z2].setTransparency(0.11);
                }
                Player1[x2][p2][z2].setColor(0, 0, 1);
                Player1[x2][p2][z2].setTransparency(0.35);
                Player1[x2][p2][z2].setIsHitten(3);
                isPlayer1 = false;

            } else if (secondSide && Player1[x2][p2][z2].getHit() == 1)
            {
                for (int j = 0; j < LengthBigCube; j++)
                {
                    Player1[x2][j][z2].setColor(0.5, 0.5, 0.8);
                    Player1[x2][j][z2].setTransparency(0.11);
                }

                Player1[x2][p2][z2].setColor(1, 0, 0);
                Player1[x2][p2][z2].setTransparency(0.35);
                Player1[x2][p2][z2].setIsHitten(4);

                bool hit = true;
                if (x2 - 1 >= 0)
                    if (Player1[x2 - 1][p2][z2].getHit() == 1)
                        hit = false;
                if (x2 + 1 < LengthBigCube)
                    if (Player1[x2 + 1][p2][z2].getHit() == 1)
                        hit = false;
                if (p2 - 1 >= 0)
                    if (Player1[x2][p2 - 1][z2].getHit() == 1)
                        hit = false;
                if (p2 + 1 < LengthBigCube)
                    if (Player1[x2][p2 + 1][z2].getHit() == 1)
                        hit = false;
                if (z2 - 1 >= 0)
                    if (Player1[x2][p2][z2 - 1].getHit() == 1)
                        hit = false;
                if (z2 + 1 < LengthBigCube)
                    if (Player1[x2][p2][z2 + 1].getHit() == 1)
                        hit = false;

                if (hit)
                {
                    shipsLifeFirst--;
                    if (x2 - 1 >= 0 && Player1[x2 - 1][p2][z2].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = x2;
                            while (_x >= 0 && Player1[_x][p2][z2].getHit() == 4)
                            {
                                _x--;
                            }
                            _x++;
                            while (_x < LengthBigCube && Player1[_x][p2][z2].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            for (int i = _x - length - 1; i <= _x; i++)
                                for (int j = p2 - 1; j <= p2 + 1; j++)
                                    for (int k = z2 - 1; k <= z2 + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player1[i][j][k].getHit() != 4)
                                                Player1[i][j][k].setIsHitten(3);
                        }
                    } else if (x2 + 1 < LengthBigCube && Player1[x2 + 1][p2][z2].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = x2;
                            while (_x < LengthBigCube && Player1[_x][p2][z2].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            _x--;
                            while (_x >= 0 && Player1[_x][p2][z2].getHit() == 4)
                            {
                                _x--;
                            }

                            for (int i = _x + length - 1; i <= _x - length + 1; i++)
                                for (int j = p2 - 1; j <= p2 + 1; j++)
                                    for (int k = z2 - 1; k <= z2 + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player1[i][j][k].getHit() != 4)
                                                Player1[i][j][k].setIsHitten(3);
                        }
                    } else if (p2 - 1 >= 0 && Player1[x2][p2 - 1][z2].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = p2;
                            while (_x >= 0 && Player1[x2][_x][z2].getHit() == 4)
                            {
                                _x--;
                            }
                            _x++;
                            while (_x < LengthBigCube && Player1[x2][_x][z2].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            for (int i = x2 - 1; i <= x2 + 1; i++)
                                for (int j = _x - length - 1; j <= _x; j++)
                                    for (int k = z2 - 1; k <= z2 + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player1[i][j][k].getHit() != 4)
                                                Player1[i][j][k].setIsHitten(3);
                        }
                    } else if (p2 + 1 < LengthBigCube && Player1[x2][p2 + 1][z2].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = p2;
                            while (_x < LengthBigCube && Player1[x2][_x][z2].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            _x--;
                            while (_x >= 0 && Player1[x2][_x][z2].getHit() == 4)
                            {
                                _x--;
                            }

                            for (int i = x2 - 1; i <= x2 + 1; i++)
                                for (int j = _x; j <= _x + length + 1; j++)
                                    for (int k = z2 - 1; k <= z2 + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player1[i][j][k].getHit() != 4)
                                                Player1[i][j][k].setIsHitten(3);
                        }
                    } else if (z2 - 1 >= 0 && Player1[x2][p2][z2 - 1].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = z2;
                            while (_x >= 0 && Player1[x2][p2][_x].getHit() == 4)
                            {
                                _x--;
                            }
                            _x++;
                            while (_x < LengthBigCube && Player1[x2][p2][_x].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            for (int i = x2 - 1; i <= x2 + 1; i++)
                                for (int j = p2 - 1; j <= p2 + 1; j++)
                                    for (int k = _x - length - 1; k <= _x; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player1[i][j][k].getHit() != 4)
                                                Player1[i][j][k].setIsHitten(3);
                        }
                    } else if (z2 + 1 < LengthBigCube && Player1[x2][p2][z2 + 1].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = z2;
                            while (_x < LengthBigCube && Player1[x2][p2][_x].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            _x--;
                            while (_x >= 0 && Player1[x2][p2][_x].getHit() == 4)
                            {
                                _x--;
                            }

                            for (int i = x2 - 1; i <= x2 + 1; i++)
                                for (int j = p2 - 1; j <= p2 + 1; j++)
                                    for (int k = _x; k <= _x + length + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player1[i][j][k].getHit() != 4)
                                                Player1[i][j][k].setIsHitten(3);
                        }
                    } else
                    {
                        for (int i = x2 - 1; i <= x2 + 1; i++)
                            for (int j = p2 - 1; j <= p2 + 1; j++)
                                for (int k = z2 - 1; k <= z2 + 1; k++)
                                    if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                        k < LengthBigCube)
                                        if (Player1[i][j][k].getHit() != 4)
                                        {
                                            Player1[i][j][k].setIsHitten(3);
                                            Player1[i][j][k].setColor(0, 0, 1);
                                        }
                    }
                }
                if (shipsLifeFirst == 0)
                    end1 = true;
            } else if (thirdSide && (Player1[x3][y3][p3].getHit() == 0 || Player1[x3][y3][p3].getHit() == 2))
            {
                for (int k = 0; k < LengthBigCube; k++)
                {
                    Player1[x3][y3][k].setColor(0.5, 0.5, 0.8);
                    Player1[x3][y3][k].setTransparency(0.11);
                }
                Player1[x3][y3][p3].setColor(0, 0, 1);
                Player1[x3][y3][p3].setTransparency(0.35);
                Player1[x3][y3][p3].setIsHitten(3);
                isPlayer1 = false;
            } else if (thirdSide && Player1[x3][y3][p3].getHit() == 1)
            {
                for (int j = 0; j < LengthBigCube; j++)
                {
                    Player1[x3][j][p3].setColor(0.5, 0.5, 0.8);
                    Player1[x3][j][p3].setTransparency(0.11);
                }

                Player1[x3][y3][p3].setColor(1, 0, 0);
                Player1[x3][y3][p3].setTransparency(0.35);
                Player1[x3][y3][p3].setIsHitten(4);

                bool hit = true;
                if (x3 - 1 >= 0)
                    if (Player1[x3 - 1][y3][p3].getHit() == 1)
                        hit = false;
                if (x3 + 1 < LengthBigCube)
                    if (Player1[x3 + 1][y3][p3].getHit() == 1)
                        hit = false;
                if (y3 - 1 >= 0)
                    if (Player1[x3][y3 - 1][p3].getHit() == 1)
                        hit = false;
                if (y3 + 1 < LengthBigCube)
                    if (Player1[x3][y3 + 1][p3].getHit() == 1)
                        hit = false;
                if (p3 - 1 >= 0)
                    if (Player1[x3][y3][p3 - 1].getHit() == 1)
                        hit = false;
                if (p3 + 1 < LengthBigCube)
                    if (Player1[x3][y3][p3 + 1].getHit() == 1)
                        hit = false;

                if (hit)
                {
                    shipsLifeFirst--;
                    if (x3 - 1 >= 0 && Player1[x3 - 1][y3][p3].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = x3;
                            while (_x >= 0 && Player1[_x][y3][p3].getHit() == 4)
                            {
                                _x--;
                            }
                            _x++;
                            while (_x < LengthBigCube && Player1[_x][y3][p3].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            for (int i = _x - length - 1; i <= _x; i++)
                                for (int j = y3 - 1; j <= y3 + 1; j++)
                                    for (int k = p3 - 1; k <= p3 + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player1[i][j][k].getHit() != 4)
                                                Player1[i][j][k].setIsHitten(3);
                        }
                    } else if (x3 + 1 < LengthBigCube && Player1[x3 + 1][y3][p3].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = x3;
                            while (_x < LengthBigCube && Player1[_x][y3][p3].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            _x--;
                            while (_x >= 0 && Player1[_x][y3][p3].getHit() == 4)
                            {
                                _x--;
                            }

                            for (int i = _x + length - 1; i <= _x - length + 1; i++)
                                for (int j = y3 - 1; j <= y3 + 1; j++)
                                    for (int k = p3 - 1; k <= p3 + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player1[i][j][k].getHit() != 4)
                                                Player1[i][j][k].setIsHitten(3);
                        }
                    } else if (y3 - 1 >= 0 && Player1[x3][y3 - 1][p3].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = y3;
                            while (_x >= 0 && Player1[x3][_x][p3].getHit() == 4)
                            {
                                _x--;
                            }
                            _x++;
                            while (_x < LengthBigCube && Player1[x3][_x][p3].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            for (int i = x3 - 1; i <= x3 + 1; i++)
                                for (int j = _x - length - 1; j <= _x; j++)
                                    for (int k = p3 - 1; k <= p3 + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player1[i][j][k].getHit() != 4)
                                                Player1[i][j][k].setIsHitten(3);
                        }
                    } else if (y3 + 1 < LengthBigCube && Player1[x3][y3 + 1][p3].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = y3;
                            while (_x < LengthBigCube && Player1[x3][_x][p3].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            _x--;
                            while (_x >= 0 && Player1[x3][_x][p3].getHit() == 4)
                            {
                                _x--;
                            }

                            for (int i = x3 - 1; i <= x3 + 1; i++)
                                for (int j = _x; j <= _x + length + 1; j++)
                                    for (int k = p3 - 1; k <= p3 + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player1[i][j][k].getHit() != 4)
                                                Player1[i][j][k].setIsHitten(3);
                        }
                    } else if (p3 - 1 >= 0 && Player1[x3][y3][p3 - 1].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = p3;
                            while (_x >= 0 && Player1[x3][y3][_x].getHit() == 4)
                            {
                                _x--;
                            }
                            _x++;
                            while (_x < LengthBigCube && Player1[x3][y3][_x].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            for (int i = x3 - 1; i <= x3 + 1; i++)
                                for (int j = y3 - 1; j <= y3 + 1; j++)
                                    for (int k = _x - length - 1; k <= _x; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player1[i][j][k].getHit() != 4)
                                                Player1[i][j][k].setIsHitten(3);
                        }
                    } else if (p3 + 1 < LengthBigCube && Player1[x3][y3][p3 + 1].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = p3;
                            while (_x < LengthBigCube && Player1[x3][y3][_x].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            _x--;
                            while (_x >= 0 && Player1[x3][y3][_x].getHit() == 4)
                            {
                                _x--;
                            }

                            for (int i = x3 - 1; i <= x3 + 1; i++)
                                for (int j = y3 - 1; j <= y3 + 1; j++)
                                    for (int k = _x; k <= _x + length + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player1[i][j][k].getHit() != 4)
                                                Player1[i][j][k].setIsHitten(3);
                        }
                    } else
                    {
                        for (int i = x3 - 1; i <= x3 + 1; i++)
                            for (int j = y3 - 1; j <= y3 + 1; j++)
                                for (int k = p3 - 1; k <= p3 + 1; k++)
                                    if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                        k < LengthBigCube)
                                        if (Player1[i][j][k].getHit() != 4)
                                        {
                                            Player1[i][j][k].setIsHitten(3);
                                            Player1[i][j][k].setColor(0, 0, 1);
                                        }
                    }
                }
                if (shipsLifeFirst == 0)
                    end1 = true;
            }
            forEnter = 0;
        } else
        {
            if (firstSide && (Player2[p1][yf][z1].getHit() == 0 || Player2[p1][yf][z1].getHit() == 2))
            {
                for (auto &i : Player2)
                {
                    i[yf][z1].setColor(0.5, 0.5, 0.8);
                    i[yf][z1].setTransparency(0.11);
                }

                Player2[p1][yf][z1].setColor(0, 0, 1);
                Player2[p1][yf][z1].setTransparency(0.35);
                Player2[p1][yf][z1].setIsHitten(3);
                isPlayer1 = true;

            } else if (firstSide && Player2[p1][yf][z1].getHit() == 1)
            {
                for (auto &i : Player2)
                {
                    i[yf][z1].setColor(0.5, 0.5, 0.8);
                    i[yf][z1].setTransparency(0.11);
                }

                Player2[p1][yf][z1].setColor(1, 0, 0);
                Player2[p1][yf][z1].setTransparency(0.35);
                Player2[p1][yf][z1].setIsHitten(4);

                bool hit = true;
                if (p1 - 1 >= 0)
                    if (Player2[p1 - 1][yf][z1].getHit() == 1)
                        hit = false;
                if (p1 + 1 < LengthBigCube)
                    if (Player2[p1 + 1][yf][z1].getHit() == 1)
                        hit = false;
                if (yf - 1 >= 0)
                    if (Player2[p1][yf - 1][z1].getHit() == 1)
                        hit = false;
                if (yf + 1 < LengthBigCube)
                    if (Player2[p1][yf + 1][z1].getHit() == 1)
                        hit = false;
                if (z1 - 1 >= 0)
                    if (Player2[p1][yf][z1 - 1].getHit() == 1)
                        hit = false;
                if (z1 + 1 < LengthBigCube)
                    if (Player2[p1][yf][z1 + 1].getHit() == 1)
                        hit = false;

                if (hit)
                {
                    shipsLifeSecond--;
                    if (p1 - 1 >= 0 && Player2[p1 - 1][yf][z1].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = p1;
                            while (_x >= 0 && Player2[_x][yf][z1].getHit() == 4)
                            {
                                _x--;
                            }
                            _x++;
                            while (_x < LengthBigCube && Player2[_x][yf][z1].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            for (int i = _x - length - 1; i <= _x; i++)
                                for (int j = yf - 1; j <= yf + 1; j++)
                                    for (int k = z1 - 1; k <= z1 + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player2[i][j][k].getHit() != 4)
                                                Player2[i][j][k].setIsHitten(3);
                        }
                    } else if (p1 + 1 < LengthBigCube && Player2[p1 + 1][yf][z1].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = p1;
                            while (_x < LengthBigCube && Player2[_x][yf][z1].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            _x--;
                            while (_x >= 0 && Player2[_x][yf][z1].getHit() == 4)
                            {
                                _x--;
                            }

                            for (int i = _x + length - 1; i <= _x - length + 1; i++)
                                for (int j = yf - 1; j <= yf + 1; j++)
                                    for (int k = z1 - 1; k <= z1 + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player2[i][j][k].getHit() != 4)
                                                Player2[i][j][k].setIsHitten(3);
                        }
                    } else if (yf - 1 >= 0 && Player2[p1][yf - 1][z1].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = yf;
                            while (_x >= 0 && Player2[p1][_x][z1].getHit() == 4)
                            {
                                _x--;
                            }
                            _x++;
                            while (_x < LengthBigCube && Player2[p1][_x][z1].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            for (int i = p1 - 1; i <= p1 + 1; i++)
                                for (int j = _x - length - 1; j <= _x; j++)
                                    for (int k = z1 - 1; k <= z1 + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player2[i][j][k].getHit() != 4)
                                                Player2[i][j][k].setIsHitten(3);
                        }
                    } else if (yf + 1 < LengthBigCube && Player2[p1][yf + 1][z1].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = yf;
                            while (_x < LengthBigCube && Player2[p1][_x][z1].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            _x--;
                            while (_x >= 0 && Player2[p1][_x][z1].getHit() == 4)
                            {
                                _x--;
                            }

                            for (int i = p1 - 1; i <= p1 + 1; i++)
                                for (int j = _x; j <= _x + length + 1; j++)
                                    for (int k = z1 - 1; k <= z1 + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player2[i][j][k].getHit() != 4)
                                                Player2[i][j][k].setIsHitten(3);
                        }
                    } else if (z1 - 1 >= 0 && Player2[p1][yf][z1 - 1].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = z1;
                            while (_x >= 0 && Player2[p1][yf][_x].getHit() == 4)
                            {
                                _x--;
                            }
                            _x++;
                            while (_x < LengthBigCube && Player2[p1][yf][_x].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            for (int i = p1 - 1; i <= p1 + 1; i++)
                                for (int j = yf - 1; j <= yf + 1; j++)
                                    for (int k = _x - length - 1; k <= _x; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player2[i][j][k].getHit() != 4)
                                                Player2[i][j][k].setIsHitten(3);
                        }
                    } else if (z1 + 1 < LengthBigCube && Player2[p1][yf][z1 + 1].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = z1;
                            while (_x < LengthBigCube && Player2[p1][yf][_x].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            _x--;
                            while (_x >= 0 && Player2[p1][yf][_x].getHit() == 4)
                            {
                                _x--;
                            }

                            for (int i = p1 - 1; i <= p1 + 1; i++)
                                for (int j = yf - 1; j <= yf + 1; j++)
                                    for (int k = _x; k <= _x + length + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player2[i][j][k].getHit() != 4)
                                                Player2[i][j][k].setIsHitten(3);
                        }
                    } else
                    {
                        for (int i = p1 - 1; i <= p1 + 1; i++)
                            for (int j = yf - 1; j <= yf + 1; j++)
                                for (int k = z1 - 1; k <= z1 + 1; k++)
                                    if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                        k < LengthBigCube)
                                        if (Player2[i][j][k].getHit() != 4)
                                        {
                                            Player2[i][j][k].setIsHitten(3);
                                            Player2[i][j][k].setColor(0, 0, 1);
                                        }
                    }
                }
                if (shipsLifeSecond == 0)
                    end2 = true;
            }else if (secondSide && (Player2[x2][p2][z2].getHit() == 0 || Player2[x2][p2][z2].getHit() == 2))
            {
                for (int j = 0; j < LengthBigCube; j++)
                {
                    Player2[x2][j][z2].setColor(0.5, 0.5, 0.8);
                    Player2[x2][j][z2].setTransparency(0.11);
                }
                Player2[x2][p2][z2].setColor(0, 0, 1);
                Player2[x2][p2][z2].setTransparency(0.35);
                Player2[x2][p2][z2].setIsHitten(3);
                isPlayer1 = true;

            } else if (secondSide && Player2[x2][p2][z2].getHit() == 1)
            {
                for (int j = 0; j < LengthBigCube; j++)
                {
                    Player2[x2][j][z2].setColor(0.5, 0.5, 0.8);
                    Player2[x2][j][z2].setTransparency(0.11);
                }

                Player2[x2][p2][z2].setColor(1, 0, 0);
                Player2[x2][p2][z2].setTransparency(0.35);
                Player2[x2][p2][z2].setIsHitten(4);

                bool hit = true;
                if (x2 - 1 >= 0)
                    if (Player2[x2 - 1][p2][z2].getHit() == 1)
                        hit = false;
                if (x2 + 1 < LengthBigCube)
                    if (Player2[x2 + 1][p2][z2].getHit() == 1)
                        hit = false;
                if (p2 - 1 >= 0)
                    if (Player2[x2][p2 - 1][z2].getHit() == 1)
                        hit = false;
                if (p2 + 1 < LengthBigCube)
                    if (Player2[x2][p2 + 1][z2].getHit() == 1)
                        hit = false;
                if (z2 - 1 >= 0)
                    if (Player2[x2][p2][z2 - 1].getHit() == 1)
                        hit = false;
                if (z2 + 1 < LengthBigCube)
                    if (Player2[x2][p2][z2 + 1].getHit() == 1)
                        hit = false;

                if (hit)
                {
                    shipsLifeSecond--;
                    if (x2 - 1 >= 0 && Player2[x2 - 1][p2][z2].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = x2;
                            while (_x >= 0 && Player2[_x][p2][z2].getHit() == 4)
                            {
                                _x--;
                            }
                            _x++;
                            while (_x < LengthBigCube && Player2[_x][p2][z2].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            for (int i = _x - length - 1; i <= _x; i++)
                                for (int j = p2 - 1; j <= p2 + 1; j++)
                                    for (int k = z2 - 1; k <= z2 + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player2[i][j][k].getHit() != 4)
                                                Player2[i][j][k].setIsHitten(3);
                        }
                    } else if (x2 + 1 < LengthBigCube && Player2[x2 + 1][p2][z2].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = x2;
                            while (_x < LengthBigCube && Player2[_x][p2][z2].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            _x--;
                            while (_x >= 0 && Player2[_x][p2][z2].getHit() == 4)
                            {
                                _x--;
                            }

                            for (int i = _x + length - 1; i <= _x - length + 1; i++)
                                for (int j = p2 - 1; j <= p2 + 1; j++)
                                    for (int k = z2 - 1; k <= z2 + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player2[i][j][k].getHit() != 4)
                                                Player2[i][j][k].setIsHitten(3);
                        }
                    } else if (p2 - 1 >= 0 && Player2[x2][p2 - 1][z2].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = p2;
                            while (_x >= 0 && Player2[x2][_x][z2].getHit() == 4)
                            {
                                _x--;
                            }
                            _x++;
                            while (_x < LengthBigCube && Player2[x2][_x][z2].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            for (int i = x2 - 1; i <= x2 + 1; i++)
                                for (int j = _x - length - 1; j <= _x; j++)
                                    for (int k = z2 - 1; k <= z2 + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player2[i][j][k].getHit() != 4)
                                                Player2[i][j][k].setIsHitten(3);
                        }
                    } else if (p2 + 1 < LengthBigCube && Player2[x2][p2 + 1][z2].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = p2;
                            while (_x < LengthBigCube && Player2[x2][_x][z2].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            _x--;
                            while (_x >= 0 && Player2[x2][_x][z2].getHit() == 4)
                            {
                                _x--;
                            }

                            for (int i = x2 - 1; i <= x2 + 1; i++)
                                for (int j = _x; j <= _x + length + 1; j++)
                                    for (int k = z2 - 1; k <= z2 + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player2[i][j][k].getHit() != 4)
                                                Player2[i][j][k].setIsHitten(3);
                        }
                    } else if (z2 - 1 >= 0 && Player2[x2][p2][z2 - 1].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = z2;
                            while (_x >= 0 && Player2[x2][p2][_x].getHit() == 4)
                            {
                                _x--;
                            }
                            _x++;
                            while (_x < LengthBigCube && Player2[x2][p2][_x].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            for (int i = x2 - 1; i <= x2 + 1; i++)
                                for (int j = p2 - 1; j <= p2 + 1; j++)
                                    for (int k = _x - length - 1; k <= _x; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player2[i][j][k].getHit() != 4)
                                                Player2[i][j][k].setIsHitten(3);
                        }
                    } else if (z2 + 1 < LengthBigCube && Player2[x2][p2][z2 + 1].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = z2;
                            while (_x < LengthBigCube && Player2[x2][p2][_x].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            _x--;
                            while (_x >= 0 && Player2[x2][p2][_x].getHit() == 4)
                            {
                                _x--;
                            }

                            for (int i = x2 - 1; i <= x2 + 1; i++)
                                for (int j = p2 - 1; j <= p2 + 1; j++)
                                    for (int k = _x; k <= _x + length + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player2[i][j][k].getHit() != 4)
                                                Player2[i][j][k].setIsHitten(3);
                        }
                    } else
                    {
                        for (int i = x2 - 1; i <= x2 + 1; i++)
                            for (int j = p2 - 1; j <= p2 + 1; j++)
                                for (int k = z2 - 1; k <= z2 + 1; k++)
                                    if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                        k < LengthBigCube)
                                        if (Player2[i][j][k].getHit() != 4)
                                        {
                                            Player2[i][j][k].setIsHitten(3);
                                            Player2[i][j][k].setColor(0, 0, 1);
                                        }
                    }
                }
                if (shipsLifeSecond == 0)
                    end2 = true;
            }else if (thirdSide && (Player2[x3][y3][p3].getHit() == 0 || Player2[x3][y3][p3].getHit() == 2))
            {
                for (int k = 0; k < LengthBigCube; k++)
                {
                    Player2[x3][y3][k].setColor(0.5, 0.5, 0.8);
                    Player2[x3][y3][k].setTransparency(0.11);
                }
                Player2[x3][y3][p3].setColor(0, 0, 1);
                Player2[x3][y3][p3].setTransparency(0.35);
                Player2[x3][y3][p3].setIsHitten(3);
                isPlayer1 = true;

            } else if (thirdSide && Player2[x3][y3][p3].getHit() == 1)
            {
                for (int j = 0; j < LengthBigCube; j++)
                {
                    Player2[x3][j][p3].setColor(0.5, 0.5, 0.8);
                    Player2[x3][j][p3].setTransparency(0.11);
                }

                Player2[x3][y3][p3].setColor(1, 0, 0);
                Player2[x3][y3][p3].setTransparency(0.35);
                Player2[x3][y3][p3].setIsHitten(4);

                bool hit = true;
                if (x3 - 1 >= 0)
                    if (Player2[x3 - 1][y3][p3].getHit() == 1)
                        hit = false;
                if (x3 + 1 < LengthBigCube)
                    if (Player2[x3 + 1][y3][p3].getHit() == 1)
                        hit = false;
                if (y3 - 1 >= 0)
                    if (Player2[x3][y3 - 1][p3].getHit() == 1)
                        hit = false;
                if (y3 + 1 < LengthBigCube)
                    if (Player2[x3][y3 + 1][p3].getHit() == 1)
                        hit = false;
                if (p3 - 1 >= 0)
                    if (Player2[x3][y3][p3 - 1].getHit() == 1)
                        hit = false;
                if (p3 + 1 < LengthBigCube)
                    if (Player2[x3][y3][p3 + 1].getHit() == 1)
                        hit = false;

                if (hit)
                {
                    shipsLifeSecond--;
                    if (x3 - 1 >= 0 && Player2[x3 - 1][y3][p3].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = x3;
                            while (_x >= 0 && Player2[_x][y3][p3].getHit() == 4)
                            {
                                _x--;
                            }
                            _x++;
                            while (_x < LengthBigCube && Player2[_x][y3][p3].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            for (int i = _x - length - 1; i <= _x; i++)
                                for (int j = y3 - 1; j <= y3 + 1; j++)
                                    for (int k = p3 - 1; k <= p3 + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player2[i][j][k].getHit() != 4)
                                                Player2[i][j][k].setIsHitten(3);
                        }
                    } else if (x3 + 1 < LengthBigCube && Player2[x3 + 1][y3][p3].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = x3;
                            while (_x < LengthBigCube && Player2[_x][y3][p3].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            _x--;
                            while (_x >= 0 && Player2[_x][y3][p3].getHit() == 4)
                            {
                                _x--;
                            }

                            for (int i = _x + length - 1; i <= _x - length + 1; i++)
                                for (int j = y3 - 1; j <= y3 + 1; j++)
                                    for (int k = p3 - 1; k <= p3 + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player2[i][j][k].getHit() != 4)
                                                Player2[i][j][k].setIsHitten(3);
                        }
                    } else if (y3 - 1 >= 0 && Player2[x3][y3 - 1][p3].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = y3;
                            while (_x >= 0 && Player2[x3][_x][p3].getHit() == 4)
                            {
                                _x--;
                            }
                            _x++;
                            while (_x < LengthBigCube && Player2[x3][_x][p3].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            for (int i = x3 - 1; i <= x3 + 1; i++)
                                for (int j = _x - length - 1; j <= _x; j++)
                                    for (int k = p3 - 1; k <= p3 + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player2[i][j][k].getHit() != 4)
                                                Player2[i][j][k].setIsHitten(3);
                        }
                    } else if (y3 + 1 < LengthBigCube && Player2[x3][y3 + 1][p3].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = y3;
                            while (_x < LengthBigCube && Player2[x3][_x][p3].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            _x--;
                            while (_x >= 0 && Player2[x3][_x][p3].getHit() == 4)
                            {
                                _x--;
                            }

                            for (int i = x3 - 1; i <= x3 + 1; i++)
                                for (int j = _x; j <= _x + length + 1; j++)
                                    for (int k = p3 - 1; k <= p3 + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player2[i][j][k].getHit() != 4)
                                                Player2[i][j][k].setIsHitten(3);
                        }
                    } else if (p3 - 1 >= 0 && Player2[x3][y3][p3 - 1].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = p3;
                            while (_x >= 0 && Player2[x3][y3][_x].getHit() == 4)
                            {
                                _x--;
                            }
                            _x++;
                            while (_x < LengthBigCube && Player2[x3][y3][_x].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            for (int i = x3 - 1; i <= x3 + 1; i++)
                                for (int j = y3 - 1; j <= y3 + 1; j++)
                                    for (int k = _x - length - 1; k <= _x; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player2[i][j][k].getHit() != 4)
                                                Player2[i][j][k].setIsHitten(3);
                        }
                    } else if (p3 + 1 < LengthBigCube && Player2[x3][y3][p3 + 1].getHit() == 4)
                    {
                        {
                            int length = 1;
                            int _x = p3;
                            while (_x < LengthBigCube && Player2[x3][y3][_x].getHit() == 4)
                            {
                                _x++;
                                length++;
                            }
                            _x--;
                            while (_x >= 0 && Player2[x3][y3][_x].getHit() == 4)
                            {
                                _x--;
                            }

                            for (int i = x3 - 1; i <= x3 + 1; i++)
                                for (int j = y3 - 1; j <= y3 + 1; j++)
                                    for (int k = _x; k <= _x + length + 1; k++)
                                        if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                            k < LengthBigCube)
                                            if (Player2[i][j][k].getHit() != 4)
                                                Player2[i][j][k].setIsHitten(3);
                        }
                    } else
                    {
                        for (int i = x3 - 1; i <= x3 + 1; i++)
                            for (int j = y3 - 1; j <= y3 + 1; j++)
                                for (int k = p3 - 1; k <= p3 + 1; k++)
                                    if (i >= 0 && j >= 0 && k >= 0 && i < LengthBigCube && j < LengthBigCube &&
                                        k < LengthBigCube)
                                        if (Player2[i][j][k].getHit() != 4)
                                        {
                                            Player2[i][j][k].setIsHitten(3);
                                            Player2[i][j][k].setColor(0, 0, 1);
                                        }
                    }
                }
                if (shipsLifeSecond == 0)
                    end2 = true;
            }
            forEnter = 0;
        }
        p1 = 0;
        yf = 0;
        z1 = 0;
        x2 = LengthBigCube - 1;
        p2 = 0;
        z2 = LengthBigCube - 1;
        x3 = LengthBigCube - 1;
        y3 = 0;
        p3 = 0;
    }

    if (key == 27)
    {
        movement = true;
        forEnter--;
        if (forEnter < 0)
            forEnter = 0;
        default_position(r_rotate_x, r_rotate_y
        );
        firstSide = false;
        secondSide = false;
        thirdSide = false;
    }

    glutPostRedisplay(); //а это просто обязательная функция
}


void ChooseCube(int page)
{
    if (firstSide)
    {
        if (p1 > 0)
            for (int i = p1; i <= ship; i++)
                a[i][yf][z1].setTransparency(0.7);

        if (page == 1 && p1 < LengthBigCube - ship)
        {
            for (int i = 0; i <= p1; i++)
                a[i][yf][z1].setTransparency(0.2);
            p1++;
            for (int i = p1; i < p1 + ship; i++)
                a[i][yf][z1].setTransparency(0.7);

        } else if (page == 2 && p1 > 0)
        {
            p1--;
            for (int i = p1 + ship - 1; i > p1 - 1; i--)
                a[i][yf][z1].setTransparency(0.7);

            for (int i = LengthBigCube - 1; i > p1 + ship - 1; i--)
                a[i][yf][z1].setTransparency(0.2);
        }

    } else if (secondSide)
    {
        if (p2 > 0)
            for (int j = p2; j <= ship; j++)
                a[x2][j][z2].setTransparency(0.7);

        if (page == 1 && p2 < LengthBigCube - ship)
        {
            for (int j = 0; j <= p2; j++)
                a[x2][j][z2].setTransparency(0.2);
            p2++;
            for (int j = p2; j < p2 + ship; j++)
                a[x2][j][z2].setTransparency(0.7);

        } else if (page == 2 && p2 > 0)
        {
            p2--;
            for (int j = p2 + ship - 1; j > p2 - 1; j--)
                a[x2][j][z2].setTransparency(0.7);

            for (int j = LengthBigCube - 1; j > p2 + ship - 1; j--)
                a[x2][j][z2].setTransparency(0.2);
        }

    } else if (thirdSide)
    {
        if (p3 > 0)
            for (int k = p3; k <= ship; k++)
                a[x3][y3][k].setTransparency(0.7);

        if (page == 1 && p3 < LengthBigCube - ship)
        {
            for (int k = 0; k <= p3; k++)
                a[x3][y3][k].setTransparency(0.2);
            p3++;
            for (int k = p3; k < p3 + ship; k++)
                a[x3][y3][k].setTransparency(0.7);

        } else if (page == 2 && p3 > 0)
        {
            p3--;
            for (int k = p3 + ship - 1; k > p3 - 1; k--)
                a[x3][y3][k].setTransparency(0.7);

            for (int k = LengthBigCube - 1; k > p3 + ship - 1; k--)
                a[x3][y3][k].setTransparency(0.2);
        }
    }
}

void ChooseColumn(int arrow)
{
    if (firstSide)// && forEnter >= 2)
    {

        if (arrow == 4)
        {//работает стрелочка вправо
            if (forTwoPlayers == 2)
            {
                if (isPlayer1)
                {
                    Player1[LengthBigCube - 1][yf][z1].setTransparency(0.11);
                    Player1[LengthBigCube - 1][yf][z1].setColor(0, 0, 1);
                    /*if (a[LengthBigCube - 1][yf][z1].getHit() == 2)
                        a[LengthBigCube - 1][yf][z1].setPaint(false);
                    if (a[LengthBigCube - 1][yf][z1].getHit() == 1)
                        a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[i][yf][z1].setColor(0.5, 0.5, 0.8);
                        Player1[i][yf][z1].setTransparency(0.11);
                        /*if (a[i][yf][z1].getHit() == 2)
                            a[i][yf][z1].setPaint(false);
                        a[i][yf][z1].setRed(false);*/
                    }
                    z1++;
                    if (z1 > LengthBigCube - 1)
                        z1 = 0;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        //if (a[i][yf][z1].getHit() == 0)
                        Player1[i][yf][z1].setColor(1, 1, 0);
                        // else
                        //    {
                        //a[i][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        // a[i][yf][z1].setPaint(true);
                        // if (a[i][yf][z1].getHit() == 1)
                        //     a[i][yf][z1].setRed(true);
                        //   }
                        Player1[i][yf][z1].setTransparency(0.3);
                    }
                    /*if (a[LengthBigCube - 1][yf][z1].getHit() != 0)
                    {
                        a[LengthBigCube - 1][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[LengthBigCube - 1][yf][z1].setPaint(true);
                        a[LengthBigCube - 1][yf][z1].setRed(true);
                    } else*/ Player1[LengthBigCube - 1][yf][z1].setColor(1, 1, 0);
                    Player1[LengthBigCube - 1][yf][z1].setTransparency(0.7);
                } else
                {
                    Player2[LengthBigCube - 1][yf][z1].setTransparency(0.11);
                    Player2[LengthBigCube - 1][yf][z1].setColor(0, 0, 1);
                    /*if (a[LengthBigCube - 1][yf][z1].getHit() == 2)
                        a[LengthBigCube - 1][yf][z1].setPaint(false);
                    if (a[LengthBigCube - 1][yf][z1].getHit() == 1)
                        a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[i][yf][z1].setColor(0.5, 0.5, 0.8);
                        Player2[i][yf][z1].setTransparency(0.11);
                        /*if (a[i][yf][z1].getHit() == 2)
                            a[i][yf][z1].setPaint(false);
                        a[i][yf][z1].setRed(false);*/
                    }
                    z1++;
                    if (z1 > LengthBigCube - 1)
                        z1 = 0;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        //if (a[i][yf][z1].getHit() == 0)
                        Player2[i][yf][z1].setColor(1, 1, 0);
                        // else
                        //    {
                        //a[i][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        // a[i][yf][z1].setPaint(true);
                        // if (a[i][yf][z1].getHit() == 1)
                        //     a[i][yf][z1].setRed(true);
                        //   }
                        Player2[i][yf][z1].setTransparency(0.3);
                    }
                    /*if (a[LengthBigCube - 1][yf][z1].getHit() != 0)
                    {
                        a[LengthBigCube - 1][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[LengthBigCube - 1][yf][z1].setPaint(true);
                        a[LengthBigCube - 1][yf][z1].setRed(true);
                    } else*/ Player2[LengthBigCube - 1][yf][z1].setColor(1, 1, 0);
                    Player2[LengthBigCube - 1][yf][z1].setTransparency(0.7);
                }
            } else
            {
                a[LengthBigCube - 1][yf][z1].setTransparency(0.11);
                a[LengthBigCube - 1][yf][z1].setColor(0, 0, 1);
                if (a[LengthBigCube - 1][yf][z1].getHit() == 2)
                    a[LengthBigCube - 1][yf][z1].setPaint(false);
                if (a[LengthBigCube - 1][yf][z1].getHit() == 1)
                    a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[i][yf][z1].setColor(0.5, 0.5, 0.8);
                    a[i][yf][z1].setTransparency(0.11);
                    if (a[i][yf][z1].getHit() == 2)
                        a[i][yf][z1].setPaint(false);
                    a[i][yf][z1].setRed(false);
                }
                z1++;
                if (z1 > LengthBigCube - 1)
                    z1 = 0;
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    if (a[i][yf][z1].getHit() == 0)
                        a[i][yf][z1].setColor(1, 1, 0);
                    else
                    {
                        a[i][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[i][yf][z1].setPaint(true);
                        if (a[i][yf][z1].getHit() == 1)
                            a[i][yf][z1].setRed(true);
                    }
                    a[i][yf][z1].setTransparency(0.3);
                }
                if (a[LengthBigCube - 1][yf][z1].getHit() != 0)
                {
                    a[LengthBigCube - 1][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                    a[LengthBigCube - 1][yf][z1].setPaint(true);
                    a[LengthBigCube - 1][yf][z1].setRed(true);
                } else a[LengthBigCube - 1][yf][z1].setColor(1, 1, 0);
                a[LengthBigCube - 1][yf][z1].setTransparency(0.7);
            }
        } else if (arrow == 2)
        {//стрелочка вверх
            if (forTwoPlayers == 2)
            {
                if (isPlayer1)
                {
                    Player1[LengthBigCube - 1][yf][z1].setTransparency(0.11);
                    Player1[LengthBigCube - 1][yf][z1].setColor(0, 0, 1);
                    /*if (a[LengthBigCube - 1][yf][z1].getHit() == 1)
                        a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
                    if (a[LengthBigCube - 1][yf][z1].getHit() == 2)
                        a[LengthBigCube - 1][yf][z1].setPaint(false);*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[i][yf][z1].setColor(0.5, 0.5, 0.8);
                        Player1[i][yf][z1].setTransparency(0.11);
                        /* if (a[i][yf][z1].getHit() == 2)
                             a[i][yf][z1].setPaint(false);
                         a[i][yf][z1].setRed(false);*/
                    }
                    yf++;
                    if (yf > LengthBigCube - 1)
                        yf = 0;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        //if (a[i][yf][z1].getHit() == 0)
                        Player1[i][yf][z1].setColor(1, 1, 0);
                        // else
                        //{
                        //    a[i][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        //    a[i][yf][z1].setPaint(true);
                        //    if (a[i][yf][z1].getHit() == 1)
                        //        a[i][yf][z1].setRed(true);
                        // }
                        Player1[i][yf][z1].setTransparency(0.3);
                    }
                    /* if (a[LengthBigCube - 1][yf][z1].getHit() != 0)
                     {
                         a[LengthBigCube - 1][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                         a[LengthBigCube - 1][yf][z1].setPaint(true);
                         a[LengthBigCube - 1][yf][z1].setRed(true);
                     } else*/ Player1[LengthBigCube - 1][yf][z1].setColor(1, 1, 0);
                    Player1[LengthBigCube - 1][yf][z1].setTransparency(0.7);
                } else
                {
                    Player2[LengthBigCube - 1][yf][z1].setTransparency(0.11);
                    Player2[LengthBigCube - 1][yf][z1].setColor(0, 0, 1);
                    /*if (a[LengthBigCube - 1][yf][z1].getHit() == 1)
                        a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
                    if (a[LengthBigCube - 1][yf][z1].getHit() == 2)
                        a[LengthBigCube - 1][yf][z1].setPaint(false);*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[i][yf][z1].setColor(0.5, 0.5, 0.8);
                        Player2[i][yf][z1].setTransparency(0.11);
                        /* if (a[i][yf][z1].getHit() == 2)
                             a[i][yf][z1].setPaint(false);
                         a[i][yf][z1].setRed(false);*/
                    }
                    yf++;
                    if (yf > LengthBigCube - 1)
                        yf = 0;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        //if (a[i][yf][z1].getHit() == 0)
                        Player2[i][yf][z1].setColor(1, 1, 0);
                        // else
                        //{
                        //    a[i][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        //    a[i][yf][z1].setPaint(true);
                        //    if (a[i][yf][z1].getHit() == 1)
                        //        a[i][yf][z1].setRed(true);
                        // }
                        Player2[i][yf][z1].setTransparency(0.3);
                    }
                    /* if (a[LengthBigCube - 1][yf][z1].getHit() != 0)
                     {
                         a[LengthBigCube - 1][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                         a[LengthBigCube - 1][yf][z1].setPaint(true);
                         a[LengthBigCube - 1][yf][z1].setRed(true);
                     } else*/ Player2[LengthBigCube - 1][yf][z1].setColor(1, 1, 0);
                    Player2[LengthBigCube - 1][yf][z1].setTransparency(0.7);
                }
            } else
            {
                a[LengthBigCube - 1][yf][z1].setTransparency(0.11);
                a[LengthBigCube - 1][yf][z1].setColor(0, 0, 1);
                if (a[LengthBigCube - 1][yf][z1].getHit() == 1)
                    a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
                if (a[LengthBigCube - 1][yf][z1].getHit() == 2)
                    a[LengthBigCube - 1][yf][z1].setPaint(false);
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[i][yf][z1].setColor(0.5, 0.5, 0.8);
                    a[i][yf][z1].setTransparency(0.11);
                    if (a[i][yf][z1].getHit() == 2)
                        a[i][yf][z1].setPaint(false);
                    a[i][yf][z1].setRed(false);
                }
                yf++;
                if (yf > LengthBigCube - 1)
                    yf = 0;
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    if (a[i][yf][z1].getHit() == 0)
                        a[i][yf][z1].setColor(1, 1, 0);
                    else
                    {
                        a[i][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[i][yf][z1].setPaint(true);
                        if (a[i][yf][z1].getHit() == 1)
                            a[i][yf][z1].setRed(true);
                    }
                    a[i][yf][z1].setTransparency(0.3);
                }
                if (a[LengthBigCube - 1][yf][z1].getHit() != 0)
                {
                    a[LengthBigCube - 1][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                    a[LengthBigCube - 1][yf][z1].setPaint(true);
                    a[LengthBigCube - 1][yf][z1].setRed(true);
                } else a[LengthBigCube - 1][yf][z1].setColor(1, 1, 0);
                a[LengthBigCube - 1][yf][z1].setTransparency(0.7);
            }
        } else if (arrow == 1)
        {//стрелочка влево
            if (forTwoPlayers == 2)
            {
                if (isPlayer1)
                {
                    Player1[LengthBigCube - 1][yf][z1].setTransparency(0.11);
                    Player1[LengthBigCube - 1][yf][z1].setColor(0, 0, 1);
                    /*if (a[LengthBigCube - 1][yf][z1].getHit() == 1)
                        a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
                    if (a[LengthBigCube - 1][yf][z1].getHit() == 2)
                        a[LengthBigCube - 1][yf][z1].setPaint(false);*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[i][yf][z1].setColor(0.5, 0.5, 0.8);
                        Player1[i][yf][z1].setTransparency(0.11);
                        /*if (a[i][yf][z1].getHit() == 2)
                            a[i][yf][z1].setPaint(false);
                        a[i][yf][z1].setRed(false);*/
                    }
                    z1--;
                    if (z1 < 0)
                        z1 = LengthBigCube - 1;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[i][yf][z1].setTransparency(0.3);
                        //if (a[i][yf][z1].getHit() == 0)
                        Player1[i][yf][z1].setColor(1, 1, 0);
                        /*else
                        {
                            a[i][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                            a[i][yf][z1].setPaint(true);
                            if (a[i][yf][z1].getHit() == 1)
                                a[i][yf][z1].setRed(true);
                        }*/
                    }
                    /*if (a[LengthBigCube - 1][yf][z1].getHit() != 0)
                    {
                        a[LengthBigCube - 1][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[LengthBigCube - 1][yf][z1].setPaint(true);
                        a[LengthBigCube - 1][yf][z1].setRed(true);
                    } else*/ Player1[LengthBigCube - 1][yf][z1].setColor(1, 1, 0);
                    Player1[LengthBigCube - 1][yf][z1].setTransparency(0.7);
                } else
                {
                    Player2[LengthBigCube - 1][yf][z1].setTransparency(0.11);
                    Player2[LengthBigCube - 1][yf][z1].setColor(0, 0, 1);
                    /*if (a[LengthBigCube - 1][yf][z1].getHit() == 1)
                        a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
                    if (a[LengthBigCube - 1][yf][z1].getHit() == 2)
                        a[LengthBigCube - 1][yf][z1].setPaint(false);*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[i][yf][z1].setColor(0.5, 0.5, 0.8);
                        Player2[i][yf][z1].setTransparency(0.11);
                        /*if (a[i][yf][z1].getHit() == 2)
                            a[i][yf][z1].setPaint(false);
                        a[i][yf][z1].setRed(false);*/
                    }
                    z1--;
                    if (z1 < 0)
                        z1 = LengthBigCube - 1;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[i][yf][z1].setTransparency(0.3);
                        //if (a[i][yf][z1].getHit() == 0)
                        Player2[i][yf][z1].setColor(1, 1, 0);
                        /*else
                        {
                            a[i][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                            a[i][yf][z1].setPaint(true);
                            if (a[i][yf][z1].getHit() == 1)
                                a[i][yf][z1].setRed(true);
                        }*/
                    }
                    /*if (a[LengthBigCube - 1][yf][z1].getHit() != 0)
                    {
                        a[LengthBigCube - 1][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[LengthBigCube - 1][yf][z1].setPaint(true);
                        a[LengthBigCube - 1][yf][z1].setRed(true);
                    } else*/ Player2[LengthBigCube - 1][yf][z1].setColor(1, 1, 0);
                    Player2[LengthBigCube - 1][yf][z1].setTransparency(0.7);
                }
            } else
            {
                a[LengthBigCube - 1][yf][z1].setTransparency(0.11);
                a[LengthBigCube - 1][yf][z1].setColor(0, 0, 1);
                if (a[LengthBigCube - 1][yf][z1].getHit() == 1)
                    a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
                if (a[LengthBigCube - 1][yf][z1].getHit() == 2)
                    a[LengthBigCube - 1][yf][z1].setPaint(false);
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[i][yf][z1].setColor(0.5, 0.5, 0.8);
                    a[i][yf][z1].setTransparency(0.11);
                    if (a[i][yf][z1].getHit() == 2)
                        a[i][yf][z1].setPaint(false);
                    a[i][yf][z1].setRed(false);
                }
                z1--;
                if (z1 < 0)
                    z1 = LengthBigCube - 1;
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[i][yf][z1].setTransparency(0.3);
                    if (a[i][yf][z1].getHit() == 0)
                        a[i][yf][z1].setColor(1, 1, 0);
                    else
                    {
                        a[i][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[i][yf][z1].setPaint(true);
                        if (a[i][yf][z1].getHit() == 1)
                            a[i][yf][z1].setRed(true);
                    }
                }
                if (a[LengthBigCube - 1][yf][z1].getHit() != 0)
                {
                    a[LengthBigCube - 1][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                    a[LengthBigCube - 1][yf][z1].setPaint(true);
                    a[LengthBigCube - 1][yf][z1].setRed(true);
                } else a[LengthBigCube - 1][yf][z1].setColor(1, 1, 0);
                a[LengthBigCube - 1][yf][z1].setTransparency(0.7);
            }
        } else if (arrow == 3)
        {
            if (forTwoPlayers == 2)
            {
                if (isPlayer1)
                {
                    Player1[LengthBigCube - 1][yf][z1].setTransparency(0.11);
                    Player1[LengthBigCube - 1][yf][z1].setColor(0, 0, 1);
                    /*if (a[LengthBigCube - 1][yf][z1].getHit() == 1)
                        a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
                    if (a[LengthBigCube - 1][yf][z1].getHit() == 2)
                        a[LengthBigCube - 1][yf][z1].setPaint(false);*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[i][yf][z1].setTransparency(0.11);
                        Player1[i][yf][z1].setColor(0.5, 0.5, 0.8);
                        /*if (a[i][yf][z1].getHit() == 2)
                            a[i][yf][z1].setPaint(false);
                        a[i][yf][z1].setRed(false);*/
                    }
                    yf--;
                    if (yf < 0)
                        yf = LengthBigCube - 1;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[i][yf][z1].setTransparency(0.3);
                        //if (a[i][yf][z1].getHit() == 0)
                        Player1[i][yf][z1].setColor(1, 1, 0);
                        /* else
                         {
                             a[i][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                             a[i][yf][z1].setPaint(true);

                             if (a[i][yf][z1].getHit() == 1)
                                 a[i][yf][z1].setRed(true);
                         }*/
                    }
                    /*if (a[LengthBigCube - 1][yf][z1].getHit() != 0)
                    {
                        a[LengthBigCube - 1][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[LengthBigCube - 1][yf][z1].setPaint(true);
                        a[LengthBigCube - 1][yf][z1].setRed(true);
                    } else*/ Player1[LengthBigCube - 1][yf][z1].setColor(1, 1, 0);
                    Player1[LengthBigCube - 1][yf][z1].setTransparency(0.7);
                } else
                {
                    Player2[LengthBigCube - 1][yf][z1].setTransparency(0.11);
                    Player2[LengthBigCube - 1][yf][z1].setColor(0, 0, 1);
                    /*if (a[LengthBigCube - 1][yf][z1].getHit() == 1)
                        a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
                    if (a[LengthBigCube - 1][yf][z1].getHit() == 2)
                        a[LengthBigCube - 1][yf][z1].setPaint(false);*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[i][yf][z1].setTransparency(0.11);
                        Player2[i][yf][z1].setColor(0.5, 0.5, 0.8);
                        /*if (a[i][yf][z1].getHit() == 2)
                            a[i][yf][z1].setPaint(false);
                        a[i][yf][z1].setRed(false);*/
                    }
                    yf--;
                    if (yf < 0)
                        yf = LengthBigCube - 1;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[i][yf][z1].setTransparency(0.3);
                        //if (a[i][yf][z1].getHit() == 0)
                        Player2[i][yf][z1].setColor(1, 1, 0);
                        /* else
                         {
                             a[i][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                             a[i][yf][z1].setPaint(true);

                             if (a[i][yf][z1].getHit() == 1)
                                 a[i][yf][z1].setRed(true);
                         }*/
                    }
                    /*if (a[LengthBigCube - 1][yf][z1].getHit() != 0)
                    {
                        a[LengthBigCube - 1][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[LengthBigCube - 1][yf][z1].setPaint(true);
                        a[LengthBigCube - 1][yf][z1].setRed(true);
                    } else*/ Player2[LengthBigCube - 1][yf][z1].setColor(1, 1, 0);
                    Player2[LengthBigCube - 1][yf][z1].setTransparency(0.7);
                }
            } else
            {
                a[LengthBigCube - 1][yf][z1].setTransparency(0.11);
                a[LengthBigCube - 1][yf][z1].setColor(0, 0, 1);
                if (a[LengthBigCube - 1][yf][z1].getHit() == 1)
                    a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
                if (a[LengthBigCube - 1][yf][z1].getHit() == 2)
                    a[LengthBigCube - 1][yf][z1].setPaint(false);
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[i][yf][z1].setTransparency(0.11);
                    a[i][yf][z1].setColor(0.5, 0.5, 0.8);
                    if (a[i][yf][z1].getHit() == 2)
                        a[i][yf][z1].setPaint(false);
                    a[i][yf][z1].setRed(false);
                }
                yf--;
                if (yf < 0)
                    yf = LengthBigCube - 1;
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[i][yf][z1].setTransparency(0.3);
                    if (a[i][yf][z1].getHit() == 0)
                        a[i][yf][z1].setColor(1, 1, 0);
                    else
                    {
                        a[i][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[i][yf][z1].setPaint(true);

                        if (a[i][yf][z1].getHit() == 1)
                            a[i][yf][z1].setRed(true);
                    }
                }
                if (a[LengthBigCube - 1][yf][z1].getHit() != 0)
                {
                    a[LengthBigCube - 1][yf][z1].setColor(255 / 255., 105 / 255., 60 / 255.);
                    a[LengthBigCube - 1][yf][z1].setPaint(true);
                    a[LengthBigCube - 1][yf][z1].setRed(true);
                } else a[LengthBigCube - 1][yf][z1].setColor(1, 1, 0);
                a[LengthBigCube - 1][yf][z1].setTransparency(0.7);
            }
        }
    } else if (secondSide)// && forEnter >= 2)
    {

        if (arrow == 2)
        {//работает стрелочка вправо
            if (forTwoPlayers == 2)
            {
                if (isPlayer1)
                {
                    Player1[x2][LengthBigCube - 1][z2].setTransparency(0.11);
                    Player1[x2][LengthBigCube - 1][z2].setColor(0.0, 0, 1);
                    /*if (a[x2][LengthBigCube - 1][z2].getHit() == 1)
                        a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
                    if (a[x2][LengthBigCube - 1][z2].getHit() == 2)
                        a[x2][LengthBigCube - 1][z2].setPaint(false);
*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[x2][i][z2].setTransparency(0.11);
                        Player1[x2][i][z2].setColor(0.5, 0.5, 0.8);
                        /*if (a[x2][i][z2].getHit() == 2)
                            a[x2][i][z2].setPaint(false);
                        a[x2][i][z2].setRed(false);*/
                    }
                    z2--;
                    if (z2 < 0)
                        z2 = LengthBigCube - 1;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[x2][i][z2].setTransparency(0.3);
                        // if (a[x2][i][z2].getHit() == 0)
                        Player1[x2][i][z2].setColor(1, 1, 0);
                        /*else
                        {
                            a[x2][i][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                            a[x2][i][z2].setPaint(true);
                            if (a[x2][i][z2].getHit() == 1)
                                a[x2][i][z2].setRed(true);
                        }*/
                    }
                    /*if (a[x2][LengthBigCube - 1][z2].getHit() != 0)
                    {
                        a[x2][LengthBigCube - 1][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x2][LengthBigCube - 1][z2].setPaint(true);
                        a[x2][LengthBigCube - 1][z2].setRed(true);
                    } else */ Player1[x2][LengthBigCube - 1][z2].setColor(1, 1, 0.0);
                    Player1[x2][LengthBigCube - 1][z2].setTransparency(0.7);
                } else
                {
                    Player2[x2][LengthBigCube - 1][z2].setTransparency(0.11);
                    Player2[x2][LengthBigCube - 1][z2].setColor(0.0, 0, 1);
                    /*if (a[x2][LengthBigCube - 1][z2].getHit() == 1)
                        a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
                    if (a[x2][LengthBigCube - 1][z2].getHit() == 2)
                        a[x2][LengthBigCube - 1][z2].setPaint(false);
*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[x2][i][z2].setTransparency(0.11);
                        Player2[x2][i][z2].setColor(0.5, 0.5, 0.8);
                        /*if (a[x2][i][z2].getHit() == 2)
                            a[x2][i][z2].setPaint(false);
                        a[x2][i][z2].setRed(false);*/
                    }
                    z2--;
                    if (z2 < 0)
                        z2 = LengthBigCube - 1;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[x2][i][z2].setTransparency(0.3);
                        // if (a[x2][i][z2].getHit() == 0)
                        Player2[x2][i][z2].setColor(1, 1, 0);
                        /*else
                        {
                            a[x2][i][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                            a[x2][i][z2].setPaint(true);
                            if (a[x2][i][z2].getHit() == 1)
                                a[x2][i][z2].setRed(true);
                        }*/
                    }
                    /*if (a[x2][LengthBigCube - 1][z2].getHit() != 0)
                    {
                        a[x2][LengthBigCube - 1][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x2][LengthBigCube - 1][z2].setPaint(true);
                        a[x2][LengthBigCube - 1][z2].setRed(true);
                    } else */ Player2[x2][LengthBigCube - 1][z2].setColor(1, 1, 0.0);
                    Player2[x2][LengthBigCube - 1][z2].setTransparency(0.7);
                }
            } else
            {
                a[x2][LengthBigCube - 1][z2].setTransparency(0.11);
                a[x2][LengthBigCube - 1][z2].setColor(0.0, 0, 1);
                if (a[x2][LengthBigCube - 1][z2].getHit() == 1)
                    a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
                if (a[x2][LengthBigCube - 1][z2].getHit() == 2)
                    a[x2][LengthBigCube - 1][z2].setPaint(false);

                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[x2][i][z2].setTransparency(0.11);
                    a[x2][i][z2].setColor(0.5, 0.5, 0.8);
                    if (a[x2][i][z2].getHit() == 2)
                        a[x2][i][z2].setPaint(false);
                    a[x2][i][z2].setRed(false);
                }
                z2--;
                if (z2 < 0)
                    z2 = LengthBigCube - 1;
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[x2][i][z2].setTransparency(0.3);
                    if (a[x2][i][z2].getHit() == 0)
                        a[x2][i][z2].setColor(1, 1, 0);
                    else
                    {
                        a[x2][i][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x2][i][z2].setPaint(true);
                        if (a[x2][i][z2].getHit() == 1)
                            a[x2][i][z2].setRed(true);
                    }
                }
                if (a[x2][LengthBigCube - 1][z2].getHit() != 0)
                {
                    a[x2][LengthBigCube - 1][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                    a[x2][LengthBigCube - 1][z2].setPaint(true);
                    a[x2][LengthBigCube - 1][z2].setRed(true);
                } else a[x2][LengthBigCube - 1][z2].setColor(1, 1, 0.0);
                a[x2][LengthBigCube - 1][z2].setTransparency(0.7);
            }
        } else if (arrow == 1)
        {//стрелочка вверх
            if (forTwoPlayers == 2)
            {
                if (isPlayer1)
                {
                    Player1[x2][LengthBigCube - 1][z2].setTransparency(0.11);
                    Player1[x2][LengthBigCube - 1][z2].setColor(0.0, 0, 1);
                    /*if (a[x2][LengthBigCube - 1][z2].getHit() == 1)
                        a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
                    if (a[x2][LengthBigCube - 1][z2].getHit() == 2)
                        a[x2][LengthBigCube - 1][z2].setPaint(false);
*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[x2][i][z2].setTransparency(0.11);
                        Player1[x2][i][z2].setColor(0.5, 0.5, 0.8);
                        /*if (a[x2][i][z2].getHit() == 2)
                            a[x2][i][z2].setPaint(false);
                        a[x2][i][z2].setRed(false);*/
                    }
                    x2++;
                    if (x2 > LengthBigCube - 1)
                        x2 = 0;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[x2][i][z2].setTransparency(0.3);
                        // if (a[x2][i][z2].getHit() == 0)
                        Player1[x2][i][z2].setColor(1, 1, 0);
                        /*else
                        {
                            a[x2][i][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                            a[x2][i][z2].setPaint(true);
                            if (a[x2][i][z2].getHit() == 1)
                                a[x2][i][z2].setRed(true);
                        }*/
                    }
                    /*if (a[x2][LengthBigCube - 1][z2].getHit() != 0)
                    {
                        a[x2][LengthBigCube - 1][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x2][LengthBigCube - 1][z2].setPaint(true);
                        a[x2][LengthBigCube - 1][z2].setRed(true);
                    } else */ Player1[x2][LengthBigCube - 1][z2].setColor(1, 1, 0.0);
                    Player1[x2][LengthBigCube - 1][z2].setTransparency(0.7);
                } else
                {
                    Player2[x2][LengthBigCube - 1][z2].setTransparency(0.11);
                    Player2[x2][LengthBigCube - 1][z2].setColor(0.0, 0, 1);
                    /*if (a[x2][LengthBigCube - 1][z2].getHit() == 1)
                        a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
                    if (a[x2][LengthBigCube - 1][z2].getHit() == 2)
                        a[x2][LengthBigCube - 1][z2].setPaint(false);
*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[x2][i][z2].setTransparency(0.11);
                        Player2[x2][i][z2].setColor(0.5, 0.5, 0.8);
                        /*if (a[x2][i][z2].getHit() == 2)
                            a[x2][i][z2].setPaint(false);
                        a[x2][i][z2].setRed(false);*/
                    }
                    x2++;
                    if (x2 > LengthBigCube - 1)
                        x2 = 0;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[x2][i][z2].setTransparency(0.3);
                        // if (a[x2][i][z2].getHit() == 0)
                        Player2[x2][i][z2].setColor(1, 1, 0);
                        /*else
                        {
                            a[x2][i][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                            a[x2][i][z2].setPaint(true);
                            if (a[x2][i][z2].getHit() == 1)
                                a[x2][i][z2].setRed(true);
                        }*/
                    }
                    /*if (a[x2][LengthBigCube - 1][z2].getHit() != 0)
                    {
                        a[x2][LengthBigCube - 1][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x2][LengthBigCube - 1][z2].setPaint(true);
                        a[x2][LengthBigCube - 1][z2].setRed(true);
                    } else */ Player2[x2][LengthBigCube - 1][z2].setColor(1, 1, 0.0);
                    Player2[x2][LengthBigCube - 1][z2].setTransparency(0.7);
                }
            } else
            {
                a[x2][LengthBigCube - 1][z2].setTransparency(0.11);
                a[x2][LengthBigCube - 1][z2].setColor(0.0, 0, 1);
                if (a[x2][LengthBigCube - 1][z2].getHit() == 1)
                    a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
                if (a[x2][LengthBigCube - 1][z2].getHit() == 2)
                    a[x2][LengthBigCube - 1][z2].setPaint(false);
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[x2][i][z2].setTransparency(0.11);
                    a[x2][i][z2].setColor(0.5, 0.5, 0.8);
                    if (a[x2][i][z2].getHit() == 2)
                        a[x2][i][z2].setPaint(false);
                    a[x2][i][z2].setRed(false);
                }
                x2++;
                if (x2 > LengthBigCube - 1)
                    x2 = 0;
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[x2][i][z2].setTransparency(0.3);
                    if (a[x2][i][z2].getHit() == 0)
                        a[x2][i][z2].setColor(1, 1, 0);
                    else
                    {
                        a[x2][i][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x2][i][z2].setPaint(true);
                        if (a[x2][i][z2].getHit() == 1)
                            a[x2][i][z2].setRed(true);
                    }
                }
                if (a[x2][LengthBigCube - 1][z2].getHit() != 0)
                {
                    a[x2][LengthBigCube - 1][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                    a[x2][LengthBigCube - 1][z2].setPaint(true);
                    a[x2][LengthBigCube - 1][z2].setRed(true);
                } else a[x2][LengthBigCube - 1][z2].setColor(1, 1, 0.0);
                a[x2][LengthBigCube - 1][z2].setTransparency(0.7);
            }
        } else if (arrow == 3)
        {//стрелочка влево
            if (forTwoPlayers == 2)
            {
                if (isPlayer1)
                {
                    Player1[x2][LengthBigCube - 1][z2].setTransparency(0.11);
                    Player1[x2][LengthBigCube - 1][z2].setColor(0.0, 0, 1);
                    /*if (a[x2][LengthBigCube - 1][z2].getHit() == 1)
                        a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
                    if (a[x2][LengthBigCube - 1][z2].getHit() == 2)
                        a[x2][LengthBigCube - 1][z2].setPaint(false);
*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[x2][i][z2].setTransparency(0.11);
                        Player1[x2][i][z2].setColor(0.5, 0.5, 0.8);
                        /*if (a[x2][i][z2].getHit() == 2)
                            a[x2][i][z2].setPaint(false);
                        a[x2][i][z2].setRed(false);*/
                    }
                    z2++;
                    if (z2 > LengthBigCube - 1)
                        z2 = 0;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[x2][i][z2].setTransparency(0.3);
                        // if (a[x2][i][z2].getHit() == 0)
                        Player1[x2][i][z2].setColor(1, 1, 0);
                        /*else
                        {
                            a[x2][i][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                            a[x2][i][z2].setPaint(true);
                            if (a[x2][i][z2].getHit() == 1)
                                a[x2][i][z2].setRed(true);
                        }*/
                    }
                    /*if (a[x2][LengthBigCube - 1][z2].getHit() != 0)
                    {
                        a[x2][LengthBigCube - 1][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x2][LengthBigCube - 1][z2].setPaint(true);
                        a[x2][LengthBigCube - 1][z2].setRed(true);
                    } else */ Player1[x2][LengthBigCube - 1][z2].setColor(1, 1, 0.0);
                    Player1[x2][LengthBigCube - 1][z2].setTransparency(0.7);
                } else
                {
                    Player2[x2][LengthBigCube - 1][z2].setTransparency(0.11);
                    Player2[x2][LengthBigCube - 1][z2].setColor(0.0, 0, 1);
                    /*if (a[x2][LengthBigCube - 1][z2].getHit() == 1)
                        a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
                    if (a[x2][LengthBigCube - 1][z2].getHit() == 2)
                        a[x2][LengthBigCube - 1][z2].setPaint(false);
*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[x2][i][z2].setTransparency(0.11);
                        Player2[x2][i][z2].setColor(0.5, 0.5, 0.8);
                        /*if (a[x2][i][z2].getHit() == 2)
                            a[x2][i][z2].setPaint(false);
                        a[x2][i][z2].setRed(false);*/
                    }
                    z2++;
                    if (z2 > LengthBigCube - 1)
                        z2 = 0;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[x2][i][z2].setTransparency(0.3);
                        // if (a[x2][i][z2].getHit() == 0)
                        Player2[x2][i][z2].setColor(1, 1, 0);
                        /*else
                        {
                            a[x2][i][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                            a[x2][i][z2].setPaint(true);
                            if (a[x2][i][z2].getHit() == 1)
                                a[x2][i][z2].setRed(true);
                        }*/
                    }
                    /*if (a[x2][LengthBigCube - 1][z2].getHit() != 0)
                    {
                        a[x2][LengthBigCube - 1][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x2][LengthBigCube - 1][z2].setPaint(true);
                        a[x2][LengthBigCube - 1][z2].setRed(true);
                    } else */ Player2[x2][LengthBigCube - 1][z2].setColor(1, 1, 0.0);
                    Player2[x2][LengthBigCube - 1][z2].setTransparency(0.7);
                }
            } else
            {
                a[x2][LengthBigCube - 1][z2].setTransparency(0.11);
                a[x2][LengthBigCube - 1][z2].setColor(0.0, 0, 1);
                if (a[x2][LengthBigCube - 1][z2].getHit() == 1)
                    a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
                if (a[x2][LengthBigCube - 1][z2].getHit() == 2)
                    a[x2][LengthBigCube - 1][z2].setPaint(false);
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[x2][i][z2].setTransparency(0.11);
                    a[x2][i][z2].setColor(0.5, 0.5, 0.8);
                    if (a[x2][i][z2].getHit() == 2)
                        a[x2][i][z2].setPaint(false);
                    a[x2][i][z2].setRed(false);
                }
                z2++;
                if (z2 > LengthBigCube - 1)
                    z2 = 0;
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[x2][i][z2].setTransparency(0.3);
                    if (a[x2][i][z2].getHit() == 0)
                        a[x2][i][z2].setColor(1, 1, 0);
                    else
                    {
                        a[x2][i][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x2][i][z2].setPaint(true);
                        if (a[x2][i][z2].getHit() == 1)
                            a[x2][i][z2].setRed(true);
                    }
                }
                if (a[x2][LengthBigCube - 1][z2].getHit() != 0)
                {
                    a[x2][LengthBigCube - 1][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                    a[x2][LengthBigCube - 1][z2].setPaint(true);
                    a[x2][LengthBigCube - 1][z2].setRed(true);
                } else a[x2][LengthBigCube - 1][z2].setColor(1, 1, 0.0);
                a[x2][LengthBigCube - 1][z2].setTransparency(0.7);
            }
        } else if (arrow == 4)
        {//стрелочка вниз
            if (forTwoPlayers == 2)
            {
                if (isPlayer1)
                {
                    Player1[x2][LengthBigCube - 1][z2].setTransparency(0.11);
                    Player1[x2][LengthBigCube - 1][z2].setColor(0.0, 0, 1);
                    /*if (a[x2][LengthBigCube - 1][z2].getHit() == 1)
                        a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
                    if (a[x2][LengthBigCube - 1][z2].getHit() == 2)
                        a[x2][LengthBigCube - 1][z2].setPaint(false);
*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[x2][i][z2].setTransparency(0.11);
                        Player1[x2][i][z2].setColor(0.5, 0.5, 0.8);
                        /*if (a[x2][i][z2].getHit() == 2)
                            a[x2][i][z2].setPaint(false);
                        a[x2][i][z2].setRed(false);*/
                    }
                    x2--;
                    if (x2 < 0)
                        x2 = LengthBigCube - 1;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[x2][i][z2].setTransparency(0.3);
                        // if (a[x2][i][z2].getHit() == 0)
                        Player1[x2][i][z2].setColor(1, 1, 0);
                        /*else
                        {
                            a[x2][i][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                            a[x2][i][z2].setPaint(true);
                            if (a[x2][i][z2].getHit() == 1)
                                a[x2][i][z2].setRed(true);
                        }*/
                    }
                    /*if (a[x2][LengthBigCube - 1][z2].getHit() != 0)
                    {
                        a[x2][LengthBigCube - 1][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x2][LengthBigCube - 1][z2].setPaint(true);
                        a[x2][LengthBigCube - 1][z2].setRed(true);
                    } else */ Player1[x2][LengthBigCube - 1][z2].setColor(1, 1, 0.0);
                    Player1[x2][LengthBigCube - 1][z2].setTransparency(0.7);
                } else
                {
                    Player2[x2][LengthBigCube - 1][z2].setTransparency(0.11);
                    Player2[x2][LengthBigCube - 1][z2].setColor(0.0, 0, 1);
                    /*if (a[x2][LengthBigCube - 1][z2].getHit() == 1)
                        a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
                    if (a[x2][LengthBigCube - 1][z2].getHit() == 2)
                        a[x2][LengthBigCube - 1][z2].setPaint(false);
*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[x2][i][z2].setTransparency(0.11);
                        Player2[x2][i][z2].setColor(0.5, 0.5, 0.8);
                        /*if (a[x2][i][z2].getHit() == 2)
                            a[x2][i][z2].setPaint(false);
                        a[x2][i][z2].setRed(false);*/
                    }
                    x2--;
                    if (x2 < 0)
                        x2 = LengthBigCube - 1;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[x2][i][z2].setTransparency(0.3);
                        // if (a[x2][i][z2].getHit() == 0)
                        Player2[x2][i][z2].setColor(1, 1, 0);
                        /*else
                        {
                            a[x2][i][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                            a[x2][i][z2].setPaint(true);
                            if (a[x2][i][z2].getHit() == 1)
                                a[x2][i][z2].setRed(true);
                        }*/
                    }
                    /*if (a[x2][LengthBigCube - 1][z2].getHit() != 0)
                    {
                        a[x2][LengthBigCube - 1][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x2][LengthBigCube - 1][z2].setPaint(true);
                        a[x2][LengthBigCube - 1][z2].setRed(true);
                    } else */ Player2[x2][LengthBigCube - 1][z2].setColor(1, 1, 0.0);
                    Player2[x2][LengthBigCube - 1][z2].setTransparency(0.7);
                }
            } else
            {
                a[x2][LengthBigCube - 1][z2].setTransparency(0.11);
                a[x2][LengthBigCube - 1][z2].setColor(0.0, 0, 1);
                if (a[x2][LengthBigCube - 1][z2].getHit() == 1)
                    a[LengthBigCube - 1][yf][z1].setColor(0, 1, 0);
                if (a[x2][LengthBigCube - 1][z2].getHit() == 2)
                    a[x2][LengthBigCube - 1][z2].setPaint(false);
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[x2][i][z2].setTransparency(0.11);
                    a[x2][i][z2].setColor(0.5, 0.5, 0.8);
                    if (a[x2][i][z2].getHit() == 2)
                        a[x2][i][z2].setPaint(false);
                    a[x2][i][z2].setRed(false);
                }
                x2--;
                if (x2 < 0)
                    x2 = LengthBigCube - 1;
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[x2][i][z2].setTransparency(0.3);
                    if (a[x2][i][z2].getHit() == 0)
                        a[x2][i][z2].setColor(1, 1, 0);
                    else
                    {
                        a[x2][i][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x2][i][z2].setPaint(true);
                        if (a[x2][i][z2].getHit() == 1)
                            a[x2][i][z2].setRed(true);
                    }
                }
                if (a[x2][LengthBigCube - 1][z2].getHit() != 0)
                {
                    a[x2][LengthBigCube - 1][z2].setColor(255 / 255., 105 / 255., 60 / 255.);
                    a[x2][LengthBigCube - 1][z2].setPaint(true);
                    a[x2][LengthBigCube - 1][z2].setRed(true);
                } else a[x2][LengthBigCube - 1][z2].setColor(1, 1, 0.0);
                a[x2][LengthBigCube - 1][z2].setTransparency(0.7);
            }
        }

    } else if (thirdSide)// && forEnter >= 2)
    {

        if (arrow == 1)
        {//работает стрелочка вправо
            if (forTwoPlayers == 2)
            {
                if (isPlayer1)
                {
                    Player1[x3][y3][LengthBigCube - 1].setTransparency(0.11);
                    Player1[x3][y3][LengthBigCube - 1].setColor(0.0, 0.0, 1);
                    /*if (a[x3][y3][LengthBigCube - 1].getHit() == 2)
                        a[x3][y3][LengthBigCube - 1].setPaint(false);
                    if (a[x3][y3][LengthBigCube - 1].getHit() == 1)
                        a[x3][y3][LengthBigCube - 1].setColor(0, 1, 0);*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[x3][y3][i].setTransparency(0.11);
                        Player1[x3][y3][i].setColor(0.5, 0.5, 0.8);
                        /* if (a[x3][y3][i].getHit() == 2)
                             a[x3][y3][i].setPaint(false);
                         a[x3][y3][i].setRed(false);*/
                    }
                    x3++;
                    if (x3 > LengthBigCube - 1)
                        x3 = 0;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[x3][y3][i].setTransparency(0.3);
                        //if (a[x3][y3][i].getHit() == 0)
                        Player1[x3][y3][i].setColor(1, 1, 0);
                        /*else
                        {
                            a[x3][y3][i].setColor(255 / 255., 105 / 255., 60 / 255.);
                            a[x3][y3][i].setPaint(true);
                            if (a[x3][y3][i].getHit() == 1)
                                a[x3][y3][i].setRed(true);
                        }*/
                    }
                    /*if (a[x3][y3][LengthBigCube - 1].getHit() != 0)
                    {
                        a[x3][y3][LengthBigCube - 1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x3][y3][LengthBigCube - 1].setPaint(true);
                        a[x3][y3][LengthBigCube - 1].setRed(true);
                    } else*/ Player1[x3][y3][LengthBigCube - 1].setColor(1, 1, 0.0);
                    Player1[x3][y3][LengthBigCube - 1].setTransparency(0.7);
                } else
                {
                    Player2[x3][y3][LengthBigCube - 1].setTransparency(0.11);
                    Player2[x3][y3][LengthBigCube - 1].setColor(0.0, 0.0, 1);
                    /*if (a[x3][y3][LengthBigCube - 1].getHit() == 2)
                        a[x3][y3][LengthBigCube - 1].setPaint(false);
                    if (a[x3][y3][LengthBigCube - 1].getHit() == 1)
                        a[x3][y3][LengthBigCube - 1].setColor(0, 1, 0);*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[x3][y3][i].setTransparency(0.11);
                        Player2[x3][y3][i].setColor(0.5, 0.5, 0.8);
                        /* if (a[x3][y3][i].getHit() == 2)
                             a[x3][y3][i].setPaint(false);
                         a[x3][y3][i].setRed(false);*/
                    }
                    x3++;
                    if (x3 > LengthBigCube - 1)
                        x3 = 0;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[x3][y3][i].setTransparency(0.3);
                        //if (a[x3][y3][i].getHit() == 0)
                        Player2[x3][y3][i].setColor(1, 1, 0);
                        /*else
                        {
                            a[x3][y3][i].setColor(255 / 255., 105 / 255., 60 / 255.);
                            a[x3][y3][i].setPaint(true);
                            if (a[x3][y3][i].getHit() == 1)
                                a[x3][y3][i].setRed(true);
                        }*/
                    }
                    /*if (a[x3][y3][LengthBigCube - 1].getHit() != 0)
                    {
                        a[x3][y3][LengthBigCube - 1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x3][y3][LengthBigCube - 1].setPaint(true);
                        a[x3][y3][LengthBigCube - 1].setRed(true);
                    } else*/ Player2[x3][y3][LengthBigCube - 1].setColor(1, 1, 0.0);
                    Player2[x3][y3][LengthBigCube - 1].setTransparency(0.7);
                }
            } else
            {
                a[x3][y3][LengthBigCube - 1].setTransparency(0.11);
                a[x3][y3][LengthBigCube - 1].setColor(0.0, 0.0, 1);
                if (a[x3][y3][LengthBigCube - 1].getHit() == 2)
                    a[x3][y3][LengthBigCube - 1].setPaint(false);
                if (a[x3][y3][LengthBigCube - 1].getHit() == 1)
                    a[x3][y3][LengthBigCube - 1].setColor(0, 1, 0);
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[x3][y3][i].setTransparency(0.11);
                    a[x3][y3][i].setColor(0.5, 0.5, 0.8);
                    if (a[x3][y3][i].getHit() == 2)
                        a[x3][y3][i].setPaint(false);
                    a[x3][y3][i].setRed(false);
                }
                x3++;
                if (x3 > LengthBigCube - 1)
                    x3 = 0;
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[x3][y3][i].setTransparency(0.3);
                    if (a[x3][y3][i].getHit() == 0)
                        a[x3][y3][i].setColor(1, 1, 0);
                    else
                    {
                        a[x3][y3][i].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x3][y3][i].setPaint(true);
                        if (a[x3][y3][i].getHit() == 1)
                            a[x3][y3][i].setRed(true);
                    }
                }
                if (a[x3][y3][LengthBigCube - 1].getHit() != 0)
                {
                    a[x3][y3][LengthBigCube - 1].setColor(255 / 255., 105 / 255., 60 / 255.);
                    a[x3][y3][LengthBigCube - 1].setPaint(true);
                    a[x3][y3][LengthBigCube - 1].setRed(true);
                } else a[x3][y3][LengthBigCube - 1].setColor(1, 1, 0.0);
                a[x3][y3][LengthBigCube - 1].setTransparency(0.7);
            }
        } else if (arrow == 3)
        {//стрелочка вверх
            if (forTwoPlayers == 2)
            {
                if (isPlayer1)
                {
                    Player1[x3][y3][LengthBigCube - 1].setTransparency(0.11);
                    Player1[x3][y3][LengthBigCube - 1].setColor(0.0, 0.0, 1);
                    /*if (a[x3][y3][LengthBigCube - 1].getHit() == 2)
                        a[x3][y3][LengthBigCube - 1].setPaint(false);
                    if (a[x3][y3][LengthBigCube - 1].getHit() == 1)
                        a[x3][y3][LengthBigCube - 1].setColor(0, 1, 0);*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[x3][y3][i].setTransparency(0.11);
                        Player1[x3][y3][i].setColor(0.5, 0.5, 0.8);
                        /* if (a[x3][y3][i].getHit() == 2)
                             a[x3][y3][i].setPaint(false);
                         a[x3][y3][i].setRed(false);*/
                    }
                    y3--;
                    if (y3 < 0)
                        y3 = LengthBigCube - 1;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[x3][y3][i].setTransparency(0.3);
                        //if (a[x3][y3][i].getHit() == 0)
                        Player1[x3][y3][i].setColor(1, 1, 0);
                        /*else
                        {
                            a[x3][y3][i].setColor(255 / 255., 105 / 255., 60 / 255.);
                            a[x3][y3][i].setPaint(true);
                            if (a[x3][y3][i].getHit() == 1)
                                a[x3][y3][i].setRed(true);
                        }*/
                    }
                    /*if (a[x3][y3][LengthBigCube - 1].getHit() != 0)
                    {
                        a[x3][y3][LengthBigCube - 1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x3][y3][LengthBigCube - 1].setPaint(true);
                        a[x3][y3][LengthBigCube - 1].setRed(true);
                    } else*/ Player1[x3][y3][LengthBigCube - 1].setColor(1, 1, 0.0);
                    Player1[x3][y3][LengthBigCube - 1].setTransparency(0.7);
                } else
                {
                    Player2[x3][y3][LengthBigCube - 1].setTransparency(0.11);
                    Player2[x3][y3][LengthBigCube - 1].setColor(0.0, 0.0, 1);
                    /*if (a[x3][y3][LengthBigCube - 1].getHit() == 2)
                        a[x3][y3][LengthBigCube - 1].setPaint(false);
                    if (a[x3][y3][LengthBigCube - 1].getHit() == 1)
                        a[x3][y3][LengthBigCube - 1].setColor(0, 1, 0);*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[x3][y3][i].setTransparency(0.11);
                        Player2[x3][y3][i].setColor(0.5, 0.5, 0.8);
                        /* if (a[x3][y3][i].getHit() == 2)
                             a[x3][y3][i].setPaint(false);
                         a[x3][y3][i].setRed(false);*/
                    }
                    y3--;
                    if (y3 < 0)
                        y3 = LengthBigCube - 1;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[x3][y3][i].setTransparency(0.3);
                        //if (a[x3][y3][i].getHit() == 0)
                        Player2[x3][y3][i].setColor(1, 1, 0);
                        /*else
                        {
                            a[x3][y3][i].setColor(255 / 255., 105 / 255., 60 / 255.);
                            a[x3][y3][i].setPaint(true);
                            if (a[x3][y3][i].getHit() == 1)
                                a[x3][y3][i].setRed(true);
                        }*/
                    }
                    /*if (a[x3][y3][LengthBigCube - 1].getHit() != 0)
                    {
                        a[x3][y3][LengthBigCube - 1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x3][y3][LengthBigCube - 1].setPaint(true);
                        a[x3][y3][LengthBigCube - 1].setRed(true);
                    } else*/ Player2[x3][y3][LengthBigCube - 1].setColor(1, 1, 0.0);
                    Player2[x3][y3][LengthBigCube - 1].setTransparency(0.7);
                }
            } else
            {
                a[x3][y3][LengthBigCube - 1].setTransparency(0.11);
                a[x3][y3][LengthBigCube - 1].setColor(0.0, 0.0, 1);
                if (a[x3][y3][LengthBigCube - 1].getHit() == 2)
                    a[x3][y3][LengthBigCube - 1].setPaint(false);
                if (a[x3][y3][LengthBigCube - 1].getHit() == 1)
                    a[x3][y3][LengthBigCube - 1].setColor(0, 1, 0);
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[x3][y3][i].setTransparency(0.11);
                    a[x3][y3][i].setColor(0.5, 0.5, 0.8);
                    if (a[x3][y3][i].getHit() == 2)
                        a[x3][y3][i].setPaint(false);
                    a[x3][y3][i].setRed(false);
                }
                y3--;
                if (y3 < 0)
                    y3 = LengthBigCube - 1;
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[x3][y3][i].setTransparency(0.3);
                    if (a[x3][y3][i].getHit() == 0)
                        a[x3][y3][i].setColor(1, 1, 0);
                    else
                    {
                        a[x3][y3][i].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x3][y3][i].setPaint(true);
                        if (a[x3][y3][i].getHit() == 1)
                            a[x3][y3][i].setRed(true);
                    }
                }
                if (a[x3][y3][LengthBigCube - 1].getHit() != 0)
                {
                    a[x3][y3][LengthBigCube - 1].setColor(255 / 255., 105 / 255., 60 / 255.);
                    a[x3][y3][LengthBigCube - 1].setPaint(true);
                    a[x3][y3][LengthBigCube - 1].setRed(true);
                } else a[x3][y3][LengthBigCube - 1].setColor(1, 1, 0.0);
                a[x3][y3][LengthBigCube - 1].setTransparency(0.7);
            }
        } else if (arrow == 4)
        {//стрелочка влево
            if (forTwoPlayers == 2)
            {
                if (isPlayer1)
                {
                    Player1[x3][y3][LengthBigCube - 1].setTransparency(0.11);
                    Player1[x3][y3][LengthBigCube - 1].setColor(0.0, 0.0, 1);
                    /*if (a[x3][y3][LengthBigCube - 1].getHit() == 2)
                        a[x3][y3][LengthBigCube - 1].setPaint(false);
                    if (a[x3][y3][LengthBigCube - 1].getHit() == 1)
                        a[x3][y3][LengthBigCube - 1].setColor(0, 1, 0);*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[x3][y3][i].setTransparency(0.11);
                        Player1[x3][y3][i].setColor(0.5, 0.5, 0.8);
                        /* if (a[x3][y3][i].getHit() == 2)
                             a[x3][y3][i].setPaint(false);
                         a[x3][y3][i].setRed(false);*/
                    }
                    x3--;
                    if (x3 < 0)
                        x3 = LengthBigCube - 1;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[x3][y3][i].setTransparency(0.3);
                        //if (a[x3][y3][i].getHit() == 0)
                        Player1[x3][y3][i].setColor(1, 1, 0);
                        /*else
                        {
                            a[x3][y3][i].setColor(255 / 255., 105 / 255., 60 / 255.);
                            a[x3][y3][i].setPaint(true);
                            if (a[x3][y3][i].getHit() == 1)
                                a[x3][y3][i].setRed(true);
                        }*/
                    }
                    /*if (a[x3][y3][LengthBigCube - 1].getHit() != 0)
                    {
                        a[x3][y3][LengthBigCube - 1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x3][y3][LengthBigCube - 1].setPaint(true);
                        a[x3][y3][LengthBigCube - 1].setRed(true);
                    } else*/ Player1[x3][y3][LengthBigCube - 1].setColor(1, 1, 0.0);
                    Player1[x3][y3][LengthBigCube - 1].setTransparency(0.7);
                } else
                {
                    Player2[x3][y3][LengthBigCube - 1].setTransparency(0.11);
                    Player2[x3][y3][LengthBigCube - 1].setColor(0.0, 0.0, 1);
                    /*if (a[x3][y3][LengthBigCube - 1].getHit() == 2)
                        a[x3][y3][LengthBigCube - 1].setPaint(false);
                    if (a[x3][y3][LengthBigCube - 1].getHit() == 1)
                        a[x3][y3][LengthBigCube - 1].setColor(0, 1, 0);*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[x3][y3][i].setTransparency(0.11);
                        Player2[x3][y3][i].setColor(0.5, 0.5, 0.8);
                        /* if (a[x3][y3][i].getHit() == 2)
                             a[x3][y3][i].setPaint(false);
                         a[x3][y3][i].setRed(false);*/
                    }
                    x3--;
                    if (x3 < 0)
                        x3 = LengthBigCube - 1;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[x3][y3][i].setTransparency(0.3);
                        //if (a[x3][y3][i].getHit() == 0)
                        Player2[x3][y3][i].setColor(1, 1, 0);
                        /*else
                        {
                            a[x3][y3][i].setColor(255 / 255., 105 / 255., 60 / 255.);
                            a[x3][y3][i].setPaint(true);
                            if (a[x3][y3][i].getHit() == 1)
                                a[x3][y3][i].setRed(true);
                        }*/
                    }
                    /*if (a[x3][y3][LengthBigCube - 1].getHit() != 0)
                    {
                        a[x3][y3][LengthBigCube - 1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x3][y3][LengthBigCube - 1].setPaint(true);
                        a[x3][y3][LengthBigCube - 1].setRed(true);
                    } else*/ Player2[x3][y3][LengthBigCube - 1].setColor(1, 1, 0.0);
                    Player2[x3][y3][LengthBigCube - 1].setTransparency(0.7);
                }
            } else
            {
                a[x3][y3][LengthBigCube - 1].setTransparency(0.11);
                a[x3][y3][LengthBigCube - 1].setColor(0.0, 0.0, 1);
                if (a[x3][y3][LengthBigCube - 1].getHit() == 2)
                    a[x3][y3][LengthBigCube - 1].setPaint(false);
                if (a[x3][y3][LengthBigCube - 1].getHit() == 1)
                    a[x3][y3][LengthBigCube - 1].setColor(0, 1, 0);
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[x3][y3][i].setTransparency(0.11);
                    a[x3][y3][i].setColor(0.5, 0.5, 0.8);
                    if (a[x3][y3][i].getHit() == 2)
                        a[x3][y3][i].setPaint(false);
                    a[x3][y3][i].setRed(false);
                }
                x3--;
                if (x3 < 0)
                    x3 = LengthBigCube - 1;
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[x3][y3][i].setTransparency(0.3);
                    if (a[x3][y3][i].getHit() == 0)
                        a[x3][y3][i].setColor(1, 1, 0);
                    else
                    {
                        a[x3][y3][i].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x3][y3][i].setPaint(true);
                        if (a[x3][y3][i].getHit() == 1)
                            a[x3][y3][i].setRed(true);
                    }
                }
                if (a[x3][y3][LengthBigCube - 1].getHit() != 0)
                {
                    a[x3][y3][LengthBigCube - 1].setColor(255 / 255., 105 / 255., 60 / 255.);
                    a[x3][y3][LengthBigCube - 1].setPaint(true);
                    a[x3][y3][LengthBigCube - 1].setRed(true);
                } else a[x3][y3][LengthBigCube - 1].setColor(1, 1, 0.0);
                a[x3][y3][LengthBigCube - 1].setTransparency(0.7);
            }
        } else if (arrow == 2)
        {//стрелочка вниз
            if (forTwoPlayers == 2)
            {
                if (isPlayer1)
                {
                    Player1[x3][y3][LengthBigCube - 1].setTransparency(0.11);
                    Player1[x3][y3][LengthBigCube - 1].setColor(0.0, 0.0, 1);
                    /*if (a[x3][y3][LengthBigCube - 1].getHit() == 2)
                        a[x3][y3][LengthBigCube - 1].setPaint(false);
                    if (a[x3][y3][LengthBigCube - 1].getHit() == 1)
                        a[x3][y3][LengthBigCube - 1].setColor(0, 1, 0);*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[x3][y3][i].setTransparency(0.11);
                        Player1[x3][y3][i].setColor(0.5, 0.5, 0.8);
                        /* if (a[x3][y3][i].getHit() == 2)
                             a[x3][y3][i].setPaint(false);
                         a[x3][y3][i].setRed(false);*/
                    }
                    y3++;
                    if (y3 > LengthBigCube - 1)
                        y3 = 0;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player1[x3][y3][i].setTransparency(0.3);
                        //if (a[x3][y3][i].getHit() == 0)
                        Player1[x3][y3][i].setColor(1, 1, 0);
                        /*else
                        {
                            a[x3][y3][i].setColor(255 / 255., 105 / 255., 60 / 255.);
                            a[x3][y3][i].setPaint(true);
                            if (a[x3][y3][i].getHit() == 1)
                                a[x3][y3][i].setRed(true);
                        }*/
                    }
                    /*if (a[x3][y3][LengthBigCube - 1].getHit() != 0)
                    {
                        a[x3][y3][LengthBigCube - 1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x3][y3][LengthBigCube - 1].setPaint(true);
                        a[x3][y3][LengthBigCube - 1].setRed(true);
                    } else*/ Player1[x3][y3][LengthBigCube - 1].setColor(1, 1, 0.0);
                    Player1[x3][y3][LengthBigCube - 1].setTransparency(0.7);
                } else
                {
                    Player2[x3][y3][LengthBigCube - 1].setTransparency(0.11);
                    Player2[x3][y3][LengthBigCube - 1].setColor(0.0, 0.0, 1);
                    /*if (a[x3][y3][LengthBigCube - 1].getHit() == 2)
                        a[x3][y3][LengthBigCube - 1].setPaint(false);
                    if (a[x3][y3][LengthBigCube - 1].getHit() == 1)
                        a[x3][y3][LengthBigCube - 1].setColor(0, 1, 0);*/
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[x3][y3][i].setTransparency(0.11);
                        Player2[x3][y3][i].setColor(0.5, 0.5, 0.8);
                        /* if (a[x3][y3][i].getHit() == 2)
                             a[x3][y3][i].setPaint(false);
                         a[x3][y3][i].setRed(false);*/
                    }
                    y3++;
                    if (y3 > LengthBigCube - 1)
                        y3 = 0;
                    for (int i = 0; i < LengthBigCube - 1; i++)
                    {
                        Player2[x3][y3][i].setTransparency(0.3);
                        //if (a[x3][y3][i].getHit() == 0)
                        Player2[x3][y3][i].setColor(1, 1, 0);
                        /*else
                        {
                            a[x3][y3][i].setColor(255 / 255., 105 / 255., 60 / 255.);
                            a[x3][y3][i].setPaint(true);
                            if (a[x3][y3][i].getHit() == 1)
                                a[x3][y3][i].setRed(true);
                        }*/
                    }
                    /*if (a[x3][y3][LengthBigCube - 1].getHit() != 0)
                    {
                        a[x3][y3][LengthBigCube - 1].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x3][y3][LengthBigCube - 1].setPaint(true);
                        a[x3][y3][LengthBigCube - 1].setRed(true);
                    } else*/ Player2[x3][y3][LengthBigCube - 1].setColor(1, 1, 0.0);
                    Player2[x3][y3][LengthBigCube - 1].setTransparency(0.7);
                }
            } else
            {
                a[x3][y3][LengthBigCube - 1].setTransparency(0.11);
                a[x3][y3][LengthBigCube - 1].setColor(0.0, 0.0, 1);
                if (a[x3][y3][LengthBigCube - 1].getHit() == 2)
                    a[x3][y3][LengthBigCube - 1].setPaint(false);
                if (a[x3][y3][LengthBigCube - 1].getHit() == 1)
                    a[x3][y3][LengthBigCube - 1].setColor(0, 1, 0);
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[x3][y3][i].setTransparency(0.11);
                    a[x3][y3][i].setColor(0.5, 0.5, 0.8);
                    if (a[x3][y3][i].getHit() == 2)
                        a[x3][y3][i].setPaint(false);
                    a[x3][y3][i].setRed(false);
                }
                y3++;
                if (y3 > LengthBigCube - 1)
                    y3 = 0;
                for (int i = 0; i < LengthBigCube - 1; i++)
                {
                    a[x3][y3][i].setTransparency(0.3);
                    if (a[x3][y3][i].getHit() == 0)
                        a[x3][y3][i].setColor(1, 1, 0);
                    else
                    {
                        a[x3][y3][i].setColor(255 / 255., 105 / 255., 60 / 255.);
                        a[x3][y3][i].setPaint(true);
                        if (a[x3][y3][i].getHit() == 1)
                            a[x3][y3][i].setRed(true);
                    }
                }
                if (a[x3][y3][LengthBigCube - 1].getHit() != 0)
                {
                    a[x3][y3][LengthBigCube - 1].setColor(255 / 255., 105 / 255., 60 / 255.);
                    a[x3][y3][LengthBigCube - 1].setPaint(true);
                    a[x3][y3][LengthBigCube - 1].setRed(true);
                } else a[x3][y3][LengthBigCube - 1].setColor(1, 1, 0.0);
                a[x3][y3][LengthBigCube - 1].setTransparency(0.7);
            }
        }
    }
    forEnter = 3;
}

void ChooseCube2(int page)
{
    if(isPlayer1)
    {
        if (firstSide)
        {
            if (page == 1)
            {
                Player1[p1][yf][z1].setTransparency(0.11);
                p1++;
                if (p1 > LengthBigCube - 1)
                    p1 = 0;
                Player1[p1][yf][z1].setTransparency(0.7);
            } else if (page == 2)
            {
                Player1[p1][yf][z1].setTransparency(0.11);
                p1--;
                if (p1 < 0)
                    p1 = LengthBigCube - 1;
                Player1[p1][yf][z1].setTransparency(0.7);
            }
        } else if (secondSide)
        {
            if (page == 1)
            {
                Player1[x2][p2][z2].setTransparency(0.11);
                p2++;
                if (p2 > LengthBigCube - 1)
                    p2 = 0;
                Player1[x2][p2][z2].setTransparency(0.7);
            } else if (page == 2)
            {
                Player1[x2][p2][z2].setTransparency(0.11);
                p2--;
                if (p2 < 0)
                    p2 = LengthBigCube - 1;
                Player1[x2][p2][z2].setTransparency(0.7);
            }
        } else if (thirdSide)
        {
            if (page == 1)
            {
                Player1[x3][y3][p3].setTransparency(0.11);
                p3++;
                if (p3 > LengthBigCube - 1)
                    p3 = 0;
                Player1[x3][y3][p3].setTransparency(0.7);
            } else if (page == 2)
            {
                Player1[x3][y3][p3].setTransparency(0.11);
                p3--;
                if (p3 < 0)
                    p3 = LengthBigCube - 1;
                Player1[x3][y3][p3].setTransparency(0.7);
            }

        }
    } else
    {
        if (firstSide)
        {
            if (page == 1)
            {
                Player2[p1][yf][z1].setTransparency(0.11);
                p1++;
                if (p1 > LengthBigCube - 1)
                    p1 = 0;
                Player2[p1][yf][z1].setTransparency(0.7);
            } else if (page == 2)
            {
                Player2[p1][yf][z1].setTransparency(0.11);
                p1--;
                if (p1 < 0)
                    p1 = LengthBigCube - 1;
                Player2[p1][yf][z1].setTransparency(0.7);
            }
        } else if (secondSide)
        {
            if (page == 1)
            {
                Player2[x2][p2][z2].setTransparency(0.11);
                p2++;
                if (p2 > LengthBigCube - 1)
                    p2 = 0;
                Player2[x2][p2][z2].setTransparency(0.7);
            } else if (page == 2)
            {
                Player2[x2][p2][z2].setTransparency(0.11);
                p2--;
                if (p2 < 0)
                    p2 = LengthBigCube - 1;
                Player2[x2][p2][z2].setTransparency(0.7);
            }
        } else if (thirdSide)
        {
            if (page == 1)
            {
                Player2[x3][y3][p3].setTransparency(0.11);
                p3++;
                if (p3 > LengthBigCube - 1)
                    p3 = 0;
                Player2[x3][y3][p3].setTransparency(0.7);
            } else if (page == 2)
            {
                Player2[x3][y3][p3].setTransparency(0.11);
                p3--;
                if (p3 < 0)
                    p3 = LengthBigCube - 1;
                Player2[x3][y3][p3].setTransparency(0.7);
            }

        }
    }

}

// 1 == left, 2 == up, 3 == down, 4 == right
void specialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_F1)
    {
        help = (!help);
        //movement = (!movement);
    }

    if (key == GLUT_KEY_F2)
    {
        statistics = (!statistics);
    }

    if (key == GLUT_KEY_RIGHT)
    {
        if (forEnter == -1)
        {
            if (isPlayer1)
            {
                isPlayer1 = false;
                for (auto &i : Player1)
                    for (auto &j : i)
                        for (auto &k : j)
                            k.setColor(135 / 256., 206 / 256., 250 / 256.);
                for (auto &i : Player2)
                    for (auto &j : i)
                        for (auto &k : j)
                            k.setColor(1, 0, 0);
            } else
            {
                isPlayer1 = true;
                for (auto &i : Player2)
                    for (auto &j : i)
                        for (auto &k : j)
                            k.setColor(10 / 256., 254 / 256., 189 / 256.);
                for (auto &i : Player1)
                    for (auto &j : i)
                        for (auto &k : j)
                            k.setColor(1, 0, 0);
            }
        } else if (movement && forEnter != -1)
        {
            rotate_y += 5;
        } else
            ChooseColumn(4);
    }//если нажата клавиша "вправо", то поворачиваем

    else if (key == GLUT_KEY_LEFT)
    {
        if (forEnter == -1)
        {
            if (isPlayer1)
            {
                isPlayer1 = false;
                for (auto &i : Player1)
                    for (auto &j : i)
                        for (auto &k : j)
                            k.setColor(135 / 256., 206 / 256., 250 / 256.);
                for (auto &i : Player2)
                    for (auto &j : i)
                        for (auto &k : j)
                            k.setColor(1, 0, 0);
            } else
            {
                isPlayer1 = true;
                for (auto &i : Player2)
                    for (auto &j : i)
                        for (auto &k : j)
                            k.setColor(10 / 256., 254 / 256., 189 / 256.);
                for (auto &i : Player1)
                    for (auto &j : i)
                        for (auto &k : j)
                            k.setColor(1, 0, 0);
            }
        } else if (movement && forEnter != -1)
        {
            rotate_y -= 5;
        } else
            ChooseColumn(1);
    }//аналогично для левой клавиши

    else if (key == GLUT_KEY_UP)
    {
        if (forEnter == -1)
        {

        } else if (movement && forEnter != -1)
        {
            //if (rotate_x <= -5)
            rotate_x += 5;
        } else
            ChooseColumn(2);
    } //это уже повороты  вверх и вниз

    else if (key == GLUT_KEY_DOWN)
    {
        if (forEnter == -1)
        {
            //
        } else if (movement && forEnter != -1)
        {
            //if (rotate_x >= -85)
            rotate_x -= 5;
        } else
            ChooseColumn(3);
    } else if (key == GLUT_KEY_HOME && forEnter <= 1)
    {
        default_position(r_rotate_x, r_rotate_y);
    } else if (key == GLUT_KEY_PAGE_UP && (forEnter == 4 || forEnter == 5))
    {
        if (forTwoPlayers < 2)
            ChooseCube(1);
        else ChooseCube2(1);
        forEnter = 5;
    } else if (key == GLUT_KEY_PAGE_DOWN && (forEnter == 4 || forEnter == 5))
    {
        if (forTwoPlayers < 2)
            ChooseCube(2);
        else ChooseCube2(2);
        forEnter = 5;
    }


    if (key == GLUT_KEY_F7 && (forEnter == 0 || forEnter == 1))
    {
        //std::cout << "123    ";
        if (forTwoPlayers == 2)
        {
            if (isPlayer1)
                view_first_side_Player1(r_rotate_x, r_rotate_y);
            else view_first_side_Player2(r_rotate_x, r_rotate_y);
        } else
            view_first_side(r_rotate_x, r_rotate_y);
        forEnter = 1;
        //movement = false;
        firstSide = true;
        thirdSide = false;
        secondSide = false;
    } else if (key == GLUT_KEY_F8 && (forEnter == 0 || forEnter == 1))
    {
        if (forTwoPlayers == 2)
        {
            if (isPlayer1)
                view_second_side_Player1(r_rotate_x, r_rotate_y);
            else view_second_side_Player2(r_rotate_x, r_rotate_y);
        } else
            view_second_side(r_rotate_x, r_rotate_y);
        forEnter = 1;
        secondSide = true;
        firstSide = false;
        thirdSide = false;
    } else if (key == GLUT_KEY_F9 && (forEnter == 0 || forEnter == 1))
    {
        if (forTwoPlayers == 2)
        {
            if (isPlayer1)
                view_third_side_Player1(r_rotate_x, r_rotate_y);
            else view_third_side_Player2(r_rotate_x, r_rotate_y);
        } else
            view_third_side(r_rotate_x, r_rotate_y);
        forEnter = 1;
        thirdSide = true;
        firstSide = false;
        secondSide = false;
    }

    glutPostRedisplay(); //а это просто обязательная функция
}


#endif //INC_3DSEEBUTTLE_WORKWITHKEYS_H
