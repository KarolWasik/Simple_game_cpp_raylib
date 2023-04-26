#include "raylib.h"
#include "game_menu.h"

void menu ::pick()
{
    if (!this->enter_menu)
    {
        if (IsKeyReleased(KEY_UP))
        {
            this->choose -= 1;
            if (this->choose < 0)
            {
                this->choose = 2;
            }
        }

        if (IsKeyReleased(KEY_DOWN))
        {
            this->choose += 1;
            if (this->choose > 2)
            {
                this->choose = 0;
            }
        }
    }
}

void menu ::draw_meun()
{
    pick();
    if (this->choose == 0)
    {
        DrawText("START", 20, 100, 50, WHITE);
        DrawText("INSTRUCTION", 20, 200, 50, YELLOW);
        DrawText("SETTINGS", 20, 300, 50, YELLOW);
        if (IsKeyDown(KEY_ENTER))
        {
            this->is_game_started = true;
        }
    }
    if (this->choose == 1)
    {
        if (this->enter_menu == false)
        {
            DrawText("START", 20, 100, 50, YELLOW);
            DrawText("INSTRUCTION", 20, 200, 50, WHITE);
            DrawText("SETTINGS", 20, 300, 50, YELLOW);
            if (IsKeyReleased(KEY_ENTER))
                this->enter_menu = true;
        }
        else
        {
            DrawText("unikaj kulek \n przebiegnij jak najwięcej metrów", 20, 30, 30, YELLOW);
            DrawText("EXIT", 100, 300, 50, WHITE);
            if (IsKeyReleased(KEY_ENTER))
                enter_menu = false;
        }
    }
    if (this->choose == 2)
    {
        DrawText("START", 20, 100, 50, YELLOW);
        DrawText("INSTRUCTION", 20, 200, 50, YELLOW);
        DrawText("SETTINGS", 20, 300, 50, WHITE);
        if (IsKeyDown(KEY_ENTER))
            ;
    }
}

void menu ::set_menu(int choose)
{
    this->choose = choose;
}

menu ::menu(int choose)
{
    set_menu(choose);
}