#include "stdafx.h"
#include "MovementDiagonal.h"
#include "Timer.h"

namespace Studio
{
	MovementDiagonal::MovementDiagonal(VECTOR2F* anObjectsPosition, float aSpeed, float anAngle)
	{
		this->myObjectsPosition = anObjectsPosition;
		myPattern = Enums::MovementPattern::Diagonal;
		mySpeed = aSpeed;
		myAngle = anAngle;
		myTotalTime = 0.0f;

	}
	void MovementDiagonal::Update()
	{
		myTotalTime += Timer::GetInstance()->TGetDeltaTime();
		myObjectsPosition->x -= mySpeed * Timer::GetInstance()->TGetDeltaTime();
		myObjectsPosition->y -= myAngle * Timer::GetInstance()->TGetDeltaTime();
	}
}