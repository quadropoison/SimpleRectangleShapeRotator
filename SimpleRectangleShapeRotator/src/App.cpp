#pragma once
#include "App.h"
#include "RectangleShape.h"
#include "ErrorsGenerator.h"
#include "AppParameters.h"

namespace SimpleRectangleShapeRotator {
	
	GLFWwindow* window;
	App app;
	RectangleShape rectangle;
	ErrorsGenerator errorsGenerator;

	App::App()
	{
	}

	App::~App()
	{
	}

	void App::Run(std::chrono::milliseconds executionTimeLimit)
	{
		errorsGenerator.ThrowRandomError(0.2); // 20 % to throw exception	

		App::isAppRunning = true;
		std::chrono::time_point<std::chrono::system_clock> end;
		end = std::chrono::system_clock::now() + executionTimeLimit;
		float current_ticks, delta_ticks;
		float totalCountRotationDegrees = 0;
		float fps = 0;
		
		fprintf(stdout, "angle speed: %f\n", rectangle.GetAngleSpeed());

		while (!glfwWindowShouldClose(window))
		{
			current_ticks = clock();

			glClear(GL_COLOR_BUFFER_BIT);

			rectangle.MakeRotatingRectangle();

			AppParameters::SetFakeRenderTime();			
			std::this_thread::sleep_for(std::chrono::milliseconds((int)(AppParameters::GetFakeRenderTime())));

			glfwSwapBuffers(window);

			glfwPollEvents();		

			//360 / (fps * rectangle.GetAngleSpeed())

			totalCountRotationDegrees = totalCountRotationDegrees + rectangle.GetAngleSpeed() * (float)glfwGetTime();
			fprintf(stdout, "fullRotations: %f\n", totalCountRotationDegrees / 360);

			RectangleShape::fullRotationsPerCycle = totalCountRotationDegrees / 360;

			if (std::chrono::system_clock::now() >= end)
			{
				break;
			}

			if (App::isAppRunning == false)
			{
				break;
			}

			delta_ticks = clock() - current_ticks;

			fprintf(stdout, "Delta time: %.2f\n", delta_ticks);

			if (delta_ticks > 0)
				fps = CLOCKS_PER_SEC / delta_ticks;

			AppParameters::SetFps(fps);
			AppParameters::SetDeltaTime(delta_ticks);
			fprintf(stdout, "FPS: %.2f\n", fps);
		}

		glfwTerminate();		
	}

	SimpleRectangleShapeRotator::App* SimpleRectangleShapeRotator::CreateApplication()
	{		 
		app.InitializeGlfw();		
		window = app.CreateWindow();
		glfwMakeContextCurrent(window);
		app.InitializeGlew();			

		return 0;
	}

	GLFWwindow * App::CreateWindow()
	{
		GLFWwindow* window = glfwCreateWindow(640, 480, "Hello CDPR", NULL, NULL);

		if (!window)
		{
			glfwTerminate();
			return nullptr;
		}

		return window;
	}

	int App::InitializeGlfw()
	{
		if (!glfwInit())
			return -1;
		else
			return 0;
	}

	void App::InitializeGlew()
	{
		GLenum err = glewInit();
		if (GLEW_OK != err)
		{
			fprintf(stderr, "Error: %s\r\n\n", glewGetErrorString(err));
		}
		fprintf(stdout, "Status: Using GLEW %s\r\n\n", glewGetString(GLEW_VERSION));
	}
}
