#include "ReloadingState.h"
#include "FullState.h"
#include <iostream>

void ReloadingState::Start(Gun* gun) {
    std::cout << "Reloading...\n";
    gun->StartReload();
}

void ReloadingState::Update(Gun* gun, float deltaTime) {
    gun->UpdateReloadProgress(deltaTime);
    if (gun->IsReloadComplete()) {
        gun->RefillAmmo();
        gun->SetState(new FullState());
    }
}
