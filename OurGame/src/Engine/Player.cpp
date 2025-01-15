#include "Player.h"
#include "raylib.h"
#include "Engine/Transform2D.h"
Player::Player()
{
	m_scaler = 30;
}

Player::~Player()
{
}

void Player::Start()
{
	Actor::Start();
}

void Player::Update(double deltaTime)
{
	Actor::Update(deltaTime);

	
	
	
	Rectangle mainbody = Rectangle{ GetTransform()->LocalPosition().x, GetTransform()->LocalPosition().y * m_scaler, GetTransform()->LocalScale().x, GetTransform()->LocalScale().y * m_scaler};
	DrawRectangleRounded(mainbody, 0.5, 6, DARKGREEN);
	

}

void Player::End()
{
	Actor::End();
}

