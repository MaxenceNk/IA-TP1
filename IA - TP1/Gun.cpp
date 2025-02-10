#include <iostream>
#include "Gun.h"

Gun::Gun(int pMaxAmmo, float pShootTime, float pReloadTime)
{
	mAmmo = pMaxAmmo;
	mCapacity = pMaxAmmo;

	mIsShooting = false;
	mIsReloading = false;

	mReloadTime = pShootTime;
	mShootTime = pReloadTime;

	mReloadProgress = 0.f;
	mShootProgress = 0.f;
}

void Gun::Update(float deltaTime)
{
	/*if (mIsShooting == true)
	{
		mShootProgress += deltaTime;

		if (mShootProgress >= mShootTime)
		{
			mShootProgress = 0.f;
			mIsShooting = false;
		}

	}
	else if (mIsReloading == true)
	{
		mReloadProgress += deltaTime;


		if (mReloadProgress >= mReloadTime)
		{
			mReloadProgress = 0.f;
			mIsReloading = false;
		}
	}*/

	if (mState == State::Shooting)
	{
		mShootProgress += deltaTime;

		if (mShootProgress >= mShootTime)
		{
			mAmmo--;
			std::cout << "Shooting!" << std::endl;
			std::cout << "Weapon loaded with " << mAmmo << " ammo." << std::endl;
			TransitionTo(State::Loaded);
			mShootProgress = 0.f;
		}

	}
	else if (mState == State::Reloading)
	{
		mReloadProgress += deltaTime;
		

		if (mReloadProgress >= mReloadTime)
		{
			mAmmo = mCapacity;
			std::cout << "Reloading..." << std::endl;
			std::cout << "Weapon loaded with " << mAmmo << " ammo." << std::endl;
			TransitionTo(State::Full);
			mReloadProgress = 0.f;
		}
	}
	if (mAmmo <= 0)
	{
		//std::cout << "Weapon empty!" << std::endl;
		TransitionTo(State::Empty);
	}
}

bool Gun::Shoot()
{
	if (mIsReloading || mIsShooting || mAmmo <= 0) 
		return false;

	mIsReloading = false;
	mIsShooting = true;

	mAmmo--;

	std::cout << "Bang! Ammo left : " << mAmmo << std::endl;

	return true;

}

bool Gun::Reload()
{
	if (mIsReloading || mIsShooting)
		return false;

	mIsReloading = true;
	mIsShooting = false;

	std::cout << "Reloading..." << std::endl;
}

bool Gun::TransitionTo(State newState)
{
	int currentStateIndex = static_cast<int>(mState);
	int newStateIndex = static_cast<int>(newState);
	
	if (mTransitions[currentStateIndex][newStateIndex] == 0)
		return false;
		
	mState = newState;

	return true;
}
