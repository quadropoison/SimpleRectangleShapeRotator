#pragma once
#include "Core.h"
#include "App.h"
#include "AppParameters.h"
#include "RectangleShape.h"

#ifdef SRSR_PLATFORM_WINDOWS

	const char* err;

	SimpleRectangleShapeRotator::App *app;	

	SRSR_API int
	__cdecl
	main(int executionTimeLimit)
	{		
		printf("\n\tWelcome to SimpleRectangleShapeRotator\r\n\n\tPlease use the Test Manager to run this app\r\n\n");
		if (executionTimeLimit < 1000)
			executionTimeLimit = 1000;
		try
		{
			SimpleRectangleShapeRotator::RectangleShape::fullRotationsPerCycle = 0;
			app = SimpleRectangleShapeRotator::CreateApplication();
			app->Run(std::chrono::milliseconds(executionTimeLimit));
		}
		catch (std::exception& ex)
		{
			::err = ex.what();
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			throw;
		}
		delete app;
	}
	
	SRSR_API void __cdecl forceExit()
	{
		exit(0);
	}

	SRSR_API void
		__cdecl
		destroyApp()
	{
		delete app;
		glfwTerminate();
		//exit(0);
		std::_Exit;
	}

	SRSR_API const char*
		__cdecl                
	exposeException()
	{
		return ::err;
	}

#endif // SRSR_PLATFORM_WINDOWS