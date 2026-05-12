#pragma once
#include <Windows.h> //Required for OpenGL on windows
#include <gl/GL.h> // OpenGL
#include <gl/GLU.h> //Open Utilities
#include "GL/freeglut.h" //freeglut library
#include "Structures.h"
#include "SceneObject.h"


class Cube : public SceneObject
{
private:

	Mesh* m_mesh;	
	float m_rotation;
	Vector3 m_position;	
	Material* m_material;	

	void InitMaterial();

public:

	Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z) ;
	~Cube();

	void Draw();
	void Update();

};

