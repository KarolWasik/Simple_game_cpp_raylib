#include "raylib.h"

class Timer
{
    private:
    float one_sec = 0;
    float frame_time = 0;
    int seconds;
    public:
    void set_timer(int seconds); 
    int get_time();
    void update_frame_time();
    void is_second_pass();
    Timer(int seconds);
};

void Timer :: set_timer(int seconds)
{
    this -> seconds = seconds;
}

void Timer :: update_frame_time()
{
    this -> frame_time = GetFrameTime();
}

void Timer :: is_second_pass()
{
    update_frame_time();
    this -> one_sec += this -> frame_time;
    if(one_sec >= 1)
    {
        this -> one_sec = 0;
        this -> seconds -= 1;
    }
}

int Timer :: get_time()
{
    return  this->seconds;
}

Timer :: Timer(int seconds)
{
    set_timer(seconds);
}
