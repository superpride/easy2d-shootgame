#include"tool.h"

//碰撞反馈, 返回0代表上边碰撞，返回1代表左边碰撞, 返回2代表下边碰撞, 返回3代表右边碰撞
int Intersects::intersectFeedback(Player* player, Platform* platform)
{
	//获取player的碰撞区域和platform的碰撞区域
	Rect rect1 = player->getHitbox();
	Rect rect2 = platform->hitbox;

	//矩形碰撞区域的四个顶点
	Point lt = rect1.leftTop;
	Point lb = Point(rect1.leftTop.x, rect1.rightBottom.y);
	Point rb = rect1.rightBottom;
	Point rt = Point(rect1.rightBottom.x, rect1.leftTop.y);

	Point lt2 = rect2.leftTop;
	Point lb2 = Point(rect2.leftTop.x, rect2.rightBottom.y);
	Point rb2 = rect2.rightBottom;
	Point rt2 = Point(rect2.rightBottom.x, rect2.leftTop.y);

	//矩形碰撞区域四条边的碰撞度，初始化为零
	int upCollision = 0;
	int downCollision = 0;
	int leftCollision = 0;
	int rightCollision = 0;

	//矩形碰撞区域的宽和高
	float width = rt.x - lt.x;
	float height = lb.y - lt.y;

	//将一条边等分的份数
	int num = 20;
	//边元的长度
	float w_length = width / num;
	float h_length = height / num;

	//两个节点所在的位置
	float pos1_x = player->getPosX();
	float pos1_y = player->getPosY();
	float pos2_x = platform->getPosX();
	float pos2_y = platform->getPosY();

	//矩形碰撞区域的shape
	auto hitboxShape = Shape::createRect(Rect(Point(pos2_x + lt2.x, pos2_y + lt2.y), rect2.getSize()));

	//对上边碰撞度的计算
	for (float i = lt.x; i <= rt.x; i += w_length)
	{
		if ( hitboxShape->containsPoint( Point(pos1_x + i, pos1_y + lt.y) ) )
			upCollision++;
	}
	//对下边碰撞度的计算
	for (float i = lb.x; i <= rb.x; i += w_length)
	{
		if (hitboxShape->containsPoint(Point(pos1_x + i, pos1_y + lb.y)))
			downCollision++;
	}
	//对左边碰撞度的计算
	for (float i = lt.y; i <= lb.y; i += h_length)
	{
		if (hitboxShape->containsPoint(Point(pos1_x + lt.x, pos1_y + i)))
			leftCollision++;
	}
	//对右边碰撞度的计算
	for (float i = rt.y; i <= rb.y; i += h_length)
	{
		if (hitboxShape->containsPoint(Point(pos1_x + rt.x, pos1_y + i)))
			rightCollision++;
	}
	
	float r2_ltx = pos2_x + lt2.x;/*rect2.getLeftTop().x*/
	float r2_lty = pos2_y + lt2.y;/*rect2.getLeftTop().y;*/
	float r2_rbx = pos2_x + rb2.x;/*rect2.getRightBottom().x;*/
	float r2_rby = pos2_y + rb2.y;/*rect2.getRightBottom().y;*/
	//std::printf("(%.f,%.f) (%.f,%.f) (%.f,%.f) (%.f,%.f)\n", lt.x + pos1_x, lt.y + pos1_y, rb.x + pos1_x, rb.y + pos1_y, r2_ltx, r2_lty, r2_rbx, r2_rby);
	
	//对最大碰撞度初始化为-1，上左下右的编号分别为0,1,2,3
	int maxf = -1;
	int id = -1;

	//判断哪个边发生碰撞
	if (upCollision > maxf)
	{
		maxf = upCollision;
		id = 0;
	}
	if (leftCollision > maxf)
	{
		maxf = leftCollision;
		id = 1;
	}
	if (downCollision > maxf)
	{
		maxf = downCollision;
		id = 2;
	}
	if (rightCollision > maxf)
	{
		maxf = rightCollision;
		id = 3;
	}

	//std::printf("%d,%d,%d,%d,%d\n", id, upCollision, leftCollision, downCollision,rightCollision);

	//if (upCollision > 0)
	//{
	//	player->setPosY(r2_rby - lt.y);
	//	player->stopping_u();
	//	//std::printf("%.f\n", r2_rby );
	//	std::printf("up:%.f\n", player->getPosY());
	//}
	//if (leftCollision > 0)
	//{
	//	player->setPosX(r2_rbx - lt.x);
	//	player->stopping_l();
	//	//std::printf("%.f\n", r2_rbx);
	//	std::printf("le:%.f\n", player->getPosX());
	//}
	//if (downCollision > 0)
	//{
	//	player->setPosY(r2_lty - 96);
	//	player->stopping_d();
	//	//std::printf("%.f\n", r2_lty);
	//	std::printf("do:%.f\n", player->getPosY());
	//}
	//if (rightCollision > 0)
	//{
	//	player->setPosX(r2_ltx - rb.x);
	//	player->stopping_r();
	//	//std::printf("%.f\n", r2_ltx);
	//	std::printf("ri:%.f\n", player->getPosX());
	//}


	//对相应边做出碰撞反馈
	//上边碰撞
	if (id == 0)
	{
		return 0;
	}
	//左边碰撞
	else if(id == 1)
	{
		return 1;
	}
	//下边碰撞
	else if (id == 2)
	{
		return 2;
	}
	//右边碰撞
	else if (id == 3)
	{
		return 3;
	}
}


