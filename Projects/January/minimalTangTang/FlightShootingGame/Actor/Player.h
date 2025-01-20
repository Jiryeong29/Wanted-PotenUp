#pragma once

#include "Actor/DrawableActor.h"

class Player : public DrawableActor
{
	RTTI_DECLARATIONS(Player, DrawableActor)

public:
	friend class TestLevel;
	Player(const char* image);

	virtual void Update(float deltaTime);
};
