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
int offset = 75;

class Food
{

public:

};

int main()
{
	InitWindow(2*offset + cellSize * cellCount, 2*offset + cellSize * cellCount, "Snake Game");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		      
		//Drawing
		ClearBackground(green);
		DrawRectangleLinesEx(Rectangle{ (float)offset - 5, (float)offset - 5, (float)cellSize * cellCount + 10, (float)cellSize * cellCount + 10 }, 5, darkGreen);
		DrawText("Snake Game", offset - 5, 20, 40, darkGreen);
		EndDrawing();
	}


	CloseWindow();
	return 0;
}