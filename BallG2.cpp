#include "BallG2.h"

void BallG2:: set_position(int x, int y)
{
    this ->x = x;
    this -> y = y;
}

void BallG2 :: set_size(int r)
{
    this -> r = r;
}

void BallG2 :: movement()
{
        if(IsKeyDown(KEY_W) == true and this -> y>0)
        {
            this -> y = this -> y - this -> speed;
        }
        if(IsKeyDown(KEY_S) == true and this -> y<this -> screen_height)
        {
            this -> y = this -> y + this -> speed;
        }
        if(IsKeyDown(KEY_A) == true and this -> x>0)
        {
            this -> x = this -> x - this -> speed;
        }
        if(IsKeyDown(KEY_D) == true and this -> x<this -> screen_width)
        {
            this -> x = this -> x + this -> speed;
        }
        update_area();
}

void BallG2 :: update_area()
{
    this -> l_circle_x = this -> x - this -> r;
    this -> r_circle_x = this -> x + this -> r;
    this -> up_circle_y = this -> y - this -> r;
    this -> down_circle_y = this -> y + this -> r;
}

void BallG2 :: draw_ball()
{
    DrawCircle(this->x, this->y,this->r,RED);   
}

BallG2::BallG2(int x, int y, int r)
{
    set_position(x,y);
    set_size(r);
}