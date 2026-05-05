#pragma once
#include <Windows.h> //Required for OpenGL on windows
#include <gl/GL.h> // OpenGL
#include <gl/GLU.h> //Open Utilities
#include "GL/freeglut.h" //freeglut library
#define Refreshrate 16

struct Vector3
{
	float x, y, z;
};

struct Camera
{
	Vector3	eye, center, up;
};

struct Color
{
	GLfloat r, g, b;
};

struct Vertex
{
	GLfloat x, y, z;
};

class HelloGL
{
public:	

	//constructor definition
	HelloGL(int argc, char* argv[]);

	//destructor
	~HelloGL(void);

	void Display();

	void DrawCube();

	void DrawCube2();

	void DrawTeapot();

	void DrawCubeArray();
		
	void Update();

	void Keyboard(unsigned char key, int x, int y);

private:
	float rotation;
	Camera* camera;
	static Color colors[];
	static Vertex vertices[];

	
};


