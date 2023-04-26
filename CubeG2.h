#include <string>
class cube
{
    private:
    //screen size
    int s_width;
    int s_height;

    //size
    int width;
    int height;

    //position
    int x;
    int y;

    //area
    public:
    int left_x = x;
    int right_x = x + width;
    int up_y = y;
    int down_y = y + height;

    private:
    //speed and direction
    int direction;

    void set_size(int width, int height);
    void set_position(int x, int y);
    void set_speed(int speed);
    void set_screen(int width, int heigth);


    public:
    void movement();
    void variable_update();   
    void draw_cube();
    cube(int x, int y, int width, int height, int speed, int s_width, int s_height);
};