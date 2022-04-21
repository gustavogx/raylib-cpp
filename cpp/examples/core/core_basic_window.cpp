/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

// Compile on linux
// g++ -std=c++17 -o basic_window core_basic_window.cpp -lraylib -I../../build/raylib/include/. -I../../cpp/. -lGL -lm -lpthread -ldl -lrt -lX11 

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