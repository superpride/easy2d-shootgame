#pragma once
#include "common.h"

class Platform : public Sprite
{
public:
	Platform(Point, Size);
	Platform();
	//void addPlatform(int);
	void showHitbox();

	static int platformNum;
	Point hitbox_leftTop;//= Point(0.0f, 0.0f);//��ײ�������ϽǶ���
	Size hitboxSize; //= Size(63, 58);//��ײ����Ĵ�С
	Rect hitbox;// = Rect(hitbox_leftTop, hitboxSize);//��ײ����
	//Intersects tool;
};



