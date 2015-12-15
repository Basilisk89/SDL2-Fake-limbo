//# predefined compiler operatives
//<> go to where the includes are
#include <stdio.h>
#include <stdlib.h>
#include <thread>
//Include GameSceneManager
#include "Main.h"

using namespace Game_Lib;
// old Main call
// int args

// char *argv[] i would like the pointer/address to the argv character array
int main(int args, char *argv[]) {
	Debug::clean();
	Debug::Log(EMessageType::INFO, "Main", "Main", __FILE__, __LINE__, "Main started");
	GameSceneManager* gsm = GameSceneManager::getInstance();
	std::thread thread1(&GameSceneManager::Run, gsm);
	std::thread thread2(&GameSceneManager::Init, gsm);
	std::thread thread3(&GameSceneManager::deleteInstance, gsm);
	Debug::Log(EMessageType::INFO, "Main", "GSM::Run", __FILE__, __LINE__, thread1.get_id(), "Thread1 id");
	Debug::Log(EMessageType::INFO, "Main", "GSM::Init", __FILE__, __LINE__, thread2.get_id(), "Thread2 id");
	Debug::Log(EMessageType::INFO, "Main", "GSM::deleteInstance", __FILE__, __LINE__, thread3.get_id(), "Thread3 id");
	thread1.detach();
	thread2.detach();
	thread3.detach();
	// press any key call
	getchar();
	Debug::Log(EMessageType::INFO, "Main", "Main", __FILE__, __LINE__, "Exit");
	// Main needs to return something right ?
	return 0;
}
// when closing Program , since GameSceneManager is on the stack , since its out of scope , it calls its detructor.
//dynamic binding need to read up on 