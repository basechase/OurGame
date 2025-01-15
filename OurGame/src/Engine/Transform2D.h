#pragma once
#include "Matrix3.h"
#include "Vector2.h"
#include <vector>
#include "DynamicArray.h"

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

	
	DynamicArray<Transform2D*> _children;
	//^ i have no idea if that will work 


	//
public:
	void Translate(MathLibrary::Vector2 direction);
	void Translate(float x, float y);
	void AddChild(Transform2D* child);
	void UpdateTransforms();
	void Rotate(float radians);
	bool RemoveChild(Transform2D* child);
	
	



	//getters  setters

	Actor* GetOwner() { return _owner; }
	DynamicArray<Transform2D*> GetChild() { return _children; }
	Transform2D* GetParent() { return _parent; }
	float LocalRotationAngle() { return _localRotationAngle; };

	void LocalRotation(MathLibrary::Matrix3 rotation);
	void LocalPosition(MathLibrary::Vector2 position);
	void LocalScale(MathLibrary::Vector2 scale);
	MathLibrary::Vector2 Forward();
	MathLibrary::Vector2 Right();
	MathLibrary::Vector2 LocalPosition();

	MathLibrary::Vector2 LocalScale();
	MathLibrary::Vector2 GlobalPosition();
	MathLibrary::Vector2 GlobalScale();
	MathLibrary::Matrix3 LocalRotation();
	

	float GetToDegrees();
	float ToDegrees(float radians);
	float ToRadians(float degrees);






};