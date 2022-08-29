#pragma once

#include "baseGame.h"// inheriting form baseGame

class demoGame : public baseGame 
{

public:
	void onTick() override;
};