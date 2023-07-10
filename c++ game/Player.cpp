//
//  main.cpp
//  player
//
//  Created by ����� on 2023/5/13.
//
#include"Player.h"
namespace {
    //�����ٶȵȳ���
    const float Gravity = 700.f;
    const float jumpspeed = 500.f;

    const float max_speed = 500.f;
    const float friction = 500.f;
    const float acceleration = 500.f;
}


Player::Player()
{
   /* frames = gcnew FrameSequence(0.1f);
    frames->add(Image::load("res/platformChar_idle.png"));*/
    //��ʼ��
    //auto seq = gcnew FrameSequence(0.1);
    //seq->add(Image::load("res/platformChar_idle.png"));
    //auto animation = gcnew Animation(seq);
    //auto action = gcnew Loop(animation);
    // ����ִ��ѭ����֡����
    //this->runAction(action);

    living = true;
    equipment = false;
    landing = true;
    x_speed = 0;
    y_speed = 0;
    damage = 5;
    blood = 100;
}

Player::~Player()
{

}

void Player::move()
{
    movePosX(Time::getDeltaTime() * x_speed);
}


void Player::stopping()
{
    x_speed = 0;
}

//��y�������ٶ�����
void Player::stopping_u()
{
    if (y_speed < 0)
        y_speed = 0;
}

//��y�������ٶ�����
void Player::stopping_d()
{
    if (y_speed > 0)
        y_speed = 0;
}

//��x�������ٶ�����
void Player::stopping_l()
{
    if (x_speed < 0)
        x_speed = 0;
}

//��x�������ٶ�����
void Player::stopping_r()
{
    if (x_speed > 0)
        x_speed = 0;
}


void Player::fall()
{
    movePosY(Time::getDeltaTime() * y_speed);
    y_speed += Time::getDeltaTime() * Gravity;
    if (getPosY() > 460)
    {
        setPosY(460);
        y_speed = 0;
        this->_land();
    }
}


void Player::alive()
{
    if (blood <= 0)
    {
        blood = 0;
        living = false;
    }
}


void Player::jump()
{
    //��½�һ���
    if (living && jumpNum < 2)
    {
        y_speed = -jumpspeed;
        //landing = false;//�����Ͳ�����½
        jumpNum++;
        //std::printf("%d\n", jumpNum);
    }
}


void Player::leftmoving()
{
    if (living)
    {
        x_speed = -movingspeed;
    }
}


void Player::rightmoving()
{
    if (living)
    {
        x_speed = movingspeed;
    }
}


void Player::be_attack(float damage)
{
    if (living)
        blood -= damage;
}


void Player::be_cure(float curing)
{
    if (living)
        blood += curing;
}

//���߼���
void Player::speedup(float x)
{
    movingspeed *= x;
}

void Player::_land()
{
    //landing = true;
    jumpNum = 0;
    //std::printf("land");
}
void Player::_equipemt()
{
    equipment = !equipment;
}

//��ʾhitbox
void Player::showHitbox()
{
    auto hitbox = Shape::createRect(this->hitbox);
    //Rect hitbox = Rect(hitbox_leftTop, hitboxSize);
    auto hitboxNode = gcnew ShapeNode(hitbox);
    hitboxNode->setStrokeColor(Color::White);
    hitboxNode->setStrokeWidth(0.0);
    this->addChild(hitboxNode);
}

//����hitbox
void Player::setHitbox(const Point& pos, const Size& size)
{
    this->hitbox_leftTop = pos;
    this->hitboxSize = size;
}

//��ȡ��ײ����
Rect Player::getHitbox()
{
    return this->hitbox;
}

////�ϰ�������
//void Player::BarrierLimit()
//{
//    leftAble = true;
//    rightAble = true;
//    upAble = true;
//    downAble = true;
//    grativAble = true;
//    for(int i=0;i<)
//    
//}

//���ҷ�����ײ


//���·�����ײ
// 
//�������﷽��
void Player::setDirection(int direction)
{
    this->direction = direction;
}

//��ȡ���﷽��
int Player::getDirection()
{
    return direction;
}
//����ֵ
float Player::getBlood()
{
    return this->blood;
}
float Player::getX_speed()
{
    return x_speed;
}
float Player::getY_speed()
{
    return y_speed;
}
float Player::getDamage()
{
    return damage;
}
bool Player::getLiving()
{
    return living;
}
bool Player::getLanding()
{
    return landing;
}
bool Player::getEquipment()
{
    return equipment;
}



