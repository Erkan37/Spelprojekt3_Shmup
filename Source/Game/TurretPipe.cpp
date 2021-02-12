#include "stdafx.h"
#include "TurretPipe.h"
#include "TypePattern_Enemy.h"
#include "Enemy.h"
#include "SpriteSheet.h"
#include "Timer.h"
#include "PlayerAccessor.h"
#include "tga2d/sprite/sprite.h"
#include "RendererAccessor.h"
#include "Renderer.h"
#include "LevelAccessor.h"

#define PI (3.14159265358979323846f)

Studio::TurretPipe::TurretPipe(Enemy* aEnemyPointer, TypePattern_Enemy* aTypePatternEnemy):
	myEnemy(aEnemyPointer),
	myEnemyType(aTypePatternEnemy)
{
	mySpriteSheet = new SpriteSheet(myEnemyType->GetTurretPipeImagePath().c_str());
	mySpriteSheet->SetLayer(myEnemy->GetSpriteSheet().GetLayer() - 1);
	mySpriteSheet->SetPivot(myEnemyType->GetTurretPivot());
	myPosition = myEnemyType->GetTurretSpawnPoint() + myEnemy->GetPosition();
	myPipeLength = (myEnemyType->GetTurretPivot().x * mySpriteSheet->GetSprite()->GetImageSize().x - ((mySpriteSheet->GetSprite()->GetImageSize().x * 0.5f) + myEnemyType->GetTurretBulletSpawnPoint().x) );
	mySpriteSheet->SetRotation(PI * 0.5f);
	myShootTimer = 0;
	printf("\nPipeLength: %f\n\n", myPipeLength);
}

Studio::TurretPipe::~TurretPipe()
{
	SAFE_DELETE(mySpriteSheet);
}

void Studio::TurretPipe::Update()
{
	bool allowedToShoot = false;
	myPosition = myEnemyType->GetTurretSpawnPoint() + myEnemy->GetPosition();

	myTurretDirection.x = cosf(mySpriteSheet->GetRotation() - (PI * 0.5f)) / Tga2D::CEngine::GetInstance()->GetWindowSize().x;
	myTurretDirection.y = sinf(mySpriteSheet->GetRotation() - (PI * 0.5f)) / Tga2D::CEngine::GetInstance()->GetWindowSize().y;
	myTurretDirection = myTurretDirection.GetNormalized() * myPipeLength;

	const float EPSILON = 0.00001f;
	//Tga2D::Vector2f playerDirection = (PlayerAccessor::GetInstance()->GetPosition() - myPosition).GetNormalized();
	float angleToPlayer = atan2f(myPosition.y - PlayerAccessor::GetInstance()->GetPosition().y, myPosition.x - PlayerAccessor::GetInstance()->GetPosition().x);
	float currentRotation = mySpriteSheet->GetRotation();
	float turretRotationSpeed = myEnemyType->GetTurretRotationSpeed();

	float rightOrLeftModifier = 0.f;
	if (mySpriteSheet->GetRotation() <= PI && currentRotation < angleToPlayer + EPSILON)
	{
		rightOrLeftModifier = 1.f;
	}
	else if (mySpriteSheet->GetRotation() >= 0 && mySpriteSheet->GetRotation() > angleToPlayer - EPSILON)
	{
		rightOrLeftModifier = -1.f;
	}

	float new_rotation = currentRotation + (turretRotationSpeed * Studio::Timer::GetInstance()->TGetDeltaTime() * rightOrLeftModifier);
	if (new_rotation < angleToPlayer + EPSILON || new_rotation > angleToPlayer - EPSILON)
	{
		mySpriteSheet->SetRotation(angleToPlayer);
	}
	else
	{
		mySpriteSheet->SetRotation(new_rotation);
	}

	if (angleToPlayer < currentRotation + 0.05 && angleToPlayer > currentRotation - 0.05)
	{
		allowedToShoot = true;
	}
	printf("Cannon Angle to PLayer: %f\n", mySpriteSheet->GetRotation());
	mySpriteSheet->SetPosition(myPosition);


	myShootTimer += Studio::Timer::GetInstance()->TGetDeltaTime();
	if (myShootTimer > myEnemyType->GetShootInterval() && allowedToShoot)
	{
		Studio::LevelAccessor::GetInstance()->SpawnBullet("Enemy", myPosition - ((myPosition - PlayerAccessor::GetInstance()->GetPosition()).GetNormalized() * myPipeLength), ((myPosition + myTurretDirection) - PlayerAccessor::GetInstance()->GetPosition()).GetNormalized(), 1);
		myShootTimer = 0;
	}
	Studio::RendererAccessor::GetInstance()->Render(*mySpriteSheet);
}


