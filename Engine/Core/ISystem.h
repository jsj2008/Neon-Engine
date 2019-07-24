#pragma once

#include "Config.h"

#include "stdafx.h"

namespace Neon 
{
	class Context;
	
	class ISystem 
	{
	public:
		ISystem() = default;

		virtual bool Init() { return true; };

		virtual void Update();

		virtual const char* GetName() { return "ISystem"; }

		virtual ~ISystem() = default;
	};
}