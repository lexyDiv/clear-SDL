#include <iostream>
#include "Listenner.h"

bool quit = false;

void goWork()
{
    SDL_Event e;
    while (!quit)
    {

        listenner(e, quit);
        console.proc(mouse.x, mouse.y, mouse.leftKey);
        // if (!game->pause)
        // {
        //     game->prog();
        // }
        mouse.defaultKeys();
        this_thread::sleep_for(chrono::milliseconds(25));
    }
};

int main()
{
    srand(time(0));

    console.log("papa loh");

    ctx.getFont();

    thread th(goWork);
    SDL_Event e;
    while (!quit)
    {
        ctx.CreateDrawZone(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT);
        ctx.FillRect(0, 0, ctx.SCREEN_WIDTH, ctx.SCREEN_HEIGHT, "white");
        console.draw();
        ctx.End();
    }

    ctx.Close();

    th.join();

    return 0;
}