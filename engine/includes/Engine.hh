#pragma once

#include <string>
#include <unordered_map>
#include "Singleton.hh"
#include "Log.hh"
#include "../system/System.hh"


namespace StrawberryMilk {

  class Engine {

  public:
    Engine();
    ~Engine();
    Engine(Engine const &&) = delete;
    Engine(Engine const &) = delete;
    void operator=(Engine const &) = delete;

  public:
    void init();
    void run();
    void stop();

  private:
//    StrawberryMilk::Singleton<StrawberryMilk::Log> mLog;
    StrawberryMilk::Singleton<int> mLog;
    std::unordered_map<std::string, StrawberryMilk::System *> mSystem;
    bool mContinue;
  };
}
