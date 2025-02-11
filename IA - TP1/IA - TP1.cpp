#include <iostream>
#include <chrono>
#include <conio.h>
#include <Windows.h>
#include "Gun.h"

void HandleInput(Gun& gun, bool& running) {
    if (!_kbhit()) return;

    char input = _getch();
    switch (input) {
    case 's': gun.Shoot(); break;
    case 'r': gun.Reload(); break;
    case 'q': running = false; break;
    }
}

int main() {
    float dt = 0;
    bool running = true;
    Gun gun(10, 0.5f, 1.5f);

    while (running) {
        auto start = std::chrono::high_resolution_clock::now();

        gun.Update(dt);
        HandleInput(gun, running);

        auto end = std::chrono::high_resolution_clock::now();
        dt = std::chrono::duration<float>(end - start).count();
    }

    return 0;
}