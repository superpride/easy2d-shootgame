#pragma once
#include "weapon.h"
#include "common.h"
class bullet : public Sprite
{
public:
    bullet(weapon w0, float speed);
    void flying();//飞行
    void changePicture(std::string new0);//改图片
    void directionleft();//朝向设定
    void directionright();
    float getDamage();
    int getDirection();
    std::string getPicture();
    int getSpeed();
    void onUpdate() override;
    void damageup(float x);
    Point hitbox_leftTop = Point(0, 0);//碰撞区域左上角顶点
    Size hitboxSize = Size(20, 10);//碰撞区域的大小
    Rect hitbox = Rect(hitbox_leftTop, hitboxSize);//碰撞区域
    int id=0;
    bool isActive = false;
private:
    float damage;//伤害
    int direction;//朝向
    float speed;//飞行速度
    std::string picture;//图片
    weapon w0;//来自哪一把武器
};
