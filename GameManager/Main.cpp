//# predefined compiler operatives
//<> go to where the includes are
#include <stdio.h>
#include <stdlib.h>
//Include GameSceneManager
#include "Main.h"
using namespace Game_Lib;
// old Main call
// int args
// char *argv[] i would like the pointer/address to the argv character array
int main(int args, char *argv[]) {
	// GameSceneManager Obj
	GameSceneManager *gameSceneManager;
	// use the GameSceneManager func Run
	gameSceneManager->getInstance();
	// use the init call from GameManager
	gameSceneManager->getInstance()->Init();
	// use the destructor of GameManager
	gameSceneManager->getInstance()->Run();
	// print hello from Main.
	printf("Hello from Main!\n\n");
	// press any key call
	getchar();
	// Main needs to return something right ?
	return 0;
}
// when closing Program , since GameSceneManager is on the stack , since its out of scope , it calls its detructor.