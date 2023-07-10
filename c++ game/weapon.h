#pragma once
#include "common.h"
class weapon : public Sprite
{
public:
    weapon(std::string name, int damage, int bullets);
    weapon(weapon &w);
    weapon();
    void directionleft();
    void directionright();//�����趨

    void changePicture(std::string new0);//��ͼƬ
    std::string getName();
    int getDamage();
    int getBullets();
    int getDirection();
    std::string getPicture();
private:
    std::string name;//����
    int damage;//�˺�
    int bullets;//�ӵ���Ŀ
    int direction=0;//����
    std::string picture;
};