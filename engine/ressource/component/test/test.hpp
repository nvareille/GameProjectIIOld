#pragma once

#include <iostream>
#include "../../../component/Component.hh"

struct __declspec(dllexport) Test : public StrawberryMilk::Component::Component {


	Test(void) : StrawberryMilk::Component::Component(1) {} ;
	~Test(void) = default;
    void init() { std::cout << "MY COMPONENT HAS INIT"; };
    void update() { std::cout << "MY COMPONENT WAS UPDATE"; };
    void destroy() { std::cout << "MY COMPONENT WAS DESTROY"; };
};
