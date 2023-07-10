#include "GameOver.h"
#include <iostream>

GameOver::GameOver()
{
	int a = 1;
	std::cout << a << std::endl;
	//游戏结束图标
	auto gameover = gcnew Sprite("res/GAMEOVER.png");
	std::cout << a << std::endl;
	gameover->setAnchor(0.5f, 0);
	gameover->setPosY(120);
	gameover->setSize(500, 300);
	this->addChild(gameover);

	//重开图标
	//auto restartBtn = gcnew Mybutton("res/restart.png", []() {
	//	//点击音效
	//	GameScene::started = true;
	//	int a = 0;
	//	std::cout << a << std::endl;
	//	SceneManager::enter(gcnew TitleScene(), gcnew FadeTransition(0.6f), false);

	//	});
	//restartBtn->setAnchor(0.5f,0);
	//restartBtn->setPosY(550);
	//addChild(restartBtn);

	// 整体居中
	this->setPosX(Window::getWidth() / 2);
	// 将节点整体移到屏幕下方
	this->setPosY(Window::getHeight());

	// 创建向量，向上运动窗口的高度
	auto vec = Vector2(0, -Window::getHeight());
	// 位移动画，让得分面板从底部移动上来
	this->runAction(gcnew MoveBy(2, vec));
}