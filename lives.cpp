#include "lives.h"
#include "raylib.h"
#include <cstdlib>

void lives ::set_lives(int left)
{
    this->left = left;
}

void lives ::load_texture(Texture2D texture)
{
    this->heart_tex = texture;
}

void lives ::draw_lives()
{
    int i = 0;
    while (i < this->left)
    {
        this->heart_pos_loop.x = heart_pos.x + i * 30;
        DrawTextureRec(this->heart_tex, this->heart_rec, this->heart_pos_loop, WHITE);
        i++;
    }
}

void lives ::set_vector(int x, int y)
{
    this->heart_pos.x = x;
    this->heart_pos.y = y;
    this->heart_pos_loop.x = x;
    this->heart_pos_loop.y = y;
}

void lives ::set_rectangle()
{
    this->heart_rec.width = this->heart_tex.width;
    this->heart_rec.height = this->heart_tex.height;
    this->heart_rec.x = 0;
    this->heart_rec.y = 0;
}

void lives ::extra_live()
{
    if (time_to_next_extra_live < 0)
    {
        if (extra_live_pos.x < 0)
        {
            extra_live_pos.x = 550;
            extra_live_pos.y = 150;
        }
        extra_live_pos.x -= 190.0 * GetFrameTime();
        DrawTextureRec(this->heart_tex, this->heart_rec, this->extra_live_pos, WHITE);
    }
}

void lives ::update_area()
{
    float pad{1};
    this->area.x = this->extra_live_pos.x + pad;
    this->area.y = this->extra_live_pos.y + pad;
    this->area.width = this->heart_rec.width - 2 * pad;
    this->area.height = this->heart_rec.height - 2 * pad;
}

void lives::set_time_for_extra_live()
{
    time_to_next_extra_live = 3 + (rand() % 6);
}
void lives::update_time()
{
    time_to_next_extra_live -= GetFrameTime();
}

lives ::lives(int left)
{
    set_lives(left);
}