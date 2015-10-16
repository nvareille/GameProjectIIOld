#pragma once

#include <windows.h>
#include <iostream>

namespace StrawberryMilk {

  template<class T>
  class DLLLoader {

    private:
      typedef T (__stdcall *f_funci)();

    public:
        DLLLoader() : mIsInit(false) {}
        ~DLLLoader() {}
        DLLLoader(DLLLoader const &dllloader) { this->mHGetProcIDDLL = dllloader.mHGetProcIDDLL; };
        DLLLoader(DLLLoader &&dllloader) { this->mHGetProcIDDLL = dllloader.mHGetProcIDDLL; };
		    DLLLoader operator=(DLLLoader const &a) { return a;  }

  public:
      void load(std::string const &str) {
          mHGetProcIDDLL = LoadLibrary(str.c_str());
          if (mHGetProcIDDLL) {
            mIsInit = true;
          } else {
            throw std::invalid_argument("Cannot load DLL");
          }
      };

      T call(std::string const &str) {
        if (mIsInit) {
          f_funci funci = (f_funci)GetProcAddress(mHGetProcIDDLL, str.c_str());
		  return funci();
        }
      };

    private:
      HINSTANCE mHGetProcIDDLL;
      bool mIsInit;
  };
}
