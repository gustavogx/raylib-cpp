/*******************************************************************************************
*
*   raylib [core] example - split screen
*
*   This example has been created using raylib 3.7 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Example contributed by Jeffery Myers (@JeffM2501) and reviewed by Ramon Santamaria (@raysan5)
*
*   Copyright (c) 2021 Jeffery Myers (@JeffM2501)
*
********************************************************************************************/

#include "raylib.hpp"


// Scene drawing
void DrawScene(raylib::Texture2D &textureGrid, const raylib::Camera3D &cameraPlayer1, const raylib::Camera3D &cameraPlayer2)
{
	int count = 5;
	float spacing = 4;

	// Grid of cube trees on a plane to make a "world"
	raylib_c::DrawPlane({ 0, 0, 0 }, { 50, 50 }, raylib::Color::Beige); // Simple world plane

	for (float x = -count*spacing; x <= count*spacing; x += spacing)
	{
		for (float z = -count*spacing; z <= count*spacing; z += spacing)
		{
			raylib_c::DrawCubeTexture(textureGrid, { x, 1.5f, z }, 1, 1, 1, raylib::Color::Green);
			raylib_c::DrawCubeTexture(textureGrid, { x, 0.5f, z }, 0.25f, 1, 0.25f, raylib::Color::Brown);
		}
	}

	// Draw a cube at each player's position
	DrawCube(cameraPlayer1.position, 1, 1, 1, raylib::Color::Red);
	DrawCube(cameraPlayer2.position, 1, 1, 1, raylib::Color::Blue);
}

int main()
{
	namespace rl=raylib;

	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 800;
	const int screenHeight = 450;
	rl::Window window(screenWidth, screenHeight, "raylib [core] example - split screen");

	// Generate a simple texture to use for trees
	
	rl::Texture2D textureGrid;
	{
		rl::Image img(256, 256, 32, 32, rl::Color::DarkGray, rl::Color::White);
		textureGrid = img;
	}
	
	textureGrid.SetFilter(rl::Texture::Filter::Anisotropic16X).SetWrap(rl::Texture::Wrap::Repeat);

	// Setup player 1 camera and screen
	raylib::Camera cameraPlayer1;
	cameraPlayer1.target = {2.0f, 1.0f, 0.0f};
	cameraPlayer1.position = {2.0f, 1.0f, -3.0f};

	rl::RenderTexture screenPlayer1 (screenWidth/2, screenHeight);

	// Setup player two camera and screen
	raylib::Camera cameraPlayer2;
	cameraPlayer2.target = {0.0f, 3.0f, 0.0f};
	cameraPlayer2.position = {-3.0f, 3.0f, 0.0f};

	rl::RenderTexture screenPlayer2 (screenWidth / 2, screenHeight);

	// Build a flipped rectangle the size of the split view to use for drawing later
	rl::Rectangle splitScreenRect = { 0.0f, 0.0f, (float)screenPlayer1.texture.width, (float)-screenPlayer1.texture.height };

	rl::render::SetTargetFPS(60);	// Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!window.ShouldClose())   // Detect window close button or ESC key
	{
		using namespace raylib_c;
		// Update
		//----------------------------------------------------------------------------------
		// If anyone moves this frame, how far will they move based on the time since the last frame
		// this moves thigns at 10 world units per second, regardless of the actual FPS
		float offsetThisFrame = 10.0f*GetFrameTime();

		// Move Player1 forward and backwards (no turning)
		if (IsKeyDown(KEY_W)) cameraPlayer1 += rl::Vector3f::ZDir(offsetThisFrame);
		else if (IsKeyDown(KEY_S)) cameraPlayer1 -= rl::Vector3f::ZDir(offsetThisFrame);

		// Move Player2 forward and backwards (no turning)
		if (IsKeyDown(KEY_UP)) cameraPlayer2 += rl::Vector3f::XDir(offsetThisFrame);
		else if (IsKeyDown(KEY_DOWN)) cameraPlayer2 -= rl::Vector3f::XDir(offsetThisFrame);
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		// Draw Player1 view to the render texture
		ModeTexture(screenPlayer1){
			rl::render::ClearBackground(rl::Color::SkyBlue);
			Mode3D(cameraPlayer1){
				DrawScene(textureGrid,cameraPlayer1,cameraPlayer2);
			}
			rl::Text("PLAYER1 W/S to move").Draw({10, 10}, 20, rl::Color::Red);
		}

		// Draw Player2 view to the render texture
		ModeTexture(screenPlayer2){
			rl::render::ClearBackground(rl::Color::SkyBlue);
			Mode3D(cameraPlayer2){
				DrawScene(textureGrid,cameraPlayer1,cameraPlayer2);
			}
			rl::Text("PLAYER2 Up/Down to move").Draw({10, 10}, 20, rl::Color::Blue);
		}

		// Draw both views render textures to the screen side by side
		Drawing{
			rl::render::ClearBackground(rl::Color::Black);
			screenPlayer1.Draw(splitScreenRect, { 0, 0 });
			screenPlayer2.Draw(splitScreenRect, { screenWidth/2.0f, 0 });
		};
	}

	return EXIT_SUCCESS;
}