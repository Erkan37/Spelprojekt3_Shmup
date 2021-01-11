#pragma once
class Bullet : Studio::GameObject
{
public:
	Bullet() = default;
	Bullet(VECTOR2F aPosition, const float& aSpeed, VECTOR2F aDirection);
	~Bullet();
	void Update();
private:
	float mySpeed;

	VECTOR2F myPosition;
	VECTOR2F myDirection;
};
