#pragma once 
#include "Engine\DynamicArray.h"
class Scene;


class Game
{
public:
	Game();
	~Game();

	void Run();

	void AddScene(Scene* scene);

	void RemoveScene(Scene* scene);

	static Scene* GetScene(int index);

	static Game* instance;

	static Scene* GetCurrentScene() { return m_currentScene; }

	static void SetCurrentScene(Scene* scene);

private:
	static DynamicArray<Scene*> m_scenes;
	static Scene* m_currentScene;
	double deltaTime;
	Scene* m_level;
};