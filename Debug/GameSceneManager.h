#pragma once
#include "Debug.h"
#include <stdio.h>
#include <memory>
//This header defines general utilities to manage dynamic memory:
#include <thread>
/*Thread
Class to represent individual threads of execution.

A thread of execution is a sequence of instructions that can be executed concurrently with other such sequences in multithreading environments, while sharing a same address space.

An initialized thread object represents an active thread of execution; Such a thread object is joinable, and has a unique thread id.*/

namespace Game_Lib {
	class GameSceneManager
	{
	private:
		//GSM constructor
		GameSceneManager();
		//GSM destructor
		~GameSceneManager();
		//instance unique ptr type of GSM
		///std::unique_ptr is a smart pointer that destroys the object it point to when the unique_ptr goes out of scope.
		static std::unique_ptr<GameSceneManager> _instance;
		/// Since my destructor is private the template std::unique_ptr needs access so I made it a friend.
		/// However, std::default_delete is the default destruction policy used by std::unique_ptr
		/// when no deleter is specified, therefore I'll make std::default_delete my friend as well.
		friend std::default_delete<GameSceneManager>;
	protected:
	public:
		// Get the GSM instance
		static GameSceneManager* getInstance();
		//Run GSM
		void Run();
		//Run Init
		void Init();
		//Delete the GSM instance
		void deleteInstance();
	};
}
