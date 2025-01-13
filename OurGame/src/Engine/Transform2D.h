#pragma once
#include "Matrix3.h"
#include "Vector2.h"
#include <vector>


class Actor;

class Transform2D 
{
	//construct & destructor
	Transform2D(Actor* Owner = nullptr);
	~Transform2D();

	//priv member vars
private:
	
	MathLibrary::Matrix3* _localRotation;
	MathLibrary::Matrix3* _localTranslation;
	MathLibrary::Matrix3* _localScale;
	MathLibrary::Matrix3* _localMatrix;
	MathLibrary::Matrix3* _globalMatrix;
	float _localRotationAngle;
	Actor* _owner;
	Transform2D* _parent;

	
	std::vector<Transform2D*> _children;
	//^ i have no idea if that will work 


	//
public:
	void Translate(MathLibrary::Vector2 direction);
	void Translate(float x, float y);
	void AddChild(Transform2D child);
	void UpdateTransforms();
	void Rotate(float radians);
	void RemoveChild(Transform2D child);
	



	//getters  setters

	MathLibrary::Vector2 LocalPositon();
	MathLibrary::Vector2 GlobalPosition();
	MathLibrary::Vector2 LocalScale();
	MathLibrary::Vector2 Forward();

};