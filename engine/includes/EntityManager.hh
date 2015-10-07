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
      void addComponentOnEntity(ID, StrawberryMilk::Component::Component *);
	  std::list<StrawberryMilk::Component::Component *> &StrawberryMilk::Entity::EntityManager::GetComponents(ID);

      template <class T>
      T *getComponentFromEntity(StrawberryMilk::Entity::ID id) {

        std::tuple<StrawberryMilk::Entity::EntityManager::EntityState, std::list<StrawberryMilk::Component::Component *>> entity = mEntity.at(id);
        T *component;
        for (StrawberryMilk::Component::Component *tmp : std::get<1>(entity)) {
          try {
            component = dynamic_cast<T *>(tmp);
            if (component != nullptr) {
              return component;              
            }
          } catch (...) {}
        }

        throw std::invalid_argument("Component not found");
        return  nullptr; // WARNING ERROR
      }

    private:
      std::vector<
        std::tuple<
          StrawberryMilk::Entity::EntityManager::EntityState,
          std::list<StrawberryMilk::Component::Component *>
          >
        > mEntity;
        ID mCurrentId;
    };
  };
};
