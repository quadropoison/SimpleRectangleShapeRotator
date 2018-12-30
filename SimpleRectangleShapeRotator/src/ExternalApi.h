#pragma once
#include "Core.h"
#include "RectangleShape.h"
#include "AppParameters.h"

SRSR_API int __cdecl exposeFullRotationsPerCycle();

SRSR_API float __cdecl exposeFps();

SRSR_API float __cdecl exposeDeltaTime();

SRSR_API double __cdecl exposeFakeRenderTime();

SRSR_API void __cdecl setAppRunningStatusToFalse();
