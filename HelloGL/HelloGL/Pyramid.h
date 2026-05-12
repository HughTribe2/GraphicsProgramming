#pragma once
#include "SceneObject.h"

class Pyramid : public SceneObject
{
private:

	Mesh* m_mesh;
	Vector3 m_position;

public:

	Pyramid(Mesh* mesh, float x, float y, float z);
	~Pyramid();

	void Draw();
	void Update();
};

