#include "GameSceneManager.h"
using namespace Game_Lib;

GameSceneManager::GameSceneManager() {
	printf("Hello from the constructor\n\n");
}

GameSceneManager::~GameSceneManager() {
	printf("Goodbye from the detructor\n\n");
}

void GameSceneManager::Run() {
	printf("GameSceneManager uses Run\n\n");
}

void GameSceneManager::Init() {
	printf("Init The GameSceneManager\n\n");
}
GameSceneManager* GameSceneManager::getInstance() {
	if (!_instance) {
		printf("Instance Created\n\n");
		_instance = new GameSceneManager();
	}
	return _instance;
}
GameSceneManager* GameSceneManager::_instance = NULL;