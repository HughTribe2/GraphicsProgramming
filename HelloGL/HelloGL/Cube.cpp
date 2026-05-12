#include "Cube.h"
#include <iostream>
#include <fstream>

Cube::Cube(Mesh* mesh, float x, float y, float z) : SceneObject(mesh)
{
	m_mesh = mesh; // store pointer

	m_position.x = x;
	m_position.y = y;
	m_position.z = z;

	m_rotation = 0.0f;
}

Cube::~Cube()
{

}

void Cube::Draw()
{

	if (m_mesh->Colors == nullptr || m_mesh->Vertices == nullptr || m_mesh->Indices == nullptr)
	{
	std::cout << "something is nullptr\n";
	}
	else
	{
		glPushMatrix();
		glTranslatef(m_position.x, m_position.y, m_position.z);
		glRotatef(m_rotation, 1.0f, 0.0f, 0.0f);
		glBegin(GL_TRIANGLES);
		for (int i = 0; i < 36; i++)
		{
			glColor3f(m_mesh->Colors[m_mesh->Indices[i]].r, m_mesh->Colors[m_mesh->Indices[i]].g, m_mesh->Colors[m_mesh->Indices[i]].b);
			glVertex3f(m_mesh->Vertices[m_mesh->Indices[i]].x, m_mesh->Vertices[m_mesh->Indices[i]].y, m_mesh->Vertices[m_mesh->Indices[i]].z);
		}
		glEnd();

		glPopMatrix();
	}
}

void Cube::Update()
{
	m_rotation += 0.1f;

	if (m_rotation >= 360.0f)
	{
		m_rotation = 0.0f;
	}
}


