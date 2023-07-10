#include "TitleScene.h"
#include "GameScene.h"
#include "Mybutton.h"

void Start()
{
	// 创建 GameScene
	auto scene = gcnew GameScene();
	// 创建淡入淡出式切换动画
	auto transition = gcnew FadeTransition(1);
	// 进入 StartScene，最后的参数 false 表示不再返回当前场景
	SceneManager::enter(scene, transition, false);
}

TitleScene::TitleScene()
{
	//GameScene::started = true;
	//创建背景
	auto background = gcnew Sprite("res/TitleScene1.jpg");
	background->setPos(0, 0);
	background->setSize(Window::getWidth(), Window::getHeight());
	addChild(background);

	//创建标题
	/*uto titleImg = gcnew Sprite("res/platformPack_tile001.png");
	titleImg->setPos(20, 20);
	titleImg->setSize(500, 200);
	addChild(titleImg);*/

	//创建字体
	Font font = Font("宋体", 100, Font::Weight::Bold);
	DrawingStyle style = DrawingStyle();
	style.fillColor = Color::Red;
	style.strokeColor = Color::Black;
	style.strokeWidth = 4.0;

	//创建游戏名
	auto titleName = gcnew Text("星  杀", font, style);
	titleName->setPos(50, 60);
	addChild(titleName);

	Font font2 = Font("宋体", 30, Font::Weight::Bold);
	DrawingStyle style2 = DrawingStyle();
	style.fillColor = Color::Black;
	style.strokeColor = Color::Black;
	style.strokeWidth = 4.0;

	//创建游戏说明
	Font font3 = Font("宋体", 30, Font::Weight::Bold);
	DrawingStyle style3 = DrawingStyle();
	style3.fillColor = Color::White;
	//style3.strokeColor = Color::White;
	//style3.strokeWidth = 4.0;
	
	auto gameExplain = gcnew Text("移动方法：\n玩家1：WASD移动，J射击\n玩家2：小键盘上下左右移动\n空格或小键盘1射击\n\n道具说明：\n红苹果加血\n绿苹果加移动速度\n黄苹果加伤害", font3, style3);
	gameExplain->setPos(50, 250);
	addChild(gameExplain);

	

	//署名
	auto author = gcnew Text("  by txf xjh xch", font2, style2);
	author->setFontSize(70);
	author->setPos(700, 600);
	addChild(author);


	//开始游戏按钮
	auto startBtn = gcnew Mybutton("res/thebeginbutton.png", []()
		{
			//进入音效
			auto music = MusicPlayer::preload("res/startbutton.m4a");
			// 判断指针是否为空
			if (music)
			{
				// 播放音乐
				music->play();
			}
			SceneManager::enter(gcnew GameScene(), gcnew FadeTransition(0.5f));
		});
	startBtn->setPos(Window::getWidth() / 2 + 100, Window::getHeight() / 2);
	startBtn->setSize(520, 150);
	addChild(startBtn);


	//设置
	//auto setting = gcnew Mybutton("res/platformPack_tile013.png", []()
	//	{
	//		//是要再设置一个场景吗？
	//	});
	//setting->setPos(30, startBtn->getHeight() + startBtn->getPosY() + 50);
	//setting->setSize(480, 150);
	//addChild(setting);

	//主人公
	/*auto role = gcnew Sprite("res/platformChar_idle.png");
	role->setSize(300, 300);
	role->setPos(author->getPosX(), author->getPosY() + author->getHeight() + 50);
	addChild(role);*/
}