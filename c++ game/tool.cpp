#include"tool.h"

//��ײ����, ����0�����ϱ���ײ������1���������ײ, ����2�����±���ײ, ����3�����ұ���ײ
int Intersects::intersectFeedback(Player* player, Platform* platform)
{
	//��ȡplayer����ײ�����platform����ײ����
	Rect rect1 = player->getHitbox();
	Rect rect2 = platform->hitbox;

	//������ײ������ĸ�����
	Point lt = rect1.leftTop;
	Point lb = Point(rect1.leftTop.x, rect1.rightBottom.y);
	Point rb = rect1.rightBottom;
	Point rt = Point(rect1.rightBottom.x, rect1.leftTop.y);

	Point lt2 = rect2.leftTop;
	Point lb2 = Point(rect2.leftTop.x, rect2.rightBottom.y);
	Point rb2 = rect2.rightBottom;
	Point rt2 = Point(rect2.rightBottom.x, rect2.leftTop.y);

	//������ײ���������ߵ���ײ�ȣ���ʼ��Ϊ��
	int upCollision = 0;
	int downCollision = 0;
	int leftCollision = 0;
	int rightCollision = 0;

	//������ײ����Ŀ�͸�
	float width = rt.x - lt.x;
	float height = lb.y - lt.y;

	//��һ���ߵȷֵķ���
	int num = 20;
	//��Ԫ�ĳ���
	float w_length = width / num;
	float h_length = height / num;

	//�����ڵ����ڵ�λ��
	float pos1_x = player->getPosX();
	float pos1_y = player->getPosY();
	float pos2_x = platform->getPosX();
	float pos2_y = platform->getPosY();

	//������ײ�����shape
	auto hitboxShape = Shape::createRect(Rect(Point(pos2_x + lt2.x, pos2_y + lt2.y), rect2.getSize()));

	//���ϱ���ײ�ȵļ���
	for (float i = lt.x; i <= rt.x; i += w_length)
	{
		if ( hitboxShape->containsPoint( Point(pos1_x + i, pos1_y + lt.y) ) )
			upCollision++;
	}
	//���±���ײ�ȵļ���
	for (float i = lb.x; i <= rb.x; i += w_length)
	{
		if (hitboxShape->containsPoint(Point(pos1_x + i, pos1_y + lb.y)))
			downCollision++;
	}
	//�������ײ�ȵļ���
	for (float i = lt.y; i <= lb.y; i += h_length)
	{
		if (hitboxShape->containsPoint(Point(pos1_x + lt.x, pos1_y + i)))
			leftCollision++;
	}
	//���ұ���ײ�ȵļ���
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
	
	//�������ײ�ȳ�ʼ��Ϊ-1���������ҵı�ŷֱ�Ϊ0,1,2,3
	int maxf = -1;
	int id = -1;

	//�ж��ĸ��߷�����ײ
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


	//����Ӧ��������ײ����
	//�ϱ���ײ
	if (id == 0)
	{
		return 0;
	}
	//�����ײ
	else if(id == 1)
	{
		return 1;
	}
	//�±���ײ
	else if (id == 2)
	{
		return 2;
	}
	//�ұ���ײ
	else if (id == 3)
	{
		return 3;
	}
}


