#include "Level.h"
#include "Scene.h"
#include "raylib.h"
#include "Engine/Actor.h"
#include "Engine/Player.h"

Level::Level()
{
}
Level::~Level()
{
}

void Level::Start()
{
	Scene::Start();

	Actor::Instantiate(new Player());
}

void Level::Update(double deltaTime)
{
	Scene::Update(deltaTime);

	DrawRectangleLinesEx(Rectangle{ (float)75 - 5, (float)75 - 5, (float)30 * 25 + 10, (float)30 * 25 + 10 }, 5, DARKGREEN);
	DrawText("Snake Game", 75 - 5, 20, 40, DARKGREEN);
}

void Level::End()
{
	Scene::End();
}