#pragma once

#include <iostream>
#include <string>

namespace StrawberryMilk {

  class Log {

  public:
    Log();
    ~Log();
    Log(Log const &&) = delete;
    Log(Log const &) = delete;
    void operator=(Log const &) = delete;

  public:
    void Info(std::string const &) const;
    void Error(std::string const &) const;
  };
};
