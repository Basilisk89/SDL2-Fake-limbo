#include "SplashScreenScene.h"
#include <thread>
#include "MusicPlayer.h"

using namespace Game_Lib;

SplashScreenScene::SplashScreenScene(class Window& windowRef) : SceneBase(windowRef) { sceneIndex = 1; }
SplashScreenScene::~SplashScreenScene() {
	Debug::Log(EMessageType::INFO, "SSS", "Delete", __FILE__, __LINE__, "Deleting Instance");
	OnDestroy();
}
bool SplashScreenScene::OnCreate() {
	camera = Camera();

	SDL_Event SDLevent;
	SDLevent = SDL_Event();
	float aspectratio = windowPtr->GetWidth() / windowPtr->GetHeight();
	ndc = camera.NormalizedDeviceCoord(windowPtr->GetWidth(), windowPtr->GetHeight());
	projection = camera.ScreenToWorld(ndc, 0, 600 * aspectratio, 0, 800 / aspectratio, 0, 1);

	eventhandler.Initialize(SDLevent);
	keyboard.Initialize();
	mouse.Initialize();
	projection.print();
	Flys.push_back(new fly(Rectangle(10, -50, 30, 30), windowPtr, 0.0f));
	Flys.push_back(new fly(Rectangle(20, -20, 30, 30), windowPtr, 0.0f));
	Flys.push_back(new fly(Rectangle(30, -30, 30, 30), windowPtr, 0.0f));
	Flys.push_back(new fly(Rectangle(100, -20, 30, 30), windowPtr, 0.0f));
	Flys.push_back(new fly(Rectangle(200, -30, 30, 30), windowPtr, 0.0f));
	Flys.push_back(new fly(Rectangle(300, -50, 30, 30), windowPtr, 0.0f));
	Flys.push_back(new fly(Rectangle(400, -70, 30, 30), windowPtr, 0.0f));
	Flys.push_back(new fly(Rectangle(100, -20, 30, 30), windowPtr, 0.0f));
	boy.reset(new Boy(Rectangle(0.0f, -500.0f, 30, 40), windowPtr, 0.0f));
	bg = new Sprite(Rectangle(0, 0, windowPtr->GetHeight(), windowPtr->GetWidth()), windowPtr, 0);

	for (int i = 0; i < Flys.size(); i++)
		Flys.at(i)->OnCreate("C:/GameDev/fly.png");

	boy->OnCreate("C:/GameDev/hero.png");
	bg->Load("C:/GameDev/background.jpg");

	// set up music obj
	musicplayer.OpenAudio();
	musicplayer.Load("C:/GameDev/FFXIV_OST_Azys_Lla_Theme.mp3", 0);
	musicplayer.Volume(100);
	musicplayer.Play(0, -1);
	Debug::Log(EMessageType::INFO, "SSS", "OnCreate", __FILE__, __LINE__, "Assets loaded");
	return true;
}
/// Cleanup Assets
void SplashScreenScene::OnDestroy() {
	delete bg, musicplayer, eventhandler, keyboard, mouse;
	bg = nullptr;
	boy.reset();
	boy = nullptr;
	for (int i = 0; i < Flys.size(); i++) {
		delete Flys.at(i);
		Flys.at(i) = nullptr;
	}
	Flys.clear();
	Debug::Log(EMessageType::INFO, "SplashScreenScene", "OnDestroy", __FILE__, __LINE__, "Destroying assets");
}
void SplashScreenScene::Update(const float deltaTime) {
	//update the boy
	boy->Update(deltaTime);
	for (int i = 0; i < Flys.size(); i++) {
		Flys.at(i)->Update(deltaTime);
		c.Collision2D(boy.get(), Flys.at(i));
	}
	bool isGrounded = false;
	while (eventhandler.Update()) {
		// figure out what event type it is
		switch (eventhandler.getType()) {
		case Keyboard::State::KEYDOWN:
			keyboard.OnPress(eventhandler.getScanCode());
			if (keyboard.IsPressed(Keyboard::Key::D)) {
				Vec4 move;
				move.x = 30;
				boy->velocity += move;
				boy->RightFlip();
			}if (keyboard.IsPressed(Keyboard::Key::A)) {
				Vec4 move;
				move.x = -30;
				boy->velocity += move;
				boy->LeftFlip();
			}if (keyboard.IsPressed(Keyboard::Key::SPACE) && !keyboard.IsPressed(Keyboard::Key::D) && !keyboard.IsPressed(Keyboard::Key::A)) {
				Vec4 move;
				move.y = 250;
				boy->velocity.y = move.y;
				if (boy->IsFlipped() != true) {
					boy->velocity.x = 50.0;

					Vec4 move;
					move.y = 50;
					boy->velocity.y = move.y;
					if (boy->IsFlipped() == true) {
						boy->velocity.x = -50.0;
					}
				}
			}if (keyboard.IsPressed(Keyboard::Key::SPACE) && keyboard.IsPressed(Keyboard::Key::D)) {
				Vec4 move;
				move.y = 250;
				boy->velocity.y += move.y;
				if (boy->IsFlipped() != true) {
					boy->velocity.x += 100.0;
				}if (keyboard.IsPressed(Keyboard::Key::SPACE) && keyboard.IsPressed(Keyboard::Key::A)) {
					Vec4 move;
					move.y = 50;
					boy->velocity.y += move.y;
					if (boy->IsFlipped() == true) {
						boy->velocity.x = -100.0;
					}
				}
			}if (keyboard.IsPressed(Keyboard::Key::ESCAPE)) {
				isRunning = false; SDL_Quit();
			}
			break;
		case Keyboard::State::KEYUP:
			keyboard.OnRelease(eventhandler.getScanCode());
			if (keyboard.IsReleased(Keyboard::Key::D)) {
				boy->velocity.x = 0.0;
			}if (keyboard.IsReleased(Keyboard::Key::A)) {
				boy->velocity.x = 0.0f;
			}if (keyboard.IsReleased(Keyboard::Key::SPACE)) {
				-boy->acceleration;
			}
			break;
		}
	}
}
/// Draw you scene
void SplashScreenScene::Render() const {
	bg->Render(projection);
	boy->Render(projection);
	for (int i = 0; i < Flys.size(); i++)
		Flys.at(i)->Render(projection);
}

bool Game_Lib::SplashScreenScene::IsFinished() const {
	if (boy->position.x - boy->radius >= 400)
		return true;
	return false;
}