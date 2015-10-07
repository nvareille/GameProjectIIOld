#pragma once

#include <iostream>
#include "../../../component/Component.hh"
#include "../../../includes/Engine.hh"

struct __declspec(dllexport) Test : public StrawberryMilk::Component::Component {


	Test(void) : StrawberryMilk::Component::Component(1) {} ;
	~Test(void) = default;
    void init(std::string const &, StrawberryMilk::Engine * /* */) { std::cout << "MY COMPONENT HAS INIT"; };
    void update(StrawberryMilk::Engine * /* */) { std::cout << "MY COMPONENT WAS UPDATE"; };
    void destroy(StrawberryMilk::Engine * /* */) { std::cout << "MY COMPONENT WAS DESTROY"; };
};
