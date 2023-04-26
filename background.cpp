#include "backgroudn.h"

void background ::load_texture(Texture2D bg)
{
    this->bg_tex = bg;
}

void background ::set_position()
{
    this->bg_pos.x = 0.0;
    this->bg_pos.y = 0.0;
    this->bg_pos1.x = 0.0;
    this->bg_pos1.y = 0.0;
}

void background ::update_position()
{
    if (bg_x <= -bg_tex.width * 2)
    {
        bg_x = 0.0;
    }
    this->bg_x += GetFrameTime() * -speed;
    this->bg_pos.x = this->bg_x;
    this->bg_pos1.x = this->bg_x + bg_tex.width * 2;
}

void background ::draw_background()
{
    update_position();
    DrawTextureEx(this->bg_tex, this->bg_pos, 0.0, 2.0, WHITE);
    DrawTextureEx(this->bg_tex, this->bg_pos1, 0.0, 2.0, WHITE);
}

void background ::set_speed(int speed)
{
    this->speed = speed;
}

background ::background(Texture2D bg, int speed)
{
    load_texture(bg);
    set_speed(speed);
    set_position();
}