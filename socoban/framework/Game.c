/*include �� ���*/
#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"
#include "input.h"
#include "Timer.h"
#include "Game/Stage.h";

static EStageLevel gameStage = STAGE_01;
/*************************************************************
* ���� : ���Ӱ� ���õ� �����͸� �ʱ�ȭ �ϴ� �Լ�.
**************************************************************/
bool Initialize()
{
	if (false == InitializeRenderer())	//�������� �ʱ�ȭ�ϴ� �Լ�
	{
		return false;
	}
	InitializeTimer();		//Ÿ�̸� �ʱ�ȭ.

	LoadStage(STAGE_01);	//�������� �ε�
	return true;
}

/****************************************************************
* ���� : ���� ��ü������ �Է�ó���� ���ش�.
*****************************************************************/
void processInput()
{
	UpdateInput();
}

/****************************************************************
* ���� : ���� �߿� ��ȭ�ϴ� ���µ��� ������Ʈ�Ѵ�.
*****************************************************************/
void update()
{
	UpdateStage();
	//0.5�� �������� Ư�� �޽����� �����̱�.
	
	//float xTime = 1.0;
	//float oTime = 2.0;

	//static float delta = 0.0;
	//delta += GetDeltaTime();

	//if (delta >= xTime)
	//{
	//	SetMessage("���� �׷��� �ų�");

	//}

	//if (delta >= xTime + oTime)
	//{
	//	delta = 0.0;
	//}

	
}

/****************************************************************
* ���� : ���� �ֿܼ��� �ؽ�Ʈ���·� ����Ѵ�.
*****************************************************************/
void render()
{
	RenderMap();
}

/****************************************************************
* ���� : ��ü���� ������ �帧�� �����Ѵ�.
*****************************************************************/
int32_t Run()
{
	//Game Loop�� ��ü�� Frame
	while (true)
	{
		UpdateTimer();
		//������ ���� ------- ���������� ����
		//				�� ���Ⱑ ��Ÿ Ÿ��
		//�Է�ó��
		processInput();
		//������Ʈ
		update();
		//������
		render();
		if (ClearCondition() == 0)
		{
			clearStage();
			gameStage++;
			if (gameStage == STAGE_MAX) 
			{
				break;
			}
			LoadStage(gameStage);
		}
		
	}
	return 0;

}