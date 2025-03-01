#pragma once

//-----include section-----
#include "Objects.h"
class Wall;
class Rock;
class Door;


//-----class section-----
class StaticObjects : public Objects
{
public:
	using Objects::Objects;
	virtual ~StaticObjects() = default;

	virtual void handleCollision(Wall& wall) override {};
	virtual void handleCollision(Rock& rock) override {};
	virtual void handleCollision(Door& door) override {};

	void setToDisappear(bool ifDisappear);
	const bool getNeedToDisappear() const;


private:
	bool m_needToDisappear = false;
};