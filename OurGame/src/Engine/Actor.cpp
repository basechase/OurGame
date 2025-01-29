#include "Actor.h"
#include "Engine/Transform2D.h"
#include "Game.h"
#include "Engine/Components/Scene.h"
Actor::Actor()
{
	Transform = new Transform2D();

}

Actor::~Actor()
{
	delete Transform;
}

void Actor::SetEnabled(bool value)
{
	if (m_enabled == value)
		return;
	m_enabled = value;
	if (m_enabled == true) 
	{
		OnEnabled();
	}
	else 
	{
		OnDisabled();
	}
}

void Actor::OnDisabled()
{
}

void Actor::OnEnabled()
{
}

Actor* Actor::Instantiate(Actor* actor, Transform2D* parent, MathLibrary::Vector2 position, float rotation)
{
	actor->Transform->LocalPosition() = position;
	actor->Transform->Rotate(rotation);
	if (parent != nullptr)
	{
		parent->AddChild(actor->Transform);
	}
	Game::instance->GetCurrentScene()->AddActor(actor);
	return actor;
}

void Actor::Destroy(Actor* actor)
{
	for (Transform2D* element : actor->Transform->GetChild())
	{
		actor->Transform->RemoveChild(element);
	}
	if (actor->Transform->GetParent() != nullptr) 
	{
		actor->Transform->GetParent()->RemoveChild(actor->Transform);
	}

}


void Actor::Start()
{ 
	m_started = true;
}

void Actor::End()
{
}

void Actor::Update(double deltatime)
{
}

void Actor::OnCollision(Actor* other)
{
}

