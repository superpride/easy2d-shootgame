#pragma once
#include "Prop.h"

// ������ߵ���
class Props :
	public Sprite
{
public:
	Props();
	~Props();

	void onUpdate() override;
	void addProps();	// ���һ������
	void start();	// ��ʼ�ƶ�
	void stop();	// ֹͣ�ƶ�

public:
	int number;		// ��������
	Prop* props[5];	// ������ֻ��5������
};