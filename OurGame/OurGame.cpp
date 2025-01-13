#include <iostream>
#include <raylib.h>
#include "Matrix4.h"
#include "Matrix3.h"
#include "Vector3.h"
#include "Vector4.h"

Color green = { 173, 204, 96, 255 };
Color darkGreen = { 43, 51, 24, 255 };

int cellSize = 30;
int cellCount = 25;

class Food
{

public:

};

int main()
{
	InitWindow(cellSize * cellCount, cellSize * cellCount, "Snake Game");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		      
		//Drawing
		ClearBackground(green);

		EndDrawing();
	}


	CloseWindow();
	return 0;
}