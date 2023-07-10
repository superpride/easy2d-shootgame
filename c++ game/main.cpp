#include "TitleScene.h"

using namespace easy2d;

int main()
{
	// 初始化窗口
	if (Game::init("Game", 1280, 720))
	{
		// 设置窗口图标
		//Window::setIcon(IDI_ICON1);

		// 加载图片和音乐资源
		//ResLoader::init();
		// 修改节点默认中心点，便于让图片居中显示
		//Node::setDefaultAnchor(0.5f, 0.5f);
		//隐藏控制台
		Logger::showConsole(false);

		// 创建 Title 场景
		auto scene = gcnew TitleScene();
		// 创建淡入淡出式的场景切换动画
		auto transition = gcnew FadeTransition(1);
		// 进入 Title 场景
		SceneManager::enter(scene, transition);

		// 开始游戏
		Game::start();
	}
	// 回收游戏资源
	Game::destroy();
	return 0;
}