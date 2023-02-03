#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <random>

namespace raylib_c{
	#include "raylib.h"
	#include "rlgl.h"
}

namespace raylib {

	// ==================================================================================================
	// Foreword Declarations
	// ==================================================================================================


	struct Color;

	struct Vector2i;
	struct Vector2f;
	struct Vector3f;
	struct Vector4f;
	struct Matrix4f;

	struct Rectangle;
	struct Image;
	struct Texture;
	typedef Texture Texture2D;
	struct RenderTexture;

	struct GlyphInfo;
	struct Text;
	struct UniqueWindow;
	typedef UniqueWindow Window;

	struct Camera3D;
	struct Camera2D;
	typedef Camera3D Camera;	// Camera type fallback, defaults to Camera3D

	struct DrawingScope;
	struct Mode2DScope;
	struct Mode3DScope;
	struct ModeTextureScope;

	// ==================================================================================================
	// Definitions
	// ==================================================================================================

	// Color, 4 components, R8G8B8A8 (32bit)
	struct Color : public raylib_c::Color {

		// Wrappers 
		static inline void Fade(Color &color, const float &alpha) { color = raylib_c::Fade(color,alpha); }

		Color(const raylib_c::Color &color) : raylib_c::Color(color) {} 
		Color(const uint8_t &red, const uint8_t &green, const uint8_t &blue, const uint8_t &alpha=255) : raylib_c::Color{red,green,blue,alpha} {}
		
		Color Fade(const float &alpha) const { return raylib_c::Fade(*this,alpha); }

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

		// Color static constants
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

	// Integer Vector 2D
	struct Vector2i{

		int32_t x,y;

		Vector2i(const int32_t &x, const int32_t &y) : x{x}, y{y} {}
		int32_t &operator[](const uint8_t &index) { return *(&x+index); }
		inline Vector2i  operator+ (const Vector2i &other) { return {x+other.x,y+other.y}; }
		inline Vector2i& operator+=(const Vector2i &other) { return (*this=*this+other); }
		inline Vector2i  operator- (const Vector2i &other) { return {x-other.x,y-other.y}; }
		inline Vector2i& operator-=(const Vector2i &other) { return (*this=*this-other); }
		inline Vector2i  operator* (const int32_t &other) { return {x*other,y*other}; }
		inline Vector2i& operator*=(const int32_t &other) { return (*this=*this*other); }
		inline Vector2i  operator/ (const int32_t &other) { return {x/other,y/other}; }
		inline Vector2i& operator/=(const int32_t &other) { return (*this=*this/other); }

	};

	struct Vector2f : public raylib_c::Vector2 {
		Vector2f() = default;
		Vector2f(const raylib_c::Vector2 &other) : raylib_c::Vector2(other) {} 
		Vector2f(const float &x, const float &y) : raylib_c::Vector2{x,y} {}

		float &operator[](const uint8_t &index) { return *(&x+index); }
		inline Vector2f  operator= (const Vector2f &other) { this->x=other.x; this->y=other.y; return *this; }
		inline Vector2f  operator+ (const Vector2f &other) { return {x+other.x,y+other.y}; }
		inline Vector2f& operator+=(const Vector2f &other) { *this=*this+other; return *this; }
		inline Vector2f  operator- (const Vector2f &other) { return {x-other.x,y-other.y}; }
		inline Vector2f& operator-=(const Vector2f &other) { *this=*this-other; return *this; }
		inline Vector2f  operator* (const float &other) { return {x*other,y*other}; }
		inline Vector2f& operator*=(const float &other) {  *this=*this*other; return *this; }
		inline Vector2f  operator/ (const float &other) { return {x/other,y/other}; }
		inline Vector2f& operator/=(const float &other) {  *this=*this/other; return *this; }

		inline void DrawPixel(const Color &color) { raylib_c::DrawPixelV(*this,color); }
	};
	
	struct Vector3f : public raylib_c::Vector3 {

		Vector3f() = default;
		//Vector3f(const Vector3f&) = default;
		//Vector3f(Vector3f &&) = default;

		Vector3f(const float &x, const float &y, const float &z) : raylib_c::Vector3{x,y,z} {}

		static inline Vector3f UnitX() { return {1.f,0.f,0.f}; }
		static inline Vector3f UnitY() { return {0.f,1.f,0.f}; }
		static inline Vector3f UnitZ() { return {0.f,0.f,1.f}; }
		
		static inline Vector3f XDir(const float &mag=1.0f) { return {mag,0.f,0.f};}
		static inline Vector3f YDir(const float &mag=1.0f) { return {0.f,mag,0.f};}
		static inline Vector3f ZDir(const float &mag=1.0f) { return {0.f,0.f,mag};}

		float &operator[](const uint8_t &index) { return *(&x+index); }
		inline Vector3f  operator+ (const Vector3f &other) { return {x+other.x,y+other.y,z+other.z}; }
		inline Vector3f& operator+=(const Vector3f &other) { *this=*this+other; return *this; }
		inline Vector3f  operator- (const Vector3f &other) { return {x-other.x,y-other.y,z-other.z}; }
		inline Vector3f& operator-=(const Vector3f &other) { *this=*this-other; return *this; }
		inline Vector3f  operator* (const float &other) { return {x*other,y*other,z*other}; }
		inline Vector3f& operator*=(const float &other) {  *this=*this*other; return *this; }
		inline Vector3f  operator/ (const float &other) { return {x/other,y/other,z/other}; }
		inline Vector3f& operator/=(const float &other) {  *this=*this/other; return *this; }

		inline Vector3f operator^(const Vector3f &other) { return {y*other.z-z*other.y, z*other.x-x*other.z, x*other.y-y*other.z}; }
		inline float operator*(const Vector3f &other) { return x*other.x+y*other.y+z*other.z; }

		inline void DrawPoint(const Color &color) { raylib_c::DrawPoint3D(*this,color); }

		protected:
		Vector3f(const raylib_c::Vector3 &other) : raylib_c::Vector3(other) {} 
	};

	struct Vector4f : public raylib_c::Vector4{

		Vector4f() = default;
		Vector4f(const raylib_c::Vector4 &other) : raylib_c::Vector4(other) {} 
		Vector4f(const float &x, const float &y, const float &z, const float &w) : raylib_c::Vector4{x,y,z,w} {}
		Vector4f(const Vector2f &v1, const Vector2f &v2) : raylib_c::Vector4{v1.x,v1.y,v2.x,v2.y} {}

		float &operator[](const uint8_t &index) { return *(&x+index); }

		inline Vector4f  operator+(const Vector4f &other) { return {x+other.x,y+other.y,z+other.z,w+other.w}; }
		inline Vector4f& operator+=(const Vector4f &other) {  *this=*this+other; return *this; }
		inline Vector4f  operator-(const Vector4f &other) { return {x-other.x,y-other.y,z-other.z,w-other.w}; }
		inline Vector4f& operator-=(const Vector4f &other) {  *this=*this-other; return *this; }
		inline Vector4f  operator*(const float &other)  { return {x*other,y*other,z*other,w*other}; }
		inline Vector4f& operator*=(const float &other) {  *this=*this*other; return *this; }
		inline Vector4f  operator/(const float &other)  { return {x/other,y/other,z/other,w/other}; }
		inline Vector4f& operator/=(const float &other) {  *this=*this/other; return *this; }
	};

	// Quaternion Representation
	typedef Vector4f Quaternion;

	// Matrix, 4x4 components, column major, OpenGL style, right handed
	struct Matrix4f : public raylib_c::Matrix {
		
		Matrix4f() = default;
		Matrix4f(const raylib_c::Matrix &other) : raylib_c::Matrix{other} {} 
		Matrix4f(const Vector4f &v1, const Vector4f &v2, const Vector4f &v3, const Vector4f &v4) : 
			raylib_c::Matrix{v1.x,v2.x,v3.x,v4.x, v1.y,v2.y,v3.y,v4.y, v1.z,v2.z,v3.z,v4.z, v1.w,v2.w,v3.w,v4.w} {}

		Matrix4f(const float diag) : 
			raylib_c::Matrix{diag,0,0,0, 0,diag,0,0, 0,0,diag,0, 0,0,0,0} {}

		float &operator[](const uint8_t &index) { return *(&m0+index); }
		float &operator()(const uint8_t &row, const uint8_t &col) { return *(&m0+row*4+col); }
	};

	// Rectangle, 4 components
	struct Rectangle : public raylib_c::Rectangle {
		
		Rectangle() : raylib_c::Rectangle{} {}
		Rectangle(const float &x, const float &y, const float &width, const float &height) : raylib_c::Rectangle{x,y,width,height} {}
		Rectangle(const Vector2f& position, const Vector2f& dimensions) : raylib_c::Rectangle{position.x,position.y,dimensions.x,dimensions.y} {}

		inline void Draw(const Color& colorFill, const Color &colorLine={0,0,0,0}) { 
			raylib_c::DrawRectangle(x,y,width,height,colorFill); 
			if(colorFill.a) raylib_c::DrawRectangleLines(x,y,width,height,colorLine);
		}
		inline void Draw(const Vector2f &origin, const float &rotation, const Color& color) { raylib_c::DrawRectanglePro(*this,origin,rotation,color); }
		inline void DrawLine(const Color& color, const float thickness=1.0f) { raylib_c::DrawRectangleLinesEx(*this,thickness,color); }

		private:
		Rectangle(const raylib_c::Rectangle &other) :  raylib_c::Rectangle{other} {}
	};

	// Image, pixel data stored in CPU memory (RAM)
	struct Image : public raylib_c::Image {

		friend struct Texture;
		friend struct RenderTexture;
		friend struct GlyphInfo;

		Image(const Image&) = delete;
		Image(Image &&)  = default;
		~Image() { Unload(*this); }

		inline Image operator=(Image &other) { return std::move( raylib_c::ImageCopy(other)); }
		Image(const std::string &fileName) : raylib_c::Image{LoadFromFile(fileName)} {} // Load image from file into CPU memory (RAM)
		Image(const std::string &fileName, const uint32_t &width, const uint32_t &height, const uint32_t &format, const uint32_t &headerSize) : raylib_c::Image{LoadFromFileRaw(fileName, width, height, format, headerSize)} {} // Load image from RAW file data
		Image(const std::string &fileName, int32_t &frames) : raylib_c::Image{LoadAnimation(fileName,frames)} {} // Load image from RAW file data
		Image(const std::string &fileType,  const uint8_t *fileData, const uint32_t &dataSize) : raylib_c::Image{LoadFromMemory(fileType,fileData,dataSize)} {}
		Image(const int &width, const int &height, const int &checksX, const int &checksY, const Color &color1, const Color &color2) : 
			raylib_c::Image{ raylib_c::GenImageChecked(width,height,checksX,checksY,color1,color2)} {} // Creates a checked image
		
		static inline void Unload(Image &image) { raylib_c::UnloadImage(image); }
		[[nodiscard]] static inline Image LoadFromFile(const std::string &fileName) { return raylib_c::LoadImage(fileName.c_str()); }		// Load image from file into CPU memory (RAM)
		[[nodiscard]] static inline Image LoadFromFileRaw (const std::string &fileName, const uint32_t &width, const uint32_t &height, const uint32_t &format, const uint32_t &headerSize) { return raylib_c::LoadImageRaw(fileName.c_str(), width, height, format, headerSize); }       				// Load image from RAW file data
		[[nodiscard]] static inline Image LoadAnimation(const std::string &fileName, int32_t &frames) { return raylib_c::LoadImageAnim(fileName.c_str(), &frames); }	// Load image sequence from file (frames appended to image.data)
		[[nodiscard]] static inline Image LoadFromMemory(const std::string &fileType,  const uint8_t *fileData, const uint32_t &dataSize) { return raylib_c::LoadImageFromMemory(fileType.c_str(), fileData, dataSize); }	// Load image from memory buffer
		
		[[nodiscard]] static inline Image LoadFromTexture(const raylib_c::Texture &texture) { return raylib_c::LoadImageFromTexture(texture);}	// Load image from GPU texture data
		[[nodiscard]] static inline Image LoadFromScreen() { return raylib_c::LoadImageFromScreen(); }								// Load image from screen buffer and (screenshot)
    
		protected:
		Image(const raylib_c::Image &other) : raylib_c::Image{other} {}
		Image() : raylib_c::Image(){} 
	};

	// Texture, tex data stored in GPU memory (VRAM)
	struct Texture : public raylib_c::Texture {
		
		friend struct Image;
		friend struct RenderTexture;

		Texture() = default;			
		Texture(const Texture &) = delete;
		//Texture(Texture &&) = default;

		Texture(const std::string &fileName) : raylib_c::Texture{raylib_c::LoadTexture(fileName.c_str())} {}
		Texture(Image &image) : raylib_c::Texture{} {*this = image;}
		
		~Texture() { Unload(*this); }

		inline void Update(const void *pixels) { raylib_c::UpdateTexture(*this,pixels); }
		inline void Update(const Rectangle &rec, const void *pixels) { raylib_c::UpdateTextureRec(*this,rec,pixels); }
		inline void Draw(const Vector2f &position, const Color &tint=Color::White)  { Draw(*this,position,tint); }
		inline void Draw(const Vector2f &position, const float &rotation = 0.f, const float &scale = 1.f, const Color &tint=Color::White)  
						{ Draw(*this,position,rotation,scale,tint); }
		inline void Draw(const Rectangle &source, const Rectangle &destination, const Vector2f &origin = {0.f,0.f}, const float &rotation = 0.f, const Color &tint=Color::White) 
						{ Draw(*this,source,destination,origin,rotation,tint); }
		inline void Draw(const Rectangle &source, const Vector2f &position, const Color &tint=Color::White)
						{ Draw(*this,source,position,tint); }
	
		Texture &operator=(Image &image) { 
			
			auto temp = raylib_c::LoadTextureFromImage(image); 
			if(temp.id && id) {
				Unload(*this);
				this->id = temp.id;
				this->height = temp.height;
				this->width = temp.width;
				this->mipmaps = temp.mipmaps;
				this->format = temp.format;				
			}
			return *this; 
		}

		inline Texture& SetFilter(const uint32_t &filter) { raylib_c::SetTextureFilter(*this,filter); return *this; }
		inline Texture& SetWrap(const uint32_t &wrap) { raylib_c::SetTextureWrap(*this,wrap);  return *this; }

		// Wrappers
		static inline void Draw(Texture &texture, const Vector2f &position, const Color &tint=Color::White) 
			{ raylib_c::DrawTexture(texture, position.x, position.y,tint); }
		static inline void Draw(Texture &texture, const Rectangle &source, const Rectangle &destination, const Vector2f &origin = {0.f,0.f}, const float &rotation = 0.f, const Color &tint=Color::White) 
			{ raylib_c::DrawTexturePro(texture,source,destination,origin,rotation,tint); }
		static inline void Draw(Texture &texture, const Vector2f &position, const float &rotation = 0.f, const float &scale = 1.f, const Color &tint=Color::White) 
			{ raylib_c::DrawTextureEx(texture, position, rotation, scale, tint); }
		static inline void Draw(Texture &texture, const Rectangle &source, const Vector2f &position, const Color &tint) 
			{ raylib_c::DrawTextureRec(texture,source,position,tint); }

		static inline void Unload(Texture &texture) { raylib_c::UnloadTexture(texture); }
		[[nodiscard]] static inline Texture LoadFromFile(const std::string &fileName) { return raylib_c::LoadTexture(fileName.c_str()); }
		[[nodiscard]] static inline Texture LoadFromImage(const Image &image) { return raylib_c::LoadTextureFromImage(image); }

		// Texture parameters: filter mode
		// NOTE 1: Filtering considers mipmaps if available in the texture
		// NOTE 2: Filter is accordingly set for minification and magnification
		enum Filter {
			Point 			= raylib_c::TEXTURE_FILTER_POINT,			// No filter, just pixel approximation
			Bilinear 		= raylib_c::TEXTURE_FILTER_BILINEAR,		// Linear filtering
			Trilinear 		= raylib_c::TEXTURE_FILTER_TRILINEAR,		// Trilinear filtering (linear with mipmaps)
			Anisotropic4X 	= raylib_c::TEXTURE_FILTER_ANISOTROPIC_4X,	// Anisotropic filtering 4x
			Anisotropic8X 	= raylib_c::TEXTURE_FILTER_ANISOTROPIC_8X,	// Anisotropic filtering 8x
			Anisotropic16X 	= raylib_c::TEXTURE_FILTER_ANISOTROPIC_16X,	// Anisotropic filtering 16x
		};

		// Texture parameters: wrap mode
		enum Wrap{
			Repeat 			= raylib_c::TEXTURE_WRAP_REPEAT,		// Repeats texture in tiled mode
			Clamp 			= raylib_c::TEXTURE_WRAP_CLAMP,			// Clamps texture to edge pixel in tiled mode
			MirrorRepeat 	= raylib_c::TEXTURE_WRAP_MIRROR_REPEAT,	// Mirrors and repeats the texture in tiled mode
			MirrorClamp 	= raylib_c::TEXTURE_WRAP_MIRROR_CLAMP	// Mirrors and clamps to border the texture in tiled mode
		};

	protected:
		Texture(const raylib_c::Texture &other) : raylib_c::Texture{other} {}
	};

	Image TextureToImage(const Texture &Texture) { return Image::LoadFromTexture(Texture); }
	Texture ImageToTexture(const Image &image) { return Texture::LoadFromImage(image); }

	struct RenderTexture : public raylib_c::RenderTexture {
		
		friend struct Texture;
		friend struct Image;
		friend struct ModeTextureScope;

		RenderTexture(const RenderTexture &) = delete;
		RenderTexture(RenderTexture &&) = default;
		~RenderTexture() { Unload(*this); }

		RenderTexture(const Vector2i &size) : raylib_c::RenderTexture(raylib_c::LoadRenderTexture(size.x, size.y)) {}
		RenderTexture(const uint32_t &width, const uint32_t &height) : raylib_c::RenderTexture(raylib_c::LoadRenderTexture(width, height)) {}

		inline void Draw(const Vector2f &position, const Color &tint=Color::White)  
			{ raylib_c::DrawTexture(this->texture,position.x,position.y,tint); }
		inline void Draw(const Vector2f &position, const float &rotation = 0.f, const float &scale = 1.f, const Color &tint=Color::White)  
			{ raylib_c::DrawTextureEx(this->texture,position,rotation,scale,tint); }
		inline void Draw(const Rectangle &source, const Rectangle &destination, const Vector2f &origin = {0.f,0.f}, const float &rotation = 0.f, const Color &tint=Color::White) 
			{ raylib_c::DrawTexturePro(this->texture,source,destination,origin,rotation,tint); }
		inline void Draw(const Rectangle &source, const Vector2f &position, const Color &tint=Color::White)
			{ raylib_c::DrawTextureRec(this->texture,source,position,tint); }

		// Static wrappers for raylib
		static inline void Unload(const RenderTexture &texture) { raylib_c::UnloadRenderTexture(texture); }
		[[nodiscard]] static inline RenderTexture LoadRenderTexture(const uint32_t &width, const uint32_t &height) { return raylib_c::LoadRenderTexture(width, height); }

	protected:
		RenderTexture(const raylib_c::RenderTexture &other) : raylib_c::RenderTexture{other.id, other.texture, other.depth} {}
		RenderTexture() : raylib_c::RenderTexture(){}

	};


	// GlyphInfo, font characters glyphs info
	struct GlyphInfo : public raylib_c::GlyphInfo {
		Image image;            // Character image data
		
		friend struct Font;
		friend struct Image;

		protected:
		GlyphInfo(const raylib_c::GlyphInfo &other) : raylib_c::GlyphInfo(other){}
	};

	// Font, font texture and GlyphInfo array data
	struct Font : public raylib_c::Font {

		Texture texture;        // Texture atlas containing the glyphs
		Rectangle *recs;        // Rectangles in texture for the glyphs
		GlyphInfo *glyphs;      // Glyphs info data

		Font(const Font &) = delete;
		Font(Font &&) = default;
		~Font(){ UnloadFont(*this); }

		Font(const std::string &fileName) : raylib_c::Font{ LoadFont(fileName) } {} // Load font from file into GPU memory (VRAM)
		Font(const std::string &fileName, int fontSize, int *fontChars, int glyphCount) : raylib_c::Font{ LoadFont(fileName,fontSize,fontChars,glyphCount)} {}				// Load font from file with extended parameters
		Font(const Image &image, const Color &key, int firstChar)  : raylib_c::Font{ LoadFont(image,key,firstChar)} {}	// Load font from Image (XNA style)
		Font(const char *fileType, const unsigned char *fileData, int dataSize, int fontSize, int *fontChars, int glyphCount)  : raylib_c::Font{ LoadFont(fileType,fileData,dataSize,fontSize,fontChars,glyphCount)} {} // Load font from memory buffer, fileType refers to extension: i.e. '.ttf'

		// Wrappers
		static inline void Unload(Font &font) { raylib_c::UnloadFont(font); }	// Unload Font from GPU memory (VRAM)
		[[nodiscard]] static inline const Font& GetDefault() { return sDefault; }				// Get the default Font
		[[nodiscard]] static inline Font LoadFont(const std::string &fileName) { return raylib_c::LoadFont(fileName.c_str());} // Load font from file into GPU memory (VRAM)
		[[nodiscard]] static inline Font LoadFont(const std::string &fileName, int fontSize, int *fontChars, int glyphCount) { return raylib_c::LoadFontEx(fileName.c_str(),fontSize,fontChars,glyphCount); }	// Load font from file with extended parameters
		[[nodiscard]] static inline Font LoadFont(const Image &image, const Color &key, int firstChar)  { return raylib_c::LoadFontFromImage(image,key,firstChar);}	// Load font from Image (XNA style)
		[[nodiscard]] static inline Font LoadFont(const char *fileType, const unsigned char *fileData, int dataSize, int fontSize, int *fontChars, int glyphCount)  { return raylib_c::LoadFontFromMemory(fileType,fileData,dataSize,fontSize,fontChars,glyphCount);}	// Load font from memory buffer, fileType refers to extension: i.e. '.ttf'

		protected:

		Font(const raylib_c::Font &other) : raylib_c::Font(other) {}
		const static Font sDefault;
	};

	const Font Font::sDefault = std::move(raylib_c::GetFontDefault());

	struct Text : private std::string {
		
		Text() : std::string() {}
		Text(const std::stringstream &text) : std::string{text.str()} {}
		Text(const std::string &str) : std::string(str) {}
		Text(const char *str) : std::string(str) {}
		Text(const Text &text) : std::string(text) {}
		Text(const unsigned int &value) : std::string(std::to_string(value)) {}
		Text(const int &value) : std::string(std::to_string(value)) {}
		Text(const float &value) : std::string(std::to_string(value)) {}
		Text(const double &value) : std::string(std::to_string(value)) {}

		void Draw(const Vector2i &position, uint32_t fontSize, Color color) { raylib_c::DrawText(this->c_str(), position.x, position.y, fontSize, color);}
		void Draw(const raylib_c::Font &font, Vector2f position, float fontSize, float spacing, const Color &tint) { raylib_c::DrawTextEx(font,this->c_str(),position,fontSize,spacing,tint); } // Draw text using font and additional parameters
		void Draw(const raylib_c::Font &font, Vector2f position, Vector2f origin, float rotation, float fontSize, float spacing, const Color &tint) { DrawTextPro(font,this->c_str(),position,origin,rotation,fontSize,spacing,tint); } // Draw text using Font and pro parameters (rotation)

		Text* Clear() { this->clear(); return this; }
		inline uint32_t Length() { return this->length(); }
		operator const char*() const { return this->c_str(); }

		inline Text &operator<<(std::string &str) { *this += str; return *this; }
		inline Text &operator<<(std::stringstream &stream) { *this += stream.str(); return *this; }
		inline Text &operator<<(const char *text) { *this += text; return *this; }
		inline Text &operator<<(const unsigned int &value) { *this += std::to_string(value); return *this; }
		inline Text &operator<<(const int &value) { *this += std::to_string(value); return *this; }
		inline Text &operator<<(const float &value) { *this += std::to_string(value); return *this; }
		inline Text &operator<<(const double &value) { *this += std::to_string(value); return *this; }

		// Wrappers
		static inline void FPS(int posX, int posY) { raylib_c::DrawFPS(posX, posY); }       // Draw current FPS
		static inline void FPS(const Vector2i &position) { raylib_c::DrawFPS(position.x, position.y); }
		static inline void Draw(const Text &text, const Vector2i &position, uint32_t fontSize, Color color) { raylib_c::DrawText(text.c_str(), position.x, position.y, fontSize, color);}
		static inline void DrawCodepoint(const raylib_c::Font &font, int codepoint, Vector2f position, float fontSize, const Color &tint) { raylib_c::DrawTextCodepoint(font,codepoint,position,fontSize,tint); } // Draw one character (codepoint)

	};

	
	// Camera, defines position/orientation in 3d space
	struct Camera3D : public raylib_c::Camera3D {

		friend struct Mode3DScope;
		
		inline Vector3f& Position() {return (Vector3f&)position; }
		inline Vector3f& Target() {return (Vector3f&)target; }
		inline Vector3f& Up() {return (Vector3f&)up; }

		//Vector3f 

		// Camera projection
		enum Type{ 
			Perspective = 0, 
			Orthographic 
		};

		// Camera system modes
		enum Mode{
			Custom = 0,		// Custom camera
			Free,			// Free camera
			Orbital,		// Orbital camera
			FirstPerson,	// First person camera
			ThirdPerson		// Third person camera
		};

		Camera3D() : raylib_c::Camera3D{ Vector3f{}, Vector3f{}, {0.0f,1.0f,0.0f}, 45.f, Type::Perspective} {}
		Camera3D(const Vector3f &position, const Vector3f &target, const Vector3f &up={0.0f,1.0f,0.0f}, const float &fovy=45.f, const Type &type=Type::Perspective) : raylib_c::Camera3D{position,target,up,fovy,type} {}

		inline Camera3D& operator+=(const Vector3f &displace) { Position()+=displace; Target()+=displace; return *this;}
		inline Camera3D& operator-=(const Vector3f &displace) { Position()-=displace; Target()-=displace; return *this;}
/*
		inline Camera3D& operator*=(const float &rotate) { 
			auto dir = Position()-Target();
			Matrix4f rot(1.0f);
			raylib_c::rlPushMatrix();
				raylib_c::rlRotatef(rotate,dir.x,dir.y,dir.z);
				raylib_c::rlMultMatrixf(&rot[0]);
			raylib_c::rlPopMatrix();
			
			return *this;
		}
		inline Camera3D& operator/=(const float &rotate) { 
			auto dir = Position()-Target();
			raylib_c::rlRotatef(-rotate,dir.x,dir.y,dir.z);
			Position() += dir;
			return *this;
		}
*/
		void SetMode(const Camera3D::Mode &mode) { raylib_c::SetCameraMode( *this, mode); }
		void Update() { raylib_c::UpdateCamera(this); }
	
	};


	struct Camera2D : public raylib_c::Camera2D {
		Vector2f offset;	// Camera offset (displacement from target)
		Vector2f target;	// Camera target (rotation and zoom origin)

		friend struct Mode3DScope;
		Camera2D() : raylib_c::Camera2D{{0.f,0.f},{0.f,0.f},0.f,1.f} {}
	};

// ==================================================================================================
// Window class
// ==================================================================================================

	class UniqueWindow{ // One Window per application
		
	public:
		
		UniqueWindow(const uint32_t &width, const uint32_t &height, const std::string &title) { raylib_c::InitWindow(width,height,title.c_str()); }
		~UniqueWindow() { raylib_c::CloseWindow(); }

		inline bool ShouldClose() { return raylib_c::WindowShouldClose(); }

		inline void Close() { raylib_c::CloseWindow(); }
		inline bool IsReady() { return raylib_c::IsWindowReady();}				// Check if window has been initialized successfully
		inline bool IsFullScreen() { return raylib_c::IsWindowFullscreen();}	// Check if window is currently fullscreen
		inline bool IsHidden() { return raylib_c::IsWindowHidden();}			// Check if window is currently hidden (only PLATFORM_DESKTOP)
		inline bool IsMinimized() { return raylib_c::IsWindowMinimized();}    	// Check if window is currently minimized (only PLATFORM_DESKTOP)
		inline bool IsMaximized() { return raylib_c::IsWindowMaximized();}		// Check if window is currently maximized (only PLATFORM_DESKTOP)
		inline bool IsFocused() { return raylib_c::IsWindowFocused();}			// Check if window is currently focused (only PLATFORM_DESKTOP)
		inline bool IsResized() { return raylib_c::IsWindowResized();}			// Check if window has been resized last frame
		inline bool IsState(uint32_t flags) { return raylib_c::IsWindowState(flags);}	// Check if one specific window flag is enabled
		inline void SetState(uint32_t flags) { raylib_c::SetWindowState(flags);}		// Set window configuration state using flags
		inline void ClearState(uint32_t flags) { raylib_c::ClearWindowState(flags);}	// Clear window configuration state flags
		inline void ToggleFullscreen() { raylib_c::ToggleFullscreen();}					// Toggle window state: fullscreen/windowed (only PLATFORM_DESKTOP)
		inline void Maximize() { raylib_c::MaximizeWindow();}							// Set window state: maximized, if resizable (only PLATFORM_DESKTOP)
		inline void Minimize() { raylib_c::MinimizeWindow();}							// Set window state: minimized, if resizable (only PLATFORM_DESKTOP)
		inline void Restore()  { raylib_c::RestoreWindow();	}	    					// Set window state: not minimized/maximized (only PLATFORM_DESKTOP)
		inline void SetIcon(const raylib_c::Image &image) { raylib_c::SetWindowIcon(image); }			// Set icon for window (only PLATFORM_DESKTOP)
		inline void SetTitle(const std::string &title) { raylib_c::SetWindowTitle(title.c_str());}	// Set title for window (only PLATFORM_DESKTOP)
		inline void SetPosition(uint32_t x, uint32_t y) { raylib_c::SetWindowPosition(x, y);}	// Set window position on screen (only PLATFORM_DESKTOP)
		inline void SetPosition(Vector2f pos) { raylib_c::SetWindowPosition(pos.x, pos.y);}	// Set window position on screen (only PLATFORM_DESKTOP)
		inline void SetMonitor(uint32_t monitor) { raylib_c::SetWindowMonitor(monitor); }   // Set monitor for the current window (fullscreen mode)
		inline void SetMinSize(uint32_t width, uint32_t height) { raylib_c::SetWindowMinSize(width, height); } // Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)
		inline void SetSize(uint32_t width, uint32_t height) { raylib_c::SetWindowSize(width, height); }	// Set window dimensions
		inline void *GetHandle() { return raylib_c::GetWindowHandle(); };		// Get native window handle
		inline Vector2f GetPosition() { return raylib_c::GetWindowPosition(); }	// Get window position XY on monitor
		inline int GetWidth() { return raylib_c::GetScreenWidth(); }
		inline int GetHeight() { return raylib_c::GetScreenHeight(); }
		inline Vector2f GetScaleDPI() { return raylib_c::GetWindowScaleDPI(); }	// Get window scale DPI factor

		[[nodiscard]] static float GetFrameTime() { return raylib_c::GetFrameTime(); }
		[[nodiscard]] static uint32_t GetScreenWidth() { return raylib_c::GetScreenWidth(); }
		[[nodiscard]] static uint32_t GetScreenHeight() { return raylib_c::GetScreenHeight(); }

		static void SetTargetFPS(uint32_t fps) { raylib_c::SetTargetFPS(fps); }

		static void ClearBackground(const Color &color) { raylib_c::ClearBackground(color); } // Set background color (framebuffer clear color)

	};

	// Drawing-related functions
	namespace render{

		[[nodiscard]] static float GetFrameTime() { return raylib_c::GetFrameTime(); }
		[[nodiscard]] static uint32_t GetScreenWidth() { return raylib_c::GetScreenWidth(); }
		[[nodiscard]] static uint32_t GetScreenHeight() { return raylib_c::GetScreenHeight(); }

		static void SetTargetFPS(uint32_t fps) { raylib_c::SetTargetFPS(fps); }

		static void ClearBackground(const Color &color) { raylib_c::ClearBackground(color); } // Set background color (framebuffer clear color)

		struct DrawingScope{
			bool run;
			DrawingScope() : run{true} { raylib_c::BeginDrawing(); } // Setup canvas (framebuffer) to start drawing
			~DrawingScope() { raylib_c::EndDrawing(); }               // End canvas drawing and swap buffers (double buffering)
		};
		
		struct Mode2DScope{
			bool run;
			Mode2DScope(const Camera2D &camera) : run{true} { raylib_c::BeginMode2D(camera); } 	// Setup canvas (framebuffer) to start drawing
			~Mode2DScope() { raylib_c::EndMode2D(); }               							// End canvas drawing and swap buffers (double buffering)
		};

		struct Mode3DScope{
			bool run;
			Mode3DScope(const Camera3D &camera) : run(true) { raylib_c::BeginMode3D(camera); } 	// Setup canvas (framebuffer) to start drawing
			~Mode3DScope() { raylib_c::EndMode3D(); }               							// End canvas drawing and swap buffers (double buffering)
		};

		struct ModeTextureScope{
			bool run;
			ModeTextureScope(RenderTexture &target) : run{true} { raylib_c::BeginTextureMode(target); } // Setup texture to start drawing
			~ModeTextureScope() { raylib_c::EndTextureMode(); }               							// End texture drawing
		};

	}
	#define Drawing for(raylib::render::DrawingScope scope; scope.run; scope.run=false)
	#define Mode2D(camera2D) for(raylib::render::Mode2DScope scope(camera2D); scope.run; scope.run=false)
	#define Mode3D(camera3D) for(raylib::render::Mode3DScope scope(camera3D); scope.run; scope.run=false)
	#define TextureMode(target) for(raylib::render::ModeTextureScope scope(target); scope.run; scope.run=false)

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



	namespace draw {

		// Shapes
		static void Pixel(const Vector2f &position, const Color &color) { raylib_c::DrawPixelV((Vector2f)position,color); }									// Draw a pixel (Vector version)
		
		static void Rectangle(const Vector2f &position, const Vector2f &size, const Color &colorFill, const Color &colorLine={0,0,0,0} ) { // Draw a color-filled rectangle
			raylib_c::DrawRectangleV(position,size,colorFill);
			if(colorLine.a) raylib_c::DrawRectangleLines(position.x,position.y,size.x,size.y,colorLine);
		}	
		
		static void RectangleLines(const Vector2f &position, const Vector2f &size, const Color &color) { raylib_c::DrawRectangleLines(position.x,position.y,size.x,size.y,color); }	// Draw a color-filled rectangle		
		
		// Models
		static void Cube(const Vector3f &position, const Vector3f &size, const Color &color) { raylib_c::DrawCubeV(position, size, color); }                                       // Draw cube (Vector version)
		static void CubeWires(const Vector3f &position, const Vector3f &size, const Color &color) { raylib_c::DrawCubeWiresV(position, size, color); }                                  // Draw cube wires (Vector version)
		static void Grid(uint32_t slices, float spacing) { raylib_c::DrawGrid(slices,spacing); }
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

