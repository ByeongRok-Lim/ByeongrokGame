#include "stdafx.h"
#include "Renderer.h"

#define MAP_SIZE 24

static char s_map[MAP_SIZE][MAP_SIZE] = {
	"*************",
	"* sokoban   *",
	"*************"
};
static HANDLE s_consoleHandle;

//SetConsolePosition 걍 남긴거
//GetStdHandle 걍 남긴거
bool InitializeRenderer()
{
	s_consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	if (INVALID_HANDLE_VALUE == s_consoleHandle)
	{
		return false;
	}

	/*CONSOLE_CURSOR_INFO	info;
	info.dwSize = 100;
	info.bVisible = false;

	if (false == SetConsoleCursorInfo(s_consoleHandle, &info))
	{
		return false;
	}*/

	return true;
}

//테어링이 나타나는 현상은 우리가보는 화면에 다음프레임이 출력되어 찢어지는 현상이 나타나는것.
//double buffering을 이용하여 다음 프레임은 back buffer에 두고 현재 버퍼와 스위치하는 것 => 그러면 화면이 끊기는 현상이 줄어든다.
//핵심은 버퍼를 두개 사용한다.
void RenderMap()
{
	const static COORD initialPos = { 0, 0 };
	const static CONSOLE_CURSOR_INFO info = {100, false};
	SetConsoleCursorPosition(s_consoleHandle, initialPos);
	SetConsoleCursorInfo(s_consoleHandle, &info);

	//memcpy(s_map, s_backBuffer, sizeof(s_map));

	for (int i = 0; i < MAP_SIZE; i++)
	{
		puts(s_map[i]);
	}
}