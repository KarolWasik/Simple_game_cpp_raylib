#include "CubeG2.h"
#include "raylib.h"
#include <string>
 void cube :: set_position(int x, int y)
 {
    this -> x = x;
    this -> y = y;
 }

 void cube :: set_size(int height, int width)
 {
    this -> height = height;
    this -> width = width;
 }

void cube :: set_speed(int speed)
{
    this -> direction = speed;
}

void cube :: set_screen(int width, int height)
{
    this -> s_height = height;
    this -> s_width = width;
}

void cube :: variable_update()
{
    this -> left_x = this -> x;
    this -> right_x = this -> x + this -> width;
    this -> up_y = this -> y;
    this -> down_y = this -> y + this -> height;
}

void cube :: movement()
{
    if(this -> down_y >= this -> s_height || this -> up_y <= 0)
    {
        this -> direction = this -> direction * (-1);
    }
    this -> y += direction;
    variable_update();
}

 void cube :: draw_cube()
{
    DrawRectangle(this -> x, this -> y, this -> width, this -> height, BLUE);
}

cube :: cube(int x, int y, int width, int height, int speed, int s_width, int s_height)
{
    set_position(x, y);
    set_size(height, width);
    set_speed(speed);
    set_screen(s_width, s_height);
}