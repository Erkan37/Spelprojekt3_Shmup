#include "stdafx.h"
#include "TestButton.h"
#include "tga2d/sprite/sprite.h"
#include "InputManager.h"
#include <iostream>

Studio::TestButton::TestButton()
{

}

Studio::TestButton::TestButton(const char* aPath, const VECTOR2F aPosition, const VECTOR2F aSize, const VECTOR2F aPivot)
{
	mySprite = new Tga2D::CSprite(aPath);
	mySprite->SetPivot(aPivot);
	mySprite->SetSizeRelativeToImage(aSize);
	mySprite->SetPosition(aPosition);


	myLeft = mySprite->GetPosition().x - (mySprite->GetImageSize().x* aSize.x / 2);
	myRight = mySprite->GetPosition().x + (mySprite->GetImageSize().x * aSize.x / 2);
	myTop = mySprite->GetPosition().y - (mySprite->GetImageSize().y * aSize.y / 2);
	myBottom = mySprite->GetPosition().y + (mySprite->GetImageSize().y * aSize.y / 2);

	myRenderCommand = RenderCommand(mySprite, aSize,aPosition);

	//std::cout << mySprite->GetSize().x << " " << mySprite->GetSize().y << std::endl;
	std::cout << myTop << " " << myBottom << std::endl;
}

Studio::TestButton::~TestButton()
{
	delete mySprite;
	mySprite = nullptr;
}

void Studio::TestButton::Update()
{

	//if (Studio::InputManager::GetInstance()->GetMouseLPressed())
	//{
	//	std::cout << Studio::InputManager::GetInstance()->GetMousePosition().x << " " << Studio::InputManager::GetInstance()->GetMousePosition().y << std::endl;
	//}
	//
	

	if (Studio::InputManager::GetInstance()->GetMousePosition().x* renderAspect >= myLeft && Studio::InputManager::GetInstance()->GetMousePosition().x* renderAspect <= myRight)
	{
		if (Studio::InputManager::GetInstance()->GetMousePosition().y * renderAspect >= myTop && Studio::InputManager::GetInstance()->GetMousePosition().y * renderAspect <= myBottom)
		{
			if (Studio::InputManager::GetInstance()->GetMouseLPressed())
			{
				OnClick();
			}
		}
	}

	Studio::RendererAccessor::GetInstance()->RenderRenderCommand(myRenderCommand);

}

void Studio::TestButton::OnClick()
{
	std::cout << "TestButton Pressed" << std::endl;
}

void Studio::TestButton::Render()
{
	//RendererAccessor::GetInstance()->RenderRenderCommand(myRenderCommand);

	
}