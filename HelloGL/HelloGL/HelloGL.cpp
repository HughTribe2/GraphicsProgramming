#include "HelloGL.h"
#include "GLUTCallbacks.h"
#include <iostream>


HelloGL::HelloGL(int argc, char* argv[])
{	
	rotation = 0.0f;

	camera = new Camera();

	cube = new Cube(0.0f, 0.0f, 0.0f);
		
	camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -5.0f;
	//camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGL Program");
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(Refreshrate, GLUTCallbacks::Timer, Refreshrate);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//set the viewport to be the entire window
	glViewport(0, 0, 800, 800	);

	//set the correct perspective	
	gluPerspective(45, 1, 0.5, 1000);

	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_CULL_FACE);	
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);	
	glutMainLoop();
}

HelloGL::~HelloGL(void)
{
	delete camera;
	camera = nullptr;
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //this clears the scene
	glTranslatef(0.0f, 0.0f, -5.0f);

	cube->Draw();
	
	glFlush();
	glutSwapBuffers();
}
	

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'e')
	{
		rotation += 2.0f;
	}

	if (key == 'q')
	{
		rotation -= 2.0f;
	}

	if (key == 'w')
	{
		camera->eye.z += -0.1f;
	}

	if (key == 's')
	{
		camera->eye.z += 0.1f;
	}

	if (key == 'a')
	{
		camera->center.x += -0.1f;
	}

	if (key == 'd')
	{
		camera->center.x += 0.1f;
	}

	if (key == ' ')
	{
		camera->eye.y += 0.1f;
	}

	if (key == '\b')
	{
		camera->eye.y += -0.1f;
	}
}

void HelloGL::Update()
{
	glLoadIdentity();

	cube->Update();

	gluLookAt
	(
		camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y,
		camera->center.z, camera->up.x, camera->up.y, camera->up.z
	);

	glutPostRedisplay();
}

