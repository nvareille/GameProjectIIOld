#include "Physic.hh"
#include "../../../engine/includes/Engine.hh"

namespace HeroesSoul
{
	PhysicSystem::PhysicSystem()
	{
	}

	PhysicSystem::~PhysicSystem()
	{
	}

	void PhysicSystem::init()
	{
	}

	void PhysicSystem::update(StrawberryMilk::Engine *engine, std::chrono::duration<double>)
	{
		for (auto centity : m_entities)
		{
			//engine->getComponentFromEntity();
		}
	}

	void PhysicSystem::destroy()
	{
	}

	bool PhysicSystem::registerEntity(StrawberryMilk::Entity::ID entity)
	{
		m_entities.push_back(entity);
		return (true);
	}
};