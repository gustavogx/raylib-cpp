/*******************************************************************************************
*
*   raylib-cpp example - smooth pixel-perfect camera
*	
*	Based on the example 'smooth pixel-perfect camera' by
*   Copyright (c) 2021 Giancamillo Alessandroni (@NotManyIdeasDev) and Ramon Santamaria (@raysan5)
*
* 	On linux, compile with
* 	g++ -o core_smooth_pixelperfect core_smooth_pixelperfect.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -I../../build/raylib/include/. -I../. -std=c++17
*
********************************************************************************************/

/*******************************************************************************************
*
*   raylib [core] example - smooth pixel-perfect camera
*
*   This example has been created using raylib 3.7 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Example contributed by Giancamillo Alessandroni (@NotManyIdeasDev) and
*   reviewed by Ramon Santamaria (@raysan5)
*
*   Copyright (c) 2021 Giancamillo Alessandroni (@NotManyIdeasDev) and Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.hpp"

#include <math.h>       // Required for: sinf(), cosf()

int main(void)
{

	using namespace raylib;
	
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 1280;
	const int screenHeight =720;

	const int virtualScreenWidth = screenWidth/3;
	const int virtualScreenHeight = screenHeight/3;

	const float virtualRatio = (float)screenWidth/(float)virtualScreenWidth;

	UniqueWindow window(screenWidth, screenHeight, "raylib [core] example - smooth pixel-perfect camera");

	Camera2D worldSpaceCamera;// Game world camera
	Camera2D screenSpaceCamera;// Smoothing camera
	
	RenderTexture target { virtualScreenWidth, virtualScreenHeight }; // This is where we'll draw all our objects.

	Rectangle rec01 { 150.0f, 100.0f, 100.0f, 100.0f };
	Rectangle rec02 { 250.0f, 120.0f, 70.0f, 140.0f };
	Rectangle rec03 { 80.0f, 110.0f, 50.0f, 150.0f };

	// The target's height is flipped (in the source Rectangle), due to OpenGL reasons
	Rectangle sourceRec = { 0.0f, 0.0f, (float)target.texture.width, -(float)target.texture.height };
	Rectangle destRec = { -virtualRatio, -virtualRatio, screenWidth + (virtualRatio*2), screenHeight + (virtualRatio*2) };

	Vector2f origin = { 0.0f, 0.0f };

	float rotation = 0.0f;
	float cameraX = 0.0f;
	float cameraY = 0.0f;

	render::SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	Text text1, text2;
	text1 << "Screen resolution: " << screenWidth <<"x"<<screenHeight;
	text2 << "World resolution: " << virtualScreenWidth <<"x"<<virtualScreenHeight;

	// Main game loop
	while (!window.ShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		rotation += 60.0f*render::GetFrameTime();   // Rotate the rectangles, 60 degrees per second

		// Make the camera move to demonstrate the effect
		// Set the camera's target to the values computed above
		screenSpaceCamera.target.x = (sinf(raylib_c::GetTime())*virtualScreenWidth/10)-50;
		screenSpaceCamera.target.y = cosf(raylib_c::GetTime())*virtualScreenHeight/10;

		// Round worldSpace coordinates, keep decimals into screenSpace coordinates
		worldSpaceCamera.target = screenSpaceCamera.target;
		screenSpaceCamera.target -= worldSpaceCamera.target;
		screenSpaceCamera.target *= virtualRatio;

		//----------------------------------------------------------------------------------
		// Draw
		//----------------------------------------------------------------------------------
		ModeTexture(target){
			render::ClearBackground(Color::RayWhite);

			Mode2D(worldSpaceCamera){
				rec01.Draw(origin, 0.5*rotation, Color::Black);
				rec02.Draw(origin, -rotation, Color::Red.Fade(0.8f));
				rec03.Draw(origin, 2.0f*rotation + 45.0f, Color::Blue.Fade(0.7f));
			};
		}

		Drawing{
			render::ClearBackground(Color::Red);

			Mode2D(screenSpaceCamera){
				target.Draw(sourceRec,destRec,origin);
			}

			text1.Draw({10,10},20, Color::DarkBlue);
			text2.Draw({10,40},20, Color::DarkGreen);
			Text::FPS( window.GetWidth() - 95, 10 );

		}
		//----------------------------------------------------------------------------------
	} 

	return EXIT_SUCCESS;
}