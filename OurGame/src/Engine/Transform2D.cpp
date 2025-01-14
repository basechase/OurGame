#include "Transform2D.h"
#include <cmath>
#define PI 3.14

Transform2D::Transform2D(Actor* Owner)
{
	_localMatrix = new MathLibrary::Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	_globalMatrix = new MathLibrary::Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	_localTranslation = new MathLibrary::Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	_localRotation = new MathLibrary::Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	_localScale = new MathLibrary::Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	_localRotationAngle = 0;
	_parent = 0;
	_owner = Owner;

}

Transform2D::~Transform2D()
{
	 delete _localRotation;
	 delete _localTranslation;
	 delete _localScale;
	 delete _localMatrix;
	 delete  _globalMatrix;
}

void Transform2D::Translate(MathLibrary::Vector2 direction)
{
	LocalPosition(LocalPosition() + direction);
}

void Transform2D::Translate(float x, float y)
{
	LocalPosition((LocalPosition() + MathLibrary::Vector2(x, y)));
}

void Transform2D::Rotate(float radians)
{
	*_localRotation = MathLibrary::Matrix3::createRotation(_localRotationAngle + radians);
}




/// <summary>
/// Updates the Transforms Matricies
/// </summary>
void Transform2D::UpdateTransforms()
{
	*_localMatrix = *_localTranslation * *_localRotation * *_localScale;

	if (_parent != nullptr)
	{
		*_globalMatrix = *_parent->_globalMatrix * *_localMatrix;
	}
	else
	{
		*_globalMatrix = *_localMatrix;
	}
	for (Transform2D* child : _children)
	{
		child->UpdateTransforms();
	}

}

void Transform2D::AddChild(Transform2D* child)
{
	if (child == _parent) return;

	_children.push_back(child);
	child->_parent = this;
}

bool Transform2D::RemoveChild(Transform2D* child)
{


	if (_children.Length() <= 0)
		return false;
	if (_children.Length() == 1 && _children[0] == child)
	{
		_children.Clear();
		return true;
	}
	else
	{
		_children.Remove(child);
		return true;
	}



}

//Getters and Setters 

/// <summary>
/// Gets the Local Position
/// </summary>
/// <returns></returns>
MathLibrary::Vector2 Transform2D::LocalPosition()
{
	return MathLibrary::Vector2(_localTranslation->m02, _localTranslation->m12);
}
/// <summary>
/// Sets the local Position
/// </summary>
/// <param name="position"></param>
void Transform2D::LocalPosition(MathLibrary::Vector2 position)
{
	_localTranslation->m02 = position.x;
	_localTranslation->m12 = position.y;
	UpdateTransforms();
}

MathLibrary::Vector2 Transform2D::LocalScale()
{
	return MathLibrary::Vector2(_localScale->m02, _localScale->m12);
}

void Transform2D::LocalScale(MathLibrary::Vector2 scale)
{
	_localScale->m00 = scale.x;
	_localScale->m11 = scale.y;
	UpdateTransforms();
}

MathLibrary::Vector2 Transform2D::GlobalPosition()
{
	return MathLibrary::Vector2(_globalMatrix->m02, _globalMatrix->m12);
}

MathLibrary::Vector2 Transform2D::GlobalScale()
{
	MathLibrary::Vector2 xAxis = MathLibrary::Vector2(_globalMatrix->m00, _globalMatrix->m10);
	MathLibrary::Vector2 yAxis = MathLibrary::Vector2(_globalMatrix->m01, _globalMatrix->m11);

	return MathLibrary::Vector2(xAxis.getMagnitude(), yAxis.getMagnitude());
}

MathLibrary::Matrix3 Transform2D::LocalRotation()
{
	return *_localRotation;
}

void Transform2D::LocalRotation(MathLibrary::Matrix3 rotation)
{
	*_localRotation = rotation;
	_localRotationAngle = -(float)atan2(_localRotation->m01, _localRotation->m00);
	UpdateTransforms();
}
/// <summary>
/// Calculates the input to degrees
/// </summary>
/// <param name="radian"></param>
/// <returns></returns>
float Transform2D::ToDegrees(float radian)
{
	return (radian * 180) / PI;
}
/// <summary>
/// Calculates the input to radians
/// </summary>
/// <param name="degree"></param>
/// <returns></returns>
float Transform2D::ToRadians(float degree)
{
	return degree * PI / 180;
}
/// <summary>
/// Returns this objects local rotation angle in degrees
/// </summary>
/// <returns></returns>
float Transform2D::GetToDegrees()
{
	return (this->_localRotationAngle * 180) / PI;
}

MathLibrary::Vector2 Transform2D::Forward()
{
	return MathLibrary::Vector2(_globalMatrix->m00, _globalMatrix->m10).getNormalized();
}

MathLibrary::Vector2 Transform2D::Right()
{
	return MathLibrary::Vector2(_globalMatrix->m01, _globalMatrix->m11).getNormalized();
}

