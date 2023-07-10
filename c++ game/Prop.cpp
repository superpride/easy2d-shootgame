#include "Prop.h"


void Prop::showHitbox()
{
	auto hitbox = Shape::createRect(this->hitbox);
	//Rect hitbox = Rect(hitbox_leftTop, hitboxSize);
	auto hitboxNode = gcnew ShapeNode(hitbox);
	hitboxNode->setStrokeColor(Color::White);
	hitboxNode->setStrokeWidth(0.0);
	this->addChild(hitboxNode);
}

Rect Prop::getHitbox()
{
	return this->hitbox;
}

void Prop::onUpdate()
{
	//this->showHitbox();
	//fall();
}