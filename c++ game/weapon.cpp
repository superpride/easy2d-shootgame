#include"weapon.h"
weapon::weapon(std::string name, int damage, int bullets)
{
    this->name = name;
    this->damage = damage;
    this->bullets = bullets;
    this->direction = 0;//默认向右
}

weapon::weapon(weapon &w)
{
    name=w.name;//名字
    damage=w.damage;//伤害
    bullets=w.bullets;//子弹数目
    direction= w.direction;//朝向
    picture= w.picture;
}

weapon::weapon()
{

}

void weapon::directionleft()
{
    direction = 1;//改为向左
    //picture = ;//待定
}

void weapon::directionright()
{
    direction = 0;//改为向右
    //picture = ;//待定
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
