#include "Transform2D.h"



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

