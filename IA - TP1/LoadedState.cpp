#include "LoadedState.h"
#include "EmptyState.h"
#include <iostream>

void LoadedState::Start(Gun* gun) {
    std::cout << "Gun is loaded with " << gun->GetAmmo() << " ammo.\n";
}

void LoadedState::Update(Gun* gun, float deltaTime) {
    if (gun->GetAmmo() == 0) {
        gun->SetState(new EmptyState());
    }
}
