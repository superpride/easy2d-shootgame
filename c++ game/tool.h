#pragma once
#include "common.h"
#include "Player.h"
#include "Platform.h"

class Intersects : public Rect
{
public:
	static int intersectFeedback(Player* player, Platform* platform);//碰撞反馈,返回0代表上边碰撞，返回1代表左边碰撞,返回2代表下边碰撞,返回3代表右边碰撞

};
