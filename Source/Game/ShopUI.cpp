#include "stdafx.h"
#include "ShopUI.h"
#include "ShopButton.h"
#include <cstdlib>
#include "CommonUtilities\CURandom.h"
#include "PlayerAccessor.h"
#include "Enums.h"

int Studio::ShopUI::GetRandomNumberInRange(int max)
{
	return CommonUtilities::GetRandomInt(0, max);
}

Studio::ShopUI::ShopUI()
{

		myTier1Buttons.push_back(new ShopButton("Sprites/UI/ShopUI/shopUI_cards_tier1.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 5000000, Enums::Tier1Upgrades::RapidFireAttackSpeed,5));
		myTier1Buttons.push_back(new ShopButton("Sprites/UI/ShopUI/shopUI_cards_tier1.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 5000000, Enums::Tier1Upgrades::RapidFireDuration,5));
		myTier1Buttons.push_back(new ShopButton("Sprites/UI/ShopUI/shopUI_cards_tier1.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 5000000, Enums::Tier1Upgrades::RapidFireCooldown,5));
		myTier1Buttons.push_back(new ShopButton("Sprites/UI/ShopUI/shopUI_cards_tier1.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 5000000, Enums::Tier1Upgrades::ShieldCooldown , 5));
		myTier1Buttons.push_back(new ShopButton("Sprites/UI/ShopUI/shopUI_cards_tier1.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 5000000, Enums::Tier1Upgrades::ShieldDuration,5));
		myTier1Buttons.push_back(new ShopButton("Sprites/UI/ShopUI/shopUI_cards_tier1.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 5000000, Enums::Tier1Upgrades::ShieldHealth ,5));
		myTier1Buttons.push_back(new ShopButton("Sprites/UI/ShopUI/shopUI_cards_tier1.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 5000000, Enums::Tier1Upgrades::BasicAttackSpeed, 5));
		myTier1Buttons.push_back(new ShopButton("Sprites/UI/ShopUI/shopUI_cards_tier1.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 5000000, Enums::Tier1Upgrades::MissileCooldown, 5));
		myTier1Buttons.push_back(new ShopButton("Sprites/UI/ShopUI/shopUI_cards_tier1.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 5000000, Enums::Tier1Upgrades::MissileDamage, 5));
		myTier1Buttons.push_back(new ShopButton("Sprites/UI/ShopUI/shopUI_cards_tier1.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 5000000, Enums::Tier1Upgrades::MissileExplosionRadius, 5));

		myTier2Buttons.push_back(new ShopButtonTier2("Sprites/UI/ShopUI/shopUI_cards_tier2.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 500000, Enums::Tier2Upgrades::BasicAttackAdditionalProjectile, 10));
		myTier2Buttons.push_back(new ShopButtonTier2("Sprites/UI/ShopUI/shopUI_cards_tier2.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 500000, Enums::Tier2Upgrades::RapidFireDuration, 10));
		myTier2Buttons.push_back(new ShopButtonTier2("Sprites/UI/ShopUI/shopUI_cards_tier2.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 500000, Enums::Tier2Upgrades::ShieldCooldown, 10));
		myTier2Buttons.push_back(new ShopButtonTier2("Sprites/UI/ShopUI/shopUI_cards_tier2.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 500000, Enums::Tier2Upgrades::BasicAttackSpeed, 10));
		myTier2Buttons.push_back(new ShopButtonTier2("Sprites/UI/ShopUI/shopUI_cards_tier2.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 500000, Enums::Tier2Upgrades::MissileCooldown, 10));
		myTier2Buttons.push_back(new ShopButtonTier2("Sprites/UI/ShopUI/shopUI_cards_tier2.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 500000, Enums::Tier2Upgrades::MissileDamage, 10));
		myTier2Buttons.push_back(new ShopButtonTier2("Sprites/UI/ShopUI/shopUI_cards_tier2.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 500000, Enums::Tier2Upgrades::MissileExplosionRadius, 10));
		myTier2Buttons.push_back(new ShopButtonTier2("Sprites/UI/ShopUI/shopUI_cards_tier2.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 500000, Enums::Tier2Upgrades::RapidFireAttackSpeed, 10));
		myTier2Buttons.push_back(new ShopButtonTier2("Sprites/UI/ShopUI/shopUI_cards_tier2.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 500000, Enums::Tier2Upgrades::ShieldDuration, 10));
		myTier2Buttons.push_back(new ShopButtonTier2("Sprites/UI/ShopUI/shopUI_cards_tier2.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 500000, Enums::Tier2Upgrades::ShieldHealth, 10));

		myTier3Buttons.push_back(new ShopButtonTier3("Sprites/UI/ShopUI/shopUI_cards_tier3.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 5000000,Enums::Tier3Upgrades::BasicAttackSpeed,15));
		myTier3Buttons.push_back(new ShopButtonTier3("Sprites/UI/ShopUI/shopUI_cards_tier3.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 5000000, Enums::Tier3Upgrades::MissileCluster, 15));
		myTier3Buttons.push_back(new ShopButtonTier3("Sprites/UI/ShopUI/shopUI_cards_tier3.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 5000000, Enums::Tier3Upgrades::RapidFirePenetrating, 15));
		myTier3Buttons.push_back(new ShopButtonTier3("Sprites/UI/ShopUI/shopUI_cards_tier3.dds", { 0,0 }, { 1,1 }, { 0.5f,0.5f }, 5000000, Enums::Tier3Upgrades::ShieldExplosion, 15));

}

Studio::ShopUI::~ShopUI()
{

}

void Studio::ShopUI::ResetButtons()
{
	for (ShopButton* b : myTier1Buttons)
	{
		b->Reset();
	}
	for (ShopButtonTier2* p : myTier2Buttons)
	{
		p->Reset();
	}
}

std::vector<Studio::ButtonElement*> Studio::ShopUI::GetShopButtons()
{
	auto myTier1ButtonsTemp = myTier1Buttons;
	auto myTier2ButtonsTemp = myTier2Buttons;
	auto myTier3ButtonsTemp = myTier3Buttons;

	for (size_t i = 0; i < 6; i++)
	{
		int temp = GetRandomNumberInRange(myTier1ButtonsTemp.size()-1);
		ShopButton* buttonToPushBack = myTier1ButtonsTemp[temp];
		myTier1ButtonsTemp.erase(myTier1ButtonsTemp.begin()+temp);

		switch (i)
		{
		case 0:
			buttonToPushBack->SetPosition({ 400, 440 });
			break;								
		case 1:									 
			buttonToPushBack->SetPosition({ 550, 440 });
			break;								
		case 2:									 
			buttonToPushBack->SetPosition({ 700, 440 });
			break;								 
		case 3:									
			buttonToPushBack->SetPosition({ 850, 440 });
			break;
		case 4:
			buttonToPushBack->SetPosition({ 1000, 440 });
			break;
		case 5:
			buttonToPushBack->SetPosition({ 400, 600  });
			break;
		default:
			break;
		}

		myActiveButtonPtrs.push_back(buttonToPushBack);
	}

	for (float i = 0; i < 3; i++)
	{		
		int temp = GetRandomNumberInRange(myTier2ButtonsTemp.size()-1);

		ShopButtonTier2* buttonToPushBack = myTier2ButtonsTemp[temp];

		myTier2ButtonsTemp.erase(myTier2ButtonsTemp.begin() + temp);

		buttonToPushBack->SetPosition({ 550+i*150, 600 });

		myActiveButtonPtrs.push_back(buttonToPushBack);
	}

	if (PlayerAccessor::GetInstance() != nullptr)
	{
		if (PlayerAccessor::GetInstance()->GetHasClusterBombs())
		{
			delete myTier3Buttons[1];
			myTier3Buttons[1] = nullptr;
			myTier3Buttons.erase(myTier3Buttons.begin() + 1);
		}
		if (PlayerAccessor::GetInstance()->GetHasExplodingShield())
		{
			delete myTier3Buttons[3];
			myTier3Buttons[3] = nullptr;
			myTier3Buttons.erase(myTier3Buttons.begin() + 3);
		}
		if (PlayerAccessor::GetInstance()->GetHasPenetratingRounds())
		{
			delete myTier3Buttons[2];
			myTier3Buttons[2] = nullptr;
			myTier3Buttons.erase(myTier3Buttons.begin() + 2);
		}
	}
	

	ShopButtonTier3* buttonToPushBack = myTier3Buttons[GetRandomNumberInRange(myTier3Buttons.size() - 1)];

	buttonToPushBack->SetPosition({ 1000,600 });

	myActiveButtonPtrs.push_back(buttonToPushBack);

	return myActiveButtonPtrs;
}
