#pragma once
#include "rapidjson/document.h"
namespace Studio
{
	class Module
	{
	public:
		Module(rapidjson::Value& aModuleParameters);
		virtual ~Module();
		//TODO Change this stupid function name
		virtual bool DoStuff() = 0;
	protected:

	private:
	};

}

