#include "Collider.h" 
#include "Engine/Actor.h"
#include "CircleCollider.h"
#include "raylib.h"
Collider::Collider(Actor* owner)
{
	Owner = owner;
}

Collider::~Collider()
{
}



bool Collider::CheckCollison(Actor* other)
{
	if (other->m_collider != nullptr && dynamic_cast<CircleCollider*>(other->m_collider) != nullptr)
	{
		return CheckCollisionCircle(dynamic_cast<CircleCollider*>(other->m_collider));
	}
	return false;
}

bool Collider::CheckCollisionCircle(CircleCollider* collider)
{
	return false;
}



void Collider::Draw()
{

}

