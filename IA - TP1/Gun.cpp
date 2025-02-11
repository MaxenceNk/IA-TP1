#include "Gun.h"
#include "FullState.h"
#include "ShootingState.h"
#include "ReloadingState.h"
#include <iostream>

Gun::Gun(int pMaxAmmo, float pShootTime, float pReloadTime)
    : mAmmo(pMaxAmmo), mCapacity(pMaxAmmo), mShootTime(pShootTime), mReloadTime(pReloadTime),
    mReloadProgress(0.f), mShootProgress(0.f), mCurrentState(new FullState()) {
    mCurrentState->Start(this);
}

Gun::~Gun() {
    delete mCurrentState;
}

void Gun::Update(float deltaTime) {
    if (mCurrentState) {
        mCurrentState->Update(this, deltaTime);
    }
}

void Gun::SetState(State* newState) {
    if (mCurrentState) {
        delete mCurrentState;
    }
    mCurrentState = newState;
    mCurrentState->Start(this);
}

void Gun::Shoot() {
    if (mAmmo > 0) {
        SetState(new ShootingState());
    }
    else {
        std::cout << "No ammo!\n";
    }
}

void Gun::Reload() {
    if (mAmmo < mCapacity) {
        SetState(new ReloadingState());
    }
    else {
        std::cout << "Already full!\n";
    }
}
