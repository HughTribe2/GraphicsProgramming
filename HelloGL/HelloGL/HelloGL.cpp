#include "HelloGL.h"
#include "GLUTCallbacks.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	triangleRotation = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(Refreshrate, GLUTCallbacks::Timer, Refreshrate);
	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT); //this clears the scene
	//DrawPolygon();
	DrawTriangle();
	glFlush();
}

void HelloGL::DrawPolygon()
{
	glPushMatrix();
	glRotatef(triangleRotation, 0.0f, 0.0f, -1.0f);
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

void HelloGL::DrawTriangle()
{
	glPushMatrix();
	glRotatef(triangleRotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.2f, 0.0f, 0.5f);
		glVertex2f(-0.7, -0.5);
		glColor4f(0.1f, 0.2f, 0.45f, 0.67f);
		glVertex2f(0, -0.5);
		glColor4f(0.3f, 0.0f, 1.0f, 0.76f);
		glVertex2f(-0.35, 0);
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

	triangleRotation += 0.5f;

	if (triangleRotation >= 360.0f)
	{
		triangleRotation = 0.0f;
	}
}