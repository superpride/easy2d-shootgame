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
    direction = 1;//��Ϊ����
    //picture = ;//����
    speed = -abs(speed);

}

//���߼��˺�
void bullet::damageup(float x)
{
    damage *= x;
}
void bullet::directionright()
{
    direction = 0;//��Ϊ����
    //picture = ;//����
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