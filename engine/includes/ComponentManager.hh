#pragma once

#include <string>
#include <unordered_map>
#include "../component/Component.hh"
#include "DLLLoader.hh"

namespace StrawberryMilk {

  namespace Component {

    class ComponentManager {

    public:
      ComponentManager();
      ~ComponentManager();
      ComponentManager(ComponentManager const &&) = delete;
      ComponentManager(ComponentManager const &) = delete;
      void operator=(ComponentManager const &) = delete;

      void loadComponent(std::string const &name, std::string const &path);
      void unloadComponent(std::string const &name);
      void createComponent(std::string const &name);

    private:
      std::unordered_map<std::string, DLLLoader<StrawberryMilk::Component *>> mComponent;
    };
  };
};
