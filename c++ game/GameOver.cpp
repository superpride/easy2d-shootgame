#include "GameOver.h"
#include <iostream>

GameOver::GameOver()
{
	int a = 1;
	std::cout << a << std::endl;
	//��Ϸ����ͼ��
	auto gameover = gcnew Sprite("res/GAMEOVER.png");
	std::cout << a << std::endl;
	gameover->setAnchor(0.5f, 0);
	gameover->setPosY(120);
	gameover->setSize(500, 300);
	this->addChild(gameover);

	//�ؿ�ͼ��
	//auto restartBtn = gcnew Mybutton("res/restart.png", []() {
	//	//�����Ч
	//	GameScene::started = true;
	//	int a = 0;
	//	std::cout << a << std::endl;
	//	SceneManager::enter(gcnew TitleScene(), gcnew FadeTransition(0.6f), false);

	//	});
	//restartBtn->setAnchor(0.5f,0);
	//restartBtn->setPosY(550);
	//addChild(restartBtn);

	// �������
	this->setPosX(Window::getWidth() / 2);
	// ���ڵ������Ƶ���Ļ�·�
	this->setPosY(Window::getHeight());

	// ���������������˶����ڵĸ߶�
	auto vec = Vector2(0, -Window::getHeight());
	// λ�ƶ������õ÷����ӵײ��ƶ�����
	this->runAction(gcnew MoveBy(2, vec));
}