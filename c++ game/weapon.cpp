#include"weapon.h"
weapon::weapon(std::string name, int damage, int bullets)
{
    this->name = name;
    this->damage = damage;
    this->bullets = bullets;
    this->direction = 0;//Ĭ������
}

weapon::weapon(weapon &w)
{
    name=w.name;//����
    damage=w.damage;//�˺�
    bullets=w.bullets;//�ӵ���Ŀ
    direction= w.direction;//����
    picture= w.picture;
}

weapon::weapon()
{

}

void weapon::directionleft()
{
    direction = 1;//��Ϊ����
    //picture = ;//����
}

void weapon::directionright()
{
    direction = 0;//��Ϊ����
    //picture = ;//����
}

void weapon::changePicture(std::string new0)
{
    picture = new0;
}

std::string weapon::getName()
{
    return name;
}

int weapon::getBullets()
{
    return bullets;
}

int weapon::getDamage()
{
    return damage;
}

int weapon::getDirection()
{
    return direction;
}

std::string weapon::getPicture()
{
    return picture;
}
