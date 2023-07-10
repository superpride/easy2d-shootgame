#include "TitleScene.h"
#include "GameScene.h"
#include "Mybutton.h"

void Start()
{
	// ���� GameScene
	auto scene = gcnew GameScene();
	// �������뵭��ʽ�л�����
	auto transition = gcnew FadeTransition(1);
	// ���� StartScene�����Ĳ��� false ��ʾ���ٷ��ص�ǰ����
	SceneManager::enter(scene, transition, false);
}

TitleScene::TitleScene()
{
	//GameScene::started = true;
	//��������
	auto background = gcnew Sprite("res/TitleScene1.jpg");
	background->setPos(0, 0);
	background->setSize(Window::getWidth(), Window::getHeight());
	addChild(background);

	//��������
	/*uto titleImg = gcnew Sprite("res/platformPack_tile001.png");
	titleImg->setPos(20, 20);
	titleImg->setSize(500, 200);
	addChild(titleImg);*/

	//��������
	Font font = Font("����", 100, Font::Weight::Bold);
	DrawingStyle style = DrawingStyle();
	style.fillColor = Color::Red;
	style.strokeColor = Color::Black;
	style.strokeWidth = 4.0;

	//������Ϸ��
	auto titleName = gcnew Text("��  ɱ", font, style);
	titleName->setPos(50, 60);
	addChild(titleName);

	Font font2 = Font("����", 30, Font::Weight::Bold);
	DrawingStyle style2 = DrawingStyle();
	style.fillColor = Color::Black;
	style.strokeColor = Color::Black;
	style.strokeWidth = 4.0;

	//������Ϸ˵��
	Font font3 = Font("����", 30, Font::Weight::Bold);
	DrawingStyle style3 = DrawingStyle();
	style3.fillColor = Color::White;
	//style3.strokeColor = Color::White;
	//style3.strokeWidth = 4.0;
	
	auto gameExplain = gcnew Text("�ƶ�������\n���1��WASD�ƶ���J���\n���2��С�������������ƶ�\n�ո��С����1���\n\n����˵����\n��ƻ����Ѫ\n��ƻ�����ƶ��ٶ�\n��ƻ�����˺�", font3, style3);
	gameExplain->setPos(50, 250);
	addChild(gameExplain);

	

	//����
	auto author = gcnew Text("  by txf xjh xch", font2, style2);
	author->setFontSize(70);
	author->setPos(700, 600);
	addChild(author);


	//��ʼ��Ϸ��ť
	auto startBtn = gcnew Mybutton("res/thebeginbutton.png", []()
		{
			//������Ч
			auto music = MusicPlayer::preload("res/startbutton.m4a");
			// �ж�ָ���Ƿ�Ϊ��
			if (music)
			{
				// ��������
				music->play();
			}
			SceneManager::enter(gcnew GameScene(), gcnew FadeTransition(0.5f));
		});
	startBtn->setPos(Window::getWidth() / 2 + 100, Window::getHeight() / 2);
	startBtn->setSize(520, 150);
	addChild(startBtn);


	//����
	//auto setting = gcnew Mybutton("res/platformPack_tile013.png", []()
	//	{
	//		//��Ҫ������һ��������
	//	});
	//setting->setPos(30, startBtn->getHeight() + startBtn->getPosY() + 50);
	//setting->setSize(480, 150);
	//addChild(setting);

	//���˹�
	/*auto role = gcnew Sprite("res/platformChar_idle.png");
	role->setSize(300, 300);
	role->setPos(author->getPosX(), author->getPosY() + author->getHeight() + 50);
	addChild(role);*/
}