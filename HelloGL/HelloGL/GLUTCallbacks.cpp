//includes
#include "GLUTCallbacks.h"
#include "HelloGL.h"

// Namespace implementation
namespace GLUTCallbacks
{
	namespace
	{
			// Initialise to a null pointer bvefore we do anything
			HelloGL* helloGL = nullptr;
	}

	void Init(HelloGL* gl)
	{
		helloGL = gl;
	}

	void Display()
	{

		if (helloGL != nullptr)
		{
			helloGL->Display();
			
		}
	}
	void Timer(int PreferredRefresh)
	{

		
		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		helloGL->Update();
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
		glutTimerFunc(PreferredRefresh - updateTime, GLUTCallbacks::Timer, PreferredRefresh);
		
	}
}