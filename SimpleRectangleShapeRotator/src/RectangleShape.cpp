#pragma once
#include "RectangleShape.h"
#include "AppParameters.h"

namespace SimpleRectangleShapeRotator {

	RectangleShape::RectangleShape()
	{
		this->angleSpeed = CreateRandomSpeed();
		this->isRectangleRotating = false;
	}


	float RectangleShape::CreateRandomSpeed()
	{
		float angleSpeed = (float)GetRandomNumberWithMinimumMeanAndMaximum(0.1, 0.5, 1.1);
		//fprintf(stdout, "speed: %f\n", angleSpeed);
		return angleSpeed;
	}

	void RectangleShape::MakeRectangle()
	{
		if (isRectangleRotating == true)
		{
			glRotatef((float)glfwGetTime() * this->angleSpeed, 0.f, 0.f, 1.f);
		}

		if (isRectangleExists == false)
		{
			glBegin(GL_QUADS);
			glVertex2f(0.5f, 0.3f);
			glVertex2f(-0.5f, 0.3f);
			glVertex2f(-0.5f, -0.3f);
			glVertex2f(0.5f, -0.3f);
			glEnd();
		}
	}

	void RectangleShape::MakeRotatingRectangle()
	{
		this->isRectangleRotating = true;
		RectangleShape::MakeRectangle();	
	}

	float RectangleShape::GetAngleSpeed()
	{
		return this->angleSpeed;
	}

	void RectangleShape::SetRectangleState(bool state)
	{
		isRectangleExists = false;
	}

	RectangleShape::~RectangleShape()
	{
	}
}
