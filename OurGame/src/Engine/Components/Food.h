#pragma once
#include "Engine/Actor.h"
#include "Engine/Transform2D.h"


class Food : public Actor
{
public:
	Food();
	~Food();
	void Start();
	void Update(double deltaTime);
	void End();
	bool GetStarted() { return m_started; }
	int GetRandPos();
	void OnCollision(Actor* other) override;
	
private:
	bool m_started = false;


};
