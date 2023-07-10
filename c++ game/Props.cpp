#include "Props.h"
Props::Props()
{
	number = 0;
	// 添加五个道具
	addProps();
	addProps();
	addProps();
	addProps();
	addProps();

	// 关闭 onUpdate 函数
	this->setAutoUpdate(false);
}


Props::~Props()
{
}

void Props::onUpdate()
{
	// 移动所有道具
	for (int i = 0; i < number; i++)
	{

		props[i]->movePosY(Time::getDeltaTime() * 150.f);
	}
	// 判断最前面的道具是否移动到屏幕外
	if (props[0]->getPosY() >= 700)
	{
		// 若第一个道具在屏幕外，删除这个道具
		this->removeChild(props[0]);
		// 把原来下标为 1、2 、3、4、5的道具位置提前
		props[0] = props[1];
		props[1] = props[2];
		props[2] = props[3];
		props[3] = props[4];
		// 道具数量减一
		number--;
		// 添加一个道具
		addProps();
	}
}
void Props::addProps()
{
	if (number >= 5)
		return;
	int num1 = Random::range(1, 4);
	Prop *prop = new Prop(10, 0, 0);
	if (num1 == 1)
	{
		prop = new Prop(10, 1, 1);//回血
		prop->setPos(Random::range(0, Window::getWidth()), 0);
		auto sprite1 = gcnew Sprite();
		sprite1->open("res/addBlood.png");
		prop->addChild(sprite1);

	}
	else if (num1 == 2)
	{
		prop = new Prop(0, 1.2, 1);//加伤害
		prop->setPos(Random::range(0, Window::getWidth()), 0);
		auto sprite1 = gcnew Sprite();
		sprite1->open("res/damageUp.png");
		prop->addChild(sprite1);

	}

	else if (num1 == 3)
	{
		prop = new Prop(0, 1, 1.2);//加移动速度
		prop->setPos(Random::range(0, Window::getWidth()), 0);
		auto sprite1 = gcnew Sprite();
		sprite1->open("res/speedUp.png");
		prop->addChild(sprite1);

	}

	else if (num1 == 4)
	{
		prop = new Prop(-10, 1, 1);//扣血
		prop->setPos(Random::range(0, Window::getWidth()), 0);
		auto sprite1 = gcnew Sprite();
		sprite1->open("res/themeteorite.png");
		prop->addChild(sprite1);
	}
	if (number == 0)
	{
		// 第一个道具在屏幕外200像素处
		prop->setPosY(-200);
	}
	else
	{
		// 其他水管在前一个水管后方600像素处
		prop->setPosY(props[number - 1]->getPosY() - 600);
	}
	// 保存 prop 的指针
	props[number] = prop;
	// 道具数量加一
	number++;

	
	

	this->addChild(prop);

}
void Props::start()
{
	// 打开 onUpdate 函数
	this->setAutoUpdate(true);
}

void Props::stop()
{
	// 关闭 onUpdate 函数
	this->setAutoUpdate(false);
}