#pragma once
#include "common.h"
class weapon : public Sprite
{
public:
    weapon(std::string name, int damage, int bullets);
    weapon(weapon &w);
    weapon();
    void directionleft();
    void directionright();//朝向设定

    void changePicture(std::string new0);//改图片
    std::string getName();
    int getDamage();
    int getBullets();
    int getDirection();
    std::string getPicture();
private:
    std::string name;//名字
    int damage;//伤害
    int bullets;//子弹数目
    int direction=0;//朝向
    std::string picture;
};