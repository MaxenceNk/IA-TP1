#include "EmptyState.h"
#include <iostream>

void EmptyState::Start(Gun* gun) {
    std::cout << "Gun is empty!\n";
}

void EmptyState::Update(Gun* gun, float deltaTime) {
    // Attente d'une action de rechargement
}
