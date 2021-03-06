#pragma once

#include <list>

#include "../../../engine/System/System.hh"

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
		bool CompareRects();
		bool CompareCircles();
		bool CompareRectCircle();

	private:
		std::list<StrawberryMilk::Entity::ID> m_entities;
	};
};