#include <algorithm>
#include <utility>
#include <chrono>
#include "../../includes/Engine.hh"
#include "../../system/System.hh"
#include "JsonLoader.hh"

StrawberryMilk::Engine::Engine() : mContinue(true) {}
StrawberryMilk::Engine::~Engine() {}

void StrawberryMilk::Engine::stop() {
  mContinue = false;
}

void StrawberryMilk::Engine::run() {

	std::chrono::high_resolution_clock::time_point prev = std::chrono::high_resolution_clock::now();
	std::chrono::high_resolution_clock::time_point last = std::chrono::high_resolution_clock::now();
	double delta = 0;

  while (mContinue) {
	  prev = std::chrono::high_resolution_clock::now();	  
	  mSystem.updateAllSystem([&](StrawberryMilk::System *system) {
      if (system->isActive()) {
        system->update(this, delta / 1000);
      }
	  });
	  Sleep(16);
    last = std::chrono::high_resolution_clock::now();
	delta = std::chrono::duration_cast<std::chrono::milliseconds>(last - prev).count();
  }

  mSystem.updateAllSystem([&](StrawberryMilk::System *system) {
	  system->destroy(this);
  });
}

void StrawberryMilk::Engine::loadScene(StrawberryMilk::Engine::SceneLoader &scene) {
  {
    auto e = scene.getSystem();

    while (!e.empty()) {
      std::pair<std::string, std::string> system = e.top();
      try {
        std::string path = "engine\\ressource\\system\\" + system.first + "\\" + system.second;
		std::cout << path << std::endl;
		mSystem.insertSystem(system.first, path, this);
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
  {
    auto e = scene.getEntity();

    while (!e.empty()) {
      std::list<std::pair<std::string, std::string>> instr = e.top();

      try {
        StrawberryMilk::Entity::ID id_entity = mEntity.createEntity();
        for (auto comp: instr)
		{
          StrawberryMilk::Component::Component *component = mComponent.createComponent(comp.first);
          mEntity.addComponentOnEntity(id_entity, component);
		  component->init(comp.second, this);
		}

		/*WARNING TO FIX*/

		/*^ TO FIX ^*/

        mSystem.updateAllSystem([&](StrawberryMilk::System *system) {
          if (system->isActive()) {
            system->registerEntity(id_entity);
          }
    	  });


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