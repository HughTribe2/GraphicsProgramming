#include "Cube.h"
#include <iostream>
#include <fstream>

Cube::Cube(Mesh* mesh, float x, float y, float z)
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
	std::cout << "drawing\n";

	if (m_mesh->Colors == nullptr || m_mesh->Colors == nullptr || m_mesh->Indices == nullptr)
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

bool Cube::Load(char* path)
{
	std::ifstream inFile;
	inFile.open(path);
	if (!inFile.good())
	{
		std::cerr << "Can't open text file" << path << std::endl;
		return false;
	}

	inFile >> numVertices;
	indexedVertices = new Vertex[numVertices];
	for (int i = 0; i < numVertices; i++)
	{
		std::cout << "vertices\n";
		//populate indexedVertices array using inFile
		inFile >> indexedVertices[i].x
			   >> indexedVertices[i].y
			   >> indexedVertices[i].z;
	}

	inFile >> numColors;
	indexedColors = new Color[numColors];
	for (int i = 0; i < numColors; i++)
	{
		std::cout << "colors\n";
		//load color information
		inFile >> indexedColors[i].r
			   >> indexedColors[i].g
			   >> indexedColors[i].b;
	}

	inFile >> numIndices;
	indices = new GLushort[numIndices];
	for (int i = 0; i < numIndices; i++)
	{
		std::cout << "indices\n";
		//load indices information
		inFile >> indices[i];
	}

	inFile.close();

	return true;
}
