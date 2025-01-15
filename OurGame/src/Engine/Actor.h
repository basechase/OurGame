#pragma once
#include "Vector2.h"
#include "DynamicArray.h"
#include "Components/Component.h"


// wont need circle collision

class Actor
{
public:

	Actor(const char* name = nullptr);
	~Actor();

	
	static Actor* Instantiate(Actor* actor, 
		Transform2D* parent = nullptr, 
		MathLibrary::Vector2 position = MathLibrary::Vector2(), float rotation);
	void Destroy(Actor* actor);
	virtual void Start();
	virtual void Update(double deltaTime);
	virtual void End();
	virtual void OnEnable() {};
	virtual void OnDisable() {};
	virtual void OnCollision(Actor* other);
	
	bool Started() { return _started; }
	bool Enabled() { return _enabled; }
	void Enabled(bool value);
	float GetScale() { return _scale; }

	template<typename T>
	T* AddComponent(T* component);

	template<typename T>
	T* RemoveComponent(T* component);

	template<typename T>
	T* GetComponent(T* component);


	
	Transform2D* Transform;





private:
	bool m_started;
	bool m_enabled;
	const char* m_name;
	DynamicArray<Component*> _components;
	DynamicArray<Component*> _componentsToRemove;
protected:
	float _scale;





};



template<typename T>
inline T* Actor::AddComponent(T* component)
{
	Component* ptr = dynamic_cast<Component*>(component);
	if (ptr == nullptr)
	{ 
		return nullptr;
	}
	else
	{
		_components.Add(component);
		return component;
	}
}

template<typename T>
inline T* Actor::RemoveComponent(T* component)
{
	Component* ptr = dynamic_cast<Component*>(component);
	if (ptr == nullptr) {

		return false;
	}
	else
	{
		_componentsToRemove.Add(component);
		return true;
	}
}

template<typename T>
inline T* Actor::GetComponent(T* component)
{
	Component ptr = dynamic_cast<Component>(component);
	if (ptr = nullptr)
		return false;
	else
	{
		for (Component* element : m_components)
		{
			if (element = component)
			{
				return element;
			}
		}
	}
}