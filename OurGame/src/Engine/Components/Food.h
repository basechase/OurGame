#pragma once
#include "Engine/Actor.h"
class Food : public Actor
{
public:
	Food();
	~Food();

	void Start();
	void Update(double deltaTime);
	void End();
};