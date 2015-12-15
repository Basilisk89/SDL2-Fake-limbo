#pragma once
#include <stdio.h>
namespace Game_Lib {
	class GameSceneManager
	{
	private:
		GameSceneManager();
		~GameSceneManager();
		static GameSceneManager* _instance;
	protected:
	public:
		static GameSceneManager* getInstance();
		void Run();
		void Init();
	};
}
