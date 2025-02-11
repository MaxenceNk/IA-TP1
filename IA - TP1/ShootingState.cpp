#include "ShootingState.h"
#include "LoadedState.h"
#include "EmptyState.h"
#include <iostream>

void ShootingState::Start(Gun* gun) {
    std::cout << "Bang! Ammo left: " << gun->GetAmmo() - 1 << "\n";
    gun->UseAmmo();
}

void ShootingState::Update(Gun* gun, float deltaTime) {
    gun->UpdateShootProgress(deltaTime);

    if (gun->IsShootComplete()) {
        gun->DecreaseAmmo();
        gun->ResetShootProgress(); // Réinitialise le temps de tir

        // Ajoute un temps d'attente équivalent à mShootTime
        if (gun->GetShootProgress() >= gun->GetShootTime()) {
            gun->SetState(gun->GetAmmo() > 0 ? static_cast<State*>(new LoadedState()) : static_cast<State*>(new EmptyState()));
        }
    }
}




