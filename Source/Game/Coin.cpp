#include "stdafx.h"
#include "Coin.h"

namespace Studio
{
    Coin::Coin(VECTOR2F aSpawnPosition) : GameObject("Sprites/Pickups/coin1.dds")
    {
        myPosition = aSpawnPosition;
        mySpriteSheet.SetImagePath("Sprites/Pickups/coin1.dds");
        GameObject::myCollider.AddCircleColliderObject(myPosition, 16);
        myScoreValue = 1;
    }

    int Coin::GetScoreValue()
    {
        return myScoreValue;
    }

    VECTOR2F Coin::GetPosition()
    {
        return myPosition;
    }
}

