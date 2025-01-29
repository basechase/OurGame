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
	bool GetStarted() { return m_started; }
	int GetRandPos();


private:
	bool m_started = false;


};