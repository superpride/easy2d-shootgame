#pragma once
#include"common.h"

class Ground : public Sprite
{
public:
    Ground();
    void showHitbox();
    Point hitbox_leftTop = Point(0.0f, 0.0f);//��ײ�������ϽǶ���
    Size hitboxSize = Size(1280, 740);//��ײ����Ĵ�С
    Rect hitbox = Rect(hitbox_leftTop, hitboxSize);//��ײ����
};

