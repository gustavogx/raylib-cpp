/*******************************************************************************************
*
*   raylib-gx example - Basic window
*
*   raylib.hpp is an abstraction layer over raylib.h with (almost) zero overhead.
*	
*	Just drop raylib.hpp into your project's folder.
*   To learn how to use it, compare this example with the corresponding one it is based on.
*
*	Based on the example 'core_basic_window.c'
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
* 	On linux, compile with
* 	g++ -o basic_window core_basic_window.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -I../../build/raylib/include/. -I../. -std=c++17
*
********************************************************************************************/

#include "raylib.hpp"

int main(void)
{
	using namespace raylib;

	// Initialization
	//--------------------------------------------------------------------------------------
	Window window {800,450,"raylib-cpp [core] example - basic window"};
	Window::SetTargetFPS(60);	// Set our game to run at 60 frames-per-second
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
		Drawing{	// works like a named scope.

			Window::ClearBackground(Color::RayWhite);
			Text::Draw("Congrats! You created your first window!", {190, 200}, 20, Color::LightGray);
			
		}
		//----------------------------------------------------------------------------------
	}// De-Initialization is automated by the destructor.

	return EXIT_SUCCESS;
}