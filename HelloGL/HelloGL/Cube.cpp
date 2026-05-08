#include "Cube.h"

Vertex Cube::indexedVertices[] =
{
	1, 1, 1,  -1, 1, 1,  // v0,v1, 

	-1,-1, 1,   1,-1, 1,   // v2,v3 

	1,-1,-1,   1, 1,-1,    // v4,v5 

	-1, 1,-1,   -1,-1,-1  // v6,v7 
};

Color Cube::indexedColors[] =
{
	1, 1, 1,   1, 1, 0,   // v0,v1, 

	1, 0, 0,   1, 0, 1,   // v2,v3 

	0, 0, 1,   0, 1, 1,   // v4,v5 

	0, 1, 0,   0, 0, 0	  //v6,v7 
};

GLushort Cube::indices[] =
{
	0, 1, 2,  2, 3, 0,      // front 

	0, 3, 4,  4, 5, 0,      // right 

	0, 5, 6,  6, 1, 0,      // top 

	1, 6, 7,  7, 2, 1,      // left 

	7, 4, 3,  3, 2, 7,      // bottom 

	4, 7, 6,  6, 5, 4		// back
};


Cube::Cube()
{
	m_position.x = 0.0f;
	m_position.x = 0.0f;
	m_position.z = 5.0f;
}

Cube::~Cube()
{

}

void Cube::Draw()
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

void Cube::Update()
{
	m_rotation += 0.1f;

	if (m_rotation >= 360.0f)
	{
		m_rotation = 0.0f;
	}
}