#include "raylib.hpp"

int main(){

	using namespace raylib;

	Window window(800,600,"Model");
	render::SetTargetFPS(60);

	Camera3D camera;
	camera.position = { 0.0f, 5.0f, -10.0f };  // Camera position
	camera.target = { 0.0f, 0.0f, 0.0f };      // Camera looking at point
	camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
	camera.fovy = 45.0f;                       // Camera field-of-view Y
	camera.projection = Camera3D::Perspective;    // Camera mode type
	
	raylib_c::Model model = raylib_c::LoadModel("girl.glb");

	std::cout << sizeof(Vector2i) << "\n";
	
	while(!window.ShouldClose()){


		if(raylib_c::IsKeyDown('W')) {
			camera.position.z += 1.f;
			camera.target.z += 1.f;
		}
		if(raylib_c::IsKeyDown('S')) {
			camera.position.z -= 1.f;
			camera.target.z -= 1.f;
		}

		Drawing(){
			

			render::ClearBackground(Color::Black);

			Mode3D(camera){
				raylib_c::DrawGrid(20,10.f);
				raylib_c::DrawModel(model,{0.f,0.f,0.f},1.0f,Color::White);

			}
		}
	}

	return EXIT_SUCCESS;
}