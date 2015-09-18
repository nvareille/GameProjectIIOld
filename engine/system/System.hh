#pragma once

namespace StrawberryMilk {

  class System {

    enum class state {
      ACTIVE,
      PAUSE
    };

    // ctor dtor
  public:
    System();
    ~System();
    System(System const &) = delete;
    void operator=(System const &) = delete;

    // system loop
  public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void destroy() = 0;

    // member function entity
  public:
    virtual bool registerEntity(void *) = 0;

    // getter
  public:
    unsigned long getRequirement() const;

    // status function member
  public:
    bool isActive() const;
    bool isPause() const;
    void setActive();
    void setPause();

  private:
    state mState;
    unsigned long mRequirement;
  };
};
