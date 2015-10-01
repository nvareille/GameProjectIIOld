#pragma once

namespace StrawberryMilk {

  namespace Component {

    namespace Type {

      typedef unsigned long int IDComponent;
    };

    class __declspec(dllexport) Component {

      // ctor dtor
    public:

      Component(StrawberryMilk::Component::Type::IDComponent IDComponent): mIDComponent(IDComponent) {};
      ~Component() {};
      Component(Component &&) = delete;
      Component(Component const &) = delete;
      void operator=(Component const &) = delete;

      // system loop
    public:
      virtual void init() = 0;
      virtual void update() = 0;
      virtual void destroy() = 0;

      // getter
    public:
      inline StrawberryMilk::Component::Type::IDComponent getIDComponent() const { return mIDComponent; }

    private:
      // MUST BE A UNIQUE ID
      StrawberryMilk::Component::Type::IDComponent mIDComponent;
    };
  };
};
