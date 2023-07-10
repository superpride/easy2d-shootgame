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
	Point hitbox_leftTop;//= Point(0.0f, 0.0f);//碰撞区域左上角顶点
	Size hitboxSize; //= Size(63, 58);//碰撞区域的大小
	Rect hitbox;// = Rect(hitbox_leftTop, hitboxSize);//碰撞区域
	//Intersects tool;
};



