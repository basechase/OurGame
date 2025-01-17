#pragma once
#include "Engine/DynamicArray.h"
class Actor;



class Scene 
{
public:
	Scene();
	~Scene();


	void AddActor(Actor* actor);
	bool RemoveActor(Actor* actor);
	virtual void Start();
	virtual void Update(double deltatime);
	virtual void End();




private: 
	DynamicArray<Actor*> m_actors;
	DynamicArray<Actor*> m_actorsToRemove;

};
