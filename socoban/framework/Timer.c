#include "Timer.h"
#include "stdafx.h"

static clock_t s_prevTick;
static float s_deltaTime;


void InitializeTimer()
{
	s_prevTick = clock();
}

void UpdateTimer()
{
	clock_t currentTick = clock();

	s_deltaTime = (currentTick - s_prevTick) / (float)CLOCKS_PER_SEC;

	s_prevTick = currentTick;
}

float GetDeltaTime()	//프레임 사이의 간격
{
	return s_deltaTime;
}

