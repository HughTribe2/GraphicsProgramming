#include "Cube.h"
#include <iostream>
#include <fstream>

void Cube::InitMaterial()
{
	m_material = new Material();
	m_material->Ambient.x = 0.8f; m_material->Ambient.y = 0.05f; 
	m_material->Ambient.z = 0.05f; m_material->Ambient.w = 1.0f;
	m_material->Diffuse.x = 0.8f; m_material->Diffuse.y = 0.05f;
	m_material->Diffuse.z = 0.05f; m_material->Diffuse.w = 1.0f;
	m_material->Specular.x = 1.0f; m_material->Specular.y = 1.0f;
	m_material->Specular.z = 1.0f; m_material->Specular.w = 1.0f;
	m_material->Shininess = 100.0f;
}
Cube::Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture)
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

	if (m_mesh->Normals == nullptr || m_mesh->Vertices == nullptr || m_mesh->Indices == nullptr)
	{
		std::cout << "something is nullptr\n";
	}
	else
	{
		glEnable(GL_TEXTURE_2D); // seem to have to enable this before i bind texture tut said put it somewhere else haha
		glBindTexture(GL_TEXTURE_2D, m_Texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, 0, m_mesh->TexCoords);
		InitMaterial();
		glMaterialfv(GL_FRONT, GL_AMBIENT, &(m_material->Ambient.x));
		glMaterialfv(GL_FRONT, GL_AMBIENT, &(m_material->Diffuse.x));
		glMaterialfv(GL_FRONT, GL_AMBIENT, &(m_material->Specular.x));
		glMaterialf(GL_FRONT, GL_SHININESS, m_material->Shininess);
		glPushMatrix();
		glTranslatef(m_position.x, m_position.y, m_position.z);
		glRotatef(m_rotation, 1.0f, 0.0f, 0.0f);
		glBegin(GL_TRIANGLES);
		for (int i = 0; i < m_mesh->IndexCount; i++)  // use IndexCount so ive not gotta keep up with all these txt files 
		{
			glNormal3f
			(
				m_mesh->Normals[m_mesh->Indices[i]].x,
				m_mesh->Normals[m_mesh->Indices[i]].y,
				m_mesh->Normals[m_mesh->Indices[i]].z
			);
			glTexCoord2f
			(
				m_mesh->TexCoords[m_mesh->Indices[i]].u,
				m_mesh->TexCoords[m_mesh->Indices[i]].v
			);
			glVertex3f
			(
				m_mesh->Vertices[m_mesh->Indices[i]].x,
				m_mesh->Vertices[m_mesh->Indices[i]].y,
				m_mesh->Vertices[m_mesh->Indices[i]].z
			);
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


