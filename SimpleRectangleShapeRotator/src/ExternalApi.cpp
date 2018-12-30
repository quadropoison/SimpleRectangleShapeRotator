#include "ExternalApi.h"
#include "App.h"

int SimpleRectangleShapeRotator::RectangleShape::fullRotationsPerCycle;
int exposeFullRotationsPerCycle()
{
	return SimpleRectangleShapeRotator::RectangleShape::fullRotationsPerCycle;
}

bool SimpleRectangleShapeRotator::App::isAppRunning;
void setAppRunningStatusToFalse()
{
	if (SimpleRectangleShapeRotator::App::isAppRunning == true)
		SimpleRectangleShapeRotator::App::isAppRunning = false;
}

double SimpleRectangleShapeRotator::AppParameters::fakeRenderTime;
bool SimpleRectangleShapeRotator::AppParameters::isFakeRenderTimeCounterInitialized;
double exposeFakeRenderTime()
{
	return SimpleRectangleShapeRotator::AppParameters::GetFakeRenderTime();
}

float SimpleRectangleShapeRotator::AppParameters::fps;
float exposeFps()
{
	return SimpleRectangleShapeRotator::AppParameters::GetFps();
}

float SimpleRectangleShapeRotator::AppParameters::deltaTime;
float exposeDeltaTime()
{
	return SimpleRectangleShapeRotator::AppParameters::GetDeltaTime();
}
