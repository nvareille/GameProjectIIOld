#include <algorithm>
#include <utility>
#include "../includes/Engine.hh"

StrawberryMilk::Engine::Engine() : mContinue(true) {}
StrawberryMilk::Engine::~Engine() {}

void StrawberryMilk::Engine::stop() {
  mContinue = false;
}

void StrawberryMilk::Engine::run() {

  while (mContinue) {

    std::for_each(mSystem.begin(), mSystem.end(),
      [](std::pair<std::string, StrawberryMilk::System *> it) {
		      if (it.second->isActive()) {
			         it.second->update();
		      }
    });
  }

  std::for_each(mSystem.begin(), mSystem.end(),
    [](std::pair<std::string, StrawberryMilk::System *> it) {
      it.second->destroy();
      delete it.second;
  });

}

void StrawberryMilk::Engine::init() {
}
