#include "bullet.h"
bullet::bullet(weapon w0, float speed)
{
    this->speed = speed;
    this->w0 = w0;
    damage = w0.getDamage();
    direction = w0.getDirection();
    //std::printf("2");
}
void bullet::flying()
{
    movePosX(Time::getDeltaTime() * speed);
}

void bullet::directionleft()
{
    direction = 1;//改为向左
    //picture = ;//待定
    speed = -abs(speed);

}

//道具加伤害
void bullet::damageup(float x)
{
    damage *= x;
}
void bullet::directionright()
{
    direction = 0;//改为向右
    //picture = ;//待定
}

void bullet::changePicture(std::string new0)
{
    picture = new0;
}


float bullet::getDamage()
{
    return this->damage;
}

int bullet::getDirection()
{
    return direction;
}

int bullet::getSpeed()
{
    return speed;
}

std::string bullet::getPicture()
{
    return picture;
}

void bullet::onUpdate()
{
    flying();


}