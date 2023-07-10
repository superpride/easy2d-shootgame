#include "GameScene.h"
#include "Player.h"
#include "tool.h"
#include "weapon.h"
#include "bullet.h"
#include "GameOver.h"
#include "Prop.h"

//��������ָ��
GameScene* gamescene;
bool GameScene::started = 1;
auto w0 = new weapon("0", 0, 10);
auto w1 = new weapon("1", 4, 10);
auto w2 = new weapon("1", 4, 10);
auto prop0 = new Prop(0, 1, 1);

bool flag = true;
int timeLimit = 0;
int timeLimitx = 0;
int interval = 15;
//��ӵ���
GameScene::GameScene()
{
	// ��ʾ��Ϸ�տ�ʼʱ�� LOGO
	//auto splash = gcnew Sprite(ResLoader::getKeyFrame("splash"));
	//->addChild(splash);
	// ����ͼƬ������ʾ
	//splash->setPos(Window::getSize() / 2);

	// 2 ���ִ�� Start ����
	//Timer::start(2, Start)
	
	//�ӵ���ʼ��
	for (int i = 0; i < 500; i++)
	{
		bullets[i] = new bullet(*w0, 500.f);
		bullets[i]->id = 3;
		bullets[i]->isActive = false;
	}
	for (int i = 0; i < 500; i++)
	{
		bullets1[i] = new bullet(*w0, 500.f);
		bullets1[i]->id = 4;
		bullets1[i]->isActive = false;
	}

	//��ӱ���
	auto background = gcnew Sprite("res/gamescene.jpg");
	background->setPos(0, 0);
	background->setSize(Window::getWidth(), Window::getHeight());
	addChild(background);

	//Gamesceneָ���ȡ
	gamescene = this;
	//�������1
	player = gcnew Player();
	player->setPos(Window::getWidth() / 2, 150);
	//�������1ͼƬ
	auto sprite = gcnew Sprite();
	sprite->open("res/thecharacter1l.png");
	player->addChild(sprite);
	//player->setHeight()
	this->addChild(player);

	//�������2
	playerx = gcnew Player();
	playerx->setPos(Window::getWidth() / 2 -100, 150);
	//�������2ͼƬ
	auto spritex = gcnew Sprite();
	spritex->open("res/thecharacter2l.png");
	playerx->addChild(spritex);
	this->addChild(playerx);


	//��ӵ���
	ground = gcnew Ground();
	this->addChild(ground);

	//���ƽ̨�ϰ���
	platform[0] = gcnew Platform(Point(0.0f, 0.0f), Size(300, 80));
	platform[1] = gcnew Platform(Point(0.0f, 0.0f), Size(250, 64));
	platform[2] = gcnew Platform(Point(0.0f, 0.0f), Size(250, 64));
	platform[3] = gcnew Platform(Point(0.0f, 0.0f), Size(50, 100));
	platform[4] = gcnew Platform(Point(0.0f, 0.0f), Size(50, 100));
	platform[5] = gcnew Platform(Point(0.0f, 0.0f), Size(50, 100));


	this->addChild(platform[0]);
	this->addChild(platform[1]);
	this->addChild(platform[2]);
	this->addChild(platform[3]);
	this->addChild(platform[4]);
	this->addChild(platform[5]);

	//��ӵ���
	p1 = gcnew Props();
	this->addChild(p1);
	p1->start();

	//���ɵ���
	//Timer::add(addprops, 1.f, -1);
}


//void GameScene::shoot(Player *player)
//{
//	auto b1 = gcnew bullet(*w1, 500.f);
//	auto rectNode1 = gcnew ShapeNode(Shape::createRect(Rect(Point(), Size(20, 10))));
//	rectNode1->setStrokeColor(Color::Red);
//	b1->addChild(rectNode1);
//	b1->setPos(player->getPosX()+56, player->getPosY()+50);
//	this->addChild(b1);
//	if (player->getDirection() == 0)
//		b1->directionright();
//	else
//		b1->directionleft();
//	//player->addChild(b1);
//	//b1->movePosX(Time::getDeltaTime() * 250.f);
//}
//���1���
void GameScene::shoot(Player* player)
{
	//number %= 50;
	bullet* b1 = new bullet(*w1, 750.f);
	b1->id = 3;
	std::printf("number:%d ", number);
	bullets[number] = b1;
	bullets[number]->isActive=true;
	number++;
	//�ӵ��ز�
	DrawingStyle style;
	style.mode = DrawingStyle::Mode::Solid;
	style.fillColor = Color::Silver;
	style.strokeColor = Color::Silver;
	//bloodbarLeft->setDrawingStyle(style1);

	auto rectNode1 = gcnew ShapeNode(Shape::createRect(Rect(Point(), Size(20, 10))));
	rectNode1->setStrokeColor(Color::Red);
	rectNode1->setDrawingStyle(style);
	b1->addChild(rectNode1);

	this->addChild(b1);
	if (player->getDirection() == 0)
	{
		b1->directionright();
		//b1->setPos(player->getPosX() + 73, player->getPosY() + 50);
		b1->setPos(player->getPosX() + 80, player->getPosY() + 50);
	}
	else
	{
		b1->directionleft();
		//b1->setPos(player->getPosX() + 5, player->getPosY() + 50);
		b1->setPos(player->getPosX() + 10, player->getPosY() + 50);
	}
		
}
//���2���
void GameScene::shoot1(Player* player)
{
	//number1 %= 50;
	bullet* b1 = new bullet(*w2, 750.f);
	b1->setPos(player->getPosX() + 56, player->getPosY() + 50);
	b1->id = 4;
	std::printf("number1:%d ", number1);
	bullets1[number1] = b1;
	bullets1[number1]->isActive = true;
	number1++;
	//�ӵ��ز�
	DrawingStyle style;
	style.mode = DrawingStyle::Mode::Solid;
	style.fillColor = Color::DarkGray;
	style.strokeColor = Color::DarkGray;
	//bloodbarLeft->setDrawingStyle(style1);

	auto rectNode1 = gcnew ShapeNode(Shape::createRect(Rect(Point(), Size(20, 10))));
	rectNode1->setStrokeColor(Color::Red);
	rectNode1->setDrawingStyle(style);
	b1->addChild(rectNode1);

	this->addChild(b1);
	if (player->getDirection() == 0)
	{
		b1->directionright();
		/*b1->setPos(player->getPosX() + 73, player->getPosY() + 50);*/
		b1->setPos(player->getPosX() + 80, player->getPosY() + 50);
	}
	else
	{
		b1->directionleft();
		//b1->setPos(player->getPosX() + 5, player->getPosY() + 50);
		b1->setPos(player->getPosX() + 10, player->getPosY() + 50);
	}
}

//���1�ӵ���ײ����
void GameScene::bulletLimit()
{
	for (int i = 0; i < number; i++)
	{
		//���ϰ�����ײ
		for (int j = 0; j < Platform::platformNum; j++)
		{
			//��ȡbullet����ײ�����platform����ײ����
			Rect rect1 = bullets[i]->hitbox;
			Rect rect2 = platform[j]->hitbox;
			//������ײ������ĸ�����
			Point lt = rect1.leftTop;
			Point lb = Point(rect1.leftTop.x, rect1.rightBottom.y);
			Point rb = rect1.rightBottom;
			Point rt = Point(rect1.rightBottom.x, rect1.leftTop.y);

			Point lt2 = rect2.leftTop;
			Point lb2 = Point(rect2.leftTop.x, rect2.rightBottom.y);
			Point rb2 = rect2.rightBottom;
			Point rt2 = Point(rect2.rightBottom.x, rect2.leftTop.y);

			//�����ڵ����ڵ�λ��
			float pos1_x = bullets[i]->getPosX();
			float pos1_y = bullets[i]->getPosY();
			float pos2_x = platform[j]->getPosX();
			float pos2_y = platform[j]->getPosY();
			//��ײ�������ײ��������������ڵ�ͼ�е�λ��
			float r2_ltx = pos2_x + lt2.x;/*rect2.getLeftTop().x*/
			float r2_lty = pos2_y + lt2.y;/*rect2.getLeftTop().y;*/
			float r2_rbx = pos2_x + rb2.x;/*rect2.getRightBottom().x;*/
			float r2_rby = pos2_y + rb2.y;/*rect2.getRightBottom().y;*/

			Rect rect3 = Rect(Point(pos1_x + lt.x, pos1_y + lt.y), rect1.getSize());
			Rect rect4 = Rect(Point(pos2_x + lt2.x, pos2_y + lt2.y), rect2.getSize());

			//�����ײ
			if (rect3.intersects(rect4) && bullets[i]->isActive)
			{
				//�ӵ��˺���Ϊ0
				bullets[i]->isActive = false;
				std::printf("1");
				//�ӵ���ʧ
				bullets[i]->removeAllChildren();
			}
		}
		//��������ײ
		//��ȡbullet����ײ�����playerx����ײ����
		Rect rect1 = bullets[i]->hitbox;
		Rect rect2 = playerx->getHitbox();
		//������ײ������ĸ�����
		Point lt = rect1.leftTop;
		Point lb = Point(rect1.leftTop.x, rect1.rightBottom.y);
		Point rb = rect1.rightBottom;
		Point rt = Point(rect1.rightBottom.x, rect1.leftTop.y);

		Point lt2 = rect2.leftTop;
		Point lb2 = Point(rect2.leftTop.x, rect2.rightBottom.y);
		Point rb2 = rect2.rightBottom;
		Point rt2 = Point(rect2.rightBottom.x, rect2.leftTop.y);

		//�����ڵ����ڵ�λ��
		float pos1_x = bullets[i]->getPosX();
		float pos1_y = bullets[i]->getPosY();
		float pos2_x = playerx->getPosX();
		float pos2_y = playerx->getPosY();
		//��ײ�������ײ��������������ڵ�ͼ�е�λ��
		float r2_ltx = pos2_x + lt2.x;/*rect2.getLeftTop().x*/
		float r2_lty = pos2_y + lt2.y;/*rect2.getLeftTop().y;*/
		float r2_rbx = pos2_x + rb2.x;/*rect2.getRightBottom().x;*/
		float r2_rby = pos2_y + rb2.y;/*rect2.getRightBottom().y;*/

		Rect rect3 = Rect(Point(pos1_x + lt.x, pos1_y + lt.y), rect1.getSize());
		Rect rect4 = Rect(Point(pos2_x + lt2.x, pos2_y + lt2.y), rect2.getSize());
		if (rect3.intersects(rect4)&&bullets[i]->isActive)
		{
			playerx->be_attack(bullets[i]->getDamage());
			//�ӵ��˺���Ϊ0
			std::printf("p2:%.f from %d\n", playerx->getBlood(), bullets[i]->id);
			std::printf("xvhao%d ", i);
			bullets[i]->isActive = false;
			//�ӵ���ʧ
			bullets[i]->removeAllChildren();
		}
	}


}

//���2�ӵ���ײ����
void GameScene::bulletLimit1()
{
	for (int i = 0; i < number1; i++)
	{
		//���ϰ�����ײ
		for (int j = 0; j < Platform::platformNum; j++)
		{
			//��ȡbullet����ײ�����platform����ײ����
			Rect rect1 = bullets1[i]->hitbox;
			Rect rect2 = platform[j]->hitbox;
			//������ײ������ĸ�����
			Point lt = rect1.leftTop;
			Point lb = Point(rect1.leftTop.x, rect1.rightBottom.y);
			Point rb = rect1.rightBottom;
			Point rt = Point(rect1.rightBottom.x, rect1.leftTop.y);

			Point lt2 = rect2.leftTop;
			Point lb2 = Point(rect2.leftTop.x, rect2.rightBottom.y);
			Point rb2 = rect2.rightBottom;
			Point rt2 = Point(rect2.rightBottom.x, rect2.leftTop.y);

			//�����ڵ����ڵ�λ��
			float pos1_x = bullets1[i]->getPosX();
			float pos1_y = bullets1[i]->getPosY();
			float pos2_x = platform[j]->getPosX();
			float pos2_y = platform[j]->getPosY();
			//��ײ�������ײ��������������ڵ�ͼ�е�λ��
			float r2_ltx = pos2_x + lt2.x;/*rect2.getLeftTop().x*/
			float r2_lty = pos2_y + lt2.y;/*rect2.getLeftTop().y;*/
			float r2_rbx = pos2_x + rb2.x;/*rect2.getRightBottom().x;*/
			float r2_rby = pos2_y + rb2.y;/*rect2.getRightBottom().y;*/

			Rect rect3 = Rect(Point(pos1_x + lt.x, pos1_y + lt.y), rect1.getSize());
			Rect rect4 = Rect(Point(pos2_x + lt2.x, pos2_y + lt2.y), rect2.getSize());

			//�����ײ
			if (rect3.intersects(rect4) && bullets1[i]->isActive)
			{
				//�ӵ��˺���Ϊ0
				bullets1[i]->isActive = false;
				std::printf("1");
				//�ӵ���ʧ
				bullets[i]->removeAllChildren();
			}
		}
		//��������ײ
		//��ȡbullet����ײ�����player����ײ����
		Rect rect1 = bullets1[i]->hitbox;
		Rect rect2 = player->getHitbox();
		//������ײ������ĸ�����
		Point lt = rect1.leftTop;
		Point lb = Point(rect1.leftTop.x, rect1.rightBottom.y);
		Point rb = rect1.rightBottom;
		Point rt = Point(rect1.rightBottom.x, rect1.leftTop.y);

		Point lt2 = rect2.leftTop;
		Point lb2 = Point(rect2.leftTop.x, rect2.rightBottom.y);
		Point rb2 = rect2.rightBottom;
		Point rt2 = Point(rect2.rightBottom.x, rect2.leftTop.y);

		//�����ڵ����ڵ�λ��
		float pos1_x = bullets1[i]->getPosX();
		float pos1_y = bullets1[i]->getPosY();
		float pos2_x = player->getPosX();
		float pos2_y = player->getPosY();
		//��ײ�������ײ��������������ڵ�ͼ�е�λ��
		float r2_ltx = pos2_x + lt2.x;/*rect2.getLeftTop().x*/
		float r2_lty = pos2_y + lt2.y;/*rect2.getLeftTop().y;*/
		float r2_rbx = pos2_x + rb2.x;/*rect2.getRightBottom().x;*/
		float r2_rby = pos2_y + rb2.y;/*rect2.getRightBottom().y;*/

		Rect rect3 = Rect(Point(pos1_x + lt.x, pos1_y + lt.y), rect1.getSize());
		Rect rect4 = Rect(Point(pos2_x + lt2.x, pos2_y + lt2.y), rect2.getSize());
		if (rect3.intersects(rect4)&& bullets1[i]->isActive)
		{
			player->be_attack(bullets1[i]->getDamage());
			//�ӵ��˺���Ϊ0
			std::printf("p1:%.f from %d\n", player->getBlood(), bullets1[i]->id);
			bullets1[i]->isActive = false;
			//�ӵ���ʧ
			bullets1[i]->removeAllChildren();
		}
	}


}
//���1������ײ����
void GameScene::propsLimit(){
	//��ȡbullet����ײ�����player����ײ����
	for (int i = 0; i < 5; i++)
	{
		Rect rect1 = p1->props[i]->getHitbox();
		Rect rect2 = player->getHitbox();
		//������ײ������ĸ�����
		Point lt = rect1.leftTop;
		Point lb = Point(rect1.leftTop.x, rect1.rightBottom.y);
		Point rb = rect1.rightBottom;
		Point rt = Point(rect1.rightBottom.x, rect1.leftTop.y);

		Point lt2 = rect2.leftTop;
		Point lb2 = Point(rect2.leftTop.x, rect2.rightBottom.y);
		Point rb2 = rect2.rightBottom;
		Point rt2 = Point(rect2.rightBottom.x, rect2.leftTop.y);

		//�����ڵ����ڵ�λ��
		float pos1_x = p1->props[i]->getPosX();
		float pos1_y = p1->props[i]->getPosY();
		float pos2_x = player->getPosX();
		float pos2_y = player->getPosY();
		//��ײ�������ײ��������������ڵ�ͼ�е�λ��
		float r2_ltx = pos2_x + lt2.x;/*rect2.getLeftTop().x*/
		float r2_lty = pos2_y + lt2.y;/*rect2.getLeftTop().y;*/
		float r2_rbx = pos2_x + rb2.x;/*rect2.getRightBottom().x;*/
		float r2_rby = pos2_y + rb2.y;/*rect2.getRightBottom().y;*/

		Rect rect3 = Rect(Point(pos1_x + lt.x, pos1_y + lt.y), rect1.getSize());
		Rect rect4 = Rect(Point(pos2_x + lt2.x, pos2_y + lt2.y), rect2.getSize());
		if (rect3.intersects(rect4))
		{
			player->be_cure(p1->props[i]->cure);
			player->speedup(p1->props[i]->speed);
			w1 = new weapon("1", 4*p1->props[i]->strength, 10);
			if (p1->props[i]->cure < 0)
			{
				auto music = MusicPlayer::preload("res/damage.m4a");
				// �ж�ָ���Ƿ�Ϊ��
				if (music)
				{
					// ��������
					music->play();
				}
			}
			else
			{
				auto music = MusicPlayer::preload("res/up.m4a");
				// �ж�ָ���Ƿ�Ϊ��
				if (music)
				{
					// ��������
					music->play();
				}
			}
			p1->props[i]->removeAllChildren();
			p1->props[i] = prop0;

		}
	}
}

//���2������ײ����
void GameScene::propsLimit1() {
	//��ȡbullet����ײ�����player����ײ����
	for (int i = 0; i < 5; i++)
	{
		Rect rect1 = p1->props[i]->getHitbox();
		Rect rect2 = playerx->getHitbox();
		//������ײ������ĸ�����
		Point lt = rect1.leftTop;
		Point lb = Point(rect1.leftTop.x, rect1.rightBottom.y);
		Point rb = rect1.rightBottom;
		Point rt = Point(rect1.rightBottom.x, rect1.leftTop.y);

		Point lt2 = rect2.leftTop;
		Point lb2 = Point(rect2.leftTop.x, rect2.rightBottom.y);
		Point rb2 = rect2.rightBottom;
		Point rt2 = Point(rect2.rightBottom.x, rect2.leftTop.y);

		//�����ڵ����ڵ�λ��
		float pos1_x = p1->props[i]->getPosX();
		float pos1_y = p1->props[i]->getPosY();
		float pos2_x = playerx->getPosX();
		float pos2_y = playerx->getPosY();
		//��ײ�������ײ��������������ڵ�ͼ�е�λ��
		float r2_ltx = pos2_x + lt2.x;/*rect2.getLeftTop().x*/
		float r2_lty = pos2_y + lt2.y;/*rect2.getLeftTop().y;*/
		float r2_rbx = pos2_x + rb2.x;/*rect2.getRightBottom().x;*/
		float r2_rby = pos2_y + rb2.y;/*rect2.getRightBottom().y;*/

		Rect rect3 = Rect(Point(pos1_x + lt.x, pos1_y + lt.y), rect1.getSize());
		Rect rect4 = Rect(Point(pos2_x + lt2.x, pos2_y + lt2.y), rect2.getSize());
		if (rect3.intersects(rect4))
		{
			playerx->be_cure(p1->props[i]->cure);
			playerx->speedup(p1->props[i]->speed);
			w2 = new weapon("1", 4 * p1->props[i]->strength, 10);
			if (p1->props[i]->cure < 0)
			{
				auto music = MusicPlayer::preload("res/damage.m4a");
				// �ж�ָ���Ƿ�Ϊ��
				if (music)
				{
					// ��������
					music->play();
				}
			}
			else
			{
				auto music = MusicPlayer::preload("res/up.m4a");
				// �ж�ָ���Ƿ�Ϊ��
				if (music)
				{
					// ��������
					music->play();
				}
			}
			p1->props[i]->removeAllChildren();
			p1->props[i] = prop0;
		}
	}
}

void GameScene::barrierLimit(Player *player)
{
	for (int i = 0; i < Platform::platformNum; i++)
	{
		leftAble = true;
		rightAble = true;
		upAble = true;
		downAble = true;
		grativAble = true;
		//��ȡplayer����ײ�����platform����ײ����
		Rect rect1 = player->getHitbox();
		Rect rect2 = platform[i]->hitbox;

		//������ײ������ĸ�����
		Point lt = rect1.leftTop;
		Point lb = Point(rect1.leftTop.x, rect1.rightBottom.y);
		Point rb = rect1.rightBottom;
		Point rt = Point(rect1.rightBottom.x, rect1.leftTop.y);

		Point lt2 = rect2.leftTop;
		Point lb2 = Point(rect2.leftTop.x, rect2.rightBottom.y);
		Point rb2 = rect2.rightBottom;
		Point rt2 = Point(rect2.rightBottom.x, rect2.leftTop.y);

		//�����ڵ����ڵ�λ��
		float pos1_x = player->getPosX();
		float pos1_y = player->getPosY();
		float pos2_x = platform[i]->getPosX();
		float pos2_y = platform[i]->getPosY();

		//��ײ�������ײ��������������ڵ�ͼ�е�λ��
		float r2_ltx = pos2_x + lt2.x;/*rect2.getLeftTop().x*/
		float r2_lty = pos2_y + lt2.y;/*rect2.getLeftTop().y;*/
		float r2_rbx = pos2_x + rb2.x;/*rect2.getRightBottom().x;*/
		float r2_rby = pos2_y + rb2.y;/*rect2.getRightBottom().y;*/

		Rect rect3 = Rect(Point(pos1_x + lt.x,pos1_y + lt.y), rect1.getSize());
		Rect rect4 = Rect(Point(pos2_x + lt2.x, pos2_y + lt2.y), rect2.getSize());

		if (rect3.intersects(rect4))
		{
			//�����ϱ���ײ
			if (Intersects::intersectFeedback(player, platform[i]) == 0)
			{
				upAble = false;
			}
			//���������ײ
			else if (Intersects::intersectFeedback(player, platform[i]) == 1)
			{
				leftAble = false;
			}
			//�����±���ײ
			else if (Intersects::intersectFeedback(player, platform[i]) == 2)
			{
				downAble = false;
				grativAble = false;
			}
			//�����ұ���ײ
			else if (Intersects::intersectFeedback(player, platform[i]) == 3)
			{
				rightAble = false;
			}
			//std::printf("(%.f,%.f) (%.f,%.f) (%.f,%.f) (%.f,%.f)\n", lt.x + pos1_x, lt.y + pos1_y, rb.x + pos1_x, rb.y + pos1_y, r2_ltx, r2_lty, r2_rbx, r2_rby);
		}

		//����ϱ߷�����ײ����y�������ٶ�����
		if (!upAble)
		{
			player->setPosY(r2_rby - lt.y);
			player->stopping_u();
			//std::printf("up:%.f\n", player->getPosY());
		}
		//�����߷�����ײ����x�������ٶ�����
		if (!leftAble)
		{
			player->setPosX(r2_rbx - lt.x);
			player->stopping_l();
			//std::printf("le:%.f\n", player->getPosX());
		}
		//����±߷�����ײ����y�������ٶ�����
		if (!downAble)
		{
			player->setPosY(r2_lty - rb.y);
			player->stopping_d();
			player->_land();
			//std::printf("do:%.f\n", player->getPosY());
		}
		//����ұ߷�����ײ����x�������ٶ�����
		if (!rightAble)
		{
			player->setPosX(r2_ltx - rb.x);
			player->stopping_r();
			//std::printf("ri:%.f\n", player->getPosX());
		}

	}
}
//�߽�����
void GameScene::boundaryLimit() 
{
	//���1����Խ����Ļ�ϱ�
	if (player->getPosY() < -10)
	{
		player->stopping_u();
	}
	//���1����Խ����Ļ���
	if (player->getPosX() < -35)
	{
		player->stopping_l();
	}
	//���1����Խ����Ļ�ұ�
	if (player->getPosX() > 1280 - 75)
	{
		player->stopping_r();
	}
	//���2����Խ����Ļ�ϱ�
	if (playerx->getPosY() < -10)
	{
		playerx->stopping_u();
	}
	//���2����Խ����Ļ���
	if (playerx->getPosX() < -35)
	{
		playerx->stopping_l();
	}
	//���2����Խ����Ļ�ұ�
	if (playerx->getPosX() > 1280 - 75)
	{
		playerx->stopping_r();
	}

}

void GameScene::onUpdate()
{
	timeLimit++;
	timeLimitx++;
	if (started) {
		//�ϰ�������
		barrierLimit(player);
		barrierLimit(playerx);
		//�߽�����
		boundaryLimit();
		//�ӵ���ײ����
		bulletLimit();
		bulletLimit1();
		//������ײ����
		propsLimit();
		propsLimit1();
		//player
		//������Ծ
		if (Input::isPress(KeyCode::W))
		{
			player->jump();
		}
		//��������
		player->fall();
		//�ж������Ƿ���
		player->alive();
		//���������ƶ�
		player->move();
		//��ʾ��ײ����
		//player->showHitbox();
		//x�����ٶ�����
		player->stopping();
		if (Input::isDown(KeyCode::A) && leftAble)
		{
			player->removeAllChildren();
			auto sprite = gcnew Sprite();
			sprite->open("res/thecharacter1l.png");
			player->addChild(sprite);

			player->leftmoving();
			player->setDirection(1);
		}
		else if (Input::isDown(KeyCode::D) && rightAble)
		{
			player->removeAllChildren();
			auto sprite = gcnew Sprite();
			sprite->open("res/thecharacter1r.png");
			player->addChild(sprite);

			player->rightmoving();
			player->setDirection(0);
		}
		//���
		if (Input::isPress(KeyCode::J) && player->getEquipment() == false && player->getLiving() == true && timeLimit >= interval)
		{
			auto music = MusicPlayer::preload("res/shoot.mp3");
			// �ж�ָ���Ƿ�Ϊ��
			if (music)
			{
				// ��������
				music->play();
			}
			shoot(player);
			timeLimit = 0;
		}

		//playerx
		//������Ծ
		if (Input::isPress(KeyCode::Up))
		{
			playerx->jump();
		}
		//��������
		playerx->fall();
		//�ж������Ƿ���
		playerx->alive();
		//���������ƶ�
		playerx->move();
		//��ʾ��ײ����
		//playerx->showHitbox();
		//x�����ٶ�����
		playerx->stopping();
		if (Input::isDown(KeyCode::Left) && leftAble)
		{
			playerx->removeAllChildren();
			auto spritex = gcnew Sprite();
			spritex->open("res/thecharacter2l.png");
			playerx->addChild(spritex);

			playerx->leftmoving();
			playerx->setDirection(1);
		}
		else if (Input::isDown(KeyCode::Right) && rightAble)
		{
			playerx->removeAllChildren();
			auto spritex = gcnew Sprite();
			spritex->open("res/thecharacter2r.png");
			playerx->addChild(spritex);

			playerx->rightmoving();
			playerx->setDirection(0);
		}
		//���
		if ((Input::isPress(KeyCode::Numpad1) || Input::isPress(KeyCode::Space)) && playerx->getEquipment() == false && playerx->getLiving() == true && timeLimitx >= interval)
		{
			auto music = MusicPlayer::preload("res/shoot.mp3");
			// �ж�ָ���Ƿ�Ϊ��
			if (music)
			{
				// ��������
				music->play();
			}
			shoot1(playerx);
			timeLimitx = 0;
		}

		if (!flag)//ִ��һ�κ�ִ���������
		{
			bloodbarLeft->setVisible(false);
			bloodbarRight->setVisible(false);
			//player->blood = player->blood - 10; //����ĳ��ܵ��˺� if���

			DrawingStyle style1;
			style1.mode = DrawingStyle::Mode::Solid;
			style1.fillColor = Color::Green;
			style1.strokeColor = Color::Black;
			//style1.strokeWidth = 100.0f;
			//style1.lineJoin = LineJoin::Miter;

			Size size(300 * (player->getBlood() / 100), 20);
			//std::cout << size.width << std::endl;
			Rect bar(Point(0, 0), size);
			auto shape = Shape::createRoundedRect(bar, Vector2(5, 5));

			
			Size sizex(300 * (playerx->getBlood() / 100), 20);
			//std::cout << size.width << std::endl;
			Rect barx(Point(0, 0), sizex);
			auto shapex = Shape::createRoundedRect(barx, Vector2(5, 5));

			bloodbarLeft = new ShapeNode(shape);
			bloodbarRight = new ShapeNode(shapex);
			bloodbarLeft->setPos(Window::getWidth() / 2 - 150, 10);
			//bloodbarLeft->setScaleX(0.1f);
			bloodbarLeft->setOpacity(128);
			bloodbarRight->setPos(Window::getWidth() / 2 - 150, 34);
			bloodbarRight->setDrawingStyle(style1);
			style1.fillColor = Color::Yellow;
			bloodbarLeft->setDrawingStyle(style1);
			addChild(bloodbarLeft);
			addChild(bloodbarRight);
			if (player->getBlood() <= 0)
			{
				//��Ϸʧ�ܽ���
				started = 0;
				addChild(gcnew GameOver());
				/*player->blood = 5;*/
			}
		}
		else//�ʼִ����һ��
		{
			//player->blood = player->blood - 0.1;  //����ĳ��ܵ��˺�
			//std::cout << player->blood << std::endl;
			DrawingStyle style1;
			style1.mode = DrawingStyle::Mode::Solid;
			style1.fillColor = Color::Green;
			style1.strokeColor = Color::Black;
			//style1.strokeWidth = 100.0f;
			//style1.lineJoin = LineJoin::Miter;
			Size size(300 * (player->getBlood() / 100), 20);
			//std::cout << size.width << std::endl;
			Rect bar(Point(0, 0), size);
			auto shape = Shape::createRoundedRect(bar, Vector2(5, 5));

			Size sizex(300 * (playerx->getBlood() / 100), 20);
			//std::cout << size.width << std::endl;
			Rect barx(Point(0, 0), sizex);
			auto shapex = Shape::createRoundedRect(barx, Vector2(5, 5));

			bloodbarLeft = new ShapeNode(shape);
			bloodbarRight = new ShapeNode(shapex);
			bloodbarLeft->setPos(Window::getWidth() / 2 - 150, 10);
			//bloodbarLeft->setScaleX(0.1f);
			bloodbarLeft->setOpacity(128);
			bloodbarRight->setPos(Window::getWidth() / 2 - 150, 34);
			bloodbarRight->setDrawingStyle(style1);
			style1.fillColor = Color::Yellow;
			bloodbarLeft->setDrawingStyle(style1);
			addChild(bloodbarLeft);
			addChild(bloodbarRight);
			flag = 0;
		}
	}

}