#pragma once

namespace StrawberryMilk {

  class __declspec(dllexport) System {

    enum class state {
      ACTIVE,
      PAUSE
    };

    // ctor dtor
  public:
    System() : mState(StrawberryMilk::System::state::ACTIVE), mRequirement(0) {};
    ~System() { };
    System(System const &&) = delete;
    System(System const &) = delete;
    void operator=(System const &) = delete;

    // system loop
  public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void destroy() = 0;

    // member function entity
  public:
    virtual bool registerEntity() = 0;

    // getter
  public:
    inline unsigned long getRequirement() const { return mRequirement; };

    // status function member
  public:
    inline bool isActive() const { return mState == StrawberryMilk::System::state::ACTIVE;}
    inline bool isPause() const { return mState == StrawberryMilk::System::state::PAUSE; };
    inline void setActive() {   mState = StrawberryMilk::System::state::ACTIVE; };
    inline void setPause() { mState = StrawberryMilk::System::state::PAUSE;};

  private:
    state mState;
    unsigned long mRequirement;
  };
};
