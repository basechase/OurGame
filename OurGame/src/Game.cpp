#include "Game.h"
#include "raylib.h"
#include "Engine/Components/Scene.h"
#include "Engine/Components/Level.h"

Scene* Game::m_currentScene = nullptr;
DynamicArray<Scene*> Game::m_scenes;

Color green = { 173, 204, 96, 255 };
Color darkGreen = { 43, 51, 24, 255 };

Game::Game()
{
	if (m_currentScene == nullptr)
	{
		m_currentScene = this->m_currentScene;
	}
	m_level = new Level();
	deltaTime = 0;
}

Game::~Game()
{
}

void Game::Run()
{
	InitWindow(2 * 75 + 30 * 25, 2 * 75 + 30 * 25, "Snake Game");
	SetTargetFPS(60);


	AddScene(m_level);
	SetCurrentScene(m_level);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(green);

		//Drawing

		m_currentScene->Update(deltaTime);

		

		EndDrawing();
	}
	m_currentScene->End();
	CloseWindow();
}


void Game::AddScene(Scene* scene)
{
	if (!m_scenes.Contains(scene))
	{
		m_scenes.Add(scene);
	}

	if (m_currentScene == nullptr)
	{
		m_currentScene = scene;
	}
}

void Game::RemoveScene(Scene* scene)
{
	m_scenes.Remove(scene);
	if (m_currentScene == scene)
	{
		m_currentScene = GetScene(0);
	}
}

Scene* Game::GetScene(int index)
{
	if (m_scenes.Length() <= 0 || m_scenes.Length() <= index || index < 0)
		return nullptr;
	return m_scenes[index];
}

void Game::SetCurrentScene(Scene* scene)
{
	if (m_currentScene != nullptr)
		m_currentScene->End();
	m_currentScene = scene;
	m_currentScene->Start();
}
