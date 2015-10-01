#include "../../includes/Log.hh"

StrawberryMilk::Log::Log() {}
StrawberryMilk::Log::~Log() {}

void StrawberryMilk::Log::Info(std::string const &str) const {
  std::cout << "[StrawberryMilk][Info]: " << str << std::endl;
}

void StrawberryMilk::Log::Error(std::string const &str) const {
  std::cout << "[StrawberryMilk][Error]: " << str << std::endl;
}
