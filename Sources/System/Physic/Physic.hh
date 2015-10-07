#pragma once

#include <list>
#include <algorithm>

#include "../../../engine/includes/Engine.hh"
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
		virtual void init(StrawberryMilk::Engine *);
		virtual void update(StrawberryMilk::Engine *, double);
		virtual void destroy(StrawberryMilk::Engine *);

		// member function entity
	public:
		virtual bool registerEntity(StrawberryMilk::Entity::ID);

	private:
		void CompareEntities(StrawberryMilk::Entity::ID, StrawberryMilk::Entity::ID, StrawberryMilk::Engine *);
		bool CompareRects(RigidBody **, Transform **);
		bool CompareCircles(RigidBody **, Transform **);
		bool CompareRectCircle(RigidBody **, Transform **);
		void SwapContainers(void *);

		void ApplyEulerIntegration(StrawberryMilk::Engine *, StrawberryMilk::Entity::ID, double);
		void ComputeImpulse(RigidBody **, Transform **);
		float ComputeDotProduct(const StrawberryMilk::Math::Vector2 &, const StrawberryMilk::Math::Vector2 &) const;


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