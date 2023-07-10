//
//  Player.h
//  player
//
//  Created by ����� on 2023/5/13.
//
#pragma once
#include "common.h"

class Player : public Sprite
{
public:
    Player();
    ~Player();
    void move();//ÿ֡�����ƶ��������ı�x�����ٶ�ʵ��
    void stopping();//ÿ֡�ж������û�в�����û������x�����ٶ�Ϊ0
    void stopping_u();//��y�������ٶ�����
    void stopping_d();//��y�������ٶ�����
    void stopping_l();//��x�������ٶ�����
    void stopping_r();//��x�������ٶ�����
    void fall();//ÿ֡�����������ٶ���Ӱ��
    void alive();//ÿ֡�ж�����Ƿ����
    void jump();//���ڵ��'w'���ã�������Ծ�������ı�y�����ٶ�ʵ��
    void leftmoving();//���ڵ��'a'���ã�������Ծ�������ı�y�����ٶ�ʵ��
    void rightmoving();//���ڵ��'d'���ã�������Ծ�������ı�y�����ٶ�ʵ��

    void be_attack(float damage);//��������Ѫ
    void be_cure(float curing);//����߻�Ѫ
    void speedup(float x);

    void _land();//��½�ˣ�������ײʱ���ü���
    void _equipemt();//�ı�װ������equiement��

    void showHitbox();//��ʾ��ײ����
    void setHitbox(const Point& pos, const Size& size);//������ײ����
    Rect getHitbox();//��ȡ��ײ����
    //void BarrierLimit();//�ϰ�������

    void setDirection(int direction);//�������﷽��

    //���涼�Ƿ���ֵ
    float getBlood();
    float getX_speed();
    float getY_speed();
    float getDamage();
    bool getLiving();
    bool getLanding();
    bool getEquipment();
    int getDirection();//��ȡ���﷽��
    float movingspeed = 250.f;


private:
    float blood;//Ѫ��
    float x_speed;//x�����ٶ�
    float y_speed;//y�����ٶ�
    

   
    float damage;//�����˺�
    bool living;//���Ż�������
    bool equipment;//��û��װ������
    bool landing;//��û����½
    //FrameSequence* frames;//ָ֡��
    Point hitbox_leftTop = Point(35,10);//��ײ�������ϽǶ��� //rd(75,110):
    Size hitboxSize = Size(40, 100);//��ײ����Ĵ�С
    Rect hitbox = Rect(hitbox_leftTop, hitboxSize);//��ײ����
    //bool leftAble;//����Ƿ���������ƶ�
    //bool rightAble;//����Ƿ���������ƶ�
    //bool upAble;//����Ƿ���������ƶ�
    //bool downAble;//����Ƿ���������ƶ�
    //bool grativAble;//�����Ƿ����
    int direction;
    int jumpNum;//��Ծ�����������Ծ����
};      
