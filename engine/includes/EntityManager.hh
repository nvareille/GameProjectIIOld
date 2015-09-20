#pragma once

#include <vector>
#include <list>
#include <tuple>
#include "../component/Component.hh"

namespace StrawberryMilk {

  namespace Entity {
    typedef unsigned int ID;

    class EntityManager {

    private:
      enum class EntityState {
        AVAILABLE,
        NOT_AVAILABLE,
        MUST_BE_EXTERMINATE // DAAAAAALEEEEK
      };

    public:
      EntityManager();
      ~EntityManager();
      EntityManager(EntityManager const &) = delete;
      EntityManager(EntityManager const &&) = delete;
      void operator=(EntityManager const &) = delete;

    public:
      void destroyEntity(ID);
      ID createEntity();

    private:
      std::vector<
        std::tuple<
          StrawberryMilk::Entity::EntityManager::EntityState,
          std::list<StrawberryMilk::Component *>
          >
        > mEntity;
        ID mCurrentId;
    };
  };
};
