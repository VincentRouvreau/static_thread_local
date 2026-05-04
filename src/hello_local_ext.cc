#include <iostream>
#include <nanobind/nanobind.h>

#include "get_local.h"

NB_MODULE(hello_local_ext, m) {
    m.def("hello_local", []() { int default_local = get_default_local(); std::clog << "local= " << default_local << "\n"; });
}
