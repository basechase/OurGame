#pragma once
#include "Actor.h"

class Player : public Actor
{
public:
	Player();
	~Player();

	void Start();
	void Update(double deltaTime);
	void End();

private:
	float m_scaler;
};
