#pragma once
#include "State.h"
#include "Gun.h"

class EmptyState : public State {
public:
    void Start(Gun* gun) override;
    void Update(Gun* gun, float deltaTime) override;
};
