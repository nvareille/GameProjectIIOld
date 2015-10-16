#include "Physic.hh"

namespace HeroesSoul
{
	extern "C"
	{
		__declspec(dllexport) StrawberryMilk::System *create(void)
		{
			return dynamic_cast<StrawberryMilk::System *>(new PhysicSystem);
		}
	}

	PhysicSystem::PhysicSystem()
	{
		std::cout << "Construct" << std::endl;
	}

	PhysicSystem::~PhysicSystem()
	{
		std::cout << "Destruct" << std::endl;
	}

	void PhysicSystem::init(StrawberryMilk::Engine *engine)
	{	
		m_engine = engine;
		std::cout << "Init" << std::endl;
	}

	void PhysicSystem::update(StrawberryMilk::Engine *engine, double dt)
	{
		for (auto entity = m_entities.begin(); entity != m_entities.end(); ++entity)
		{
			ApplyEulerIntegration(engine, *entity, dt);

			try
			{
				auto entityNext = entity;
				++entityNext;

				if (entityNext != m_entities.end())
				{
					for (; entityNext != m_entities.end(); ++entityNext)
					{
						CompareEntities(*entity, *entityNext, engine);
					}
				}
			}
			catch (...)
			{
				//LOGGING FOR BAD ENTITY (NO RIGIDBODY)
			}
		}
	}

	void PhysicSystem::destroy(StrawberryMilk::Engine *)
	{

	}

	bool PhysicSystem::registerEntity(StrawberryMilk::Entity::ID entity)
	{	
		try
		{
			m_engine->getComponentFromEntity<RigidBody>(entity);
			std::cout << "ADDED TO PHYSIC SYSTEM" << std::endl;

			m_entities.push_back(entity);
			return (true);
		}
		catch (...)
		{
			return (false);
		}	
	}

	void PhysicSystem::CompareEntities(StrawberryMilk::Entity::ID entity, StrawberryMilk::Entity::ID collisionCandidate, StrawberryMilk::Engine *engine)
	{
		RigidBody *body[2];
		Transform *transform[2];
		int test = 0;

		body[0] = engine->getComponentFromEntity<RigidBody>(entity);
		transform[0] = engine->getComponentFromEntity<Transform>(entity);

		body[1] = engine->getComponentFromEntity<RigidBody>(collisionCandidate);
		transform[1] = engine->getComponentFromEntity<Transform>(collisionCandidate);

		test += body[0]->IsCircle() ? -1 : 1;
		test += body[1]->IsCircle() ? -1 : 1;

		if (test == 0)
		{
			if (body[0]->IsCircle())
			{
				RigidBody *swapBody = body[0];
				Transform *swapTransform = transform[0];

				body[0] = body[1];
				body[1] = swapBody;
				transform[0] = transform[1];
				transform[1] = swapTransform;
			}
			if (CompareRectCircle(body, transform))
			{

			}
		}
		else if (test == -2)
		{
			if (CompareCircles(body, transform))
			{

			}
		}
		else
		{
			if (CompareRects(body, transform))
			{
				/*body[0]->SetKinematic(true);
				body[1]->SetKinematic(true);*/

				//SEND MESSAGE TO COLLIDING RECTS
				ComputeImpulse(body, transform);
			}
		}
	}

	bool PhysicSystem::CompareRects(RigidBody **body, Transform **transform)
	{
		Square square1(body[0], transform[0]);
		Square square2(body[1], transform[1]);

		return (square1.ResolveCollision(square2));
	}

	bool PhysicSystem::CompareCircles(RigidBody **, Transform **)
	{
		return (false);
	}

	bool PhysicSystem::CompareRectCircle(RigidBody **, Transform **)
	{
		return (false);
	}

	void PhysicSystem::ApplyEulerIntegration(StrawberryMilk::Engine *engine, StrawberryMilk::Entity::ID id, double dt)
	{
		RigidBody *body = engine->getComponentFromEntity<RigidBody>(id);
		Transform *transform = engine->getComponentFromEntity<Transform>(id);
		double ResistanceFactor = (1 - body->GetAirResistance());
		
		if (!body->IsKinematic())
		{
			body->AddForce(StrawberryMilk::Math::Vector2(0, (1 / body->GetMass()) * dt) / ResistanceFactor);
			body->SetForce(body->GetForces() * ResistanceFactor);
			transform->m_position -= StrawberryMilk::Math::Vector2(-body->GetForces().x * dt * ResistanceFactor, body->GetForces().y * dt);
		}
	}

	void PhysicSystem::ComputeImpulse(RigidBody **body, Transform **transform)
	{
		StrawberryMilk::Math::Vector2 normal(0, 1);
		StrawberryMilk::Math::Vector2 rv = body[1]->GetForces() - body[0]->GetForces();
		float velAlongNormal = ComputeDotProduct(rv, normal);

		if (velAlongNormal > 0)
			return;

		//RESTITUTION
		float e = 1;

		float j = -(1 + e) * velAlongNormal;
		j /= 1 / body[0]->GetMass() + 1 / body[1]->GetMass();

		StrawberryMilk::Math::Vector2 impulse = normal * j;

		/*body[0]->SetForce(impulse * body[0]->GetImpulse() * (-1 / body[0]->GetMass()));
		body[1]->SetForce(impulse * body[1]->GetImpulse() * (1 / body[1]->GetMass()));*/
	}

	float PhysicSystem::ComputeDotProduct(const StrawberryMilk::Math::Vector2 &v1, const StrawberryMilk::Math::Vector2 &v2) const
	{
		float dotProduct;

		dotProduct = v1.x * v2.x;
		dotProduct += v1.y * v2.y;

		return (dotProduct);
	}

	Square::Square(RigidBody *body, Transform *transform)
	{
		min = body->GetDimensions() / 2;
		max = min;

		min = transform->Position() - min;
		max = transform->Position() + max;

		std::cout << "BOX BOUNDS [X " << min.x << " <=> " << max.x << "] [Y " << min.y << " <=> " << max.y << "]" << std::endl;
	}

	bool Square::ResolveCollision(const Square &square2)
	{
		if (max.x < square2.min.x || min.x > square2.max.x) return false;
		if (max.y < square2.min.y || min.y > square2.max.y) return false;
		
		return true;
	}
};