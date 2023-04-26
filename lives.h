#include "raylib.h"

class lives
{
    private:
    Texture2D heart_tex;
    Rectangle heart_rec;
    Vector2 heart_pos;
    Vector2 heart_pos_loop;
    void set_lives(int lives);
    public:
    // bool extra_life_appears{false};
    float time_to_next_extra_live{2};
    int left;
    Vector2 extra_live_pos{-5,-5};
    Rectangle area;
    void extra_live();
    void load_texture(Texture2D texture);
    void draw_lives();
    void set_rectangle();
    void set_vector(int x, int y);
    void update_area();
    void set_time_for_extra_live();
    void update_time();

    lives(int left);
};