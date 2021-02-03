#pragma once
#include "GameObject.h"
#include "Enums.h"
#include <vector>
namespace Studio
{
	class TypePattern_Bullet;
	class Bullet : public GameObject
	{
	public:
		Bullet() = default;
		Bullet(VECTOR2F aPosition, TypePattern_Bullet* aTypePattern);
		~Bullet();
		void Update();

		void RegisterEnemyHit(GameObject* anEnemy);
		void SetIsPenetrating();
		bool GetIsPenetrating();
		bool IsEnemyAlreadyHit(GameObject* anEnemy);
		VECTOR2F GetPosition();
		Enums::BulletOwner GetOwner();

	private:
		std::vector<GameObject*> myHitEnemies;
		TypePattern_Bullet* myTypePattern;
		bool myIsPenetrating = false;
		VECTOR2F myPosition;
	};
}


