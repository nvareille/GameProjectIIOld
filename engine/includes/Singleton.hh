#pragma once

namespace StrawberryMilk {

  template<class T>
  class Singleton {

  public:
    Singleton() {};
    ~Singleton() {};

  public:
    T &Get() { return t; };

  private:
    static T t;
  };
};
