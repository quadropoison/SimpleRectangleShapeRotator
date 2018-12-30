#pragma once
#include "AppParameters.h"


namespace SimpleRectangleShapeRotator {

	AppParameters::AppParameters()
	{
	}


	AppParameters::~AppParameters()
	{
	}

	double AppParameters::GetFakeRenderTime()
	{
		return AppParameters::fakeRenderTime;
	}

	float AppParameters::GetDeltaTime()
	{
		return AppParameters::deltaTime;
	}

	void AppParameters::SetDeltaTime(float time)
	{
		AppParameters::deltaTime = time;
	}

	float AppParameters::GetFps()
	{
		return AppParameters::fps;
	}

	void AppParameters::SetFps(float fps)
	{
		AppParameters::fps = fps;
	}

	void AppParameters::SetFakeRenderTime()
	{
		int fakefps = (int)GetRandomNumberWithMinimumMeanAndMaximum(10, 33, 100);
		AppParameters::fakeRenderTime = fakefps;
		fprintf(stdout, "Fake render time: %f\n", AppParameters::fakeRenderTime);
	}

	void AppParameters::InitializeFakeRenderTimeCounter()
	{
		if (isFakeRenderTimeCounterInitialized = false)
		{
			AppParameters::fakeRenderTime = 0;
			AppParameters::isFakeRenderTimeCounterInitialized = true;
		}
	}
}

double GetRandomNumberWithMinimumMeanAndMaximum(double minimum, double mean, double maximum)
{
	std::random_device rd;
	static std::mt19937 generator{ rd() };
	double const average_bound_width = ((mean - minimum) + (maximum - mean)) / 2;
	double const standard_deviation = average_bound_width / 3;
	std::normal_distribution<double> distribution(mean, standard_deviation);

	double value;
	do
	{
		value = distribution(generator);
	} 
	while (value < minimum || maximum < value);
	return value;
}

