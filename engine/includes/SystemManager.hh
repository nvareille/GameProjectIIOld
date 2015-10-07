#pragma once

#include <string>
#include <unordered_map>
#include "../system/System.hh"

namespace StrawberryMilk {

  class Engine;
  class SystemManager {

  public:
    SystemManager();
    ~SystemManager();
    SystemManager(SystemManager const &) = delete;
    SystemManager(SystemManager const &&) = delete;
    void operator=(SystemManager const &) = delete;

    // system fct
  public:
    StrawberryMilk::System &getSystem(std::string const &) const;
    void insertSystem(std::string const &, std::string const &, StrawberryMilk::Engine *);

    template<typename T>
    void updateAllSystem(T fct) {
      std::for_each(mSystem.begin(), mSystem.end(), [&](std::pair<std::string, StrawberryMilk::System *> it) {
        fct(it.second);
    });

  };

  private:
    std::unordered_map<std::string, StrawberryMilk::System *> mSystem;
  };
};
