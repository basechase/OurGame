#pragma once
#include "Vector2.h"
#include "DynamicArray.h"
#include "Engine/Components/Component.h"
#include "Components/Collision/Collider.h"
class Transform2D;



class Actor
{
public:
	Actor();
	~Actor();

	bool GetStarted() { return m_started; }
	bool GetEnabled() { return m_enabled; }	
	void SetEnabled(bool value);
	virtual void OnDisabled();
	virtual void OnEnabled();
	Transform2D* GetTransform() { return Transform; }
	static Actor* Instantiate(Actor* actor, Transform2D* parent = nullptr, MathLibrary::Vector2 position = {0,0}, float rotation = 0);
	static void Destroy(Actor* actor);
	virtual void Start();
	virtual void End();
	virtual void Update(double deltatime);
	virtual void OnCollision(Actor* other);



	Collider* m_collider;
	Transform2D* Transform;
	


private:
	bool m_started;
	bool m_enabled;




};