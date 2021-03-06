#pragma once
#include "../tga2dcore/tga2d/math/vector2imp.h"

namespace Tga2D
{
	class CSprite;
}
namespace Studio
{
	class RenderCommand
	{
		public:
			RenderCommand();
			RenderCommand(Tga2D::CSprite* aSprite);
			RenderCommand(Tga2D::CSprite* aSprite, const Tga2D::Vector2f& aSize);
			RenderCommand(Tga2D::CSprite* aSprite, const Tga2D::Vector2f& aSize, const Tga2D::Vector2f& aPosition);
			~RenderCommand();

			virtual void Update(const Tga2D::Vector2f& aPos);
			virtual void Update(const Tga2D::Vector2f& aPos, Tga2D::CSprite* aSprite);
			virtual void Update(Tga2D::CSprite* aSprite, const float aRotation);
			virtual void Update(const Tga2D::Vector2f& aPos, const float aRotation, Tga2D::CSprite* aSprite);
			virtual void Update(const Tga2D::Vector2f& aPos, const Tga2D::Vector2f& aTexRecTopL, const Tga2D::Vector2f& aTexRecBotR);
			
			void Rotate(const float aRotationInRadians);
			void RotateRight(const float aRotationInRadians);
			void RotateLeft(const float aRotationInRadians);
			void SetRotation(float aRotationInRadians);
			const float GetRotation() const;

			void Render();
			virtual void SetScale(const Tga2D::Vector2f& aScale);
			Tga2D::CSprite* GetSprite() const;

	private:
		float myRotation;
		Tga2D::CSprite* mySprite;
		Tga2D::Vector2f myPosition;
		Tga2D::Vector2f myScale;
		Tga2D::Vector2f myTextureRectTopLeft;
		Tga2D::Vector2f myTextureRectBotRight;
	};


}


