#pragma once
#include "Engine/Components/Scene.h"
class Level : public Scene
{
public:
	Level();
	~Level();

	void Start();
	void Update(double deltaTime);
	void End();




};