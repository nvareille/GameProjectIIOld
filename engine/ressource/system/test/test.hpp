#pragma once

#include <iostream>
#include "../../../system/System.hh"

struct __declspec(dllexport) Test : public StrawberryMilk::System {


	Test(void) {} ;
	~Test(void) = default;
  void init() { std::cout << "MY COMPONENT HAS INIT"; };
  void update() { std::cout << "MY COMPONENT WAS UPDATE"; };
  void destroy() { std::cout << "MY COMPONENT WAS DESTROY"; };
  bool registerEntity() { return true;  };
};
