#include "Platform.h"

int Platform::platformNum = 0;

Platform::Platform(Point p, Size s)
{
	this->hitbox = Rect(p, s);

	switch (platformNum)
	{
	case 0://中间矩形
		this->open("res/platform.png");
		this->setHeight(80.0f);
		this->setWidth(300.0f);
		this->setPos(500.0f, 330.0f);
		//this->showHitbox();
		break;
	case 1://左上横
		this->open("res/platform.png");
		this->setWidth(250.f);
		this->setPos(0.0f, 200.0f);
		//this->showHitbox();
		break;
	case 2://右上横
		this->open("res/platform.png");
		this->setWidth(250.f);
		this->setPos(1030.0f, 200.0f);
		//this->showHitbox();
		break;
	case 3://中间竖
		this->open("res/platform.png");
		this->setWidth(50.0f);

		this->setPos(625.0f, 265.0f);
		//->showHitbox();
		break;
	case 4://左上竖
		this->open("res/platform.png");
		this->setWidth(50.0f);
		this->setHeight(100.0f);
		this->setPos(150.0f, 100.0f);
		//this->showHitbox();
		break;
	case 5://右上竖
		this->open("res/platform.png");
		this->setWidth(50.0f);
		this->setHeight(100.0f);
		this->setPos(1080.0f, 100.0f);
		//this->showHitbox();
		break;
	}
	//this->showHitbox();
	this->platformNum++;
	//tool.intersectFeedback(this->hitbox);
}

Platform::Platform()
{

}

void Platform::showHitbox()
{
	auto hitbox = Shape::createRect(this->hitbox);
	//Rect hitbox = Rect(hitbox_leftTop, hitboxSize);
	auto hitboxNode = gcnew ShapeNode(hitbox);
	hitboxNode->setStrokeColor(Color::White);
	hitboxNode->setStrokeWidth(0.0);
	this->addChild(hitboxNode);
}

