#include "Pyramid.h"
#include <iostream>

Pyramid::Pyramid(Mesh* mesh, float x, float y, float z) : SceneObject(mesh, nullptr)
{
	m_mesh = mesh; // store pointer

	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}

Pyramid::~Pyramid()
{

}

void Pyramid::Draw()
{
 

	if (m_mesh->Colors != nullptr && m_mesh->Vertices != nullptr && m_mesh->Indices != nullptr)
	{
		glPushMatrix();
		glTranslatef(m_position.x, m_position.y, m_position.z);
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

void Pyramid::Update()
{
	
}
