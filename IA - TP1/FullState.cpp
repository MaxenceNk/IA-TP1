#include "FullState.h"
#include "LoadedState.h"
#include <iostream>

void FullState::Start(Gun* gun) {
    std::cout << "Gun is fully loaded.\n";
}

void FullState::Update(Gun* gun, float deltaTime) {
    if (gun->GetAmmo() < gun->GetCapacity()) {
        gun->SetState(new LoadedState());
    }
}
