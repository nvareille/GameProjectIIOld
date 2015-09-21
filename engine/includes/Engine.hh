#pragma once

#include "Singleton.hh"
#include "Log.hh"
#include "SystemManager.hh"
#include "EntityManager.hh"
#include "ComponentManager.hh"

namespace StrawberryMilk {

  class Engine {

  public:
    Engine();
    ~Engine();
    Engine(Engine const &&) = delete;
    Engine(Engine const &) = delete;
    void operator=(Engine const &) = delete;

  public:
    System &getSystem(std::string const &) const;

  public:
    void init();
    void run();
    void stop();

  private:
//    StrawberryMilk::Singleton<StrawberryMilk::Log> mLog;
    StrawberryMilk::SystemManager mSystem;
    StrawberryMilk::Entity::EntityManager mEntity;
    StrawberryMilk::Component::ComponentManager mComponent;
    bool mContinue;
  };
}
