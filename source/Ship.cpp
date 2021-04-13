#include "Ship.h"

bool Ship::shoot()
{
	if (this->canShoot())
	{
		this->lastShotTime = time(NULL);
		std::cout << "shoot: " << this->lastShotTime << std::endl;
		return true;
	}
	return false;
}

bool Ship::canShoot()
{
	if (time(NULL) - this->lastShotTime >= this->shotDelay)
		return true;
	return false;
}