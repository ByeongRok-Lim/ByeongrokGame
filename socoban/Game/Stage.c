#include "stdafx.h"
#include "Stage.h"

static char s_map[MAP_SIZE][MAP_SIZE];
static int32_t s_goalCount = 0;		//��ǥ����
static int32_t s_boxOnGoalCount = 0;	//���� �´� ����
static int32_t s_playerX = 0;	//�÷��̾� ��ǥ x
static int32_t s_playerY = 0;	//�÷��̾� ��ǥ y


bool parseMapType(int i, int j, char mapType)
{
	if (mapType == '\0' || mapType == '\n')
	{
		return false;
	}
	s_map[i][j] = mapType;
	// �� �� Ÿ�Ժ��� ����� �ϴ� �ϵ�
	switch (mapType)
	{

	case MAPTYPE_WALL:
		//�÷��̾��  �̵��Ұ�
		//���� �÷��̾��� ��ġ = -�Է°�
		return true;
	case MAPTYPE_PLAYER: {
		s_playerX = j;
		s_playerY = i;
	}
					   //�÷��̾� ��
		return true;
	case MAPTYPE_BOX:
		//�÷��̾ �и� �� �������� �ڽ��� �и���.
		//ĳ���� + �ڽ� + ���̸� �״��
		return true;
	case MAPTYPE_GOAL:
		//�ڽ��� �а� �ִ� ä�� �ö�´ٸ� -> BOX_ON_GOAL�� ����
		//�׳� �������� ����
		return true;
	case MAPTYPE_BOX_ON_GOAL:
		// �̵��Ұ����ϰ� �����ϰ� GET POINT
		if (s_boxOnGoalCount == s_goalCount)
		{

		}
		return true;
	case MAPTYPE_PATH:
		return true;
	default:
		return false;
	}
	//��ȯ �࿡ �ٴٶ��� �� 
}

/*************************************************************
* ���� : �޸𸮿��� �ʱ�ȭ �����ֱ� ���� �Լ�
**************************************************************/
void clearStage()
{
	memset(s_map, ' ', sizeof(s_map));
	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		s_map[i][MAP_SIZE - 1] = '\0';
	}
	s_goalCount = 0;
	s_boxOnGoalCount = 0;
	s_playerX = 0;	
	s_playerY = 0;


}
/*************************************************************
* ���� : ���������� �ε��Ѵ�.
**************************************************************/
void LoadStage(EStageLevel level)
{
	assert(STAGE_01 <= level && level < STAGE_MAX);
	static char path[MAX_PATH] = { 0 };
	
	sprintf_s(path, sizeof(path), "Stage/Stage%02d.txt", (int32_t)level);
	FILE* fp = NULL;
	fopen_s(&fp, path, "r");
	assert(fp != NULL);
	
	clearStage();

	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		for (size_t j = 0; j < MAP_SIZE; ++j)
		{

			char ch = fgetc(fp);
			if (false == parseMapType(i, j, ch))
			{
				break;
			}
			
		}

		if (feof(fp))
		{
			break;
		}
	}
	fclose(fp);
}



void UpdateStage()
{
	//�Է¿� ���ؼ� ó���� ��.
	//������ Ŭ���� �ƴ����� �ľ���.
}
// 1. ���ڹ� ���� �ϼ�
// 2. �������� ���� �� �߰�
// 3. ���� �־�� = > advanced
// 4. �������� �߰��ϱ� =>advanced

const char** GetMap()
{
	return s_map;
}

