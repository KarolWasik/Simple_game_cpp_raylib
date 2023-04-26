#include "raylib.h"
class background
{
private:
    Texture2D bg_tex;
    float bg_x = -1.0;
    Vector2 bg_pos;
    Vector2 bg_pos1;

    int speed;

    void load_texture(Texture2D bg);
    void set_position();
    void set_speed(int speed);

public:
    void update_position();
    void draw_background();
    background(Texture2D bg, int speed);
};