#include <algorithm>
#include <utility>
#include "../../includes/Engine.hh"
#include "../../system/System.hh"
#include "../../lib/JsonLoader.hh"

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

void StrawberryMilk::Engine::loadScene(StrawberryMilk::Engine::SceneLoader &scene) {
  {
    auto e = scene.getSystem();

    while (!e.empty()) {
      std::pair<std::string, std::string> system = e.top();
      mSystem.insertSystem(system.first, system.second);
      e.pop();
    }
  }
  {
    auto e = scene.getComponent();

    while (!e.empty()) {
      std::pair<std::string, std::string> component = e.top();
      mComponent.loadComponent(component.first, component.second);
      e.pop();
    }
  }
}

void StrawberryMilk::Engine::init() {
   JsonLoader jl("./engine/config/scene/startup-scene.json");
   StrawberryMilk::Engine::SceneLoader scene;

   jl.LoadFile();
   jl.loadObject(&scene);
   this->loadScene(scene);
//   jl.showContent();
}

void StrawberryMilk::Engine::loadScene(std::string const &path) {

}
