#include <iostream>

inline int& get_default_local() {
  static thread_local int default_local{42};
  std::cout << "get_default_local() " << &default_local << "\n";
  return default_local;
}
