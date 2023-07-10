#pragma once
#include "common.h"

class Prop : public Node
{
public:
    Prop(int cure, float strength, float speed) :cure(cure), strength(strength), speed(speed){
      /*  auto pipe1 = gcnew Sprite(ResLoader::getKeyFrame("pipe_above"));
        pipe1->setAnchor(1, 1);
        pipe1->setPosY(height - 60);*/
    };
    int cure;//回血量
    /*void getDamage();
    void getSpeed();
    void loop();*/

    float strength;//加伤害
    float speed;//加速度
    //GameScene* gamescene;//场景指针
    void showHitbox();//显示碰撞区域
    Rect getHitbox();//获取碰撞区域
    void onUpdate() override;
private:
    Point hitbox_leftTop = Point(0, 0);//碰撞区域左上角顶点
    Size hitboxSize = Size(40, 40);//碰撞区域的大小
    Rect hitbox = Rect(hitbox_leftTop, hitboxSize);//碰撞区域

};