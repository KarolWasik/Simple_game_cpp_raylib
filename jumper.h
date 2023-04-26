#include "raylib.h"

class jumper
{
private:
    // position
    int width = 70;
    int height = 70;
    int gravity;
    int velocity = 0;
    int jump_force = -600;
    int part_of_texture = 1;
    bool is_in_the_air = false;

    float frame_duration = 1 * (0.1);
    float running_time = 0;
    Texture2D bob;
    Vector2 bob_pos;

public:
    Rectangle bob_rec;
    Rectangle area;
    void load_texture(Texture2D bob);
    void set_vector(int x, int y);
    void set_rectangle();
    void set_jumper(int g);
    void draw_jumper();
    void jump();
    void horizontal_movement();
    void run_animation();
    void update_area();

    jumper(int gravity);
};