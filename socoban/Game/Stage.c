#include "stdafx.h"
#include "Stage.h"

static char s_map[MAP_SIZE][MAP_SIZE];
static int32_t s_goalCount = 0;		//목표갯수
static int32_t s_boxOnGoalCount = 0;	//현재 맞는 갯수
static int32_t s_playerX = 0;	//플레이어 좌표 x
static int32_t s_playerY = 0;	//플레이어 좌표 y


bool parseMapType(int i, int j, char mapType)
{
	if (mapType == '\0' || mapType == '\n')
	{
		return false;
	}
	s_map[i][j] = mapType;
	// 각 맵 타입별로 해줘야 하는 일들
	switch (mapType)
	{

	case MAPTYPE_WALL:
		//플레이어는  이동불가
		//내가 플레이어의 위치 = -입력값
		return true;
	case MAPTYPE_PLAYER: {
		s_playerX = j;
		s_playerY = i;
	}
					   //플레이어 값
		return true;
	case MAPTYPE_BOX:
		//플레이어가 밀면 그 방향으로 박스가 밀린다.
		//캐릭터 + 박스 + 벽이면 그대로
		return true;
	case MAPTYPE_GOAL:
		//박스를 밀고 있는 채로 올라온다면 -> BOX_ON_GOAL로 변경
		//그냥 지나가면 무시
		return true;
	case MAPTYPE_BOX_ON_GOAL:
		// 이동불가능하게 설정하고 GET POINT
		if (s_boxOnGoalCount == s_goalCount)
		{

		}
		return true;
	case MAPTYPE_PATH:
		return true;
	default:
		return false;
	}
	//반환 행에 다다랏을 때 
}

/*************************************************************
* 설명 : 메모리에서 초기화 시켜주기 위한 함수
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
* 설명 : 스테이지를 로딩한다.
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
	//입력에 대해서 처리를 함.
	//게임이 클리어 됐는지도 파악함.
}
// 1. 소코반 게임 완성
// 2. 스테이지 여러 개 추가
// 3. 연출 넣어보기 = > advanced
// 4. 컨텐츠를 추가하기 =>advanced

const char** GetMap()
{
	return s_map;
}

