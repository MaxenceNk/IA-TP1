#pragma once
class Gun
{
private:
	int mAmmo, mCapacity; 
	bool mIsReloading, mIsShooting;
	float mReloadTime, mShootTime, mReloadProgress, mShootProgress;

public:

	enum class State
	{
		Full,
		Loaded,
		Empty,
		Shooting,
		Reloading,
		
		Count
	};

	static constexpr int StateCount = static_cast<int>(State::Count);

private:

	State mState = State::Full;

	int mTransitions[StateCount][StateCount] =
	{
		//Full, Loaded, Empty, Shooting, Reloading
		{0,     0,       0,      1,       0}, //Full
		{0,     0,       0,      1,       1}, //Loaded
		{0,     0,       0,      0,       1}, //Empty
		{0,     1,       1,      0,       1}, //Shooting
		{1,     0,       0,      0,       0}  //Reloading
	};

public:

	Gun(int pMaxAmmo, float pShootTime, float pReloadTime);
	void Update(float deltaTime);
	bool Shoot();
	bool Reload();
	bool TransitionTo(State newState);

};

