#pragma once
#include "Core.h"

namespace SimpleRectangleShapeRotator {

	class RectangleShape
	{
	private:
		float angleSpeed;
		
		bool isRectangleExists;
		bool isRectangleRotating;

		float CreateRandomSpeed();
	public:
		RectangleShape();
		~RectangleShape();

		static int fullRotationsPerCycle;
		float GetAngleSpeed();
		void SetRectangleState(bool state);

		void MakeRectangle();
		void MakeRotatingRectangle();		
	};	
}

