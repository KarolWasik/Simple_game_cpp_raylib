#include "obstacle.h"
#include "raylib.h"
#include <time.h>
#include <stdlib.h>






void obstacle :: load_texture(Texture2D obstacle)
{
    this -> obstacle_tex = obstacle;
}

void obstacle :: set_vector(int x, int y)
{
    this -> obstacle_pos.x =x;
    this -> obstacle_pos.y = y;
}

void obstacle :: set_rectangle()
{
    this -> obstacle_rec.height = obstacle_tex.height/8;
    this -> obstacle_rec.width = obstacle_tex.width/8;
    this -> obstacle_rec.x = 0;
    this -> obstacle_rec.y = 0;
}

void obstacle :: set_speed(int speed)
{
    this -> speed = speed;
}

void obstacle :: obstacle_animation()
{
    
    
    if(this -> running_time < this -> frame_duration)
    {
        this -> running_time += this -> dT;
    }
    else
    {
        if(this -> horizontal_part_of_texture !=7)
        {
            this -> wertical_part_of_texture += 1;
        }
        else
        {
            this -> wertical_part_of_texture += 1;
            if(this -> wertical_part_of_texture > 4)
            {
                this -> wertical_part_of_texture = 0;
                horizontal_part_of_texture = 0;
            }
        }
        if(this -> wertical_part_of_texture > 7)
        {
                this->wertical_part_of_texture = 0;
                this -> horizontal_part_of_texture += 1;

        }
        this -> obstacle_rec.x = this -> obstacle_rec.width* this -> wertical_part_of_texture; 
        this -> obstacle_rec.y = this -> obstacle_rec.height * this -> horizontal_part_of_texture;
        this -> running_time = 0;
    }
}

void obstacle :: draw_obstacle(Color color)
{
    DrawTextureRec(this -> obstacle_tex, this -> obstacle_rec,this ->obstacle_pos,color);
}
void obstacle :: set_dT()
{
    this -> dT = GetFrameTime();
}

void obstacle :: movement()
{
    if(this -> time_to_next_obstacle <= 0)
    {
        this -> obstacle_pos.x += this -> speed * this -> dT;
    }
    time_to_next_obstacle -= this -> dT;
    if(time_to_next_obstacle <= 0 && this -> obstacle_pos.x < (-10) - this -> obstacle_rec.width)
    {
        this -> time_to_next_obstacle = rand() % 3 + 1;
        this -> obstacle_pos.x = 512 + this -> obstacle_rec.width;
    }
    
}


void obstacle :: parabolic_movement()
{
    if(this -> time_to_next_obstacle <= 0)
    {
        this -> obstacle_pos.x += (this -> speed/1.2f) * this -> dT;
        if(obstacle_pos.y <20) direction *=-1;
        if(obstacle_pos.y > 380-obstacle_rec.height) direction *=-1;
        obstacle_pos.y += (this -> speed/1.3f) * dT * direction;
    }
    time_to_next_obstacle -= this -> dT;
    if(time_to_next_obstacle <= 0 && this -> obstacle_pos.x < (-10.f) - this -> obstacle_rec.width)
    {
        this -> time_to_next_obstacle = 1 + (rand() % 6);
        this -> obstacle_pos.x = 512 + this -> obstacle_rec.width;
    }
    
}

void obstacle :: update_area()
{
    float pad{50};
    this -> area.x = this -> obstacle_pos.x + pad;
    this -> area.y = this -> obstacle_pos.y + pad;
    this -> area.width = this -> obstacle_rec.width - 2 * pad;
    this -> area.height = this -> obstacle_rec.height - 2 * pad;
}

Vector2 obstacle :: get_obstacle_pos()
{
    return obstacle_pos;
}



obstacle :: obstacle(int speed)
{
    set_speed(speed);
}

