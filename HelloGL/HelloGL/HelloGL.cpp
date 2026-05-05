#include "HelloGL.h"
#include "GLUTCallbacks.h"

HelloGL::HelloGL(int argc, char* argv[])
{	
	rotation = 0.0f;

	camera = new Camera();

	camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -5.0f;
	/*camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;*/
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
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
	glutMainLoop();
}

HelloGL::~HelloGL(void)
{
	delete camera;
	camera = nullptr;
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT); //this clears the scene
	glTranslatef(0.0f, 0.0f, -5.0f);
	//DrawTeapot();
	//DrawCube();
	DrawCube2();

	glFlush();
	glutSwapBuffers();
}

void HelloGL::DrawCube()
{
	glPushMatrix();
	glTranslatef(0.7f, -0.8f, -0.3f);
	glRotatef(rotation, 0.2f, 0.8f, -1.0f);
	/*glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex2f(0.3, 0.5);
		glColor4f(0.0f, 1.0f, 0.0f, 0.67f);
		glVertex2f(0.4, 0.5);
		glColor4f(0.0f, 0.0f, 1.0f, 0.76f);
		glVertex2f(0.4, 0.4);
		glColor4f(0.9f, 0.4f, 0.1f, 0.67f);
		glVertex2f(0.3, 0.4);
		glEnd();
	}*/
	glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
	glutWireCube(0.5);
	glPopMatrix();
}

void HelloGL::DrawTeapot()
{
	glPushMatrix();
	glRotatef(rotation, 1.0f, -0.9f, 0.0f);
	/*glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.2f, 0.0f, 0.5f);
		glVertex2f(-0.7, -0.5);
		glColor4f(0.1f, 0.2f, 0.45f, 0.67f);
		glVertex2f(0, -0.5);
		glColor4f(0.3f, 0.0f, 1.0f, 0.76f);
		glVertex2f(-0.35, 0);
		glEnd();
	}*/
	glColor4f(0.3f, 0.0f, 1.0f, 0.76f);
	glutWireTeapot(0.7);
	glPopMatrix();
}

void HelloGL::DrawCube2()
{
	glPushMatrix();
	glRotatef(rotation, 0.2f, 0.8f, -1.0f);
	glBegin(GL_TRIANGLES);
	
		//face v0-v1-v2
		glColor3f(1, 1, 1);
		glVertex3f(1, 1, 1);
		glColor3f(1, 1, 0);
		glVertex3f(-1, 1, 1);
		glColor3f(1, 0, 0);
		glVertex3f(-1, -1, 1);
		//face v2-v3-v0
		glColor3f(1, 0, 0);
		glVertex3f(-1, -1, 1);
		glColor3f(1, 0, 1);
		glVertex3f(1, -1, 1);
		glColor3f(1, 1, 1);
		glVertex3f(1, 1, 1);
		//face v0-v3-v4
		glColor3f(1, 1, 1);
		glVertex3f(1, 1, 1);
		glColor3f(1, 0, 1);
		glVertex3f(1, -1, 1);
		glColor3f(0, 0, 1);
		glVertex3f(1, -1, -1);
		//face v4-v5-v0
		glColor3f(0, 0, 1);
		glVertex3f(1, -1, -1);
		glColor3f(0, 1, 1);
		glVertex3f(1, 1, -1);
		glColor3f(1, 1, 1);
		glVertex3f(1, 1, 1);
		//face v0-v5-v6
		glColor3f(1, 1, 1);
		glVertex3f(1, 1, 1);
		glColor3f(0, 1, 1);
		glVertex3f(1, 1, -1);
		glColor3f(0, 1, 0);
		glVertex3f(-1, 1, -1);
		//face v6-v1-v0
		glColor3f(0, 1, 0);
		glVertex3f(-1, 1, -1);
		glColor3f(1, 1, 0);
		glVertex3f(-1, 1, 1);
		glColor3f(1, 1, 1);
		glVertex3f(1, 1, 1);
		//face v1-v6-v7
		glColor3f(1, 1, 0);
		glVertex3f(-1, 1, 1);
		glColor3f(0, 1, 0);
		glVertex3f(-1, 1, -1);
		glColor3f(0, 0, 0);
		glVertex3f(-1, -1, -1);
		//face v7-v2-v1
		glColor3f(0, 0, 0);
		glVertex3f(-1, -1, -1);
		glColor3f(1, 0, 0);
		glVertex3f(-1, -1, 1);
		glColor3f(1, 1, 0);
		glVertex3f(-1, 1, 1);	
		//face v7-v4-v3
		glColor3f(0, 0, 0);
		glVertex3f(-1, -1, -1);
		glColor3f(0, 0, 1);
		glVertex3f(1, -1, -1);
		glColor3f(1, 0, 1);
		glVertex3f(1, -1, 1);
		//face v3-v2-v7
		glColor3f(1, 0, 1);
		glVertex3f(1, -1, 1);
		glColor3f(1, 0, 0);
		glVertex3f(-1, -1, 1);
		glColor3f(0, 0, 0);
		glVertex3f(-1, -1, -1);
		//face v4-v7-v6
		glColor3f(0, 0, 1);
		glVertex3f(1, -1, -1);
		glColor3f(0, 0, 0);
		glVertex3f(-1, -1, -1);
		glColor3f(0, 1, 0);
		glVertex3f(-1, 1, -1);
		//face v6-v5-v4
		glColor3f(0, 1, 0);
		glVertex3f(-1, 1, -1);
		glColor3f(0, 1, 1);
		glVertex3f(1, 1, -1);
		glColor3f(0, 0, 1);
		glVertex3f(1, -1, -1);

		glEnd();
	
	glPopMatrix();
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

	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y,
		camera->center.z, camera->up.x, camera->up.y, camera->up.z);

	glutPostRedisplay();

	if (rotation >= 360.0f)
	{
		rotation = 0.0f;
	}
}

