#pragma once
#include "common.h"
#include "Player.h"
#include "Platform.h"

class Intersects : public Rect
{
public:
	static int intersectFeedback(Player* player, Platform* platform);//��ײ����,����0�����ϱ���ײ������1���������ײ,����2�����±���ײ,����3�����ұ���ײ

};
