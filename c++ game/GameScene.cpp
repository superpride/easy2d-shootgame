#include "GameScene.h"
#include "Player.h"
#include "tool.h"
#include "weapon.h"
#include "bullet.h"
#include "GameOver.h"
#include "Prop.h"

//创建场景指针
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
//添加道具
GameScene::GameScene()
{
	// 显示游戏刚开始时的 LOGO
	//auto splash = gcnew Sprite(ResLoader::getKeyFrame("splash"));
	//->addChild(splash);
	// 设置图片居中显示
	//splash->setPos(Window::getSize() / 2);

	// 2 秒后执行 Start 函数
	//Timer::start(2, Start)
	
	//子弹初始化
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

	//添加背景
	auto background = gcnew Sprite("res/gamescene.jpg");
	background->setPos(0, 0);
	background->setSize(Window::getWidth(), Window::getHeight());
	addChild(background);

	//Gamescene指针获取
	gamescene = this;
	//添加人物1
	player = gcnew Player();
	player->setPos(Window::getWidth() / 2, 150);
	//添加人物1图片
	auto sprite = gcnew Sprite();
	sprite->open("res/thecharacter1l.png");
	player->addChild(sprite);
	//player->setHeight()
	this->addChild(player);

	//添加人物2
	playerx = gcnew Player();
	playerx->setPos(Window::getWidth() / 2 -100, 150);
	//添加人物2图片
	auto spritex = gcnew Sprite();
	spritex->open("res/thecharacter2l.png");
	playerx->addChild(spritex);
	this->addChild(playerx);


	//添加地面
	ground = gcnew Ground();
	this->addChild(ground);

	//添加平台障碍物
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

	//添加道具
	p1 = gcnew Props();
	this->addChild(p1);
	p1->start();

	//生成道具
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
//玩家1射击
void GameScene::shoot(Player* player)
{
	//number %= 50;
	bullet* b1 = new bullet(*w1, 750.f);
	b1->id = 3;
	std::printf("number:%d ", number);
	bullets[number] = b1;
	bullets[number]->isActive=true;
	number++;
	//子弹素材
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
//玩家2射击
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
	//子弹素材
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

//玩家1子弹碰撞限制
void GameScene::bulletLimit()
{
	for (int i = 0; i < number; i++)
	{
		//与障碍物碰撞
		for (int j = 0; j < Platform::platformNum; j++)
		{
			//获取bullet的碰撞区域和platform的碰撞区域
			Rect rect1 = bullets[i]->hitbox;
			Rect rect2 = platform[j]->hitbox;
			//矩形碰撞区域的四个顶点
			Point lt = rect1.leftTop;
			Point lb = Point(rect1.leftTop.x, rect1.rightBottom.y);
			Point rb = rect1.rightBottom;
			Point rt = Point(rect1.rightBottom.x, rect1.leftTop.y);

			Point lt2 = rect2.leftTop;
			Point lb2 = Point(rect2.leftTop.x, rect2.rightBottom.y);
			Point rb2 = rect2.rightBottom;
			Point rt2 = Point(rect2.rightBottom.x, rect2.leftTop.y);

			//两个节点所在的位置
			float pos1_x = bullets[i]->getPosX();
			float pos1_y = bullets[i]->getPosY();
			float pos2_x = platform[j]->getPosX();
			float pos2_y = platform[j]->getPosY();
			//碰撞体矩形碰撞区域的两个顶点在地图中的位置
			float r2_ltx = pos2_x + lt2.x;/*rect2.getLeftTop().x*/
			float r2_lty = pos2_y + lt2.y;/*rect2.getLeftTop().y;*/
			float r2_rbx = pos2_x + rb2.x;/*rect2.getRightBottom().x;*/
			float r2_rby = pos2_y + rb2.y;/*rect2.getRightBottom().y;*/

			Rect rect3 = Rect(Point(pos1_x + lt.x, pos1_y + lt.y), rect1.getSize());
			Rect rect4 = Rect(Point(pos2_x + lt2.x, pos2_y + lt2.y), rect2.getSize());

			//如果碰撞
			if (rect3.intersects(rect4) && bullets[i]->isActive)
			{
				//子弹伤害变为0
				bullets[i]->isActive = false;
				std::printf("1");
				//子弹消失
				bullets[i]->removeAllChildren();
			}
		}
		//与人物碰撞
		//获取bullet的碰撞区域和playerx的碰撞区域
		Rect rect1 = bullets[i]->hitbox;
		Rect rect2 = playerx->getHitbox();
		//矩形碰撞区域的四个顶点
		Point lt = rect1.leftTop;
		Point lb = Point(rect1.leftTop.x, rect1.rightBottom.y);
		Point rb = rect1.rightBottom;
		Point rt = Point(rect1.rightBottom.x, rect1.leftTop.y);

		Point lt2 = rect2.leftTop;
		Point lb2 = Point(rect2.leftTop.x, rect2.rightBottom.y);
		Point rb2 = rect2.rightBottom;
		Point rt2 = Point(rect2.rightBottom.x, rect2.leftTop.y);

		//两个节点所在的位置
		float pos1_x = bullets[i]->getPosX();
		float pos1_y = bullets[i]->getPosY();
		float pos2_x = playerx->getPosX();
		float pos2_y = playerx->getPosY();
		//碰撞体矩形碰撞区域的两个顶点在地图中的位置
		float r2_ltx = pos2_x + lt2.x;/*rect2.getLeftTop().x*/
		float r2_lty = pos2_y + lt2.y;/*rect2.getLeftTop().y;*/
		float r2_rbx = pos2_x + rb2.x;/*rect2.getRightBottom().x;*/
		float r2_rby = pos2_y + rb2.y;/*rect2.getRightBottom().y;*/

		Rect rect3 = Rect(Point(pos1_x + lt.x, pos1_y + lt.y), rect1.getSize());
		Rect rect4 = Rect(Point(pos2_x + lt2.x, pos2_y + lt2.y), rect2.getSize());
		if (rect3.intersects(rect4)&&bullets[i]->isActive)
		{
			playerx->be_attack(bullets[i]->getDamage());
			//子弹伤害变为0
			std::printf("p2:%.f from %d\n", playerx->getBlood(), bullets[i]->id);
			std::printf("xvhao%d ", i);
			bullets[i]->isActive = false;
			//子弹消失
			bullets[i]->removeAllChildren();
		}
	}


}

//玩家2子弹碰撞限制
void GameScene::bulletLimit1()
{
	for (int i = 0; i < number1; i++)
	{
		//与障碍物碰撞
		for (int j = 0; j < Platform::platformNum; j++)
		{
			//获取bullet的碰撞区域和platform的碰撞区域
			Rect rect1 = bullets1[i]->hitbox;
			Rect rect2 = platform[j]->hitbox;
			//矩形碰撞区域的四个顶点
			Point lt = rect1.leftTop;
			Point lb = Point(rect1.leftTop.x, rect1.rightBottom.y);
			Point rb = rect1.rightBottom;
			Point rt = Point(rect1.rightBottom.x, rect1.leftTop.y);

			Point lt2 = rect2.leftTop;
			Point lb2 = Point(rect2.leftTop.x, rect2.rightBottom.y);
			Point rb2 = rect2.rightBottom;
			Point rt2 = Point(rect2.rightBottom.x, rect2.leftTop.y);

			//两个节点所在的位置
			float pos1_x = bullets1[i]->getPosX();
			float pos1_y = bullets1[i]->getPosY();
			float pos2_x = platform[j]->getPosX();
			float pos2_y = platform[j]->getPosY();
			//碰撞体矩形碰撞区域的两个顶点在地图中的位置
			float r2_ltx = pos2_x + lt2.x;/*rect2.getLeftTop().x*/
			float r2_lty = pos2_y + lt2.y;/*rect2.getLeftTop().y;*/
			float r2_rbx = pos2_x + rb2.x;/*rect2.getRightBottom().x;*/
			float r2_rby = pos2_y + rb2.y;/*rect2.getRightBottom().y;*/

			Rect rect3 = Rect(Point(pos1_x + lt.x, pos1_y + lt.y), rect1.getSize());
			Rect rect4 = Rect(Point(pos2_x + lt2.x, pos2_y + lt2.y), rect2.getSize());

			//如果碰撞
			if (rect3.intersects(rect4) && bullets1[i]->isActive)
			{
				//子弹伤害变为0
				bullets1[i]->isActive = false;
				std::printf("1");
				//子弹消失
				bullets[i]->removeAllChildren();
			}
		}
		//与人物碰撞
		//获取bullet的碰撞区域和player的碰撞区域
		Rect rect1 = bullets1[i]->hitbox;
		Rect rect2 = player->getHitbox();
		//矩形碰撞区域的四个顶点
		Point lt = rect1.leftTop;
		Point lb = Point(rect1.leftTop.x, rect1.rightBottom.y);
		Point rb = rect1.rightBottom;
		Point rt = Point(rect1.rightBottom.x, rect1.leftTop.y);

		Point lt2 = rect2.leftTop;
		Point lb2 = Point(rect2.leftTop.x, rect2.rightBottom.y);
		Point rb2 = rect2.rightBottom;
		Point rt2 = Point(rect2.rightBottom.x, rect2.leftTop.y);

		//两个节点所在的位置
		float pos1_x = bullets1[i]->getPosX();
		float pos1_y = bullets1[i]->getPosY();
		float pos2_x = player->getPosX();
		float pos2_y = player->getPosY();
		//碰撞体矩形碰撞区域的两个顶点在地图中的位置
		float r2_ltx = pos2_x + lt2.x;/*rect2.getLeftTop().x*/
		float r2_lty = pos2_y + lt2.y;/*rect2.getLeftTop().y;*/
		float r2_rbx = pos2_x + rb2.x;/*rect2.getRightBottom().x;*/
		float r2_rby = pos2_y + rb2.y;/*rect2.getRightBottom().y;*/

		Rect rect3 = Rect(Point(pos1_x + lt.x, pos1_y + lt.y), rect1.getSize());
		Rect rect4 = Rect(Point(pos2_x + lt2.x, pos2_y + lt2.y), rect2.getSize());
		if (rect3.intersects(rect4)&& bullets1[i]->isActive)
		{
			player->be_attack(bullets1[i]->getDamage());
			//子弹伤害变为0
			std::printf("p1:%.f from %d\n", player->getBlood(), bullets1[i]->id);
			bullets1[i]->isActive = false;
			//子弹消失
			bullets1[i]->removeAllChildren();
		}
	}


}
//玩家1道具碰撞限制
void GameScene::propsLimit(){
	//获取bullet的碰撞区域和player的碰撞区域
	for (int i = 0; i < 5; i++)
	{
		Rect rect1 = p1->props[i]->getHitbox();
		Rect rect2 = player->getHitbox();
		//矩形碰撞区域的四个顶点
		Point lt = rect1.leftTop;
		Point lb = Point(rect1.leftTop.x, rect1.rightBottom.y);
		Point rb = rect1.rightBottom;
		Point rt = Point(rect1.rightBottom.x, rect1.leftTop.y);

		Point lt2 = rect2.leftTop;
		Point lb2 = Point(rect2.leftTop.x, rect2.rightBottom.y);
		Point rb2 = rect2.rightBottom;
		Point rt2 = Point(rect2.rightBottom.x, rect2.leftTop.y);

		//两个节点所在的位置
		float pos1_x = p1->props[i]->getPosX();
		float pos1_y = p1->props[i]->getPosY();
		float pos2_x = player->getPosX();
		float pos2_y = player->getPosY();
		//碰撞体矩形碰撞区域的两个顶点在地图中的位置
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
				// 判断指针是否为空
				if (music)
				{
					// 播放音乐
					music->play();
				}
			}
			else
			{
				auto music = MusicPlayer::preload("res/up.m4a");
				// 判断指针是否为空
				if (music)
				{
					// 播放音乐
					music->play();
				}
			}
			p1->props[i]->removeAllChildren();
			p1->props[i] = prop0;

		}
	}
}

//玩家2道具碰撞限制
void GameScene::propsLimit1() {
	//获取bullet的碰撞区域和player的碰撞区域
	for (int i = 0; i < 5; i++)
	{
		Rect rect1 = p1->props[i]->getHitbox();
		Rect rect2 = playerx->getHitbox();
		//矩形碰撞区域的四个顶点
		Point lt = rect1.leftTop;
		Point lb = Point(rect1.leftTop.x, rect1.rightBottom.y);
		Point rb = rect1.rightBottom;
		Point rt = Point(rect1.rightBottom.x, rect1.leftTop.y);

		Point lt2 = rect2.leftTop;
		Point lb2 = Point(rect2.leftTop.x, rect2.rightBottom.y);
		Point rb2 = rect2.rightBottom;
		Point rt2 = Point(rect2.rightBottom.x, rect2.leftTop.y);

		//两个节点所在的位置
		float pos1_x = p1->props[i]->getPosX();
		float pos1_y = p1->props[i]->getPosY();
		float pos2_x = playerx->getPosX();
		float pos2_y = playerx->getPosY();
		//碰撞体矩形碰撞区域的两个顶点在地图中的位置
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
				// 判断指针是否为空
				if (music)
				{
					// 播放音乐
					music->play();
				}
			}
			else
			{
				auto music = MusicPlayer::preload("res/up.m4a");
				// 判断指针是否为空
				if (music)
				{
					// 播放音乐
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
		//获取player的碰撞区域和platform的碰撞区域
		Rect rect1 = player->getHitbox();
		Rect rect2 = platform[i]->hitbox;

		//矩形碰撞区域的四个顶点
		Point lt = rect1.leftTop;
		Point lb = Point(rect1.leftTop.x, rect1.rightBottom.y);
		Point rb = rect1.rightBottom;
		Point rt = Point(rect1.rightBottom.x, rect1.leftTop.y);

		Point lt2 = rect2.leftTop;
		Point lb2 = Point(rect2.leftTop.x, rect2.rightBottom.y);
		Point rb2 = rect2.rightBottom;
		Point rt2 = Point(rect2.rightBottom.x, rect2.leftTop.y);

		//两个节点所在的位置
		float pos1_x = player->getPosX();
		float pos1_y = player->getPosY();
		float pos2_x = platform[i]->getPosX();
		float pos2_y = platform[i]->getPosY();

		//碰撞体矩形碰撞区域的两个顶点在地图中的位置
		float r2_ltx = pos2_x + lt2.x;/*rect2.getLeftTop().x*/
		float r2_lty = pos2_y + lt2.y;/*rect2.getLeftTop().y;*/
		float r2_rbx = pos2_x + rb2.x;/*rect2.getRightBottom().x;*/
		float r2_rby = pos2_y + rb2.y;/*rect2.getRightBottom().y;*/

		Rect rect3 = Rect(Point(pos1_x + lt.x,pos1_y + lt.y), rect1.getSize());
		Rect rect4 = Rect(Point(pos2_x + lt2.x, pos2_y + lt2.y), rect2.getSize());

		if (rect3.intersects(rect4))
		{
			//人物上边碰撞
			if (Intersects::intersectFeedback(player, platform[i]) == 0)
			{
				upAble = false;
			}
			//人物左边碰撞
			else if (Intersects::intersectFeedback(player, platform[i]) == 1)
			{
				leftAble = false;
			}
			//人物下边碰撞
			else if (Intersects::intersectFeedback(player, platform[i]) == 2)
			{
				downAble = false;
				grativAble = false;
			}
			//人物右边碰撞
			else if (Intersects::intersectFeedback(player, platform[i]) == 3)
			{
				rightAble = false;
			}
			//std::printf("(%.f,%.f) (%.f,%.f) (%.f,%.f) (%.f,%.f)\n", lt.x + pos1_x, lt.y + pos1_y, rb.x + pos1_x, rb.y + pos1_y, r2_ltx, r2_lty, r2_rbx, r2_rby);
		}

		//如果上边发生碰撞，将y负方向速度置零
		if (!upAble)
		{
			player->setPosY(r2_rby - lt.y);
			player->stopping_u();
			//std::printf("up:%.f\n", player->getPosY());
		}
		//如果左边发生碰撞，将x负方向速度置零
		if (!leftAble)
		{
			player->setPosX(r2_rbx - lt.x);
			player->stopping_l();
			//std::printf("le:%.f\n", player->getPosX());
		}
		//如果下边发生碰撞，将y正方向速度置零
		if (!downAble)
		{
			player->setPosY(r2_lty - rb.y);
			player->stopping_d();
			player->_land();
			//std::printf("do:%.f\n", player->getPosY());
		}
		//如果右边发生碰撞，将x正方向速度置零
		if (!rightAble)
		{
			player->setPosX(r2_ltx - rb.x);
			player->stopping_r();
			//std::printf("ri:%.f\n", player->getPosX());
		}

	}
}
//边界限制
void GameScene::boundaryLimit() 
{
	//玩家1不能越过屏幕上边
	if (player->getPosY() < -10)
	{
		player->stopping_u();
	}
	//玩家1不能越过屏幕左边
	if (player->getPosX() < -35)
	{
		player->stopping_l();
	}
	//玩家1不能越过屏幕右边
	if (player->getPosX() > 1280 - 75)
	{
		player->stopping_r();
	}
	//玩家2不能越过屏幕上边
	if (playerx->getPosY() < -10)
	{
		playerx->stopping_u();
	}
	//玩家2不能越过屏幕左边
	if (playerx->getPosX() < -35)
	{
		playerx->stopping_l();
	}
	//玩家2不能越过屏幕右边
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
		//障碍物限制
		barrierLimit(player);
		barrierLimit(playerx);
		//边界限制
		boundaryLimit();
		//子弹碰撞限制
		bulletLimit();
		bulletLimit1();
		//道具碰撞限制
		propsLimit();
		propsLimit1();
		//player
		//人物跳跃
		if (Input::isPress(KeyCode::W))
		{
			player->jump();
		}
		//人物下落
		player->fall();
		//判断人物是否存活
		player->alive();
		//人物左右移动
		player->move();
		//显示碰撞区域
		//player->showHitbox();
		//x方向速度置零
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
		//射击
		if (Input::isPress(KeyCode::J) && player->getEquipment() == false && player->getLiving() == true && timeLimit >= interval)
		{
			auto music = MusicPlayer::preload("res/shoot.mp3");
			// 判断指针是否为空
			if (music)
			{
				// 播放音乐
				music->play();
			}
			shoot(player);
			timeLimit = 0;
		}

		//playerx
		//人物跳跃
		if (Input::isPress(KeyCode::Up))
		{
			playerx->jump();
		}
		//人物下落
		playerx->fall();
		//判断人物是否存活
		playerx->alive();
		//人物左右移动
		playerx->move();
		//显示碰撞区域
		//playerx->showHitbox();
		//x方向速度置零
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
		//射击
		if ((Input::isPress(KeyCode::Numpad1) || Input::isPress(KeyCode::Space)) && playerx->getEquipment() == false && playerx->getLiving() == true && timeLimitx >= interval)
		{
			auto music = MusicPlayer::preload("res/shoot.mp3");
			// 判断指针是否为空
			if (music)
			{
				// 播放音乐
				music->play();
			}
			shoot1(playerx);
			timeLimitx = 0;
		}

		if (!flag)//执行一次后执行这个函数
		{
			bloodbarLeft->setVisible(false);
			bloodbarRight->setVisible(false);
			//player->blood = player->blood - 10; //后面改成受到伤害 if语句

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
				//游戏失败界面
				started = 0;
				addChild(gcnew GameOver());
				/*player->blood = 5;*/
			}
		}
		else//最开始执行这一句
		{
			//player->blood = player->blood - 0.1;  //后面改成受到伤害
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