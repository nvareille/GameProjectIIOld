project(HeroesSouls)

include(CheckCXXCompilerFlag)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(ENABLE_CXX_EXCEPTIONS = 1)
add_executable (
	heroesSouls
	engine/component/Component.cc
	engine/component/Component.hh
	engine/system/System.cc
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
)
