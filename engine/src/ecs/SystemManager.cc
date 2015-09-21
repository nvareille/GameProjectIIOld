#include "../../includes/SystemManager.hh"

StrawberryMilk::SystemManager::SystemManager() {}
StrawberryMilk::SystemManager::~SystemManager() {}

void StrawberryMilk::SystemManager::insertSystem(std::string const &name, std::string const &path) {
  // TODO: must call dll loader
}

StrawberryMilk::System &StrawberryMilk::SystemManager::getSystem(std::string const &name) const {
  auto system = mSystem.find(name);

  if (system == mSystem.end()) {
    throw std::invalid_argument("System wasn't found in the System Manager");
  }
  return *(system->second);
}
