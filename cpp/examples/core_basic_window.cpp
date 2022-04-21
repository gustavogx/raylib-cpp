/*******************************************************************************************
*
*   raylib-cpp example - Basic window
*	
*	Based on the example 'Basic window' by
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

// Compile on linux
// g++ -std=c++17 -o basic_window core_basic_window.cpp -lraylib -I../../build/raylib/include/. -I../cpp/. -lGL -lm -lpthread -ldl -lrt -lX11 

#include "raylib.hpp"

int main(void)
{
    using namespace raylib;

	// Initialization
	//--------------------------------------------------------------------------------------
	Window window {800,450,"raylib-cpp [core] example - basic window"};
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

		Drawing(){

            Color z;
            
			render::ClearBackground(Color::RayWhite);
			text::Draw("Congrats! You created your first window!", 190, 200, 20, Color::LightGray);
			
		}
		//----------------------------------------------------------------------------------
	}// De-Initialization is automated by the destructor.

	return EXIT_SUCCESS;
}