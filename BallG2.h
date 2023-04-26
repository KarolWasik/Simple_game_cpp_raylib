#include "raylib.h"
class BallG2
{
    private:
    int r = 30;
    int x;
    int y;
    int speed = 5;
    int screen_width = 700;
    int screen_height = 500;

    public:
    int l_circle_x = 0;
    int r_circle_x = 0;
    int up_circle_y = 0;
    int down_circle_y = 0;
    private:
    void set_size(int r);

    public:
    void update_area();
    void set_position(int x, int y);
    void movement();
    void draw_ball();
    BallG2(int x, int y, int r);


};