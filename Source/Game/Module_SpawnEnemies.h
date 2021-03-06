#pragma once
#include "Module.h"
#include "rapidjson/document.h"
namespace Studio
{
	class Module_SpawnEnemies : public Module
	{
	public:
		Module_SpawnEnemies(rapidjson::Value& aModuleParameters);

		bool DoStuff(Boss& aBoss) override;
		void ResetModule() override;
	private:
		std::string myType;
		VECTOR2F mySpawnPosition;
		VECTOR2F myOriginalSpawnPosition;
		bool mySpawnIsRelative;
	};

}

