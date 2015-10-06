#pragma once

#include <list>

#include "../../../engine/System/System.hh"
#include "../../Component/RigidBody/RigidBody.hh"

namespace HeroesSoul
{
	class PhysicSystem : public StrawberryMilk::System
	{
		// ctor dtor
	public:
		PhysicSystem();
		~PhysicSystem();
		PhysicSystem(System const &&) = delete;
		PhysicSystem(System const &) = delete;
		void operator=(System const &) = delete;

		// system loop
	public:
		virtual void init();
		virtual void update(StrawberryMilk::Engine *, std::chrono::duration<double>);
		virtual void destroy();

		// member function entity
	public:
		virtual bool registerEntity(StrawberryMilk::Entity::ID);

	private:
		void CompareEntities(StrawberryMilk::Entity::ID, StrawberryMilk::Entity::ID, StrawberryMilk::Engine *);
		bool CompareRects(RigidBody **, Transform **);
		bool CompareCircles(RigidBody **, Transform **);
		bool CompareRectCircle(RigidBody **, Transform **);
		void SwapContainers(void *);

	private:
		std::list<StrawberryMilk::Entity::ID> m_entities;
	};

	class Square
	{
	public:
		Square(RigidBody *, Transform *);
		bool ResolveCollision(const Square &square2);

	public:
		StrawberryMilk::Math::Vector2 min;
		StrawberryMilk::Math::Vector2 max;
	};
};