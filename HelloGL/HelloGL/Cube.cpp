#include "Cube.h"
#include <iostream>
#include <fstream>

Vertex* Cube::indexedVertices = nullptr;


Color* Cube::indexedColors = nullptr;


GLushort* Cube::indices = nullptr;

int Cube::numVertices = 0;
int Cube::numColors = 0;
int Cube::numIndices = 0;



Cube::Cube()	
{
	m_position.x = 0.0f;
	m_position.y = 0.0f;
	m_position.z = 5.0f;

	m_rotation = 0.0f;
}

Cube::~Cube()
{

}

void Cube::Draw()
{
	std::cout << "drawing\n";

	if (indexedVertices == nullptr || indexedColors == nullptr || indices == nullptr)
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
			glColor3f(indexedColors[indices[i]].r, indexedColors[indices[i]].g, indexedColors[indices[i]].b);
			glVertex3f(indexedVertices[indices[i]].x, indexedVertices[indices[i]].y, indexedVertices[indices[i]].z);
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
