//
//  Player.h
//  player
//
//  Created by 许锦浩 on 2023/5/13.
//
#pragma once
#include "common.h"

class Player : public Sprite
{
public:
    Player();
    ~Player();
    void move();//每帧左右移动，依靠改变x方向速度实现
    void stopping();//每帧判断玩家有没有操作，没有则让x方向速度为0
    void stopping_u();//让y负方向速度置零
    void stopping_d();//让y正方向速度置零
    void stopping_l();//让x负方向速度置零
    void stopping_r();//让x正方向速度置零
    void fall();//每帧都有重力加速度在影响
    void alive();//每帧判断玩家是否活着
    void jump();//（在点击'w'调用），后跳跃，依靠改变y方向速度实现
    void leftmoving();//（在点击'a'调用），后跳跃，依靠改变y方向速度实现
    void rightmoving();//（在点击'd'调用），后跳跃，依靠改变y方向速度实现

    void be_attack(float damage);//被攻击掉血
    void be_cure(float curing);//捡道具回血
    void speedup(float x);

    void _land();//着陆了，上下碰撞时调用即可
    void _equipemt();//改变装备（！equiement）

    void showHitbox();//显示碰撞区域
    void setHitbox(const Point& pos, const Size& size);//设置碰撞区域
    Rect getHitbox();//获取碰撞区域
    //void BarrierLimit();//障碍物限制

    void setDirection(int direction);//设置人物方向

    //后面都是返回值
    float getBlood();
    float getX_speed();
    float getY_speed();
    float getDamage();
    bool getLiving();
    bool getLanding();
    bool getEquipment();
    int getDirection();//获取人物方向
    float movingspeed = 250.f;


private:
    float blood;//血量
    float x_speed;//x方向速度
    float y_speed;//y方向速度
    

   
    float damage;//基础伤害
    bool living;//活着还是死了
    bool equipment;//有没有装备武器
    bool landing;//有没有着陆
    //FrameSequence* frames;//帧指针
    Point hitbox_leftTop = Point(35,10);//碰撞区域左上角顶点 //rd(75,110):
    Size hitboxSize = Size(40, 100);//碰撞区域的大小
    Rect hitbox = Rect(hitbox_leftTop, hitboxSize);//碰撞区域
    //bool leftAble;//玩家是否可以向左移动
    //bool rightAble;//玩家是否可以向右移动
    //bool upAble;//玩家是否可以向上移动
    //bool downAble;//玩家是否可以向下移动
    //bool grativAble;//重力是否存在
    int direction;
    int jumpNum;//跳跃次数，最多跳跃两次
};      
