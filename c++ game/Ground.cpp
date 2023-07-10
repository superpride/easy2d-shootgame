#include "Ground.h"

Ground::Ground()
{
    this->setPos(0, 570);
    //this->showHitbox();
    this->open("res/ground.png");
    this->setWidth(Window::getWidth());
    this->setHeight(290.0f);
}

void Ground::showHitbox()
{
    auto hitbox = Shape::createRect(this->hitbox);
    //Rect hitbox = Rect(hitbox_leftTop, hitboxSize);
    auto hitboxNode = gcnew ShapeNode(hitbox);
    hitboxNode->setStrokeColor(Color::White);
    hitboxNode->setStrokeWidth(0.0);
    this->addChild(hitboxNode);
}