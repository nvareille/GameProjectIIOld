project(HeroesSouls)

add_executable (
	heroesSouls
	engine/component/Component.cc
	engine/component/Component.hh
	engine/system/System.cc
	engine/system/System.hh

	engine/src/HeroesSouls.cc
	engine/src/Log.cc
	engine/src/Engine.cc

	engine/includes/Engine.hh
	engine/includes/Singleton.hh
	engine/includes/Log.hh
)
