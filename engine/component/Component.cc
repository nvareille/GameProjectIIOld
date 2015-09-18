#include "Component.hh"

StrawberryMilk::Component::Component(unsigned long int IDComponent) : mIDComponent(IDComponent){ }

StrawberryMilk::Component::~Component() { }

unsigned long int StrawberryMilk::Component::getIDComponent() const {
  return mIDComponent;
}
