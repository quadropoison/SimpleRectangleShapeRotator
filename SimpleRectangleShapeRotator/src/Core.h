#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <map>
#include <exception>
#include <algorithm>
#include <ctime>

#ifdef SRSR_PLATFORM_WINDOWS
	#ifdef SRSR_BUILD_DLL
		#define	SRSR_API extern "C" __declspec(dllexport)
	#else
		#define	SRSR_API __declspec(dllimport)
	#endif 
#else
	#error Your OS does not supported
#endif