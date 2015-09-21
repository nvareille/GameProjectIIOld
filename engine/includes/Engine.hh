#pragma once

#include "Singleton.hh"
#include "Log.hh"
#include "SystemManager.hh"

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
    SystemManager mSystem;
    bool mContinue;
  };
}
