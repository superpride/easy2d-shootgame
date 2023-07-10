#pragma once
#include "common.h"
#include "Player.h"
#include "tool.h"
#include "Ground.h"
#include "Platform.h"
#include "Props.h"
#include "Prop.h"

#include "bullet.h"
#include "Blood.h"
#include "GameOver.h"
class GameScene : public Scene
{
public:
	GameScene();
	void onUpdate() override;
	void shoot(Player* player);
	void shoot1(Player* player);
	void barrierLimit(Player* player);
	void boundaryLimit();
	void bulletLimit();
	void bulletLimit1();
	void propsLimit();
	void propsLimit1();
	int number=0;
	int number1=0;
	static bool started;
	Props* p1;
protected:
	Player* player;
	Player* playerx;
	Sprite* sprite;
	Sprite* spritex;
	Blood* bloodbar;
	ShapeNode* bloodbarLeft, * bloodbarRight;
	Ground* ground;
	Platform* platform[6];
	bullet* bullets[1000];
	bullet* bullets1[1000];
	//bullet* b0;
	//GameScene* gamescene;
	bool leftAble;//玩家是否可以向左移动
	bool rightAble;//玩家是否可以向右移动
	bool upAble;//玩家是否可以向上移动
	bool downAble;//玩家是否可以向下移动
	bool grativAble;//重力是否存在
};
