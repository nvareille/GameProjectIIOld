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
	engine/includes/ThreadPool.hh

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

add_library(physic-System SHARED 

	engine/system/System.hh
	engine/Component/Component.hh
	engine/src/Vector2.hh
	engine/src/Vector2.cc
	engine/src/Jsoncpp.cpp
	engine/includes/Engine.hh
	engine/src/JsonSerializer.cpp

	Sources/System/Physic/Physic.hh
	Sources/System/Physic/Physic.cc
	Sources/Component/RigidBody/RigidBody.hh
	Sources/Component/Transform/Transform.hh
)

project(Update-System)

include(CheckCXXCompilerFlag)
set(ENABLE_CXX_EXCEPTIONS = 1)

include_directories(
	engine/src
	)

add_library(update-System SHARED 

	engine/system/System.hh
	engine/Component/Component.hh
	engine/src/Vector2.hh
	engine/src/Vector2.cc
	engine/src/Jsoncpp.cpp
	engine/src/ecs/EntityManager.cc
	engine/includes/Engine.hh

	Sources/System/Update/Update.hh
	Sources/System/Update/Update.cc
)

project(Transform-Component)

include(CheckCXXCompilerFlag)
set(ENABLE_CXX_EXCEPTIONS = 1)

add_library(Transform-Component SHARED
	engine/Component/Component.hh
	engine/src/Vector2.hh
	engine/src/Vector2.cc
	engine/src/Jsoncpp.cpp
	engine/src/JsonSerializer.cpp
	engine/includes/Engine.hh

	Sources/Component/Transform/Transform.hh
	Sources/Component/Transform/Transform.cc
)

project(RigidBody-Component)

include(CheckCXXCompilerFlag)
set(ENABLE_CXX_EXCEPTIONS = 1)

add_library(RigidBody-Component SHARED
	engine/Component/Component.hh
	engine/src/Vector2.hh
	engine/src/Vector2.cc
	engine/src/Jsoncpp.cpp
	engine/src/JsonSerializer.cpp
	engine/includes/Engine.hh

	Sources/Component/RigidBody/RigidBody.hh
	Sources/Component/RigidBody/RigidBody.cc
)

link_directories(Sources/Librairies/Microsoft_DirectX_SDK/Lib/x86)

project(GraphicSystem)

include(CheckCXXCompilerFlag)
set(ENABLE_CXX_EXCEPTIONS = 1)

include_directories(
	engine/src
	Sources/Librairies/Microsoft_DirectX_SDK/Include 
	)

add_library(GraphicSystem SHARED 
	Sources/Librairies/Microsoft_DirectX_SDK/Lib/x86

	engine/Component/Component.hh
	engine/src/Vector2.hh
	engine/src/Vector2.cc
	engine/src/Jsoncpp.cpp
	engine/src/JsonSerializer.cpp
	engine/includes/Engine.hh
	engine/src/ecs/Engine.cc
	Sources/Component/Transform/Transform.hh

	Sources/System/Graphic/GraphicsCore.h	
	Sources/System/Graphic/GraphSystem.h
	Sources/System/Graphic/TextureHandler.h
	Sources/System/Graphic/Camera.h
	Sources/System/Graphic/D3DWrapper.h
	Sources/System/Graphic/TextureShaderManager.h
	Sources/Component/DrawableComponent/DrawableComponent.h
	
	Sources/System/Graphic/TextureShaderManager.cpp
	Sources/System/Graphic/TextureHandler.cpp
	Sources/System/Graphic/D3DWrapper.cpp
	Sources/System/Graphic/Camera.cpp
	Sources/Component/DrawableComponent/DrawableComponent.cpp
	engine/src/ecs/ComponentManager.cc
	engine/src/ecs/EntityManager.cc
	Sources/System/Graphic/GraphicsCore.cpp
	Sources/System/Graphic/GraphSystem.cpp
	engine/src/ecs/SystemManager.cc
	Sources/System/Graphic/GraphSystemCreator.cpp
)

target_link_libraries(GraphicSystem d3dx10)

project(DrawableComponent)

include(CheckCXXCompilerFlag)
set(ENABLE_CXX_EXCEPTIONS = 1)

include_directories(
	engine/src
	Sources/Librairies/Microsoft_DirectX_SDK/Include 
	)
	
add_library(DrawableComponent SHARED
  
	engine/Component/Component.hh
	engine/src/Vector2.hh
	engine/src/Vector2.cc
	engine/src/Jsoncpp.cpp
	engine/src/JsonSerializer.cpp
	engine/includes/Engine.hh
	engine/src/ecs/Engine.cc
	Sources/Component/Transform/Transform.hh
	Sources/Component/Transform/Transform.cc


	Sources/System/Graphic/GraphicsCore.h	
	Sources/System/Graphic/GraphSystem.h
	Sources/System/Graphic/TextureHandler.h
	Sources/System/Graphic/Camera.h
	Sources/System/Graphic/D3DWrapper.h
	Sources/System/Graphic/TextureShaderManager.h
	Sources/Component/DrawableComponent/DrawableComponent.h
	
	Sources/System/Graphic/TextureShaderManager.cpp
	Sources/System/Graphic/TextureHandler.cpp
	Sources/System/Graphic/D3DWrapper.cpp
	Sources/System/Graphic/Camera.cpp
	Sources/Component/DrawableComponent/DrawableComponent.cpp
	Sources/Component/DrawableComponent/DrawableComponentCreator.cpp
	engine/src/ecs/ComponentManager.cc
	engine/src/ecs/EntityManager.cc
	Sources/System/Graphic/GraphicsCore.cpp
	Sources/System/Graphic/GraphSystem.cpp
	engine/src/ecs/SystemManager.cc
	
)

target_link_libraries(DrawableComponent d3dx10)
