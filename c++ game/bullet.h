#pragma once
#include "weapon.h"
#include "common.h"
class bullet : public Sprite
{
public:
    bullet(weapon w0, float speed);
    void flying();//����
    void changePicture(std::string new0);//��ͼƬ
    void directionleft();//�����趨
    void directionright();
    float getDamage();
    int getDirection();
    std::string getPicture();
    int getSpeed();
    void onUpdate() override;
    void damageup(float x);
    Point hitbox_leftTop = Point(0, 0);//��ײ�������ϽǶ���
    Size hitboxSize = Size(20, 10);//��ײ����Ĵ�С
    Rect hitbox = Rect(hitbox_leftTop, hitboxSize);//��ײ����
    int id=0;
    bool isActive = false;
private:
    float damage;//�˺�
    int direction;//����
    float speed;//�����ٶ�
    std::string picture;//ͼƬ
    weapon w0;//������һ������
};
