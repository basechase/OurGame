#pragma once
class Actor;
class CircleCollider;

class Collider {

public:
	Collider(Actor* owner);
	~Collider();

	Collider* GetCollider() { return m_owner; }
	bool CheckCollison(Actor* other);
	virtual bool CheckCollisionCircle(CircleCollider* collider);
	virtual void Draw(); 
	void DrawHitbox();
	Actor* Owner;




private:
	Collider* m_owner;


};