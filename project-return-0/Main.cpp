# include <Siv3D.hpp> // OpenSiv3D v0.3.2
#include"SceneManager.h"

void Main()
{
	Profiler::EnableAssetCreationWarning(false);
	Window::Resize(1280, 720);						//windowsモード
	Graphics::SetTargetFrameRateHz(60);				//60fpsで回っている
	//Graphics::SetBackground(Palette::White);

	SceneManager::initialize();
	while (System::Update())
	{
		ClearPrint();
		SceneManager::sceneUpdate();
		SceneManager::sceneDraw();
	}
}
