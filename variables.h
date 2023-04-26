#include "raylib.h"
//game 1
const int window_width{512};
const int window_height{380};

Texture2D bob;
Texture2D obstacle_tex;
Texture2D bg;

bool collision_detection = false;
bool substract_life = false;
bool add_life = false;

int distance = 0;
float timer = 0.0;

float delay = 0.0;

bool is_game_started = false;


//game1 menu
int which_game_selected=0;
bool show_menu=true;


//game2
    int window_height_g2 = 500;
    int window_width_g2 = 700;
    int circle_y_g2 = 250;
    int circle_x_g2 = 250;
    int circle_r = 10;
    int points_g2 = 0;
    int lives_g2 = 5;
    int time_g2 = 20;

    bool colision_detection_1_g2 = false;
    bool colision_detection_2_g2 = false;
    bool colision_detection_3_g2 = false;
    bool colision_detection_4_g2 = false;
    bool score_detection_g2 = false;