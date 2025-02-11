#pragma once
#include "State.h"
#include "Gun.h"

class ReloadingState : public State {
public:
    void Start(Gun* gun) override;
    void Update(Gun* gun, float deltaTime) override;
};
