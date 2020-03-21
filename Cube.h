//
// Created by alik on 18.03.2020.
//

#ifndef INC_3DSEEBUTTLE_CUBE_H
#define INC_3DSEEBUTTLE_CUBE_H

class Cube{
private:
    double transparency;  //прозрачность
    double length;  //длина стороны
    int forHit;  //для ударов и выбора кубика

    double red;
    double blue;
    double green;

    double x;
    double y;
    double z;

public:
    Cube(){
         transparency = 0;
         length = 0;
         forHit = 0;

         red = 1;
         blue = 1;
         green = 1;

         x = 0;
         y = 0;
         z = 0;
    }
    Cube(double length, double x, double y, double z, double red, double blue, double green, double transparency){
        this->length = length;
        this->transparency = transparency;
        forHit = 0;

        this->red = red;
        this->blue = blue;
        this->green = green;

        this->x = x;
        this->y = y;
        this->z = z;

        glBegin(GL_POLYGON);  //начинаем рисовать грань
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y - length/2, z - length/2);  //здесь и далее сначала цвет
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y - length/2, z - length/2);  //(красный, зеленый, синий, прозрачность)
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y + length/2, z - length/2);  //потом идет положение точки
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y + length/2, z - length/2);  //4 точки - 1 грань
        glEnd();  //закончили рисовать одну грань

        glBegin(GL_POLYGON);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y - length/2, z - length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y - length/2, z - length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y - length/2, z + length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y - length/2, z + length/2);
        glEnd();

        glBegin(GL_POLYGON);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y - length/2, z - length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y + length/2, z - length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y + length/2, z + length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y - length/2, z + length/2);
        glEnd();

        glBegin(GL_POLYGON);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y + length/2, z - length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y + length/2, z - length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y + length/2, z + length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y + length/2, z + length/2);
        glEnd();

        glBegin(GL_POLYGON);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y - length/2, z - length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y - length/2, z + length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y + length/2, z + length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y + length/2, z - length/2);
        glEnd();

        glBegin(GL_POLYGON);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y - length/2, z + length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y - length/2, z + length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y + length/2, z + length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x - length/2, y + length/2, z + length/2);
        glEnd();

        //пошли ребра
        //пошли ребра
        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y - length/2, z - length/2);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y - length/2, z - length/2);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y - length/2, z - length/2);
        glColor4f(red, green, blue, transparency);
        glVertex3f(x + length/2, y + length/2, z - length/2);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y + length/2, z - length/2);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y + length/2, z - length/2);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y - length/2, z - length/2);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y + length/2, z - length/2);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y - length/2, z - length/2);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y - length/2, z - length/2);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y - length/2, z - length/2);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y - length/2, z + length/2);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y - length/2, z + length/2);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y - length/2, z + length/2);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y - length/2, z - length/2);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y - length/2, z + length/2);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y - length/2, z - length/2);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y + length/2, z - length/2);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y + length/2, z - length/2);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y + length/2, z + length/2);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y + length/2, z + length/2);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y - length/2, z + length/2);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y - length/2, z - length/2);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y - length/2, z + length/2);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y + length/2, z - length/2);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y + length/2, z - length/2);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y + length/2, z - length/2);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y + length/2, z + length/2);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y + length/2, z + length/2);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y + length/2, z + length/2);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y + length/2, z - length/2);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y + length/2, z + length/2);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y - length/2, z - length/2);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y - length/2, z + length/2);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y - length/2, z + length/2);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y + length/2, z + length/2);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y + length/2, z + length/2);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y + length/2, z - length/2);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y - length/2, z - length/2);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y + length/2, z - length/2);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y - length/2, z + length/2);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y - length/2, z + length/2);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y - length/2, z + length/2);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y + length/2, z + length/2);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x + length/2, y + length/2, z + length/2);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y + length/2, z + length/2);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y - length/2, z + length/2);
        glColor3f(red, green, blue);
        glVertex3f(x - length/2, y + length/2, z + length/2);
        glEnd();

    }
    void setColor(double red, double blue, double green){
        this->red = red;
        this->blue = blue;
        this->green = green;
    }

    void setIsHitten(int hit){
        this->forHit = hit;
    }
};

#endif //INC_3DSEEBUTTLE_CUBE_H
