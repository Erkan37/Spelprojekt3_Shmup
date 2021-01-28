#include "stdafx.h"
#include "CoinManager.h"
#include "Coin.h"
#include "tga2d/sprite/sprite.h"
#include "RendererAccessor.h"
#include "Renderer.h"

namespace Studio
{
	CoinManager::CoinManager()
	{
		myPlayerCoins = 0;
	}

	void CoinManager::Update()
	{
		for (size_t i = 0; i < myWorldCoins.size(); i++)
		{
			myWorldCoins[i]->Update(myWorldCoins[i]->GetPosition());
			RendererAccessor::GetInstance()->Render(*myWorldCoins[i]);
		}
	}

	void CoinManager::AddCoins(int anAmount)
	{
		myPlayerCoins += anAmount;
	}

	void CoinManager::RemoveCoins(int anAmount)
	{
		myPlayerCoins -= anAmount;

	}

	void CoinManager::SetCoins(int anAmount)
	{
		myPlayerCoins = anAmount;
	}

	void CoinManager::CreateCoin(VECTOR2F aPosition)
	{
		myWorldCoins.push_back(new Coin(aPosition));

	}

	std::vector<Coin*>& CoinManager::GetWorldCoins()
	{
		return myWorldCoins;
	}
}


