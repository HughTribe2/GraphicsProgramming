#include "HelloGL.h"
#include "GLUTCallbacks.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT); //this clears the scene
	DrawPolygon();
	glFlush();
}

void HelloGL::DrawPolygon()
{
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex2f(-0.75, 0.5);
		glColor4f(0.0f, 1.0f, 0.0f, 0.67f);
		glVertex2f(0.75, 0.5);
		glColor4f(0.0f, 0.0f, 1.0f, 0.76f);
		glVertex2f(0.75, -0.5);
		glColor4f(0.9f, 0.4f, 0.1f, 0.67f);
		glVertex2f(-0.75, -0.5);
		glEnd();
	}
	glPopMatrix();
}

HelloGL::~HelloGL(void)
{
	
}

void HelloGL::Update()
{
	glutPostRedisplay();

	rotation += 0.5f;

	if (rotation >= 360.0f)
	{
		rotation = 0.0f;
	}
}