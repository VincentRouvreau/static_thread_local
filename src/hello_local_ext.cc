#include <iostream>
#include <nanobind/nanobind.h>

#include "get_local.h"

NB_MODULE(hello_local_ext, m) {
    m.def("hello_local", []() { std::clog << "local= " << get_default_local() << "\n"; });
}
