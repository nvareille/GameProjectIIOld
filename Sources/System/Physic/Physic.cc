#include "Physic.hh"

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

	void PhysicSystem::update(StrawberryMilk::Engine *, std::chrono::duration<double>)
	{
	}

	void PhysicSystem::destroy()
	{
	}

	bool PhysicSystem::registerEntity(void *entity)
	{
		m_entities.push_back(entity);

		return (true);
	}
};