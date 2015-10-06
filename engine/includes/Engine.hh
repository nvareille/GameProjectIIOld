#pragma once

#include <stack>
#include "Singleton.hh"
#include "Log.hh"
#include "SystemManager.hh"
#include "EntityManager.hh"
#include "ComponentManager.hh"
#include "../lib/json/json.h"
#include "../lib/IJsonSerializable.hh"


namespace StrawberryMilk {

  class Engine {

  private:
    class SceneLoader : public IJsonSerializable {

    public:
      SceneLoader() {};
      ~SceneLoader() {};

    public:
      void Serialize(Json::Value &root) { };

      void Deserialize(Json::Value &root) {
        for (auto e : root["System"]) {
          mSystem.push(std::make_pair(e["name"].asString(), e["dll"].asString()));
        }
        for (auto e : root["Component"]) {
          mComponent.push(std::make_pair(e["name"].asString(), e["dll"].asString()));
        }
        for (auto e : root["Scene"]) {
          std::list<std::pair<std::string, std::string>> entity;
          for (auto j: e) {
            entity.push_back(std::make_pair(j["Component"].asString(), j["data path"].asString()));
          }
          mEntity.push(entity);
        }
      };

    public:
      inline std::stack<std::pair<std::string, std::string>> &getComponent() { return mComponent; };
      inline std::stack<std::pair<std::string, std::string>> &getSystem() { return mSystem; };
      inline std::stack<std::list<std::pair<std::string, std::string>>> &getEntity() { return mEntity; }

    private:
      std::stack<std::pair<std::string, std::string>> mComponent;
      std::stack<std::pair<std::string, std::string>> mSystem;
      std::stack<std::list<std::pair<std::string, std::string>>> mEntity;
    };

  public:
    Engine();
    ~Engine();
    Engine(Engine const &&) = delete;
    Engine(Engine const &) = delete;
    Engine operator=(Engine const &) = delete;

  public:
    System &getSystem(std::string const &) const;

  public:
    template <class T>
	   T *getComponentFromEntity(StrawberryMilk::Entity::ID id) {
       return mEntity.getComponentFromEntity<T>(id);
     };

  public:
    void init();
    void run();
    void stop();

  private:
    void loadScene(StrawberryMilk::Engine::SceneLoader &);

  private:
    void loadScene(std::string const &);

  private:
//    StrawberryMilk::Singleton<StrawberryMilk::Log> mLog;
    StrawberryMilk::SystemManager mSystem;
    StrawberryMilk::Entity::EntityManager mEntity;
    StrawberryMilk::Component::ComponentManager mComponent;
    bool mContinue;
  };
}
