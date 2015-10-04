#pragma once

#include <list>

#include "../../../engine/System/System.hh"
#include "../../../engine/includes/Engine.hh"

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
		virtual bool registerEntity(void *);

	private:
		std::list<void *> m_entities;
	};
};