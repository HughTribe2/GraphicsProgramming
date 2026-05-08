#pragma once
#include <Windows.h> //Required for OpenGL on windows
#include <gl/GL.h> // OpenGL
#include <gl/GLU.h> //Open Utilities
#include "GL/freeglut.h" //freeglut library
#include "Structures.h"

class Cube
{
private:

	static Vertex indexedVertices[];
	static Color indexedColors[];
	static GLushort indices[];
	float m_rotation;
	Vector3 m_position;

public:

	Cube();
	~Cube();

	void Draw();
	void Update();
};

