#pragma once
#include <stdbool.h>

typedef enum KeyCode
{
	W = 'w',
	A = 'a',
	S = 's',
	D = 'd'
} EKeyCode;

/// <summary>
/// �Է� ���¸� ������Ʈ �Ѵ�.
/// </summary>
void UpdateInput();

/// <summary>
/// ���� �����ӿ� ��ư�� �������� üũ�Ѵ�.
/// </summary>
/// <param name = "keyCode" > ���� Ű �ڵ� </param>
/// <return �����ٸ� true, �ƴϸ� false</return>
bool GetButtonDown(EKeyCode keyCode);

/// <summary>
/// ���� �����ӿ� ��ư�� �������� üũ�Ѵ�.
/// </summary>
/// <param name = "keyCode" > ���� Ű �ڵ� </param>
/// <return �����ٸ� true, �ƴϸ� false</return>
bool GetButtonUp(EKeyCode keyCode);

/// <summary>
/// ��ư�� ��� ���ȴ��� üũ�Ѵ�.
/// </summary>
/// <param name = "keyCode" > ���� Ű �ڵ� </param>
/// <return �����ٸ� true, �ƴϸ� false</return>
bool GetButoon(EKeyCode keyCode);
