#include "Component.hh"

StrawberryMilk::Component::Component(StrawberryMilk::Type::IDComponent IDComponent) : mIDComponent(IDComponent){ }

StrawberryMilk::Component::~Component() { }

StrawberryMilk::Type::IDComponent StrawberryMilk::Component::getIDComponent() const {
  return mIDComponent;
}
