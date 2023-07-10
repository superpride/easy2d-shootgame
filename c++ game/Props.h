#pragma once
#include "Prop.h"

// 管理道具的类
class Props :
	public Sprite
{
public:
	Props();
	~Props();

	void onUpdate() override;
	void addProps();	// 添加一根道具
	void start();	// 开始移动
	void stop();	// 停止移动

public:
	int number;		// 道具数量
	Prop* props[5];	// 场景中只有5个道具
};