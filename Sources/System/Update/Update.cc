#include <list>
#include "Update.hh"
#include "../../../engine/includes/Engine.hh"

namespace HeroesSoul
{
	extern "C"
	{
		__declspec(dllexport) StrawberryMilk::System *create(void)
		{
			return dynamic_cast<StrawberryMilk::System *>(new UpdateSystem);
		}
	}

	UpdateSystem::UpdateSystem()
	{
		std::cout << "Construct" << std::endl;
	}

	UpdateSystem::~UpdateSystem()
	{
		std::cout << "Destruct" << std::endl;
	}

	void UpdateSystem::init()
	{

		std::cout << "Init" << std::endl;
	}

	void UpdateSystem::update(StrawberryMilk::Engine *engine, std::chrono::duration<double>)
	{
		for (auto entity : m_entities)
		{
			auto components = engine->GetComponents(entity);

			for (auto component : components)
			{
				component->update();
			}
		}

	}

	void UpdateSystem::destroy()
	{

	}

	bool UpdateSystem::registerEntity(StrawberryMilk::Entity::ID entity)
	{
		printf("ADD\n");

		m_entities.push_back(entity);
		return (true);
	}
};