#pragma once
#include "Matrix3.h"
#include "Vector2.h"



class Actor;

class Transform2D 
{
	Transform2D();
	~Transform2D();
private:
	
	MathLibrary::Matrix3* _localRotation;
	MathLibrary::Matrix3* _localTranslation;
	MathLibrary::Matrix3* _localScale;
	MathLibrary::Matrix3* _localMatrix;
	MathLibrary::Matrix3* _globalMatrix;
	float _localRotationAngle;
	Actor* owner;


public:
	void Translate(MathLibrary::Vector2 direction);
	void Translate(float x, float y);
	void AddChild(Transform2D child);
	void UpdateTransforms();
	void Rotate(float radians);




};