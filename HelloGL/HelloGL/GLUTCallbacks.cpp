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

		
		
		helloGL->Update();
		glutTimerFunc(PreferredRefresh, Timer, PreferredRefresh);
		
	}
}