#pragma once

namespace StrawberryMilk {

  class Component {

    // ctor dtor
  public:
    Component(unsigned long int);
    ~Component();
    Component(Component const &) = delete;
    void operator=(Component const &) = delete;

    // system loop
  public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void destroy() = 0;

    // getter
  public:
    unsigned long int getIDComponent() const;

  private:
    // MUST BE A UNIQUE ID
    unsigned long int mIDComponent;
  };
};
