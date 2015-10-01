#pragma once

#include <windows.h>


namespace StrawberryMilk {

  template<class T>
  class DLLLoader {

    private:
      typedef T (__stdcall *f_funci)();

    public:
        DLLLoader() {}
        ~DLLLoader() {}
        DLLLoader(DLLLoader const &dllloader) { this->mHGetProcIDDLL = dllloader.mHGetProcIDDLL; };
        DLLLoader(DLLLoader &&dllloader) { this->mHGetProcIDDLL = dllloader.mHGetProcIDDLL; };

    public:
      void load(std::string const &str) {

        if (!mIsInit) {
          mHGetProcIDDLL = LoadLibrary(str.c_str());
          if (mHGetProcIDDLL) {
            mIsInit = true;
          } else {
            throw std::invalid_argument("Cannot load DLL: Wrong path");
          }
        } else {
          throw std::invalid_argument("Cannot load DLL: DLL already load");
        }
      };

      T call(std::string const &str) {
        if (mIsInit) {
          f_funci funci = (f_funci)GetProcAddress(hGetProcIDDLL, str.c_str());
          return funci()
        }
      };

    private:
      HINSTANCE mHGetProcIDDLL;
      bool isInit;
  };
}
