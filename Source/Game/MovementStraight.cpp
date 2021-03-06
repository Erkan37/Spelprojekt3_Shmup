#include "stdafx.h"
#include "MovementStraight.h"
#include "Timer.h"

namespace Studio
{
	MovementStraight::MovementStraight(VECTOR2F* anObjectsPosition, float aSpeed)
	{
		this->myObjectsPosition = anObjectsPosition;
		myPattern = Enums::MovementPattern::Straight;
		mySpeed = aSpeed;
	}

	void MovementStraight::SetMovementStartPosition(VECTOR2F* aPosition)
	{
		this->myObjectsPosition = aPosition;
	}

	void MovementStraight::Update()
	{
		myDirection = *myObjectsPosition;
		myObjectsPosition->x -= mySpeed * Timer::GetInstance()->TGetDeltaTime();
		myDirection = (myDirection - *myObjectsPosition).GetNormalized();
	}
}

