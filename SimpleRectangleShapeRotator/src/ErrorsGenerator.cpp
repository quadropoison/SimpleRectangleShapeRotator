#include "ErrorsGenerator.h"

namespace SimpleRectangleShapeRotator {

	ErrorsGenerator::ErrorsGenerator()
	{
	}

	ErrorsGenerator::~ErrorsGenerator()
	{
	}

	void ErrorsGenerator::ThrowRandomError(double chanceToThrowError)
	{
		srand(time(NULL)); 
		int randIndex = rand() % 3; 
		double val = (double)rand() / RAND_MAX;
		if (val < chanceToThrowError)  
			switch (errorsToThrow(randIndex))
			{
				case out_of_range:
					throw std::out_of_range("error - out_of_range");
					break;
				case length_error:
					throw std::length_error("error - length_error");
					break;
				case overflow_error: 
					throw std::overflow_error("error - overflow_error");
					break;
				default:						
					break;
			}
	}
}
