#pragma once
#include <Windows.h> //Required for OpenGL on windows
#include <gl/GL.h> // OpenGL
#include <gl/GLU.h> //Open Utilities
#include "GL/freeglut.h" //freeglut library
#include "Structures.h"
#include "Cube.h"
#define Refreshrate 16


class HelloGL
{
public:	

	//constructor definition
	HelloGL(int argc, char* argv[]);

	//destructor
	~HelloGL(void);

	void Display();
	
	void Update();

	void Keyboard(unsigned char key, int x, int y);

private:
	float rotation;
	Camera* camera;
	Cube* cube;	
};

