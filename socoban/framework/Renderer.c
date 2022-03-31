#include "stdafx.h"
#include "Renderer.h"

#define MAP_SIZE 24

//�������� ����
static char s_map[MAP_SIZE][MAP_SIZE] = {
	"*************" ,
	"* sokoban   *" ,
	"*************"
};
static HANDLE s_consoleHandle;

void clear()
{
	memset(s_map, ' ', sizeof(s_map));

	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		s_map[i][MAP_SIZE - 1] = '\0';
	}
}


/*************************************************************
* ���� : ������(Renderer)�� �ʱ�ȭ�ϴ� �Լ�
**************************************************************/
bool InitializeRenderer()
{	//GetStdHandle => ǥ�� ����̽��� ���� �ڵ� �˻�
	s_consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);		//ǥ�� ��� ����̽�
	
	if (INVALID_HANDLE_VALUE == s_consoleHandle)		//�Լ� ���� ��ȯ ���� s_consoleHandle
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



/*************************************************************
* ���� : ���� �׸��� �Լ�
**************************************************************/
void RenderMap()
{
	const static COORD initialPos = { 0, 0 }; //�ܼ� ȭ�� ���ۿ��� ���� ���� ��ǥ�� ����.
	const static CONSOLE_CURSOR_INFO info = {100, false};	//�ܼ�â���� Ŀ�� on/off
	SetConsoleCursorPosition(s_consoleHandle, initialPos);	//������ �ܼ� ȭ�� ���ۿ��� Ŀ�� ��ġ�� ����
	SetConsoleCursorInfo(s_consoleHandle, &info);	// �ܼ� Ŀ���� ���� (�β� or ���⿩��) �� �����ϴ� ����



	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		puts(s_map[i]);		//�ʴ� MAP_SIZE��ŭ ���
		
	}	
	clear();
	
}

void SetMessage(const char* message)
{
	strcpy_s(s_map[0], MAP_SIZE, message);
}

void SetKeyMessage(int32_t keyCode)
{
	sprintf_s(s_map[0], sizeof(s_map[0]), "%cŰ�� ����", keyCode);
}