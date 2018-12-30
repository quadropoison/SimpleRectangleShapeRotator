#pragma once
#include "Core.h"

namespace SimpleRectangleShapeRotator {

	class AppParameters
	{
	private:
		static double fakeRenderTime;
		static bool isFakeRenderTimeCounterInitialized;
		static float deltaTime;
		static float fps;
	public:
		AppParameters();
		~AppParameters();

		static double GetFakeRenderTime();
		static float GetDeltaTime();
		static float GetFps();

		static void SetDeltaTime(float time);		
		static void SetFps(float fps);
		static void SetFakeRenderTime();

		static void InitializeFakeRenderTimeCounter();
	};

}
	double GetRandomNumberWithMinimumMeanAndMaximum(double minimum, double mean, double maximum);
