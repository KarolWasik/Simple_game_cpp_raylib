#include "raylib.h"

class TimerG2
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
    TimerG2(int seconds);
};

void TimerG2 :: set_timer(int seconds)
{
    this -> seconds = seconds;
}

void TimerG2 :: update_frame_time()
{
    this -> frame_time = GetFrameTime();
}

void TimerG2 :: is_second_pass()
{
    update_frame_time();
    this -> one_sec += this -> frame_time;
    if(one_sec >= 1)
    {
        this -> one_sec = 0;
        this -> seconds -= 1;
    }
}

int TimerG2 :: get_time()
{
    return  this->seconds;
}

TimerG2 :: TimerG2(int seconds)
{
    set_timer(seconds);
}
