/*******************************************************************************************
*
*   raylib-cpp example - Initialize 3d camera free
*	
*	Based on the example 'Initialize 3d camera free' by
*   Copyright (c) 2015 Ramon Santamaria (@raysan5)
*
* 	On linux, compile with
* 	g++ -o 3d_camera_free core_3d_camera_free.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -I../../build/raylib/include/. -I../. -std=c++17
*
********************************************************************************************/

#include "raylib.hpp"

int main(void)
{
	using namespace raylib;

	// Initialization
	//--------------------------------------------------------------------------------------
	Window window(800,450,"raylib [core] example - 3d camera free");

	// Define the camera to look into our 3d world
	Camera3D camera( { 0.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f } );  // Camera position and looking at point
	camera.SetMode(Camera3D::Free); // Set a free camera mode

	render::SetTargetFPS(60);	// Set our game to run at 60 frames-per-second
	
	Vector3f cubePosition = { 0.0f, 0.0f, 0.0f };
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!window.ShouldClose())        // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		camera.Update();          // Update camera

		if (raylib_c::IsKeyDown('Z')) camera.target = { 0.0f, 0.0f, 0.0f };
		//----------------------------------------------------------------------------------

		// Drawing as a c++ scope
		//----------------------------------------------------------------------------------
		Drawing{
			
			render::ClearBackground(Color::RayWhite);

			Mode3D(camera){

								
				draw::Cube(cubePosition, {2.0f, 2.0f, 2.0f}, Color::Red);
				draw::CubeWires(cubePosition, {2.0f, 2.0f, 2.0f}, Color::Maroon);
				draw::Grid(10, 1.0f);

			};

			draw::Rectangle( {10, 10}, {320, 133}, Color::SkyBlue.Fade(0.5f), Color::Blue );

			text::Draw("Free camera default controls:", {20, 20}, 10, Color::Black);
			text::Draw("- Mouse Wheel to Zoom in-out", {40, 40}, 10, Color::DarkGray);
			text::Draw("- Mouse Wheel Pressed to Pan", {40, 60}, 10, Color::DarkGray);
			text::Draw("- Alt + Mouse Wheel Pressed to Rotate", {40, 80}, 10, Color::DarkGray);
			text::Draw("- Alt + Ctrl + Mouse Wheel Pressed for Smooth Zoom", {40, 100}, 10, Color::DarkGray);
			text::Draw("- Z to zoom to (0, 0, 0)", {40, 120}, 10, Color::DarkGray);

		}
		//----------------------------------------------------------------------------------
	}   // De-Initialization is automated by the destructor.


	return EXIT_SUCCESS;
}