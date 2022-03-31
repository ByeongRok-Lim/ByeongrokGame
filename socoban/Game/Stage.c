#include "stdafx.h"
#include "Stage.h"

static char s_map[MAP_SIZE][MAP_SIZE];
static int32_t s_goalCount = 0;		//목표갯수
static int32_t s_boxOnGoalCount = 0;	//현재 맞는 갯수
static int32_t s_playerX = 0;	//플레이어 좌표 x
static int32_t s_playerY = 0;	//플레이어 좌표 y

bool parseMapType(int i, int j, char mapType)
{

	s_map[i][j] = mapType;
	switch (mapType)
	{
		
		// 각 맵 타입별로 해줘야 하는 일들
	}
	//반환 행에 다다랏을 때 
}

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

