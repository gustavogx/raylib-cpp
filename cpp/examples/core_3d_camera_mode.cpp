/*******************************************************************************************
*
*   raylib-cpp example - Initialize 3d camera mode
*	
*	Based on the example 'Initialize 3d camera mode' by
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
* 	On linux, compile with
* 	g++ -o 3d_camera_mode core_3d_camera_mode.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -I../../build/raylib/include/. -I../. -std=c++17
*
********************************************************************************************/

#include "raylib.hpp"

int main(void)
{
	using namespace raylib;

	// Initialization
	//--------------------------------------------------------------------------------------
	Window window(800,450,"raylib [core] example - 3d camera mode");

	// Define the camera to look into our 3d world
	Camera3D camera( { 0.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f } );  // Camera position and looking at point

	Vector3f cubePosition { 0.0f, 0.0f, 0.0f };

	render::SetTargetFPS(60);	// Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!window.ShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		Drawing{

			render::ClearBackground(Color::RayWhite);

			Mode3D(camera){

				draw::Cube(cubePosition, {2.0f, 2.0f, 2.0f}, Color::Red);
				draw::CubeWires(cubePosition, {2.0f, 2.0f, 2.0f}, Color::Maroon);
				draw::Grid(10, 1.0f);

			}

			text::Draw("Welcome to the third dimension!", {10, 40}, 20, Color::DarkGray);
			text::FPS({10, 10});

		}
		//----------------------------------------------------------------------------------
	}	// De-Initialization is automated by the destructor.

	return 0;
}