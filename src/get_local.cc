#include <iostream>

#define GET_LOCAL_EXPORT
#include "get_local.h"

int& get_default_local() {
  thread_local int default_local{42};
  std::clog << "get_default_local() " << &default_local << "\n";
  return default_local;
}
