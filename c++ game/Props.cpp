#include "Props.h"
Props::Props()
{
	number = 0;
	// ����������
	addProps();
	addProps();
	addProps();
	addProps();
	addProps();

	// �ر� onUpdate ����
	this->setAutoUpdate(false);
}


Props::~Props()
{
}

void Props::onUpdate()
{
	// �ƶ����е���
	for (int i = 0; i < number; i++)
	{

		props[i]->movePosY(Time::getDeltaTime() * 150.f);
	}
	// �ж���ǰ��ĵ����Ƿ��ƶ�����Ļ��
	if (props[0]->getPosY() >= 700)
	{
		// ����һ����������Ļ�⣬ɾ���������
		this->removeChild(props[0]);
		// ��ԭ���±�Ϊ 1��2 ��3��4��5�ĵ���λ����ǰ
		props[0] = props[1];
		props[1] = props[2];
		props[2] = props[3];
		props[3] = props[4];
		// ����������һ
		number--;
		// ���һ������
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
		prop = new Prop(10, 1, 1);//��Ѫ
		prop->setPos(Random::range(0, Window::getWidth()), 0);
		auto sprite1 = gcnew Sprite();
		sprite1->open("res/addBlood.png");
		prop->addChild(sprite1);

	}
	else if (num1 == 2)
	{
		prop = new Prop(0, 1.2, 1);//���˺�
		prop->setPos(Random::range(0, Window::getWidth()), 0);
		auto sprite1 = gcnew Sprite();
		sprite1->open("res/damageUp.png");
		prop->addChild(sprite1);

	}

	else if (num1 == 3)
	{
		prop = new Prop(0, 1, 1.2);//���ƶ��ٶ�
		prop->setPos(Random::range(0, Window::getWidth()), 0);
		auto sprite1 = gcnew Sprite();
		sprite1->open("res/speedUp.png");
		prop->addChild(sprite1);

	}

	else if (num1 == 4)
	{
		prop = new Prop(-10, 1, 1);//��Ѫ
		prop->setPos(Random::range(0, Window::getWidth()), 0);
		auto sprite1 = gcnew Sprite();
		sprite1->open("res/themeteorite.png");
		prop->addChild(sprite1);
	}
	if (number == 0)
	{
		// ��һ����������Ļ��200���ش�
		prop->setPosY(-200);
	}
	else
	{
		// ����ˮ����ǰһ��ˮ�ܺ�600���ش�
		prop->setPosY(props[number - 1]->getPosY() - 600);
	}
	// ���� prop ��ָ��
	props[number] = prop;
	// ����������һ
	number++;

	
	

	this->addChild(prop);

}
void Props::start()
{
	// �� onUpdate ����
	this->setAutoUpdate(true);
}

void Props::stop()
{
	// �ر� onUpdate ����
	this->setAutoUpdate(false);
}