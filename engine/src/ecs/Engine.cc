#include <algorithm>
#include <utility>
#include "../../includes/Engine.hh"
#include "../../system/System.hh"

StrawberryMilk::Engine::Engine() : mContinue(true) {}
StrawberryMilk::Engine::~Engine() {}

void StrawberryMilk::Engine::stop() {
  mContinue = false;
}

void StrawberryMilk::Engine::run() {

  while (mContinue) {
	  mSystem.updateAllSystem([](StrawberryMilk::System *system) {
      if (system->isActive()) {
        system->update();
      }
	  });
  }

  mSystem.updateAllSystem([](StrawberryMilk::System *system) {
	  system->destroy();
  });
}

void StrawberryMilk::Engine::init() {
}

void StrawberryMilk::Engine::loadScene(std::string const &path) {
}
