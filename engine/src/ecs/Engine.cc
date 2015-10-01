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

  std::cout << "lol" << std::endl;
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
      try {
        std::string path = "engine\\ressource\\system\\" + system.first + "\\" + system.second;
        mSystem.insertSystem(system.first, path);
      } catch (...) {

      }
      e.pop();
    }
  }
  {
    auto e = scene.getComponent();

    while (!e.empty()) {
      std::pair<std::string, std::string> component = e.top();
      std::string path = "engine\\ressource\\component\\" + component.first + "\\" + component.second;
      std::cout << path << std::endl;
      try {
        mComponent.loadComponent(component.first, path);
      } catch (std::invalid_argument &a) {
        std::cout << a.what() << std::endl;
      }
      e.pop();
    }
  }
}

void StrawberryMilk::Engine::init() {
   JsonLoader jl("engine\\config\\scene\\startup-scene.json");
   StrawberryMilk::Engine::SceneLoader scene;

   jl.LoadFile();
   jl.showContent();
   jl.loadObject(&scene);
   this->loadScene(scene);
}

void StrawberryMilk::Engine::loadScene(std::string const &path) {

}
