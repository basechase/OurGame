#pragma once


class Food 
{
public:

	void Start();
	void Update(double deltaTime);
	void End();
	bool GetStarted() { return m_started; }

private:
	bool m_started = false;


};