#pragma once
#include "ButtonElement.h"
#include "RendererAccessor.h"
#include "Renderer.h"

namespace Studio
{
	class ShopButton : public ButtonElement
	{
	public:
		ShopButton(const char* aPath, const VECTOR2F aPosition, const VECTOR2F aSize, const VECTOR2F aPivot, int aLayer);
		~ShopButton();

		void Update() override;
		void OnClick() override;

	private:
		bool myIsClicked = false;

	};
}
