#include "Physic.hh"
#include "../../../engine/includes/Engine.hh"
#include "../../Component/RigidBody/RigidBody.hh"

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
		for (auto entity = m_entities.begin(); entity != m_entities.end(); ++entity)
		{
			try
			{
				auto entityNext = entity;
				++entityNext;

				for (; entityNext != m_entities.end(); ++entityNext)
				{
					CompareEntities(*entity, *entityNext, engine);
				}
			}
			catch (...)
			{
				//LOGGING FOR BAD ENTITY (NO RIGIDBODY)
			}
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

	void PhysicSystem::CompareEntities(StrawberryMilk::Entity::ID entity, StrawberryMilk::Entity::ID collisionCandidate, StrawberryMilk::Engine *engine)
	{
		RigidBody *body[2];
		Transform *transform[2];

		body[0] = engine->getComponentFromEntity<RigidBody>(entity);
		transform[0] = engine->getComponentFromEntity<Transform>(entity);

		body[1] = engine->getComponentFromEntity<RigidBody>(collisionCandidate);
		transform[1] = engine->getComponentFromEntity<Transform>(collisionCandidate);


	}
};