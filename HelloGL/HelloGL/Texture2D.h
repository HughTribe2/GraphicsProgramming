#pragma once
#include <Windows.h> //Required for OpenGL on windows
#include <gl/GL.h> // OpenGL
#include "GL/freeglut.h" //freeglut library
#include <gl/GLU.h> //Open Utilities

class Texture2D
{
private:

	GLuint m_ID; // Texture ID
	int m_width, m_height;

public:

	Texture2D();

	~Texture2D();

	bool Load(char* path, int width, int height);

	GLuint GetID() const { return m_ID; }

	int GetWidth() const { return m_width; }

	int GetHeight() const { return m_height; }


};

