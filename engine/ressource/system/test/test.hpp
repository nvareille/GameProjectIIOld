#pragma once

#include <iostream>
#include <chrono>
#include "../../../system/System.hh"
#include "../../../includes/Engine.hh"
#include "../../../component/Component.hh"

struct __declspec(dllexport) Test : public StrawberryMilk::System {


	Test(void) {} ;
	~Test(void) = default;
  void init(StrawberryMilk::Engine *) { std::cout << "MY COMPONENT HAS INIT"; };
  void update(std::chrono::duration<double> /* */, StrawberryMilk::Engine * /* */) { std::cout << "MY COMPONENT WAS UPDATE"; };
  void destroy(StrawberryMilk::Engine * /* */) { std::cout << "MY COMPONENT WAS DESTROY"; };
  bool registerEntity(StrawberryMilk::Component::Type::IDComponent /* */) { return true;  };
};
