#include "Food.h"
#include "Scene.h"
#include "raylib.h"
#include "Engine/Transform2D.h"
#include <Engine/Player.h>

Food::Food()
{
}

Food::~Food()
{
}

void Food::Start()
{

}

void Food::Update(double deltaTime)
{
	Vector2 position{};

	void Draw();
	{
		DrawRectangle(75 + position.x * 25, 75 + position.y * 25, 30, 30, DARKGREEN);

	}

	Vector2 GenerateRandomCell();
	{
		float x = GetRandomValue(0, 30 - 1);
		float y = GetRandomValue(0, 30 - 1);
		return Vector2{ x,y };
	}
}

void Food::End()
{
}
