#include "Component.h"

Component::Component(Actor* owner)
{
	m_enabled = true;
	m_started = false;
	m_owner = owner;
}

Component::~Component()
{
	
}

void Component::SetEnabled(bool value)
{
	if (m_enabled == value) 
		return;
	m_enabled = value;
	if (m_enabled)
	{
		OnEnable();
	}
	else
	{
		OnDisable();
	}
}

void Component::OnEnable()
{
	
}

void Component::OnDisable()
{
	


}

void Component::Start()
{
	m_started = true;
	
}

void Component::Update(double deltaTime)
{
}

void Component::End()
{
}
