#pragma once
#include "Core.h"

namespace SimpleRectangleShapeRotator {

	class ErrorsGenerator
	{
	public:
		enum errorsToThrow { out_of_range, length_error, overflow_error };

		ErrorsGenerator();
		~ErrorsGenerator();

		void ThrowRandomError(double length);
	};
}

