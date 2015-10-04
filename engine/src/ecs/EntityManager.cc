#include <algorithm>
#include <tuple>
#include "../../includes/EntityManager.hh"

StrawberryMilk::Entity::EntityManager::EntityManager() : mCurrentId(0) {}
StrawberryMilk::Entity::EntityManager::~EntityManager() {}

void StrawberryMilk::Entity::EntityManager::destroyEntity(ID id) {
  std::get<0>(mEntity[id]) = StrawberryMilk::Entity::EntityManager::EntityState::MUST_BE_EXTERMINATE;
}

StrawberryMilk::Entity::ID StrawberryMilk::Entity::EntityManager::createEntity() {
  ID id = 0;
  auto it = std::find_if(mEntity.begin(), mEntity.end(), [&](std::tuple<StrawberryMilk::Entity::EntityManager::EntityState, std::list<StrawberryMilk::Component::Component *>> it) {
      ++id;
      return std::get<0>(it) == StrawberryMilk::Entity::EntityManager::EntityState::AVAILABLE;
  });

  if (it != mEntity.end()) {
    std::get<0>(*it) = StrawberryMilk::Entity::EntityManager::EntityState::NOT_AVAILABLE;
    return id - 1;
  } else {
    std::list<StrawberryMilk::Component::Component *> emptyList;
    mEntity.push_back(std::make_tuple(StrawberryMilk::Entity::EntityManager::EntityState::NOT_AVAILABLE, emptyList));
    return mCurrentId++;
  }
}

void StrawberryMilk::Entity::EntityManager::addComponentOnEntity(ID id, StrawberryMilk::Component::Component * component) {
  std::get<1>(mEntity.at(id)).push_back(component);
}

StrawberryMilk::Component::Component *StrawberryMilk::Entity::EntityManager::getComponentFromEntity(ID id, StrawberryMilk::Component::Type::IDComponent id_comp) {

  std::tuple<StrawberryMilk::Entity::EntityManager::EntityState, std::list<StrawberryMilk::Component::Component *>> entity = mEntity.at(id);

  auto it = std::find_if(std::get<1>(entity).begin(), std::get<1>(entity).end(), [&](StrawberryMilk::Component::Component const *component) {
    return component->getIDComponent() == id_comp;
  });

  if (it == std::get<1>(entity).end()) {
    throw std::invalid_argument("Component not found");
  }

  return *it;
}
