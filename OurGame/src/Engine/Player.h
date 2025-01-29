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
	float GetScale() { return m_scaler; }
	void SetScale(int value) { value = m_scaler; }
private:
	float m_scaler;
};
