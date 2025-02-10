#include <iostream>
#include <chrono>
#include <conio.h>
#include <Windows.h>
#include "Gun.h"

void HandleInput(Gun& gun, bool running)
{
    if (_kbhit() == false)
        return;

    char input = _getch();
    switch (input)
    {
    case 's':
		gun.TransitionTo(Gun::State::Shooting);
        break;
    case 'r':
        gun.TransitionTo(Gun::State::Reloading);
        break;
    case 'q':
		running = false;
        break;
    }
}

int main()
{
    float dt = 0;
	bool running = true;
    Gun gun(10, .5f, 0.5f);

    while (running)
    {
        auto start = std::chrono::high_resolution_clock::now();

        gun.Update(dt);
        HandleInput(gun, running);
        
        /*
            DRAW
        */

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end - start;
        dt = duration.count();
    }
}