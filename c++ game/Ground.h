#pragma once
#include"common.h"

class Ground : public Sprite
{
public:
    Ground();
    void showHitbox();
    Point hitbox_leftTop = Point(0.0f, 0.0f);//碰撞区域左上角顶点
    Size hitboxSize = Size(1280, 740);//碰撞区域的大小
    Rect hitbox = Rect(hitbox_leftTop, hitboxSize);//碰撞区域
};

