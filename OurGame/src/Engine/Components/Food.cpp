#include "Food.h"
#include "raylib.h"
Food::Food()
{
}

Food::~Food()
{
}

void Food::Start()
{
	Actor::Start();
	GetTransform()->Translate({ 500,500 });
}

void Food::Update(double deltaTime)
{
	DrawCircle(GetTransform()->LocalPosition().x, GetTransform()->LocalPosition().y, 10, BLUE);
}

void Food::End()
{
}

int Food::GetRandPos()
{
	return 0;
}

void Food::OnCollision(Actor* other)
{
	Actor().Destroy(this);
}

