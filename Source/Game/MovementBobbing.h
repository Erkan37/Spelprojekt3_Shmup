#pragma once
#include "Movement.h"

namespace Studio
{
	class MovementBobbing : public Movement
	{
	public:
		MovementBobbing(VECTOR2F* anObjectsPosition, float aVerticalSpeed, float aWaveHeight);
		void Update() override;
	private:
		float myWaveHeight;
		float mySpawnYPos;
		float myVerticalSpeed;

		const float myCalculatedSpeed;
	};
}


