#include "../../includes/SystemManager.hh"
#include "../../includes/DLLLoader.hh"

StrawberryMilk::SystemManager::SystemManager() {}
StrawberryMilk::SystemManager::~SystemManager() {}

void StrawberryMilk::SystemManager::insertSystem(std::string const &name, std::string const &path) {

  StrawberryMilk::DLLLoader<System *> loader;
  loader.load(path);
  System *system = loader.call("create");
  system->init();
  mSystem[name] = system;
}

StrawberryMilk::System &StrawberryMilk::SystemManager::getSystem(std::string const &name) const {
  auto system = mSystem.find(name);

  if (system == mSystem.end()) {
    throw std::invalid_argument("System wasn't found in the System Manager");
  }
  return *(system->second);
}
