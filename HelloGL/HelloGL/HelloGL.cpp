#include "HelloGL.h"
#include "GLUTCallbacks.h"
#include <iostream>


HelloGL::HelloGL(int argc, char* argv[])
{
	InitGL(argc, argv);
	InitObjects();
	glutMainLoop();
}	

HelloGL::~HelloGL(void)
{
	delete camera;
	camera = nullptr;

	delete cube;
	cube = nullptr;
}

	
void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //this clears the scene	
	cube->Draw();
	glFlush();
	glutSwapBuffers();
}
	

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	// calculate forward vector (direction camera is looking)
	float forwardX = camera->center.x - camera->eye.x;
	float forwardZ = camera->center.z - camera->eye.z;


	// strafe vector is perpendicular to forward (might change strafe name not sure what else to call it tho)
	float strafeX = -forwardZ;
	float strafeZ = forwardX;

	if (key == 'w')  // move forward
	{
		camera->eye.x += forwardX * 0.1f;
		camera->eye.z += forwardZ * 0.1f;
		camera->center.x += forwardX * 0.1f;
		camera->center.z += forwardZ * 0.1f;
	}
	if (key == 's')  // move backward
	{
		camera->eye.x -= forwardX * 0.1f;
		camera->eye.z -= forwardZ * 0.1f;
		camera->center.x -= forwardX * 0.1f;
		camera->center.z -= forwardZ * 0.1f;
	}
	if (key == 'a')  // move left
	{
		camera->eye.x -= strafeX * 0.1f;
		camera->eye.z -= strafeZ * 0.1f;
		camera->center.x -= strafeX * 0.1f;
		camera->center.z -= strafeZ * 0.1f;
	}
	if (key == 'd')  // move right
	{
		camera->eye.x += strafeX * 0.1f;
		camera->eye.z += strafeZ * 0.1f;
		camera->center.x += strafeX * 0.1f;
		camera->center.z += strafeZ * 0.1f;
	}
	if (key == ' ')  // up
	{
		camera->eye.y += 0.1f;
		camera->center.y += 0.1f;  // move center too so you don't tilt
	}
if (key == '\b')  // down
{
	camera->eye.y -= 0.1f;
	camera->center.y -= 0.1f;
}
}

void HelloGL::InitObjects()
{
	camera = new Camera();

	Cube::Load((char*)"cube.txt");

	cube = new Cube();

	camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -5.0f;
	//camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
}

void HelloGL::InitGL(int argc, char* argv[])
{
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
	glViewport(0, 0, 800, 800);

	//set the correct perspective	
	gluPerspective(45, 1, 0.5, 1000);

	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
}

void HelloGL::Update()
{
	glLoadIdentity();
	
	

	gluLookAt
	(
		camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y,
		camera->center.z, camera->up.x, camera->up.y, camera->up.z
	);

	cube->Update();

	glutPostRedisplay();

	

	
}

