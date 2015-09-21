#include <algorithm>
#include "../includes/EntityManager.hh"

StrawberryMilk::Entity::EntityManager::EntityManager() : mCurrentId(0) {}
StrawberryMilk::Entity::EntityManager::~EntityManager() {}

void StrawberryMilk::Entity::EntityManager::destroyEntity(ID id) {
  std::get<0>(mEntity[id]) = StrawberryMilk::Entity::EntityManager::EntityState::AVAILABLE;
  std::get<1>(mEntity[id]).clear();
}

StrawberryMilk::Entity::ID StrawberryMilk::Entity::EntityManager::createEntity() {
  ID id = 0;
  auto it = std::find_if(mEntity.begin(), mEntity.end(), [&](std::tuple<StrawberryMilk::Entity::EntityManager::EntityState, std::list<StrawberryMilk::Component *>> it) {
      ++id;
      return std::get<0>(it) == StrawberryMilk::Entity::EntityManager::EntityState::AVAILABLE;
    });

    if (it != mEntity.end()) {
      return id - 1;
    }
    else {
		std::list<StrawberryMilk::Component *> emptyList;
      mEntity.push_back(std::make_tuple(StrawberryMilk::Entity::EntityManager::EntityState::NOT_AVAILABLE, emptyList));
      return mCurrentId++;
    }
}
