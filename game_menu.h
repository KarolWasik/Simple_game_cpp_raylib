class menu
{
private:
    int choose = 0;
    float bufor = 0.0;
    void set_menu(int choose);
    bool enter_menu = false;

public:
    bool is_game_started = false;
    void pick();
    void draw_meun();
    menu(int choose);
};