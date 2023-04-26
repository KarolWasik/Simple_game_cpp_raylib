#include "raylib.h"
#include "variables.h"
#include "jumper.h"
#include "obstacle.h"
#include "backgroudn.h"
#include "lives.h"
#include "timer.h"
#include "game_menu.h"
// game2
#include <TimerG2.h>
#include <iostream>
#include "CubeG2.h"
#include "FunctionsG2.h"
#include <string>
#include "BallG2.h"

int main()
{
    jumper jumper1(1000);
    obstacle obstacle_ob(-500);
    obstacle obstacle_ob_1(-500);
    lives lives_left(5);
    menu menu1(0);

    InitWindow(window_width, window_height, "karol");
    // textures
    bob = LoadTexture("textures/bob.png");
    bg = LoadTexture("textures/far-buildings.png");
    obstacle_tex = LoadTexture("textures/obstacle.png");
    Texture2D mg = LoadTexture("textures/back-buildings.png");
    Texture2D fg = LoadTexture("textures/foreground.png");
    Texture2D heart = LoadTexture("textures/heart.png");

    lives_left.load_texture(heart);
    lives_left.set_rectangle();
    lives_left.set_vector(-15, 20);

    background bg1(bg, 20);
    background fg1(fg, 40);
    background mg1(mg, 80);

    jumper1.load_texture(bob);
    jumper1.set_rectangle();
    jumper1.set_vector(0, 0);

    obstacle_ob.load_texture(obstacle_tex);
    obstacle_ob.set_rectangle();
    obstacle_ob.set_vector(window_width, window_height - obstacle_ob.obstacle_rec.height);

    obstacle_ob_1.load_texture(obstacle_tex);
    obstacle_ob_1.set_rectangle();
    obstacle_ob_1.set_vector(window_width, window_height - obstacle_ob.obstacle_rec.height);

    // game2
    cube cube1_g2(600, 250, 30, 30, 10, window_width_g2, window_height_g2);
    cube cube2_g2(500, 250, 30, 30, 16, window_width_g2, window_height_g2);
    cube cube3_g2(400, 250, 30, 30, 7, window_width_g2, window_height_g2);
    cube cube4_g2(300, 250, 30, 30, 15, window_width_g2, window_height_g2);
    cube cube5_g2(window_width_g2 - 25, 0, 25, window_height_g2, 0, window_width_g2, window_height_g2);

    BallG2 ball_g2(circle_x_g2, circle_y_g2, circle_r);

    TimerG2 seconds_left_g2(time_g2);
    int time_left_g2 = seconds_left_g2.get_time();

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        // game menu***********************************************
        if (show_menu)
        {
            SetWindowSize(500,300);
            DrawText("Choose Game", 40, 10, 60, RED);
            if (IsKeyReleased(KEY_LEFT))
                which_game_selected = 1;
            if (IsKeyReleased(KEY_RIGHT))
                which_game_selected = 2;
            if (which_game_selected == 1)
            {
                DrawRectangle(90, 90, 120, 120, BLUE);
            }
            if (which_game_selected == 2)
            {
                DrawRectangle(290, 90, 120, 120, BLUE);
            }
            if (IsKeyReleased(KEY_ENTER))
                show_menu = false;

            DrawRectangle(100, 100, 100, 100, WHITE);
            DrawText("Game ",115,110,30,BROWN);
            DrawText("1",145,150,45,BROWN);
            DrawRectangle(300, 100, 100, 100, WHITE);
            DrawText("Game ",315,110,30,BROWN);
            DrawText("2",345,150,45,BROWN);
            ClearBackground(BLACK);
        }

        // game1
        if (!show_menu && which_game_selected == 1)
        {
            SetWindowSize(window_width, window_height);
            if (!is_game_started)
            {

                bg1.draw_background();
                menu1.draw_meun();
                is_game_started = menu1.is_game_started;
            }
            else if (!collision_detection)
            {
                jumper1.jump();
                jumper1.horizontal_movement();
                jumper1.run_animation();

                obstacle_ob.set_dT();
                obstacle_ob.movement();
                obstacle_ob.obstacle_animation();

                obstacle_ob_1.set_dT();
                obstacle_ob_1.parabolic_movement();
                obstacle_ob_1.obstacle_animation();
                if (timer > 0.1)
                {
                    distance += 1;
                    timer = 0.0;
                }
                timer += GetFrameTime();
                bg1.draw_background();
                mg1.draw_background();
                fg1.draw_background();

                DrawText(TextFormat("distance: %.i meters", distance), 10, 10, 20, BLACK);

                jumper1.draw_jumper();
                
                //begin extra life handler**************************************************************************************************************************
                lives_left.extra_live();
                lives_left.update_area();
                lives_left.update_time();
                if (CheckCollisionRecs(jumper1.area, lives_left.area))
                {
                    lives_left.extra_live_pos.x=-70.f;
                    lives_left.extra_live_pos.y=-70.f;
                    add_life = true;
                    lives_left.set_time_for_extra_live();
                }
                if (add_life && !CheckCollisionRecs(jumper1.area, lives_left.area)) 
                {
                    if(lives_left.left <5) lives_left.left +=1;
                    add_life =false;
                }
                if(lives_left.time_to_next_extra_live<-0.1f && lives_left.extra_live_pos.x<-0.1f) lives_left.set_time_for_extra_live();

                lives_left.draw_lives();
                //**********************************************************************************************************************
            
                jumper1.update_area();
                obstacle_ob.update_area();
                obstacle_ob_1.update_area();
                if (CheckCollisionRecs(jumper1.area, obstacle_ob.area))
                {
                    substract_life = true;
                    obstacle_ob.target_hitted=true;
                }
                // else if(obstacle_ob.get_obstacle_pos().x>10)
                // {
                //     obstacle_ob.draw_obstacle(WHITE);
                // }

                if (CheckCollisionRecs(jumper1.area, obstacle_ob_1.area))
                {
                    substract_life = true;
                    obstacle_ob_1.target_hitted=true;
                }

                if(!obstacle_ob.target_hitted) obstacle_ob.draw_obstacle(WHITE);
                if(obstacle_ob.get_obstacle_pos().x>513) obstacle_ob.target_hitted=false;
                
                if(!obstacle_ob_1.target_hitted) obstacle_ob_1.draw_obstacle(RED);
                if(obstacle_ob_1.get_obstacle_pos().x>513) obstacle_ob_1.target_hitted=false;

                if (substract_life && ((CheckCollisionRecs(jumper1.area, obstacle_ob.area) == false &&
                 CheckCollisionRecs(jumper1.area, obstacle_ob_1.area) == false)|| lives_left.left == 1))
                {
                    lives_left.left -= 1;
                    if (lives_left.left == 0)
                        collision_detection = true;
                    substract_life = false;
                }
            }
            else
            {
                bg1.draw_background();
                mg1.draw_background();
                fg1.draw_background();
                DrawText("Game Over", 50, 100, 70, RED);
                DrawText(TextFormat("distance: %.i meters", distance), 60, 180, 30, WHITE);
                DrawText("press y to play again", 60, window_height - 70, 25, YELLOW);
                if (IsKeyDown(KEY_Y))
                {
                    collision_detection = false;
                    obstacle_ob.set_vector(window_width, window_height - obstacle_ob.obstacle_rec.height);
                    obstacle_ob_1.set_vector(window_width, window_height - obstacle_ob.obstacle_rec.height);
                    obstacle_ob.update_area();
                    obstacle_ob.time_to_next_obstacle = 4;
                    distance = 0;
                    lives_left.left = 5;
                }
                // wstawianie tekstu ze zmienną
                //  DrawText(TextFormat("Score: %.2f", obstacle_ob.time_to_next_obstacle), 20, 20, 40, RED);
            }
            if (IsKeyReleased(KEY_B))
                show_menu = true;
            ClearBackground(WHITE);
        }

        // game 2
        if (!show_menu && which_game_selected == 2)
        {
            SetWindowSize(window_width_g2, window_height_g2);

            if (colision_detection_1_g2 == false && colision_detection_2_g2 == false &&
                colision_detection_3_g2 == false && colision_detection_4_g2 == false && score_detection_g2 == false && time_left_g2 > 0)
            {

                seconds_left_g2.is_second_pass();
                time_left_g2 = seconds_left_g2.get_time();

                colision_detection_1_g2 = CollisionDetecitionG2(ball_g2.l_circle_x, ball_g2.r_circle_x, ball_g2.up_circle_y, ball_g2.down_circle_y,
                                                                cube1_g2.left_x, cube1_g2.right_x, cube1_g2.up_y, cube1_g2.down_y);

                colision_detection_2_g2 = CollisionDetecitionG2(ball_g2.l_circle_x, ball_g2.r_circle_x, ball_g2.up_circle_y, ball_g2.down_circle_y,
                                                                cube2_g2.left_x, cube2_g2.right_x, cube2_g2.up_y, cube2_g2.down_y);

                colision_detection_3_g2 = CollisionDetecitionG2(ball_g2.l_circle_x, ball_g2.r_circle_x, ball_g2.up_circle_y, ball_g2.down_circle_y,
                                                                cube3_g2.left_x, cube3_g2.right_x, cube3_g2.up_y, cube3_g2.down_y);

                colision_detection_4_g2 = CollisionDetecitionG2(ball_g2.l_circle_x, ball_g2.r_circle_x, ball_g2.up_circle_y, ball_g2.down_circle_y,
                                                                cube4_g2.left_x, cube4_g2.right_x, cube4_g2.up_y, cube4_g2.down_y);

                score_detection_g2 = CollisionDetecitionG2(ball_g2.l_circle_x, ball_g2.r_circle_x, ball_g2.up_circle_y, ball_g2.down_circle_y,
                                                           cube5_g2.left_x, cube5_g2.right_x, cube5_g2.up_y, cube5_g2.down_y);

                cube1_g2.movement();
                cube2_g2.movement();
                cube3_g2.movement();
                cube4_g2.movement();
                cube5_g2.movement();
                ball_g2.movement();

                cube1_g2.draw_cube();
                cube2_g2.draw_cube();
                cube3_g2.draw_cube();
                cube4_g2.draw_cube();
                cube5_g2.draw_cube();
                ball_g2.draw_ball();

                DrawText(TextFormat("Score: %i", points_g2), 20, 20, 40, RED);
                DrawText(TextFormat("Lives: %i", lives_g2), 20, 60, 40, RED);
                DrawText(TextFormat("Time left: %i", time_left_g2), 20, 100, 40, RED);
            }
            else if (score_detection_g2 == true && time_left_g2 > 0)
            {
                ball_g2.set_position(circle_x_g2, circle_y_g2);
                ball_g2.update_area();
                score_detection_g2 = false;
                seconds_left_g2.set_timer(time_left_g2+5);
                points_g2 += 1;
            }
            else
            {
                if (lives_g2 == 1)
                {
                    DrawText("Game Over!!!", 150, 150, 60, RED);
                    DrawText(TextFormat("Score: %i", points_g2), 150, 250, 60, RED);
                    DrawText("press y to play again", 150, 400, 30, YELLOW);
                    if (IsKeyDown(KEY_Y) == true)
                    {
                        ball_g2.set_position(circle_x_g2, circle_y_g2);
                        ball_g2.update_area();
                        lives_g2 = 5;
                        points_g2 = 0;
                        time_left_g2 = time_g2;
                        seconds_left_g2.set_timer(time_left_g2);
                        colision_detection_1_g2 = false;
                        colision_detection_2_g2 = false;
                        colision_detection_3_g2 = false;
                        colision_detection_4_g2 = false;
                    }
                }
                else
                {
                    ball_g2.set_position(circle_x_g2, circle_y_g2);
                    ball_g2.update_area();
                    colision_detection_1_g2 = false;
                    colision_detection_2_g2 = false;
                    colision_detection_3_g2 = false;
                    colision_detection_4_g2 = false;
                    lives_g2 -= 1;
                }
            }
            ClearBackground(BLACK);
            if (IsKeyReleased(KEY_B))
                show_menu = true;
            // DrawText("gra2",100,100,50,RED);
            // ClearBackground(WHITE);
            // if(IsKeyReleased(KEY_B)) show_menu = true;
        }

        EndDrawing();
    }
}