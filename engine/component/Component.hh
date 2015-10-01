#pragma once

namespace StrawberryMilk {

  namespace Component {

    namespace Type {

      typedef unsigned long int IDComponent;
    };

    class Component {

      // ctor dtor
    public:
      Component(StrawberryMilk::Component::Type::IDComponent);
      ~Component();
      Component(Component const &&) = delete;
      Component(Component const &) = delete;
      void operator=(Component const &) = delete;

      // system loop
    public:
      virtual void init() = 0;
      virtual void update() = 0;
      virtual void destroy() = 0;

      // getter
    public:
      StrawberryMilk::Component::Type::IDComponent getIDComponent() const;

    private:
      // MUST BE A UNIQUE ID
      StrawberryMilk::Component::Type::IDComponent mIDComponent;
    };
  };
};
