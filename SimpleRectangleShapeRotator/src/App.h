#pragma once
#include "Core.h"
#include "AppParameters.h"

namespace SimpleRectangleShapeRotator {

	class App {

	public:
		App();

		static bool isAppRunning;

		virtual ~App();

		void Run(std::chrono::milliseconds executionTimeLimit);

		int InitializeGlfw();

		GLFWwindow* CreateWindow();

		void InitializeGlew();

	};
	
	App* CreateApplication();
}