#pragma once
#include <easy2d/easy2d.h>

using namespace easy2d;

class Mybutton : public Sprite
{
public:
	Mybutton(const String& imageName, Function<void()> callback)
		:Sprite(imageName), _originPosY(0), _callback(callback)
	{
		auto lis = gcnew ButtonListener(std::bind(&Mybutton::handle, this, std::placeholders::_1));
		this->addListener(lis);
	}
private:
	void handle(ButtonEvent evt)
	{
		if (!_originPosY)
		{
			_originPosY = this->getPosY();
		}
		if (evt == ButtonEvent::Pressed)//按下的按钮动态
		{
			this->setPosY(_originPosY + 5);
		}
		else
		{
			this->setPosY(_originPosY);
		}
		if (evt == ButtonEvent::Clicked)
		{
			_callback();
		}
	}
	float _originPosY;
	Function<void()> _callback;
};

