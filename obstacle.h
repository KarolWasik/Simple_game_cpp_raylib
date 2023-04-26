#include "raylib.h"



class obstacle
{
    private:
    int speed;
    int direction = -1;

    float frame_duration = 1.0/12.0;
    float running_time = 0.0;

    float dT = 0.0;
    int wertical_part_of_texture = 0;
    int horizontal_part_of_texture=0;



    Texture2D obstacle_tex;
    Vector2 obstacle_pos;
    public:
    bool target_hitted{false};
    Rectangle obstacle_rec;
    Rectangle area;
    float time_to_next_obstacle = 5.0;

    void load_texture(Texture2D bob);
    void set_vector(int x, int y);
    void set_rectangle();
    void obstacle_animation();
    void set_speed(int speed);
    void movement();
    void parabolic_movement();
    void draw_obstacle(Color color);
    void set_dT();
    void update_area();
    Vector2 get_obstacle_pos();


    obstacle(int speed);


};