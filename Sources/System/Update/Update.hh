#pragma once

#include <list>

#include "../../../engine/System/System.hh"

namespace HeroesSoul
{
	class UpdateSystem : public StrawberryMilk::System
	{
		// ctor dtor
	public:
		UpdateSystem();
		~UpdateSystem();
		UpdateSystem(System const &&) = delete;
		UpdateSystem(System const &) = delete;
		void operator=(System const &) = delete;

		// system loop
	public:
		virtual void init(StrawberryMilk::Engine *);
		virtual void update(StrawberryMilk::Engine *, std::chrono::duration<double>);
		virtual void destroy(StrawberryMilk::Engine *);

		// member function entity
	public:
		virtual bool registerEntity(StrawberryMilk::Entity::ID);

	private:
		std::list<StrawberryMilk::Entity::ID> m_entities;
	};
};