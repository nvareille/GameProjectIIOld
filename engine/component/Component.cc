#include "Component.hh"

StrawberryMilk::Component::Component::Component(StrawberryMilk::Component::Type::IDComponent IDComponent) : mIDComponent(IDComponent){ }

StrawberryMilk::Component::Component::~Component() { }

StrawberryMilk::Component::Type::IDComponent
StrawberryMilk::Component::Component::getIDComponent() const {
  return mIDComponent;
}
