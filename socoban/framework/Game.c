/*****************************************************************
* �ҽ����ϸ�       :   Game.c
* �� �� ��         :   �Ӻ���
* �� �� ��         :   2022.03.30
* ��    ��         :   SOKOBAN ���� �����
*****************************************************************/
#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"
#include "input.h"
/*************************************************************
* ���� : ���Ӱ� ���õ� �����͸� �ʱ�ȭ �ϴ� �Լ�.
**************************************************************/
bool Initialize()
{
	if (false == InitializeRenderer())	//�������� �ʱ�ȭ�ϴ� �Լ�
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
	//Game Loop = �÷��̾�κ����� �Է��� �ϵ����� �и���Ų��.
	//���ۿ� �������α׷��� �����̶�� �˻� ������
	
	//Game Loop�� ��ü�� Frame
	while (true)
	{
		//�Է�ó��
		processInput();
		//������Ʈ
		update();
		//������
		render();
	}
	return 0;

}