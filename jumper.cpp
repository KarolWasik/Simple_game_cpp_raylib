#include "jumper.h"
#include "raylib.h"

void jumper ::set_jumper(int g)
{
    this->gravity = g;
}

void jumper ::draw_jumper()
{
    DrawTextureRec(this->bob, this->bob_rec, this->bob_pos, WHITE);
}

void jumper ::jump()
{
    float dT = GetFrameTime();
    if (IsKeyDown(KEY_SPACE) && this->bob_pos.y == 380 - this->bob_rec.height)
    {
        velocity = this->jump_force;
        this->is_in_the_air = true;
    }
    else if (this->bob_pos.y < 380 - this->bob_rec.height)
    {
        velocity += gravity * dT;
    }
    else
    {
        velocity = 0;
    }

    if (this->bob_pos.y <= 380 - this->bob_rec.height)
    {
        this->bob_pos.y += velocity * dT;
    }

    if (this->bob_pos.y == 380 - this->bob_rec.height)
    {
        this->is_in_the_air = false;
    }

    if (this->bob_pos.y > 380 - this->bob_rec.height)
    {
        this->bob_pos.y = 380 - this->bob_rec.height;
        this->is_in_the_air = false;
    }
}

void jumper::horizontal_movement()
{
    if(IsKeyDown(KEY_LEFT))
    {
        if(bob_pos.x>0) bob_pos.x -= GetFrameTime()*400.f;
    }
    if(IsKeyDown(KEY_RIGHT))
    {
        if(bob_pos.x<200) bob_pos.x +=GetFrameTime()*400.f;
    }
}

void jumper ::load_texture(Texture2D bob)
{
    this->bob = bob;
}

void jumper ::set_vector(int x, int y)
{
    this->bob_pos.x;
    this->bob_pos.y;
}

void jumper ::set_rectangle()
{
    this->bob_rec.width = this->bob.width / 6;
    this->bob_rec.height = this->bob.height;
    this->bob_rec.x = 0;
    this->bob_rec.y = 0;
}

void jumper ::run_animation()
{
    if (this->is_in_the_air == false)
    {
        float dT = GetFrameTime();
        if (this->running_time < this->frame_duration)
        {
            this->running_time += dT;
        }
        else
        {
            part_of_texture += 1;
            if (this->part_of_texture > 5)
            {
                part_of_texture = 0;
            }
            this->bob_rec.x = this->bob_rec.width * this->part_of_texture;
            this->running_time = 0;
        }
    }
}

void jumper ::update_area()
{
    this->area.x = this->bob_pos.x;
    this->area.y = this->bob_pos.y;
    this->area.width = this->bob_rec.width;
    this->area.height = this->bob_rec.height;
}

jumper ::jumper(int gravity)
{
    set_jumper(gravity);
}