#pragma once
#include <Windows.h> //Required for OpenGL on windows
#include <gl/GL.h> // OpenGL
#include <gl/GLU.h> //Open Utilities
#include "GL/freeglut.h" //freeglut library
#include "Structures.h"
#include "Cube.h"
#include "Pyramid.h"
#include "MeshLoader.h"
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

	void InitObjects();

	void InitGL(int argc, char* argv[]);

	void InitLighting();

private:

	float rotation;
	Camera* camera;
	SceneObject* objects[100];
	Vector4* m_lightPosition;
	Lighting* m_lightData;
};

