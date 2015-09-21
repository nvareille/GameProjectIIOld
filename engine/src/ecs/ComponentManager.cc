#include "../../includes/ComponentManager.hh"

StrawberryMilk::Component::ComponentManager::ComponentManager() {}

StrawberryMilk::Component::ComponentManager::~ComponentManager() {}

void StrawberryMilk::Component::ComponentManager::loadComponent(std::string const &name, std::string const &path) {
  // TODO: MUST CALL DLL LOADER
}

void StrawberryMilk::Component::ComponentManager::unloadComponent(std::string const &name) {
  auto it = mComponent.find(name);

  if (it == mComponent.end()) {
    throw std::invalid_argument("Component wasn't found in the Component Manager");
  }
  // TODO: MUST CALL DLL UNLOADER
}

void StrawberryMilk::Component::ComponentManager::createComponent(std::string const &name) {
  auto it = mComponent.find(name);

  if (it != mComponent.end()) {

    // You think it was a valid DLL, but it was me, DIO !!!
    throw std::invalid_argument("Component was already found in the Component Manager");
  }
}
