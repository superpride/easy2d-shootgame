#pragma once
#include "common.h"

class Prop : public Node
{
public:
    Prop(int cure, float strength, float speed) :cure(cure), strength(strength), speed(speed){
      /*  auto pipe1 = gcnew Sprite(ResLoader::getKeyFrame("pipe_above"));
        pipe1->setAnchor(1, 1);
        pipe1->setPosY(height - 60);*/
    };
    int cure;//��Ѫ��
    /*void getDamage();
    void getSpeed();
    void loop();*/

    float strength;//���˺�
    float speed;//���ٶ�
    //GameScene* gamescene;//����ָ��
    void showHitbox();//��ʾ��ײ����
    Rect getHitbox();//��ȡ��ײ����
    void onUpdate() override;
private:
    Point hitbox_leftTop = Point(0, 0);//��ײ�������ϽǶ���
    Size hitboxSize = Size(40, 40);//��ײ����Ĵ�С
    Rect hitbox = Rect(hitbox_leftTop, hitboxSize);//��ײ����

};