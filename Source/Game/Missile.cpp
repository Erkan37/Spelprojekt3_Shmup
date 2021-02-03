#include "stdafx.h"
#include "Missile.h"
#include "TypePattern_Bullet.h"
#include "Timer.h"
namespace Studio
{
	Missile::Missile(const Enums::BulletOwner& aOwner, const Tga2D::Vector2f& aPosition)
	{
		myTypePattern = new TypePattern_Bullet("sprites/debugpixel.dds", 12, 0.0f, aOwner);
		myPosition = aPosition;

		myIsSlowingDown = true;

		// TODO: Make JSON??
		myInitialSpeed = 400.0f;
		myDeaccelerationSpeed = 500.0f;
		myAccelerationSpeed = 100.0f;

		myVelocity = { myInitialSpeed, 0.0f };

		myCollider.AddBoxColliderObject(myPosition, { 5,5 });

		mySpriteSheet.SetImagePath("sprites/bullets/missilelvl1.dds");
	}

	void Missile::Update()
	{
		auto deltaTime = Timer::GetInstance()->TGetDeltaTime();

		if (myIsSlowingDown)
		{
			myVelocity.x -= myDeaccelerationSpeed * deltaTime;

			if (myVelocity.x <= 0.0f)
			{
				myIsSlowingDown = false;
				myVelocity.x = 0.0f;
				myVelocity.y = 0.0f;
			}
		}
		else
		{
			myVelocity.x += myAccelerationSpeed;
		}
		
		myPosition += myVelocity * deltaTime;
		GameObject::Update(myPosition);
	}
}
