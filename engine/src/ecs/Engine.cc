#include <algorithm>
#include <utility>
#include <chrono>
#include <functional>
#include "../../includes/Engine.hh"
#include "../../includes/ThreadPool.hh"
#include "../../system/System.hh"
#include "JsonLoader.hh"

StrawberryMilk::Engine::Engine() : mContinue(true) {}
StrawberryMilk::Engine::~Engine() {}

void StrawberryMilk::Engine::stop() {
  mContinue = false;
}

void StrawberryMilk::Engine::run() {

  std::chrono::high_resolution_clock::time_point time_begin = std::chrono::high_resolution_clock::now();
  std::chrono::high_resolution_clock::time_point time_end = std::chrono::high_resolution_clock::now();
  unsigned concurentThreadsSupported = std::thread::hardware_concurrency();
  concurentThreadsSupported = concurentThreadsSupported == 0 ? 1 : concurentThreadsSupported;
  std::cout << concurentThreadsSupported << std::endl;
  StrawberryMilk::Thread::ThreadPool threadpool(concurentThreadsSupported);

  while (mContinue) {
	  prev = std::chrono::high_resolution_clock::now();	  
	  mSystem.updateAllSystem([&](StrawberryMilk::System *system) {
		  std::function<void()> task = [&]() {
			  if (system->isActive()) {
				  system->update(this, delta);
			  }
		  };
		  threadpool.addTask(task);
	  });
    time_begin = time_end;
    time_end = std::chrono::high_resolution_clock::now();
	  while (threadpool.getWorkingThreads() != 0);
    std::cout << "lol" << std::endl;
  }

  mSystem.updateAllSystem([&](StrawberryMilk::System *system) {
	  system->destroy(this);
  });
}

void StrawberryMilk::Engine::loadScene(StrawberryMilk::Engine::SceneLoader &scene) {
	std::cout << "debug4";
  {
    auto e = scene.getSystem();
	std::cout << "debug4.5";
    while (!e.empty()) {
		std::cout << "debug5";
      std::pair<std::string, std::string> system = e.top();
      try {
        std::string path = "engine\\ressource\\system\\" + system.first + "\\" + system.second;
		std::cout << "System : " << path << std::endl;
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
	  std::cout << "Component : " << path << std::endl;
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
          component->init(comp.second, this, id_entity);
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

   std::cout << "debug1";
   jl.LoadFile();
   jl.showContent();
   std::cout << "debug2";
   jl.loadObject(&scene);
   std::cout << "debug3";
   this->loadScene(scene);
   std::cout << "debugEnd";

}

void StrawberryMilk::Engine::loadScene(std::string const &path) {

}
