#include <nanobind/nanobind.h>

#include "get_local.h"

NB_MODULE(static_thread_local_ext, m) {
    m.def("set_local", [](int value) { get_default_local() = value; });
    m.def("get_local", []() { return get_default_local(); });
}
