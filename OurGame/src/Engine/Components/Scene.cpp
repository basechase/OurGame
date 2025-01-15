#include "Scene.h"
#include "Engine/Actor.h"
Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::AddActor(Actor* actor)
{
	if (!m_actors.Contains(actor))
	{
		m_actors.Add(actor);
	}
}

bool Scene::RemoveActor(Actor* actor)
{
	m_actorsToRemove.Add(actor);
	return true;
}

void Scene::Start()
{
}

void Scene::Update(double deltatime)
{
	for (int i = 0; i < m_actors.Length(); i++)
	{
		if (!m_actors[i]->GetStarted()) 
		{
			m_actors[i]->Start();

		}
		m_actors[i]->Update(deltatime);
	}

	//check for collison

	//Actully remove all he removed actors

	m_actors.Remove(m_actorsToRemove);
	
	for (int i = 0; i < m_actorsToRemove.Length(); i++)
	{
		delete m_actorsToRemove[i];
		m_actorsToRemove[i] = nullptr;
	}
	m_actorsToRemove.Clear();
}

void Scene::End()
{
	for (int i = 0; i < m_actors.Length(); i++)
	{
		m_actors[i]->End();
	}
}
