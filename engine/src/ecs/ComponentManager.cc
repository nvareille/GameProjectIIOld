#include "../../includes/ComponentManager.hh"
#include "../../includes/DLLLoader.hh"

StrawberryMilk::Component::ComponentManager::ComponentManager() {}

StrawberryMilk::Component::ComponentManager::~ComponentManager() {}

void StrawberryMilk::Component::ComponentManager::loadComponent(std::string const &name, std::string const &path) {

  {
	  StrawberryMilk::DLLLoader<StrawberryMilk::Component::Component *> tmp;
	  std::pair<std::string, StrawberryMilk::DLLLoader<StrawberryMilk::Component::Component *>>it;
	  it.first = name;
      it.second = tmp;
      mComponent.insert(it);
  }

  mComponent[name].load(path);
}

void StrawberryMilk::Component::ComponentManager::unloadComponent(std::string const &name) {
  auto it = mComponent.find(name);

  if (it == mComponent.end()) {
    throw std::invalid_argument("Component wasn't found in the Component Manager");
  }
  // TODO: MUST CALL DLL UNLOADER
}

StrawberryMilk::Component::Component *StrawberryMilk::Component::ComponentManager::createComponent(std::string const &name) {
  auto it = mComponent.find(name);

  if (it != mComponent.end()) {
    throw std::invalid_argument("Component was already found in the Component Manager");
  }

  return (*it).second.call("create");
}
