#ifndef GET_LOCAL_H_
#define GET_LOCAL_H_

#include <iostream>

// Export macro — works on Linux/macOS (ELF) and Windows (PE)
#if defined(_WIN32)
  #if defined GET_LOCAL_EXPORT
    #define GET_LOCAL_API __declspec(dllexport)
  #endif
  #if defined GET_LOCAL_IMPORT
    #define GET_LOCAL_API __declspec(dllimport)
  #endif
#else
  #define GET_LOCAL_API __attribute__((visibility("default")))
#endif

// Declaration only — NOT inline, NOT defined here
GET_LOCAL_API int& get_default_local();

#endif  // GET_LOCAL_H_
