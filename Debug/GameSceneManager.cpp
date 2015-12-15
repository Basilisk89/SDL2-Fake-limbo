#include "GameSceneManager.h"
// just another bucket to use
using namespace Game_Lib;

GameSceneManager::GameSceneManager() {
	// log it happened
	Debug::Log(EMessageType::INFO, "GSM", "constructor", __FILE__, __LINE__, "GSM Created");
}
//GSM destructor
GameSceneManager::~GameSceneManager() {
	//log it happened
	Debug::Log(EMessageType::INFO, "GSM", "destructor", __FILE__, __LINE__, "GSM Killed");
}
//Run the GSM
void GameSceneManager::Run() {
	// log it happened
	Debug::Log(EMessageType::INFO, "GSM", "Run", __FILE__, __LINE__, "Running GSM");
	// loop i times
	for (int i = 0; i < 10; ++i) {
		//make sure the loop happens every second ?
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		// print out hello from thread i times
		Debug::Log(EMessageType::INFO, "GSM", "Run", __FILE__, __LINE__, "Looped");
		std::cout << i << " :: Hello from thread" << std::endl;
	}
}
// initialize the GSM
void GameSceneManager::Init() {
	//log the method happened
	Debug::Log(EMessageType::INFO, "GSM", "init", __FILE__, __LINE__, "GSM Initialized");
}
//get the GSM instance
GameSceneManager* GameSceneManager::getInstance() {
	//if there is now instance to get
	if (!_instance.get())
		// reset the unique ptr to a new GSM
		_instance.reset(new GameSceneManager());
	//reutrn the Instance
	return _instance.get();
	//log the method happened
	Debug::Log(EMessageType::INFO, "GSM", "getInstance", __FILE__, __LINE__, "GSM getting new instance");
}
// delete the GSM instance
void GameSceneManager::deleteInstance() {
	// is there is an instance to get
	if (_instance.get())
		// get the deleter of the unique ptr instance
		_instance.get_deleter();
	// making sure it is a nullptr
	_instance = nullptr;
	// log the method happened
	Debug::Log(EMessageType::INFO, "GSM", "deleteInstance", __FILE__, __LINE__, "GSM instance Killed");
}
// new to c 11 unique_ptr //std::unique_ptr is a smart pointer that retains sole ownership of an object
//through a pointer and destroys that object when the unique_ptr goes out of scope.
//No two unique_ptr instances can manage the same object.
//IT is a template class
std::unique_ptr<GameSceneManager>GameSceneManager::_instance(nullptr);
//GSM constructor