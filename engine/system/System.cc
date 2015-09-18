#include "System.hh"

StrawberryMilk::System::System()
: mState(StrawberryMilk::System::state::ACTIVE), mRequirement(0) {}

StrawberryMilk::System::~System() {}

unsigned long StrawberryMilk::System::getRequirement() const {
  return mRequirement;
}

bool StrawberryMilk::System::isActive() const {
  return mState == StrawberryMilk::System::state::ACTIVE;
}

bool StrawberryMilk::System::isPause() const {
  return mState == StrawberryMilk::System::state::PAUSE;
}

void StrawberryMilk::System::setActive() {
  mState = StrawberryMilk::System::state::ACTIVE;
}

void StrawberryMilk::System::setPause() {
  mState = StrawberryMilk::System::state::PAUSE;
}

int main() {
  return 0;
}
