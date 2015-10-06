cmake_minimum_required(VERSION 3.2)

project(HeroesSouls)

include(CheckCXXCompilerFlag)
set(ENABLE_CXX_EXCEPTIONS = 1)
add_executable (
	heroesSouls

	engine/component/Component.hh
	engine/system/System.hh

	engine/src/HeroesSouls.cc
	engine/src/log/Log.cc
	engine/src/ecs/Engine.cc
	engine/src/ecs/SystemManager.cc
	engine/src/ecs/EntityManager.cc
	engine/src/ecs/ComponentManager.cc

	engine/includes/Engine.hh
	engine/includes/Singleton.hh
	engine/includes/Log.hh
	engine/includes/SystemManager.hh
	engine/includes/EntityManager.hh
	engine/includes/ComponentManager.hh

	engine/lib/jsoncpp.cpp
	engine/lib/JsonSerializer.cpp

	engine/lib/IJsonSerializable.hh
	engine/lib/JsonLoader.hh
	engine/lib/JsonSerializer.hh

	engine/lib/json/json.h
	engine/lib/json/json-forwards.h
)

project(Physic-System)

include(CheckCXXCompilerFlag)
set(ENABLE_CXX_EXCEPTIONS = 1)

include_directories(
	engine/src
	)

add_library(physic-System SHARED 

	engine/system/System.hh
	engine/Component/Component.hh
	engine/src/Vector2.hh
	engine/src/Vector2.cc
	engine/src/Jsoncpp.cpp
	engine/includes/Engine.hh

	Sources/System/Physic/Physic.hh
	Sources/System/Physic/Physic.cc
	Sources/Component/RigidBody/RigidBody.hh
	Sources/Component/RigidBody/RigidBody.cc
	Sources/Component/Transform/Transform.hh
)
