#include "Actor.h"

Actor::Actor(const char* name)
{
	Transform = new Transform2D();
	_started = false;
	_enabled = true;
	_name = name;
	_scale = 0;

}

Actor::~Actor()
{
	delete Transform;
	delete Actor;
}



Actor* Actor::Instantiate(Actor* actor, Transform2D* parent, MathLibrary::Vector2 position, float rotation)
{
	actor->Transform->LocalPosition(position);
	
	if (parent != nullptr)
		parent->AddChild(actor->Transform);
	Game::GetCurrentScene()->AddActor(actor);
	return actor;
}

void Actor::Destroy(Actor* actor)
{
	for (Transform2D* element : actor->Transform->GetChildren())
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

void Actor::Update(double deltaTime)
{
	for (int i = 0; i < m_components.Length(); i++)
	{
		if (!m_components[i]->Started())
			m_components[i]->Start();

		m_components[i]->Update(deltaTime);
	}
	m_components.Remove(m_componentsToRemove);

}

void Actor::End()
{
	for (Component* element : m_components)
	{
		element->End();
	}
}

void Actor::OnCollision(Actor* other)
{
}

void Actor::Enabled(bool value)
{
	if (m_enabled == value)
		return;
	m_enabled = value;
	if (m_enabled)
		OnEnable();
	else
		OnDisable();
}