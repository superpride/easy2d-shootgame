//
//  main.cpp
//  player
//
//  Created by 许锦浩 on 2023/5/13.
//
#include"Player.h"
namespace {
    //重力速度等常量
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
    //初始化
    //auto seq = gcnew FrameSequence(0.1);
    //seq->add(Image::load("res/platformChar_idle.png"));
    //auto animation = gcnew Animation(seq);
    //auto action = gcnew Loop(animation);
    // 精灵执行循环的帧动画
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

//让y负方向速度置零
void Player::stopping_u()
{
    if (y_speed < 0)
        y_speed = 0;
}

//让y正方向速度置零
void Player::stopping_d()
{
    if (y_speed > 0)
        y_speed = 0;
}

//让x负方向速度置零
void Player::stopping_l()
{
    if (x_speed < 0)
        x_speed = 0;
}

//让x正方向速度置零
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
    //着陆且活着
    if (living && jumpNum < 2)
    {
        y_speed = -jumpspeed;
        //landing = false;//起跳就不再着陆
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

//道具加速
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

//显示hitbox
void Player::showHitbox()
{
    auto hitbox = Shape::createRect(this->hitbox);
    //Rect hitbox = Rect(hitbox_leftTop, hitboxSize);
    auto hitboxNode = gcnew ShapeNode(hitbox);
    hitboxNode->setStrokeColor(Color::White);
    hitboxNode->setStrokeWidth(0.0);
    this->addChild(hitboxNode);
}

//设置hitbox
void Player::setHitbox(const Point& pos, const Size& size)
{
    this->hitbox_leftTop = pos;
    this->hitboxSize = size;
}

//获取碰撞区域
Rect Player::getHitbox()
{
    return this->hitbox;
}

////障碍物限制
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

//左右发生碰撞


//上下发生碰撞
// 
//设置人物方向
void Player::setDirection(int direction)
{
    this->direction = direction;
}

//获取人物方向
int Player::getDirection()
{
    return direction;
}
//返回值
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



