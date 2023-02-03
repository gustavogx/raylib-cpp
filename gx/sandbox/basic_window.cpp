/*******************************************************************************************
*
*   raylib-cpp Sandbox for basic class testing
*	
* 	On linux, compile with
* 	g++ -o basic_window basic_window.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -I../../build/raylib/include/. -I../. -std=c++17
*
********************************************************************************************/

#include "raylib.hpp"

int main(void)
{
	using namespace raylib;

	// Initialization
	//--------------------------------------------------------------------------------------
	Window window {800,450,"raylib-cpp - sanbox"};
	render::SetTargetFPS(60);	// Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	Text text("Congrats! You created your first window!");
	text << " again";

	// Main game loop
	while (!window.ShouldClose())    // Detect window close button or ESC key
	{
		ScreenDraw{

			render::ClearBackground(Color::RayWhite);
			text.Draw( {190, 200}, 20, Color::LightGray);
			
		}
	}

	return EXIT_SUCCESS;
}