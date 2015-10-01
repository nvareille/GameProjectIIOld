#pragma once

#include <string>

class Config {

public:
  Config();
  ~Config();
  Config(Config const &);
  Config operator=(Config const &);

private:
  std::list<std::string> mAuthor;
};
