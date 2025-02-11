#pragma once
#include "State.h"

class Gun {
private:
    int mAmmo, mCapacity;
    float mReloadTime, mShootTime, mReloadProgress, mShootProgress;
    State* mCurrentState;

public:
    Gun(int pMaxAmmo, float pShootTime, float pReloadTime);
    ~Gun();

    void Update(float deltaTime);
    void SetState(State* newState);
    void Shoot();
    void Reload();

    float GetShootTime() const { return mShootTime; }
    float GetShootProgress() const { return mShootProgress; }
    void ResetShootProgress() { mShootProgress = 0.f; }
    void DecreaseAmmo() { if (mAmmo > 0) mAmmo--; }

    int GetAmmo() const { return mAmmo; }
    int GetCapacity() const { return mCapacity; }
    void UseAmmo() { mAmmo--; }
    void RefillAmmo() { mAmmo = mCapacity; }

    void StartReload() { mReloadProgress = 0.f; }
    void UpdateReloadProgress(float deltaTime) { mReloadProgress += deltaTime; }
    bool IsReloadComplete() const { return mReloadProgress >= mReloadTime; }

    void UpdateShootProgress(float deltaTime) { mShootProgress += deltaTime; }
    bool IsShootComplete() const { return mShootProgress >= mShootTime; }
};
