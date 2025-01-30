#pragma once

//-----include section-----
#include "Objects.h"


//-----class section-----
class StaticObjects : public Objects
{
public:
	using Objects::Objects;
	virtual ~StaticObjects() = default;

	//virtual void RobotCollide(Objects& otherObject) = 0;

private:
};