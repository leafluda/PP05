#pragma once
#include <chrono>
#include <thread>
#include "MConsolUtil.hpp"


using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool _isGameRunning;
		MConsoleRenderer cRenderer;
		chrono::system_clock::time_point startRenderTimePoint;
		chrono::duration<double>renderDuration;
		string fps = "";
		int a = 0;
		

	public:
		MGameLoop() { _isGameRunning = false; }
		~MGameLoop() {}

		void Run()
		{
			_isGameRunning = true;

			Initialize();

			while (_isGameRunning)
			{
				Input();
				Update();
				Render();
			}
			Release();
		}
		void Stop()
		{
			_isGameRunning = false;
		}
	private:

		void Initialize() {}
		void Input()
		{
			startRenderTimePoint = chrono::system_clock::now();

			if (GetAsyncKeyState(VK_SPACE) == -0x8000 || GetAsyncKeyState(VK_SPACE) == -0x8001)
			{

			}
			else
			{

			}
		}
		void Update()
		{

		}
		void Render()
		{
			renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			cRenderer.MoveCursor(10, 20);
			fps = "RenderingTime(seconds) : " + to_string(renderDuration.count());
			cRenderer.DrawString(fps);
			cRenderer.MoveCursor(10, 21);
			fps = "FPS(seconds) : " + to_string((int)(1/renderDuration.count()));
			cRenderer.DrawString(fps);

			//cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;
			//int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
			//if (remainingFrameTime > 0)
			//this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));
			//cRenderer.Clear();
			//cout << "Rendering...";
		}
		void Release() {}

	};
}
