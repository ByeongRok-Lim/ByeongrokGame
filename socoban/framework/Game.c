/*****************************************************************
* 소스파일명       :   Game.c
* 작 성 자         :   임병록
* 작 성 일         :   2022.03.30
* 설    명         :   SOKOBAN 게임 만들기
*****************************************************************/
#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"
#include "input.h"
/*************************************************************
* 설명 : 게임과 관련된 데이터를 초기화 하는 함수.
**************************************************************/
bool Initialize()
{
	if (false == InitializeRenderer())	//렌더러를 초기화하는 함수
	{
		return false;
	}
	return true;
}

void processInput()
{
	UpdateInput();
}

void update()
{

	if (GetButton(KEYCODE_W))
	{
		SetKeyMessage(KEYCODE_W);
	}	
	else if (GetButton(KEYCODE_D))
	{
		SetKeyMessage(KEYCODE_D);
	}	
	else if (GetButton(KEYCODE_S))
	{
		SetKeyMessage(KEYCODE_S);
	}	
	else if (GetButton(KEYCODE_A))
	{
		SetKeyMessage(KEYCODE_A);
	}	
}

void render()
{
	RenderMap();
}

int32_t Run()
{
	//Game Loop = 플레이어로부터의 입력을 하드웨어와 분리시킨다.
	//구글에 게임프로그래밍 패턴이라고 검색 ㄱㄱㄱ
	
	//Game Loop의 전체를 Frame
	while (true)
	{
		//입력처리
		processInput();
		//업데이트
		update();
		//렌더링
		render();
	}
	return 0;

}