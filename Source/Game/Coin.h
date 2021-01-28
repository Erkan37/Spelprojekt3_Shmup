#pragma once
#include "GameObject.h"
namespace Studio
{
	class Coin : public GameObject
	{
	public:
		Coin(VECTOR2F aSpawnPosition);

		int GetScoreValue();

		VECTOR2F GetPosition();
	private:
		int myScoreValue;

		VECTOR2F myPosition;

	};
}


