#pragma once

#include <string>
#include <iostream>
#include <random>

namespace raylib_c{
	#include "raylib.h"
}

namespace raylib {

	// ==================================================================================================
	// Structures
	// ==================================================================================================

	// Color, 4 components, R8G8B8A8 (32bit)
	struct Color : public raylib_c::Color {
		Color() = default;
		Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha=255) : raylib_c::Color{red,green,blue,alpha} {}

		// Custom raylib color palette for amazing visuals
		static Color const Gray;		// Gray
		static Color const LightGray;	// Light Gray
		static Color const DarkGray;	// Dark Gray
		static Color const Yellow;		// Yellow
		static Color const Gold;		// Gold
		static Color const Orange;		// Orange
		static Color const Pink;		// Pink
		static Color const Red;			// Red
		static Color const Maroon;		// Maroon
		static Color const Green;		// Green
		static Color const Lime;		// Lime
		static Color const DarkGreen;	// Dark Green
		static Color const SkyBlue;		// Sky Blue
		static Color const Blue;		// Blue
		static Color const DarkBlue;	// Dark Blue
		static Color const Purple;		// Purple
		static Color const Violet;		// Violet
		static Color const DarkPurple;	// Dark Purple
		static Color const Beige;		// Beige
		static Color const Brown;		// Brown
		static Color const DarkBrown;	// Dark Brown

		static Color const White;		// White
		static Color const Black;		// Black
		static Color const Blank;		// Transparent
		static Color const Magenta;		// Magenta
		static Color const RayWhite;	// Ray White

	};

	Color const Color::LightGray 	= LIGHTGRAY;
	Color const Color::Gray 		= GRAY;
	Color const Color::DarkGray 	= DARKGRAY;
	Color const Color::Yellow 		= YELLOW;
	Color const Color::Gold 		= GOLD;
	Color const Color::Orange 		= ORANGE;
	Color const Color::Pink			= PINK;
	Color const Color::Red			= RED;
	Color const Color::Maroon		= MAROON;
	Color const Color::Green		= GREEN;
	Color const Color::Lime			= LIME;
	Color const Color::DarkGreen	= DARKGREEN;
	Color const Color::SkyBlue		= SKYBLUE;
	Color const Color::Blue			= BLUE;
	Color const Color::DarkBlue		= DARKBLUE;
	Color const Color::Purple		= PURPLE;
	Color const Color::Violet		= VIOLET;
	Color const Color::DarkPurple	= DARKPURPLE;
	Color const Color::Beige		= BEIGE;
	Color const Color::Brown		= BROWN;
	Color const Color::DarkBrown	= DARKBROWN;

	Color const Color::White		= WHITE;
	Color const Color::Black		= BLACK;
	Color const Color::Blank		= BLANK;
	Color const Color::Magenta		= MAGENTA;
	Color const Color::RayWhite		= RAYWHITE;

	struct Vector2i{
		uint32_t x,y;
		uint32_t &u = x;
		uint32_t &v = y;
		uint32_t &operator[](const uint8_t &index) { return *(&x+index); }
		inline Vector2i operator+=(const Vector2i &other) { x+=other.x; y+=other.y; return *this; }
		inline Vector2i operator+(const Vector2i &other) { return {x+other.x,y+other.y}; }
		inline Vector2i operator-=(const Vector2i &other) { x-=other.x; y-=other.y; return *this; }
		inline Vector2i operator-(const Vector2i &other) { return {x-other.x,y-other.y}; }
		inline Vector2i operator*=(const uint32_t &other) { x*=other; y*=other; return *this; }
		inline Vector2i operator*(const uint32_t &other) { return {x*other,y*other}; }
	};


	struct Vector2f : public raylib_c::Vector2 {
		Vector2f() = default;
		Vector2f(const float &x, const float &y) : raylib_c::Vector2{x,y} {}

		float &operator[](const uint8_t &index) { return *(&x+index); }
		
		inline Vector2f operator+=(const Vector2f &other) { x+=other.x; y+=other.y; return *this; }
		inline Vector2f operator+(const Vector2f &other) { return {x+other.x,y+other.y}; }
		inline Vector2f operator-=(const Vector2f &other) { x-=other.x; y-=other.y; return *this; }
		inline Vector2f operator-(const Vector2f &other) { return {x-other.x,y-other.y}; }
		inline Vector2f operator*=(const float &other) { x*=other; y*=other; return *this; }
		inline Vector2f operator*(const float &other) { return {x*other,y*other}; }
	};
	
	struct Vector3f : public raylib_c::Vector3{
		Vector3f() = default;
		Vector3f(const float &x, const float &y, const float &z) : raylib_c::Vector3{x,y,z} {}

		float &operator[](const uint8_t &index) { return *(&x+index); }

		inline Vector3f operator+=(const Vector3f &other) { x+=other.x; y+=other.y; z+=other.z; return *this; }
		inline Vector3f operator+(const Vector3f &other) { return {x+other.x,y+other.y,z+other.z}; }
		inline Vector3f operator-=(const Vector3f &other) { x-=other.x; y-=other.y; z-=other.z; return *this; }
		inline Vector3f operator-(const Vector3f &other) { return {x-other.x,y-other.y,z-other.z}; }
		inline Vector3f operator*=(const float &other) { x*=other; y*=other; z*=other; return *this; }
		inline Vector3f operator*(const float &other) { return {x*other,y*other,z*other}; }
	};

	struct Vector4f : public raylib_c::Vector4{
		Vector4f() = default;
		Vector4f(const float &x, const float &y, const float &z, const float &w) : raylib_c::Vector4{x,y,z,w} {}

		float &operator[](const uint8_t &index) { return *(&x+index); }

		inline Vector4f operator+=(const Vector4f &other) { x+=other.x; y+=other.y; z+=other.z; w+=other.w; return *this; }
		inline Vector4f operator+(const Vector4f &other) { return {x+other.x,y+other.y,z+other.z,w+other.w}; }
		inline Vector4f operator-=(const Vector4f &other) { x-=other.x; y-=other.y; z-=other.z; w-=other.w; return *this; }
		inline Vector4f operator-(const Vector4f &other) { return {x-other.x,y-other.y,z-other.z,w-other.w}; }
		inline Vector4f operator*=(const float &other) { x*=other; y*=other; z*=other; w*=other; return *this; }
		inline Vector4f operator*(const float &other) { return {x*other,y*other,z*other,w*other}; }
	};

	// Camera, defines position/orientation in 3d space
	struct Camera3D : public raylib_c::Camera3D {

		// Camera projection
		enum Type{ 
			Perspective = 0, 
			Orthographic 
		};

		// Camera system modes
		enum Mode{
			Custom = 0,             // Custom camera
			Free,                   // Free camera
			Orbital,                // Orbital camera
			FirstPerson,            // First person camera
			ThirdPerson             // Third person camera
		};
	
		void SetMode(const Camera3D::Mode &system) { raylib_c::SetCameraMode( *this, system); }
		void Update() { raylib_c::UpdateCamera( this); }

	};

	typedef Camera3D Camera;    // Camera type fallback, defaults to Camera3D

	// Camera2D, defines position/orientation in 2d space
	struct Camera2D : public raylib_c::Camera2D {
	};

/*
	// Texture, tex data stored in GPU memory (VRAM)
	class Texture {
		
		::Texture mTextureData;


	public:
	
		//operator ::Texture() { return {ID,Width,Height,Mipmaps,Format}; }
		//operator ::Texture() const { return {ID,Width,Height,Mipmaps,Format}; }
		Texture() = default;
		Texture(const Texture &) = default;		
		Texture(const ::Texture &other) : mTextureData{other} {}
		Texture(const std::string &fileName) { this->mTextureData = ::LoadTexture(fileName.c_str()); }
		Texture(const Image &image) { this->mTextureData = ::LoadTextureFromImage(image); }
		~Texture() { UnloadTexture(mTextureData); }

		::Texture &GetTextuteData() { return mTextureData; }
		::Texture GetTextuteData() const { return mTextureData; }

		inline uint32_t &GetID() { return mTextureData.id; }
		inline uint32_t GetID() const { return mTextureData.id; }

		inline int32_t &GetWidth() { return mTextureData.width; }
		inline int32_t GetWidth() const { return mTextureData.width; }

		inline int32_t &GetHeight() { return mTextureData.height; }
		inline int32_t GetHeight() const { return mTextureData.height; }

		void Draw(const Vector2i &position, const Color &tint) { ::DrawTexture(mTextureData, position.x, position.y, tint); }
		//void Draw(const Vector2f &position, const Color &tint) { ::DrawTexture(mTextureData, (int32_t)position.x, (int32_t)position.y, tint); }
	};

	// Texture2D, same as Texture
	typedef Texture Texture2D;

	// TextureCubemap, same as Texture
	typedef Texture TextureCubemap;

*/

// ==================================================================================================
// Window class
// ==================================================================================================

	class UniqueWindow{ // One Window per application
		
	public:
		
		UniqueWindow(const uint32_t &width, const uint32_t &height, const std::string &title) { raylib_c::InitWindow(width,height,title.c_str()); }
		~UniqueWindow() { raylib_c::CloseWindow(); }

		static bool ShouldClose() { return raylib_c::WindowShouldClose(); }

/*		static void Close() { ::CloseWindow(); }
		static bool IsReady() { return ::IsWindowReady();}				// Check if window has been initialized successfully
		static bool IsFullScreen() { return ::IsWindowFullscreen();}	// Check if window is currently fullscreen
		static bool IsHidden() { return ::IsWindowHidden();}			// Check if window is currently hidden (only PLATFORM_DESKTOP)
		static bool IsMinimized() { return ::IsWindowMinimized();}    	// Check if window is currently minimized (only PLATFORM_DESKTOP)
		static bool IsMaximized() { return ::IsWindowMaximized();}		// Check if window is currently maximized (only PLATFORM_DESKTOP)
		static bool IsFocused() { return ::IsWindowFocused();}			// Check if window is currently focused (only PLATFORM_DESKTOP)
		static bool IsResized() { return ::IsWindowResized();}			// Check if window has been resized last frame
		static bool IsState(uint32_t flags) { return ::IsWindowState(flags);}	// Check if one specific window flag is enabled
		static void SetState(uint32_t flags) { ::SetWindowState(flags);}		// Set window configuration state using flags
		static void ClearState(uint32_t flags) { ::ClearWindowState(flags);}	// Clear window configuration state flags
		static void ToggleFullscreen() { ::ToggleFullscreen();}					// Toggle window state: fullscreen/windowed (only PLATFORM_DESKTOP)
		static void Maximize() { ::MaximizeWindow();}							// Set window state: maximized, if resizable (only PLATFORM_DESKTOP)
		static void Minimize() { ::MinimizeWindow();}							// Set window state: minimized, if resizable (only PLATFORM_DESKTOP)
		static void Restore()  { ::RestoreWindow();	}	    					// Set window state: not minimized/maximized (only PLATFORM_DESKTOP)
		static void SetIcon(Image image) { ::SetWindowIcon(image); }			// Set icon for window (only PLATFORM_DESKTOP)
		static void SetTitle(const std::string &title) { ::SetWindowTitle(title.c_str());}	// Set title for window (only PLATFORM_DESKTOP)
		static void SetPosition(uint32_t x, uint32_t y) { ::SetWindowPosition(x, y);}	// Set window position on screen (only PLATFORM_DESKTOP)
		static void SetPosition(Vector2 pos) { ::SetWindowPosition(pos.x, pos.y);}	// Set window position on screen (only PLATFORM_DESKTOP)
		static void SetMonitor(uint32_t monitor) { ::SetWindowMonitor(monitor); }   // Set monitor for the current window (fullscreen mode)
		static void SetMinSize(uint32_t width, uint32_t height) { ::SetWindowMinSize(width, height); } // Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)
		static void SetSize(uint32_t width, uint32_t height) { ::SetWindowSize(width, height); }	// Set window dimensions
		static void *GetHandle() { return ::GetWindowHandle(); };		// Get native window handle
		static Vector2 GetPosition() { return ::GetWindowPosition(); }	// Get window position XY on monitor
		static int GetWidth() { return GetScreenWidth(); }
		static int GetHeight() { return GetScreenHeight(); }
		static Vector2 GetScaleDPI() { return ::GetWindowScaleDPI(); }	// Get window scale DPI factor
*/
/*		
	int GetMonitorCount(void);                                              // Get number of connected monitors
	int GetCurrentMonitor(void);                                            // Get current connected monitor
	Vector2 GetMonitorPosition(int monitor);                                // Get specified monitor position
	int GetMonitorWidth(int monitor);                                       // Get specified monitor width (max available by monitor)
	int GetMonitorHeight(int monitor);                                      // Get specified monitor height (max available by monitor)
	int GetMonitorPhysicalWidth(int monitor);                               // Get specified monitor physical width in millimetres
	int GetMonitorPhysicalHeight(int monitor);                              // Get specified monitor physical height in millimetres
	int GetMonitorRefreshRate(int monitor);                                 // Get specified monitor refresh rate
	Vector2 GetWindowPosition(void);                                        // Get window position XY on monitor
	Vector2 GetWindowScaleDPI(void);                                        // Get window scale DPI factor
	const char *GetMonitorName(int monitor);                                // Get the human-readable, UTF-8 encoded name of the primary monitor
	void SetClipboardText(const char *text);                                // Set clipboard text content
	const char *GetClipboardText(void);                                     // Get clipboard text content
*/

	};
	typedef UniqueWindow Window;

	// Drawing-related functions
	namespace render{

		static void SetTargetFPS(uint32_t fps) { raylib_c::SetTargetFPS(fps); }

		static void ClearBackground(const Color &color) { raylib_c::ClearBackground(color); } // Set background color (framebuffer clear color)

		struct Drawing{
			bool run;
			Drawing() : run(true) { raylib_c::BeginDrawing(); } // Setup canvas (framebuffer) to start drawing
			~Drawing() { raylib_c::EndDrawing(); }               // End canvas drawing and swap buffers (double buffering)
		};
		
		struct Mode2D{
			bool run;
			Mode2D(const Camera2D &camera) : run(true) { raylib_c::BeginMode2D(camera); } 	// Setup canvas (framebuffer) to start drawing
			~Mode2D() { raylib_c::EndMode2D(); }               								// End canvas drawing and swap buffers (double buffering)
		};

		struct Mode3D{
			bool run;
			Mode3D(const Camera3D &camera) : run(true) { raylib_c::BeginMode3D(camera); } 	// Setup canvas (framebuffer) to start drawing
			~Mode3D() { raylib_c::EndMode3D(); }               								// End canvas drawing and swap buffers (double buffering)
		};
		
	}
	#define Drawing() for(raylib::render::Drawing scope; scope.run; scope.run=false)
	#define Mode2D(camera2D) for(raylib::render::Mode2D scope(camera2D); scope.run; scope.run=false)
	#define Mode3D(camera3D) for(raylib::render::Mode3D scope(camera3D); scope.run; scope.run=false)
/*
	static void BeginTextureMode(RenderTexture2D target) { ::BeginTextureMode(target); }    // Begin drawing to render texture
	static void EndTextureMode() { :: EndTextureMode(); }                                   // Ends drawing to render texture
	static void BeginShaderMode(Shader shader) { ::BeginShaderMode(shader); }				// Begin custom shader drawing
	static void EndShaderMode() { ::EndShaderMode(); }										// End custom shader drawing (use default shader)
	static void BeginBlendMode(uint32_t mode) { ::BeginBlendMode(mode); }					// Begin blending mode (alpha, additive, multiplied, subtract, custom)
	static void EndBlendMode() { ::EndBlendMode(); }										// End blending mode (reset to default: alpha blending)
	static void BeginScissorMode(uint32_t x, uint32_t y, uint32_t width, uint32_t height) { ::BeginScissorMode(x, y, width, height); }             // Begin scissor mode (define screen area for following drawing)
	static void EndScissorMode() { ::EndScissorMode(); } 									// End scissor mode
	static void BeginVrStereoMode(VrStereoConfig config) { ::BeginVrStereoMode(config); }	// Begin stereo rendering (requires VR simulator)
	static void EndVrStereoMode() { ::EndVrStereoMode(); } 									// End stereo rendering (requires VR simulator)
*/

	namespace Draw {
		// Shapes
		static void Pixel(const Vector2f &position, const Color &color) { raylib_c::DrawPixelV((Vector2f)position,color); }									// Draw a pixel (Vector version)
		static void Rectangle(const Vector2f &position, const Vector2f &size, const Color &color) { raylib_c::DrawRectangleV(position,size,color); }	// Draw a color-filled rectangle
		static void RectangleLines(const Vector2f &position, const Vector2f &size, const Color &color) { raylib_c::DrawRectangleLines(position.x,position.y,size.x,size.y,color); }	// Draw a color-filled rectangle		
		
		// Models
		static void Cube(const Vector3f &position, const Vector3f &size, const Color &color) { raylib_c::DrawCubeV(position, size, color); }                                       // Draw cube (Vector version)
		static void CubeWires(const Vector3f &position, const Vector3f &size, const Color &color) { raylib_c::DrawCubeWiresV(position, size, color); }                                  // Draw cube wires (Vector version)
		static void Grid(uint32_t slices, float spacing) { raylib_c::DrawGrid(slices,spacing); }
	}

	namespace text{

		void FPS(const Vector2i &position) { raylib_c::DrawFPS(position.x, position.y); }
		void Draw(const std::string &text, const Vector2i &position, uint32_t fontSize, Color color) { raylib_c::DrawText(text.c_str(), position.x, position.y, fontSize, color);}
	}

	namespace Input{


	// Input-related functions: mouse
//	Vector2f GetMousePosition() { return { ::GetMousePosition().x, ::GetMousePosition().y}; }		// Get mouse position XY

/*
	bool IsMouseButtonPressed(int button);                                  // Check if a mouse button has been pressed once
	bool IsMouseButtonDown(int button);                                     // Check if a mouse button is being pressed
	bool IsMouseButtonReleased(int button);                                 // Check if a mouse button has been released once
	bool IsMouseButtonUp(int button);                                       // Check if a mouse button is NOT being pressed
	int GetMouseX(void);                                                    // Get mouse position X
	int GetMouseY(void);                                                    // Get mouse position Y
	Vector2 GetMouseDelta(void);                                            // Get mouse delta between frames
	void SetMousePosition(int x, int y);                                    // Set mouse position XY
	void SetMouseOffset(int offsetX, int offsetY);                          // Set mouse offset
	void SetMouseScale(float scaleX, float scaleY);                         // Set mouse scaling
	float GetMouseWheelMove(void);                                          // Get mouse wheel movement Y
	void SetMouseCursor(int cursor);                                        // Set mouse cursor
*/

	}
}

