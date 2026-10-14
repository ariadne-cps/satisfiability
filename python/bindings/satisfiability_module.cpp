#include "pybind11.hpp"

void satisfiability_submodule(pybind11::module& module);

void satisfiability_module(pybind11::module& module) {
    satisfiability_submodule(module);
}
