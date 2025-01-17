#include "Player.h"
#include "raylib.h"
#include "Engine/Transform2D.h"

Player::Player()
{
	m_scaler = 100;
}

Player::~Player()
{
}

void Player::Start()
{
	Actor::Start();
	GetTransform()->Translate({300,300});
}

void Player::Update(double deltaTime)
{
	Actor::Update(deltaTime);
	if (IsKeyDown(KEY_A))
	{
		GetTransform()->Translate(GetTransform()->Forward() * -2);
	}
	if (IsKeyDown(KEY_D))
	{
		GetTransform()->Translate(GetTransform()->Forward() * 2);
	}
	if (IsKeyDown(KEY_W))
	{
		GetTransform()->Translate(GetTransform()->Right() * -2);
	}if (IsKeyDown(KEY_S))
	{
		GetTransform()->Translate(GetTransform()->Right() * 2);
	}
	
	Rectangle mainbody = Rectangle{ GetTransform()->LocalPosition().x, GetTransform()->LocalPosition().y * m_scaler, GetTransform()->LocalScale().x, GetTransform()->LocalScale().y * m_scaler};
	
	DrawCircle(GetTransform()->LocalPosition().x, GetTransform()->LocalPosition().y, m_scaler, BLACK);

}

void Player::End()
{
	Actor::End();
}

