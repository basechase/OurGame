#pragma once

class Actor;


class Scene {
public:
	void AddActor(Actor* actor);
	bool RemoveActor(Actor* actor);
	virtual void Start();
	virtual void Update(double deltatime);
	virtual void End();



private: 
	

};
